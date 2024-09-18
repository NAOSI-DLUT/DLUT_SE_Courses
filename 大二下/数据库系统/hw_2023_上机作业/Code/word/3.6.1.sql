SELECT ename,
    sal,
    job
FROM emp
WHERE sal > 2500
UNION
SELECT ename,
    sal,
    job
FROM emp
WHERE job = 'MANAGER';