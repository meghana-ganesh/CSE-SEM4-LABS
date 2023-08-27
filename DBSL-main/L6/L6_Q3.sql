SET SERVEROUTPUT ON
DECLARE
pl_isdate book.issue_date%TYPE;
pl_redate book.return_date%TYPE;
x Number(2);
BEGIN
pl_isdate := '&issue_date';
pl_redate := '&return_date';

x := pl_redate-pl_isdate;

IF  x > 7 AND x <= 15 THEN
DBMS_OUTPUT.PUT_LINE('Fine:'||(1*x));
ELSIF x > 15 AND x <= 30 THEN
DBMS_OUTPUT.PUT_LINE('Fine:'||(2*x));
ELSIF x > 30 THEN
DBMS_OUTPUT.PUT_LINE('Fine:'||(5*x));
END IF;
END;
/