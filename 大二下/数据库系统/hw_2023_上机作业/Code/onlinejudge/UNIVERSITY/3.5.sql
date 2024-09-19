SELECT student.id,
    student.name,
    takes.course_id,
    COUNT(*),
    SUM(
        CASE
            WHEN takes.grade = 'F' THEN 1
            ELSE 0
        END
    )
FROM student
    JOIN takes ON student.id = takes.id
GROUP BY student.id,
    student.name,
    takes.course_id
HAVING COUNT(*) > 1;