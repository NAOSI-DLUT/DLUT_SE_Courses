SELECT ename,
    sal,
    (
        SELECT grade
        FROM salgrade
        WHERE sal BETWEEN losal AND hisal
    ) AS grade
FROM emp;