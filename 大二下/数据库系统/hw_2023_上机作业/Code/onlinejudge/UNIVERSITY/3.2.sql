SELECT student.name,
    student.dept_name
FROM student
WHERE NOT EXISTS (
        select course_id
        FROM course
        WHERE student.dept_name = course.dept_name
        EXCEPT
        SELECT course_id
        FROM takes
        WHERE grade <> 'F'
            AND student.id = takes.id
    );