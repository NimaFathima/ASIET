import java.util.*;
class Employee{
	String name;
	int age;
	int phone;
	String address;
	int salary;
	int printSalary(){
		System.out.println("SALARY OF THE EMPLOYEE"+salary);	
	}
}

class Officer extends Employee{
	String specialisation;
}

class Manager extends Employee{
	String department;
}

class main{
 public static void main(String args[]){
 	Scanner s = new Scanner(System.in);
 	System.out.println("ENTER THE NAME : ");
 	String name =s.nextLine();
 	System.out.println("ENTER THE AGE : ");
 	int age =s.nextInt();
 	System.out.println("ENTER THE PHONE NUMBER : ");
 	int phone =s.nextInt();
 	System.out.println("ENTER THE ADDRESS : ");
 	String address =s.nextLine();
 	System.out.println("ENTER THE SALARY : ");
 	int salary  =s.nextInt();
 	Officer o= new Officer();
 	o.printSalary();
 	Manager m=new Manager();
 	m.printSalary();
  }
}
