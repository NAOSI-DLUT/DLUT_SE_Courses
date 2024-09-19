INSERT INTO ly.ly_dept
VALUES (001, 'Accounting', 'Dalian');
INSERT INTO ly.ly_emp
VALUES ('1000', 'LY', 'Student', 001, '18:40:00', 500, 500, 001);
INSERT INTO ly.ly_emp (empno)
VALUES ('1001');
INSERT INTO ly.ly_emp (empno, ename, job, hiredate, sal)
VALUES ('1002', 'LY_1', 'Student', '18:50:00', 800);