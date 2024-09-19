SELECT course_id,
    year,
    semester,
    sec_id,
    count(
        CASE
            WHEN grade LIKE '%A%' THEN 1
            ELSE NULL
        END
    ),
    count(
        CASE
            WHEN grade LIKE '%B%' THEN 1
            ELSE NULL
        END
    ),
    count(
        CASE
            WHEN grade LIKE '%C%' THEN 1
            ELSE NULL
        END
    ),
    count(
        CASE
            WHEN grade LIKE '%D%' THEN 1
            ELSE NULL
        END
    ),
    count(
        CASE
            WHEN grade LIKE '%F%' THEN 1
            ELSE NULL
        END
    ),
    count(
        CASE
            WHEN grade IS NULL THEN 1
            ELSE NULL
        END
    )
FROM takes
GROUP BY course_id,
    year,
    semester,
    sec_id;