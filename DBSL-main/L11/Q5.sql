DROP VIEW Advisor_Student;

CREATE VIEW Advisor_Student AS 
SELECT Advisor.S_ID, Advisor.I_ID, Student.name S_NAME, Instructor.name I_NAME
FROM Advisor, Student, Instructor WHERE Advisor.S_ID = Student.ID AND Advisor.I_ID = Instructor.ID;

CREATE OR REPLACE TRIGGER delAdvisor
INSTEAD OF DELETE ON Advisor_Student
BEGIN 
    DELETE FROM Advisor WHERE S_ID = :OLD.S_ID AND I_ID = :OLD.I_ID;
END;
/