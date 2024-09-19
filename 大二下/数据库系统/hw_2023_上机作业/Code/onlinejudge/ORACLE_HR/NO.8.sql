WITH test AS (
    SELECT r.region_id,
        d.department_id,
        AVG(e.salary) AS AVGsal
    FROM regions r
        JOIN countries c ON c.region_id = r.region_id
        JOIN locations l ON l.country_id = c.country_id
        JOIN departments d ON d.location_id = l.location_id
        JOIN employees e ON e.department_id = d.department_id
    GROUP BY r.region_id,
        d.department_id
),
department_AVGsal AS (
    SELECT e.department_id,
        AVG(e.salary) AS AVGsal
    FROM employees e
    GROUP BY e.department_id
),
endless AS (
    SELECT r.region_id,
        max(t.AVGsal) AS maxsal
    FROM regions r
        JOIN test t ON t.region_id = r.region_id
    GROUP BY r.region_id
),
endll AS (
    SELECT r.region_id,
        t.department_id
    FROM regions r
        JOIN test t ON t.region_id = r.region_id
        JOIN endless e1 ON e1.region_id = r.region_id
        AND e1.maxsal = t.AVGsal
)
SELECT e.employee_id,
    e.first_name || ' ' || e.lASt_name AS name,
    d.department_name,
    j.job_title,
    e.salary
FROM employees e
    JOIN departments d ON e.department_id = d.department_id
    JOIN jobs j ON e.job_id = j.job_id
    JOIN department_AVGsal d1 ON e.department_id = d1.department_id
    JOIN endll e2 ON e2.department_id = d.department_id
WHERE e.salary > d1.AVGsal;