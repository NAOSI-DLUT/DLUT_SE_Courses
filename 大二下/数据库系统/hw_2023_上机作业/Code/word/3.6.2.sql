SELECT ename,
    sal,
    job
FROM emp
WHERE sal > 2500
INTERSECT
SELECT ename,
    sal,
    job
FROM emp
WHERE job = 'MANAGER';