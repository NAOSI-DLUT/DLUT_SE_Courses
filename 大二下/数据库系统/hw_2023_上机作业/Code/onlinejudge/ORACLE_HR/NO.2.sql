SELECT locations.state_province,
    locations.city,
    locations.street_address
FROM locations
WHERE location_id NOT IN(
        SELECT location_id
        FROM departments
            JOIN employees ON departments.department_id = employees.department_id
    );