WITH A AS(
    SELECT employee_id,
        department_id,
        job_id
    FROM employees
),
B AS(
    SELECT employee_id,
        department_id,
        job_id
    FROM job_history
),
E AS (
    SELECT employee_id,
        count(*) AS job_count
    FROM (
            SELECT *
            FROM A
            UNION
            SELECT *
            FROM B
        )
    GROUP BY employee_id
    HAVING count(*) >= 2
)
SELECT employee_id,
    first_name,
    last_name,
    job_count
FROM employees
    JOIN E USING (employee_id)
ORDER BY job_count DESC,
    salary ASC,
    hire_date ASC;