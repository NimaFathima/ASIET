import java.util.*;
class Employee{
	String name;
	int age;
	int phone;
	String address;
	int salary;
	void printSalary(){
		System.out.println("SALARY OF THE EMPLOYEE"+salary);	
	}
	Employee(String name,int age,int phone,String address,int salary){
		this.name = name;
		this.age= age;
	    this.phone= phone;
		this.address=address;
		this.salary= salary;
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
 	Employee e=new Employee(name,age,phone,address,salary);
 	Officer o= new Officer();
 	o.printSalary();
 	Manager m=new Manager();
 	m.printSalary();
  }
}
