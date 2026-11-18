-- Week 10, Problem 6: Banking enterprise database

DROP TABLE IF EXISTS borrower;
DROP TABLE IF EXISTS loan;
DROP TABLE IF EXISTS depositor;
DROP TABLE IF EXISTS account;
DROP TABLE IF EXISTS customer;
DROP TABLE IF EXISTS branch;

-- a) Tables with primary and foreign keys
CREATE TABLE branch (
    branch_name VARCHAR(30) PRIMARY KEY,
    branch_city VARCHAR(30) NOT NULL,
    assets DECIMAL(15,2) NOT NULL
);

CREATE TABLE customer (
    customer_name VARCHAR(30) PRIMARY KEY,
    customer_street VARCHAR(50) NOT NULL,
    customer_city VARCHAR(30) NOT NULL
);

CREATE TABLE account (
    accno INT PRIMARY KEY,
    branch_name VARCHAR(30) NOT NULL,
    balance DECIMAL(15,2) NOT NULL,
    FOREIGN KEY (branch_name) REFERENCES branch(branch_name)
);

CREATE TABLE depositor (
    customer_name VARCHAR(30),
    accno INT,
    PRIMARY KEY (customer_name, accno),
    FOREIGN KEY (customer_name) REFERENCES customer(customer_name),
    FOREIGN KEY (accno) REFERENCES account(accno)
);

CREATE TABLE loan (
    loan_number INT PRIMARY KEY,
    branch_name VARCHAR(30) NOT NULL,
    amount DECIMAL(15,2) NOT NULL,
    FOREIGN KEY (branch_name) REFERENCES branch(branch_name)
);

CREATE TABLE borrower (
    customer_name VARCHAR(30),
    loan_number INT,
    PRIMARY KEY (customer_name, loan_number),
    FOREIGN KEY (customer_name) REFERENCES customer(customer_name),
    FOREIGN KEY (loan_number) REFERENCES loan(loan_number)
);

-- b) At least five tuples per relation
INSERT INTO branch VALUES ('Main', 'Aligarh', 9000000.00);
INSERT INTO branch VALUES ('Civil Lines', 'Aligarh', 4000000.00);
INSERT INTO branch VALUES ('Connaught Place', 'Delhi', 12000000.00);
INSERT INTO branch VALUES ('Karol Bagh', 'Delhi', 7000000.00);
INSERT INTO branch VALUES ('Hazratganj', 'Lucknow', 5000000.00);

INSERT INTO customer VALUES ('Aman', 'Sir Syed Nagar', 'Aligarh');
INSERT INTO customer VALUES ('Bilal', 'Marris Road', 'Aligarh');
INSERT INTO customer VALUES ('Chetan', 'Rajouri Garden', 'Delhi');
INSERT INTO customer VALUES ('Danish', 'Gomti Nagar', 'Lucknow');
INSERT INTO customer VALUES ('Eram', 'Dodhpur', 'Aligarh');

INSERT INTO account VALUES (101, 'Main', 50000.00);
INSERT INTO account VALUES (102, 'Main', 75000.00);
INSERT INTO account VALUES (103, 'Civil Lines', 30000.00);
INSERT INTO account VALUES (104, 'Connaught Place', 120000.00);
INSERT INTO account VALUES (105, 'Karol Bagh', 45000.00);
INSERT INTO account VALUES (106, 'Hazratganj', 62000.00);
INSERT INTO account VALUES (107, 'Connaught Place', 88000.00);
INSERT INTO account VALUES (108, 'Main', 20000.00);
INSERT INTO account VALUES (109, 'Karol Bagh', 33000.00);

INSERT INTO depositor VALUES ('Aman', 101);
INSERT INTO depositor VALUES ('Aman', 102);
INSERT INTO depositor VALUES ('Bilal', 103);
INSERT INTO depositor VALUES ('Chetan', 104);
INSERT INTO depositor VALUES ('Chetan', 105);
INSERT INTO depositor VALUES ('Danish', 106);
INSERT INTO depositor VALUES ('Eram', 108);
INSERT INTO depositor VALUES ('Eram', 107);
INSERT INTO depositor VALUES ('Eram', 109);
INSERT INTO depositor VALUES ('Bilal', 101);

INSERT INTO loan VALUES (201, 'Main', 200000.00);
INSERT INTO loan VALUES (202, 'Civil Lines', 150000.00);
INSERT INTO loan VALUES (203, 'Connaught Place', 500000.00);
INSERT INTO loan VALUES (204, 'Karol Bagh', 300000.00);
INSERT INTO loan VALUES (205, 'Hazratganj', 100000.00);

INSERT INTO borrower VALUES ('Aman', 201);
INSERT INTO borrower VALUES ('Bilal', 202);
INSERT INTO borrower VALUES ('Chetan', 203);
INSERT INTO borrower VALUES ('Danish', 205);
INSERT INTO borrower VALUES ('Eram', 204);

-- c) Customers with at least two accounts at the main branch
SELECT d.customer_name
FROM depositor d
JOIN account a ON d.accno = a.accno
WHERE a.branch_name = 'Main'
GROUP BY d.customer_name
HAVING COUNT(DISTINCT a.accno) >= 2;

-- d) Customers having an account at every branch in a specific city (here: Delhi)
SELECT c.customer_name
FROM customer c
WHERE NOT EXISTS (
    SELECT b.branch_name
    FROM branch b
    WHERE b.branch_city = 'Delhi'
    AND NOT EXISTS (
        SELECT 1
        FROM depositor d
        JOIN account a ON d.accno = a.accno
        WHERE d.customer_name = c.customer_name
        AND a.branch_name = b.branch_name
    )
);

-- e) Delete all account tuples at every branch located in a specific city (here: Delhi)
-- Dependent depositor rows are removed first because of the foreign key
DELETE FROM depositor
WHERE accno IN (
    SELECT accno FROM account
    WHERE branch_name IN (SELECT branch_name FROM branch WHERE branch_city = 'Delhi')
);

DELETE FROM account
WHERE branch_name IN (SELECT branch_name FROM branch WHERE branch_city = 'Delhi');

SELECT * FROM account;
