SELECT deptno,
    job,
    AVG(total) AS average,
    MAX(total)
FROM emp
GROUP BY deptno,
    job;