SELECT employees.employee_id,
    employees.first_name,
    employees.last_name,
    employees.salary,
    departments.department_name
FROM employees
    JOIN departments ON employees.department_id = departments.department_id
WHERE departments.department_name like 'F%'
ORDER BY departments.department_name ASC,
    employees.salary DESC,
    employees.employee_id ASC;