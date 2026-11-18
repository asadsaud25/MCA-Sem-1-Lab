-- Week 12, Problem 5: Inter University Database

DROP TABLE IF EXISTS syllabus;
DROP TABLE IF EXISTS faculty;
DROP TABLE IF EXISTS course;
DROP TABLE IF EXISTS program;
DROP TABLE IF EXISTS department;
DROP TABLE IF EXISTS university;

-- a) Tables with primary keys, foreign keys and secondary indexes
CREATE TABLE university (
    univ_id INT PRIMARY KEY,
    univ_name VARCHAR(50) NOT NULL,
    full_name VARCHAR(100) NOT NULL,
    city VARCHAR(30) NOT NULL,
    state VARCHAR(30) NOT NULL
);

CREATE TABLE department (
    dept_id INT PRIMARY KEY,
    dept_name VARCHAR(60) NOT NULL,
    univ_id INT NOT NULL,
    hod_name VARCHAR(50),
    building VARCHAR(50),
    FOREIGN KEY (univ_id) REFERENCES university(univ_id)
);

CREATE TABLE program (
    program_id INT PRIMARY KEY,
    program_name VARCHAR(30) NOT NULL,
    dept_id INT NOT NULL,
    duration_years INT NOT NULL,
    degree_level VARCHAR(20) NOT NULL,
    FOREIGN KEY (dept_id) REFERENCES department(dept_id)
);

CREATE TABLE course (
    course_id INT PRIMARY KEY,
    course_name VARCHAR(60) NOT NULL,
    program_id INT NOT NULL,
    credits INT NOT NULL,
    semester INT NOT NULL,
    FOREIGN KEY (program_id) REFERENCES program(program_id)
);

CREATE TABLE syllabus (
    syllabus_id INT PRIMARY KEY,
    course_id INT NOT NULL,
    topics VARCHAR(255) NOT NULL,
    textbook VARCHAR(100) NOT NULL,
    revision_year INT NOT NULL,
    FOREIGN KEY (course_id) REFERENCES course(course_id)
);

CREATE TABLE faculty (
    faculty_id INT PRIMARY KEY,
    faculty_name VARCHAR(50) NOT NULL,
    dept_id INT NOT NULL,
    specialization VARCHAR(60) NOT NULL,
    designation VARCHAR(30) NOT NULL,
    FOREIGN KEY (dept_id) REFERENCES department(dept_id)
);

CREATE INDEX idx_university_city ON university(city);
CREATE INDEX idx_department_univ ON department(univ_id);
CREATE INDEX idx_program_name ON program(program_name);
CREATE INDEX idx_course_name ON course(course_name);
CREATE INDEX idx_syllabus_course ON syllabus(course_id);
CREATE INDEX idx_faculty_specialization ON faculty(specialization);

-- b) Sample data
INSERT INTO university VALUES (1, 'AMU', 'Aligarh Muslim University', 'Aligarh', 'Uttar Pradesh');
INSERT INTO university VALUES (2, 'JNU', 'Jawaharlal Nehru University', 'Delhi', 'Delhi');
INSERT INTO university VALUES (3, 'DU', 'University of Delhi', 'Delhi', 'Delhi');
INSERT INTO university VALUES (4, 'University of Jammu', 'University of Jammu', 'Jammu', 'Jammu and Kashmir');
INSERT INTO university VALUES (5, 'JMI', 'Jamia Millia Islamia', 'Delhi', 'Delhi');

INSERT INTO department VALUES (1, 'Computer Science', 1, 'Dr. Rahman', 'Science Faculty');
INSERT INTO department VALUES (2, 'Physics', 1, 'Dr. Khan', 'Science Faculty');
INSERT INTO department VALUES (3, 'Computer and Systems Sciences', 2, 'Dr. Mehra', 'SC&SS Building');
INSERT INTO department VALUES (4, 'Computer Science', 3, 'Dr. Sharma', 'North Campus');
INSERT INTO department VALUES (5, 'Computer Science and IT', 4, 'Dr. Gupta', 'Baba Saheb Ambedkar Road');
INSERT INTO department VALUES (6, 'Computer Engineering', 5, 'Dr. Ansari', 'Engineering Block');

INSERT INTO program VALUES (1, 'MCA', 1, 2, 'Postgraduate');
INSERT INTO program VALUES (2, 'MSc Physics', 2, 2, 'Postgraduate');
INSERT INTO program VALUES (3, 'MCA', 3, 3, 'Postgraduate');
INSERT INTO program VALUES (4, 'MSc Computer Science', 4, 2, 'Postgraduate');
INSERT INTO program VALUES (5, 'MCA', 5, 2, 'Postgraduate');
INSERT INTO program VALUES (6, 'BTech Computer', 6, 4, 'Undergraduate');

