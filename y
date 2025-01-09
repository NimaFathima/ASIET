mysql> create table t3(roll_no int primary key,name varchar(10) unique);
Query OK, 0 rows affected (0.05 sec)

mysql> insert into t3 values(1,"AAA"),(2,"BBB"),(3,"AAA");
ERROR 1062 (23000): Duplicate entry 'AAA' for key 't3.name'
mysql> create table t4(roll_no int primary key,name varchar(10) NOT NULL);
Query OK, 0 rows affected (0.02 sec)

mysql> insert into t3 values(1,"AAA"),(2,"BBB"),(null,"AAA");
ERROR 1048 (23000): Column 'roll_no' cannot be null
