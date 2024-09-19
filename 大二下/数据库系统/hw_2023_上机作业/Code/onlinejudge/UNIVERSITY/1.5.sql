WITH num AS (
    SELECT dept_name,
        count(name) AS total
    FROM instructor
    GROUP BY dept_name
)
SELECT department.dept_name,
    department.building,
    total
FROM department
    JOIN num ON department.dept_name = num.dept_name
WHERE EXISTS(
        SELECT department.dept_name
        FROM department d
            JOIN instructor ON d.dept_name = instructor.dept_name
        WHERE d.dept_name = department.dept_name
            AND instructor.name LIKE '%世%'
        GROUP BY department.dept_name
    );