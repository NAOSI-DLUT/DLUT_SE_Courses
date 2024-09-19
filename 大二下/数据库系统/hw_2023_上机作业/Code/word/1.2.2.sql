CREATE TABLE LY.LY_emp(
    empno VARCHAR(30),
    ename VARCHAR(30),
    empJOB VARCHAR(30),
    MGR INTEGER,
    hiredate TIME,
    sal INTEGER,
    comm INTEGER,
    deptno INTEGER
);
CREATE TABLE LY.LY_dept(
    deptno INTEGER,
    dname VARCHAR(30),
    loc VARCHAR(30)
);
ALTER TABLE LY.LY_emp
ADD CONSTRAINT LY_PK_EMP PRIMARY KEY(empno);