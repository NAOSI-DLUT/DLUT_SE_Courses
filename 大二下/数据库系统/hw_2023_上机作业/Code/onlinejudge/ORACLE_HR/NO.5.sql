SELECT region_name,
    count(DISTINCT e.employee_id),
    count(DISTINCT d.department_id),
    coalesce(round(avg(e.salary), 2), 0)
FROM regions r
    LEFT JOIN countries c ON r.region_id = c.region_id
    LEFT JOIN locations l ON c.country_id = l.country_id
    LEFT JOIN departments d ON l.location_id = d.location_id
    LEFT JOIN employees e ON d.department_id = e.department_id
GROUP BY r.region_name
ORDER BY CASE
        WHEN region_name = 'Asia' then 1
        WHEN region_name = 'Europe' then 2
        WHEN region_name = 'Americas' then 3
        WHEN region_name = 'Middle East and Africa' then 4
        ELSE 5
    END;