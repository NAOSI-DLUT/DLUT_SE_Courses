SELECT leader.ename
FROM emp AS employ
    JOIN emp leader ON employ.mgr = leader.empno
WHERE employ.ename = 'SCOTT';