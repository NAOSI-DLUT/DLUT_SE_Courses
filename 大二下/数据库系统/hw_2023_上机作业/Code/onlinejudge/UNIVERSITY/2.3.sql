WITH tim AS (
    SELECT t.time_slot_id,
        t.end_hr,
        t.end_min,
        t.start_hr,
        t.start_min,
        COUNT(t.day) *(
            (t.end_hr - t.start_hr) * 60 +(t.end_min - t.start_min)
        ) / 50 AS tt
    FROM time_slot t
    GROUP BY t.time_slot_id,
        t.end_hr,
        t.end_min,
        t.start_hr,
        t.start_min
)
SELECT s.course_id,
    s.year,
    s.semester,
    count(s.sec_id) AS total,
    sum(tt)
FROM section s
    JOIN tim t ON s.time_slot_id = t.time_slot_id
GROUP BY s.course_id,
    s.year,
    s.semester;