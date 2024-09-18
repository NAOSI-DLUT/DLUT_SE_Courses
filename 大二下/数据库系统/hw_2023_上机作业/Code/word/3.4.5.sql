SELECT dept.dname,
    emp.ename
FROM dept
    LEFT JOIN emp on dept.dname = emp.job;