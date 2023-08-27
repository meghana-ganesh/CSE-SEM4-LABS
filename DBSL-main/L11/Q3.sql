SET SERVEROUTPUT ON
create or replace trigger q3
BEFORE
	insert or UPDATE
on instructor
for each ROW
DECLARE
bud department.budget%TYPE;
begin 
select budget into bud 
from department WHERE
dept_name = :new.dept_name;

IF(:new.salary <=0) then
RAISE_APPLICATION_ERROR(-20000,'ENTER POSITIVE NONZERO SALARY ONLY!');

ELSIF(:new.salary >= bud) then
RAISE_APPLICATION_ERROR(-20000,'SALARY EXCEEDS BUDGET!');

ELSIF(LENGTH(TRIM(TRANSLATE(:NEW.name, 'abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ', ' '))) > 0) THEN
RAISE_APPLICATION_ERROR(-20000,'ENTER ONLY ALPHABETS');

END IF;
END;
/
