CREATE TABLE SALARY_RAISE(INST_ID varchar(5),RAISE_DATE date,RAISE_AMT numeric(12,2),CONSTRAINT INST_FK FOREIGN KEY(INST_ID) REFERENCES INSTRUCTOR(ID));
SET SERVEROUTPUT ON
DECLARE
DName Instructor.dept_name%TYPE;
CURSOR C(DName Instructor.dept_name%TYPE) is (select * from instructor where dept_name = DName) for update;
BEGIN

DName := '&dept_name';
FOR BK IN C(DName) LOOP
UPDATE Instructor 
SET salary = (1.05*salary)
WHERE CURRENT OF C;

IF C%FOUND THEN
	DBMS_OUTPUT.PUT_LINE(C%ROWCOUNT||'ROW(S) UPDATED');
	INSERT INTO salary_raise VALUES(BK.ID,CURRENT_DATE,(0.05)*BK.salary);
END IF;
END LOOP;
END;
/