INSERT INTO course VALUES (1, 'Computer Architecture', 1, 4, 2);
INSERT INTO course VALUES (2, 'Data Structures', 1, 4, 1);
INSERT INTO course VALUES (3, 'Information Security', 1, 3, 3);
INSERT INTO course VALUES (4, 'Computer Architecture', 3, 4, 2);
INSERT INTO course VALUES (5, 'Computer Architecture', 4, 4, 2);
INSERT INTO course VALUES (6, 'Quantum Mechanics', 2, 4, 1);
INSERT INTO course VALUES (7, 'Computer Architecture', 5, 3, 2);
INSERT INTO course VALUES (8, 'Operating Systems', 6, 4, 4);

INSERT INTO syllabus VALUES (1, 1, 'Number systems, ALU design, pipelining, memory hierarchy', 'Mano - Computer System Architecture', 2023);
INSERT INTO syllabus VALUES (2, 2, 'Arrays, linked lists, trees, graphs, hashing', 'Cormen - Introduction to Algorithms', 2023);
INSERT INTO syllabus VALUES (3, 3, 'Cryptography, network security, access control', 'Stallings - Cryptography and Network Security', 2022);
INSERT INTO syllabus VALUES (4, 4, 'Instruction sets, control unit, cache, I/O organization', 'Hennessy and Patterson - Computer Architecture', 2022);
INSERT INTO syllabus VALUES (5, 5, 'Processor design, memory systems, parallel processors', 'Stallings - Computer Organization and Architecture', 2021);
INSERT INTO syllabus VALUES (6, 6, 'Wave functions, operators, perturbation theory', 'Griffiths - Introduction to Quantum Mechanics', 2023);
INSERT INTO syllabus VALUES (7, 7, 'Digital logic, CPU organization, microprogramming', 'Mano - Computer System Architecture', 2024);
INSERT INTO syllabus VALUES (8, 8, 'Processes, scheduling, memory management, file systems', 'Silberschatz - Operating System Concepts', 2023);

INSERT INTO faculty VALUES (1, 'Dr. Rahman', 1, 'Information Security', 'Professor');
INSERT INTO faculty VALUES (2, 'Dr. Fatima', 1, 'Machine Learning', 'Associate Professor');
INSERT INTO faculty VALUES (3, 'Dr. Mehra', 3, 'Information Security', 'Professor');
INSERT INTO faculty VALUES (4, 'Dr. Verma', 4, 'Databases', 'Assistant Professor');
INSERT INTO faculty VALUES (5, 'Dr. Singh', 5, 'Information Security', 'Associate Professor');
INSERT INTO faculty VALUES (6, 'Dr. Ansari', 6, 'Operating Systems', 'Professor');

-- c) Queries
-- i) Universities situated in Delhi
SELECT univ_name, full_name FROM university WHERE city = 'Delhi';

-- ii) All departments of AMU
SELECT d.dept_name
FROM department d
JOIN university u ON d.univ_id = u.univ_id
WHERE u.univ_name = 'AMU';

-- iii) Location of JNU
SELECT city, state FROM university WHERE univ_name = 'JNU';

-- iv) All programs run by the University of Jammu
SELECT DISTINCT p.program_name
FROM program p
JOIN department d ON p.dept_id = d.dept_id
JOIN university u ON d.univ_id = u.univ_id
WHERE u.univ_name = 'University of Jammu';

-- v) Universities that run the program MCA
SELECT DISTINCT u.univ_name
FROM university u
JOIN department d ON u.univ_id = d.univ_id
JOIN program p ON d.dept_id = p.dept_id
WHERE p.program_name = 'MCA';

-- vi) Courses of MCA run by AMU
SELECT c.course_name
FROM course c
JOIN program p ON c.program_id = p.program_id
JOIN department d ON p.dept_id = d.dept_id
JOIN university u ON d.univ_id = u.univ_id
WHERE p.program_name = 'MCA' AND u.univ_name = 'AMU';

-- vii) Faculty specialized in Information Security across universities
SELECT f.faculty_name, u.univ_name
FROM faculty f
JOIN department d ON f.dept_id = d.dept_id
JOIN university u ON d.univ_id = u.univ_id
WHERE f.specialization = 'Information Security';

-- viii) Syllabus of Computer Architecture at different universities
SELECT u.univ_name, s.topics, s.textbook, s.revision_year
FROM syllabus s
JOIN course c ON s.course_id = c.course_id
JOIN program p ON c.program_id = p.program_id
JOIN department d ON p.dept_id = d.dept_id
JOIN university u ON d.univ_id = u.univ_id
WHERE c.course_name = 'Computer Architecture';
