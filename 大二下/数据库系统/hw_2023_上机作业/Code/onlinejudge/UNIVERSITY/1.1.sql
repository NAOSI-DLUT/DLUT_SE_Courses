SELECT student.name,
    course.title,
    count (*)
FROM student
    JOIN takes ON student.id = takes.id
    JOIN course ON takes.course_id = course.course_id
GROUP BY (student.name, course.title)
HAVING count (*) >= 2;