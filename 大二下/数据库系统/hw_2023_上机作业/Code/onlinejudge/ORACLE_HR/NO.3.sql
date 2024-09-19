WITH E AS (
    SELECT *
    FROM Employees
        LEFT JOIN Departments USING(Department_id)
        LEFT JOIN Locations USING(Location_id)
        LEFT JOIN Countries USING(Country_id)
)
SELECT country_name,
    count(employee_id),
    min(salary),
    max(salary)
FROM E
WHERE state_province IN (
        SELECT State_province
        FROM E
        GROUP BY state_province
        HAVING avg(salary) > 8000
    )
GROUP BY country_name;