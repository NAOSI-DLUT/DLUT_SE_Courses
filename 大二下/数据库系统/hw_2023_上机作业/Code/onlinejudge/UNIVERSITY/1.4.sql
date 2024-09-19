--第一种方法
WITH A AS (
    SELECT department.dept_name,
        count(*)
    FROM department
        JOIN instructor ON department.dept_name = instructor.dept_name
    GROUP BY department.dept_name
    HAVING count(*) >= 4
)
SELECT student.id,
    student.name,
    student.dept_name
FROM student
    JOIN A ON student.dept_name = A.dept_name;
--第二种方法
SELECT student.id,
    student.name,
    student.dept_name
FROM student
WHERE EXISTS (
        SELECT department.dept_name
        FROM department
            JOIN instructor ON department.dept_name = instructor.dept_name
        WHERE student.dept_name = department.dept_name
        GROUP BY department.dept_name
        HAVING count(*) >= 4
    );