WITH A AS(
    SELECT Employee_id,
        first_name,
        Last_name,
        Department_id,
        Salary,
        Manager_id
    FROM Employees
),
B AS(
    SELECT Employee_id,
        first_name,
        Last_name,
        Department_id,
        Salary,
        Manager_id,
        (
            SELECT count(*)
            FROM A B START WITH B.Employee_id = C.Employee_id CONNECT BY PRIOR B.employee_id = B.manager_id
        ) AS employees_num
    FROM A C
),
C AS(
    SELECT *
    FROM B
    WHERE Employees_num > 1
),
D AS(
    SELECT Employee_id,
        first_name,
        Last_name,
        Department_id,
        Salary,
        Manager_id,
        employees_num,
        (
            SELECT avg(salary)
            FROM (
                    SELECT *
                    FROM A Z START WITH Z.Manager_id = Y.Employee_id CONNECT BY PRIOR Z.employee_id = Z.manager_id
                )
        ) AS Employees_avg_salary
    FROM C Y
),
E AS(
    SELECT Department_id,
        MAX(salary) AS max_Salary,
        MAX(employees_num) AS max_num
    FROM D
    GROUP BY Department_id
)
SELECT Employee_id,
    first_name,
    Last_name,
    Department_id,
    employees_avg_salary
FROM D result1
WHERE salary = (
        SELECT max_salary
        FROM E
        WHERE department_id = result1.department_id
    )
    AND employees_num = (
        SELECT max_num
        FROM E
        WHERE department_id = result1.department_id
    )
ORDER BY employees_avg_salary DESC,
    employee_id ASC;