SELECT job,
    AVG(total) AS average
FROM emp
GROUP BY job;