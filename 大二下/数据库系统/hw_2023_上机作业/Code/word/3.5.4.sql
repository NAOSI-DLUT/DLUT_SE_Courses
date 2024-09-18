SELECT ename,
    sal,
    deptno
FROM emp
WHERE sal >(
        SELECT max(sal)
        FROM emp
        WHERE deptno = 30
    );