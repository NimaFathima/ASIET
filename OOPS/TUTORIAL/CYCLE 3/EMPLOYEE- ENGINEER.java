import java.util.*;
class Employee{
    String name;
    String id;
    double salary;
    void display(){
        System.out.println("Employee");
    }
    void calcSalary(){
        System.out.println("salary of the employee:"+salary);
    }
}
class Engineer extends Employee{ 
    void calcSalary(){
        System.out.println("salary of the engineer:"+salary);
    }
}

public class Main{
    public static void main(String[] args) {
        Scanner s=new Scanner(System.in);
        Engineer e =new Engineer();
        System.out.println("ENTER THE EMPLOYEE NAME,ID,SALARY: ");
        e.name=s.next();
        e.id=s.next();
        e.salary=s.nextDouble();
        e.display();
        e.calcSalary();
    }
}
