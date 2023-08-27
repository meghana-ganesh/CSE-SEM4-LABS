set serveroutput on
declare
pl_gpa student_table.gpa%TYPE;
pl_rollno student_table.rollno%TYPE;
MAX_VAL number(2,1) := 0.0;

BEGIN
FOR i in 1..5 LOOP
pl_rollno := i;

select gpa
into pl_gpa
from student_table
where rollno = pl_rollno;

IF pl_gpa > MAX_VAL then
MAX_VAL := pl_gpa;
END IF;
END LOOP;
DBMS_OUTPUT.PUT_LINE(MAX_VAL);
END;
/