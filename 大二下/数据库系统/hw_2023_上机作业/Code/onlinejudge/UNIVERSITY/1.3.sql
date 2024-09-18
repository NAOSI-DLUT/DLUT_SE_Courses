SELECT DISTINCT c.title,
    t.sec_id,
    t.year,
    t.semester
FROM section s
    JOIN course c ON s.course_id = c.course_id
    JOIN takes t ON t.sec_id = s.sec_id
WHERE t.grade is NULL
    AND t.course_id = c.course_id;