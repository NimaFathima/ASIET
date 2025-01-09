// UNIQUE & NOT NULL
mysql> create table t3(roll_no int primary key,name varchar(10) unique);
Query OK, 0 rows affected (0.05 sec)

mysql> insert into t3 values(1,"AAA"),(2,"BBB"),(3,"AAA");
ERROR 1062 (23000): Duplicate entry 'AAA' for key 't3.name'
mysql> create table t4(roll_no int primary key,name varchar(10) NOT NULL);
Query OK, 0 rows affected (0.02 sec)

mysql> insert into t3 values(1,"AAA"),(2,"BBB"),(null,"AAA");
ERROR 1048 (23000): Column 'roll_no' cannot be null

}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}]]
//CHECK
mysql> create table t5(name varchar(10),age int  check(age>=18));
Query OK, 0 rows affected (0.02 sec)

mysql> insert into t5 values("AAA", 24),("BBB",28);
Query OK, 2 rows affected (0.00 sec)
Records: 2  Duplicates: 0  Warnings: 0

mysql> insert into t5 values("ccc",15);
ERROR 3819 (HY000): Check constraint 't5_chk_1' is violated.
mysql> 

}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}
