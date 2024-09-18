WITH A AS (
    SELECT takes.course_id,
        takes.id
    FROM student
        JOIN takes ON student.id = takes.id
    WHERE grade = 'F'
    MINUS
    SELECT takes.course_id,
        takes.id
    FROM student
        JOIN takes ON student.id = takes.id
    WHERE grade != 'F'
)
SELECT s.id,
    s.name,
    COUNT(A.course_id)
FROM student s
    JOIN A ON s.id = A.id
GROUP BY (s.id, s.name);