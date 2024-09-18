WITH coun AS(
    SELECT s.course_id,
        count(*) AS total
    FROM section s
    GROUP BY s.course_id
),
course_noF AS(
    SELECT DISTINCT course.course_id
    FROM course
        LEFT JOIN takes ON course.course_id = takes.course_id
    WHERE course.course_id NOT IN (
            SELECT course_id
            FROM takes
            WHERE grade = 'F'
        )
)
SELECT course.course_id,
    course.title,
    COALESCE(coun.total, 0)
FROM course_noF
    LEFT JOIN course ON course_noF.course_id = course.course_id
    LEFT JOIN coun ON coun.course_id = course.course_id;