SELECT S.ID,
    S.name
FROM student S
WHERE (
        SELECT count(*)
        FROM student T
        WHERE T.id < S.ID
    ) > 4
    AND (
        SELECT count(*)
        FROM student T
        WHERE T.id < S.ID
    ) < 10;