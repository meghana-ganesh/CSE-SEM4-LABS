CREATE TABLE Client_master (
    client_no NUMBER,
    name VARCHAR(20),
    address VARCHAR(50),
    bal_due NUMBER,
    PRIMARY KEY (client_no));

INSERT INTO Client_master VALUES (1,'Client1','Addr1',20000);
INSERT INTO Client_master VALUES (2,'Client2','Addr2',10000);
INSERT INTO Client_master VALUES (3,'Client3','Addr3',50000);
INSERT INTO Client_master VALUES (4,'Client4','Addr4',80000);

CREATE TABLE auditclient (
    client_no NUMBER,
    name VARCHAR(20),
    bal_due NUMBER,
    operation VARCHAR(20),
    userid NUMBER,
    opdate DATE);

CREATE OR REPLACE TRIGGER auditLog
BEFORE UPDATE OF bal_due OR DELETE ON Client_master
BEGIN
CASE
WHEN UPDATING THEN
    INSERT INTO auditClient VALUES (:OLD.client_no, :OLD.name, :OLD.bal_due, 'Update', 1440, SYSDATE);
WHEN DELETING THEN 
    INSERT INTO auditClient VALUES (:OLD.client_no, :OLD.name, :OLD.bal_due, 'Delete', 1440, SYSDATE);
END CASE;
END;
/