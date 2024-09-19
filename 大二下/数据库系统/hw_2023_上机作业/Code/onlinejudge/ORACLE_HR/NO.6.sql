WITH department_avgsal AS (
    SELECT department_id,
        AVG(salary) avgsal
    FROM employees
    GROUP BY employees.department_id
),
people_on_people AS (
    SELECT e.employee_id,
        count(*) AS total
    FROM employees e
        JOIN employees e2 ON e2.manager_id = e.employee_id
    WHERE e2.salary > 7000
    GROUP BY e.employee_id
    HAVING count(*) > 4
)
SELECT e.employee_id,
    e.first_name || ' ' || e.lASt_name,
    j.job_title,
    p2.total,
    e.salary
FROM employees e
    JOIN department_avgsal d2 ON e.department_id = d2.department_id
    JOIN people_on_people p2 ON e.employee_id = p2.employee_id
    JOIN jobs j ON e.job_id = j.job_id
WHERE e.salary > 1.3 * d2.avgsal
    AND p2.total IS NOT NULL;