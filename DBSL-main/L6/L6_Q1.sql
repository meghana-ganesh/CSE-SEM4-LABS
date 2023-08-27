set serveroutput on
declare
pl_rollno student_table.rollno%TYPE;
pl_gpa student_table.gpa%TYPE;

BEGIN
pl_rollno := '&rollno';

select rollno,gpa
into pl_rollno,pl_gpa
from student_table
where rollno = pl_rollno;

dbms_output.put_line('GPA:'||pl_gpa);


END;
/