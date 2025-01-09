student@ml-15:~/NIMA_46$ mysql -u root -p
Enter password: 
Welcome to the MySQL monitor.  Commands end with ; or \g.
Your MySQL connection id is 10
Server version: 8.0.40-0ubuntu0.22.04.1 (Ubuntu)

Copyright (c) 2000, 2024, Oracle and/or its affiliates.

Oracle is a registered trademark of Oracle Corporation and/or its
affiliates. Other names may be trademarks of their respective
owners.

Type 'help;' or '\h' for help. Type '\c' to clear the current input statement.

mysql> use NIMA;
Reading table information for completion of table and column names
You can turn off this feature to get a quicker startup with -A

Database changed
mysql> DESC EMPLOYEE;
ERROR 1146 (42S02): Table 'NIMA.EMPLOYEE' doesn't exist
mysql> DESC employee;
+--------+-------------+------+-----+---------+-------+
| Field  | Type        | Null | Key | Default | Extra |
+--------+-------------+------+-----+---------+-------+
| emp_no | int         | NO   |     | NULL    |       |
| name   | varchar(20) | YES  |     | NULL    |       |
+--------+-------------+------+-----+---------+-------+
2 rows in set (0.00 sec)

mysql> create table t1(roll_no int primary key,name varchar(10));
Query OK, 0 rows affected (0.04 sec)

mysql> create table t2(roll int, room_no int);
Query OK, 0 rows affected (0.04 sec)

mysql> insert into t1 values(1,"AAA")(2,"BBB")(3,"CCC");
ERROR 1064 (42000): You have an error in your SQL syntax; check the manual that corresponds to your MySQL server version for the right syntax to use near '(2,"BBB")(3,"CCC")' at line 1
mysql> insert into t1 values(1,"AAA"),(2,"BBB"),(3,"CCC");
Query OK, 3 rows affected (0.01 sec)
Records: 3  Duplicates: 0  Warnings: 0

mysql> insert into t2 values(1,303),(3,"301");
Query OK, 2 rows affected (0.03 sec)
Records: 2  Duplicates: 0  Warnings: 0

mysql> DESC T1;
ERROR 1146 (42S02): Table 'NIMA.T1' doesn't exist
mysql> DESC t1;
+---------+-------------+------+-----+---------+-------+
| Field   | Type        | Null | Key | Default | Extra |
+---------+-------------+------+-----+---------+-------+
| roll_no | int         | NO   | PRI | NULL    |       |
| name    | varchar(10) | YES  |     | NULL    |       |
+---------+-------------+------+-----+---------+-------+
2 rows in set (0.00 sec)

mysql> DESC t2;
+---------+------+------+-----+---------+-------+
| Field   | Type | Null | Key | Default | Extra |
+---------+------+------+-----+---------+-------+
| roll    | int  | YES  |     | NULL    |       |
| room_no | int  | YES  |     | NULL    |       |
+---------+------+------+-----+---------+-------+
2 rows in set (0.00 sec)

mysql> drop table t2;
Query OK, 0 rows affected (0.01 sec)

mysql> DESC t2;
ERROR 1146 (42S02): Table 'NIMA.t2' doesn't exist
mysql> create table t2(roll int, room_no int,foreign key(roll) references t1(roll_no);
ERROR 1064 (42000): You have an error in your SQL syntax; check the manual that corresponds to your MySQL server version for the right syntax to use near '' at line 1
mysql> create table t2(roll int, room_no int,foreign key(roll) references t1(roll_no));
Query OK, 0 rows affected (0.03 sec)

mysql> DESC t1;
+---------+-------------+------+-----+---------+-------+
| Field   | Type        | Null | Key | Default | Extra |
+---------+-------------+------+-----+---------+-------+
| roll_no | int         | NO   | PRI | NULL    |       |
| name    | varchar(10) | YES  |     | NULL    |       |
+---------+-------------+------+-----+---------+-------+
2 rows in set (0.01 sec)

mysql> DESC t2;
+---------+------+------+-----+---------+-------+
| Field   | Type | Null | Key | Default | Extra |
+---------+------+------+-----+---------+-------+
| roll    | int  | YES  | MUL | NULL    |       |
| room_no | int  | YES  |     | NULL    |       |
+---------+------+------+-----+---------+-------+
2 rows in set (0.00 sec)

mysql> insert into t2 values(1,303),(3,"301");
Query OK, 2 rows affected (0.01 sec)
Records: 2  Duplicates: 0  Warnings: 0

mysql> select * from t1;
+---------+------+
| roll_no | name |
+---------+------+
|       1 | AAA  |
|       2 | BBB  |
|       3 | CCC  |
+---------+------+
3 rows in set (0.00 sec)

mysql> select * from t2;
+------+---------+
| roll | room_no |
+------+---------+
|    1 |     303 |
|    3 |     301 |
+------+---------+
2 rows in set (0.00 sec)
