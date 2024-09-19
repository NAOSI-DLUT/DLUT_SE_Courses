WITH people_on_people AS (
    SELECT e.employee_id,
        count(*) AS total
    FROM employees e
        JOIN employees e2 ON e2.manager_id = e.employee_id
    WHERE e2.salary > 3000
    GROUP BY e.employee_id
    HAVING count(*) > 4
),
people AS (
    SELECT e.employee_id,
        round(avg(e2.salary), 2) AS avgsal
    FROM employees e
        JOIN employees e2 ON e2.manager_id = e.employee_id
    GROUP BY e.employee_id
),
department_avgsal AS (
    SELECT e.department_id,
        avg(e.salary) avgsal
    FROM employees e
    GROUP BY e.department_id
)
SELECT e.employee_id,
    e.first_name || ' ' || e.lASt_name AS name,
    j.job_title,
    p2.total,
    p.avgsal,
    e.salary
FROM employees e
    JOIN people_on_people p2 ON e.employee_id = p2.employee_id
    JOIN people p ON e.employee_id = p.employee_id
    JOIN jobs j ON e.job_id = j.job_id
    JOIN department_avgsal d ON e.department_id = d.department_id
ORDER BY d.avgsal,
    e.salary DESC,
    e.employee_id;