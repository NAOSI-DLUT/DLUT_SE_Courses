SELECT id,
    name
FROM student
WHERE id NOT IN (
        SELECT id
        FROM takes
    );