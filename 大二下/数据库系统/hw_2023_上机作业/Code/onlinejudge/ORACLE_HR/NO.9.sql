SELECT first_name,
    LAST_NAME,
    DEPARTMENT_NAME,
    SALARY,
    (
        SELECT count(*)
        FROM employees s START WITH s.employee_id = e.employee_id
            AND s.employee_id IN (
                SELECT manager_id
                FROM employees
            ) CONNECT BY PRIOR s.employee_id = s.manager_id
    ) AS num_employees
FROM employees e
    LEFT JOIN DEPARTMENTS USING(DEPARTMENT_ID)
WHERE (
        SELECT count(*)
        FROM employees s START WITH s.employee_id = e.employee_id
            AND s.employee_id IN (
                SELECT manager_id
                FROM employees
            ) CONNECT BY PRIOR s.employee_id = s.manager_id
    ) > 0
ORDER BY num_employees DESC,
    salary ASC;