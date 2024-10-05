import java.util.*;
class Employee{
    String name;
    int age;
    double phone;
    String address;
    double salary;
    void printSalary(){
        System.out.println("salary:"+salary);
    }
}
class Manager extends Employee{ 
    String specialisation;
}

class Officer extends Employee{ 
    String department;
}

public class Main{
    public static void main(String[] args) {
        Scanner s=new Scanner(System.in);
        System.out.println("ENTER THE DETAILS OF THE MANAGER: ");
        System.out.println("ENTER THE NAME,AGE,PHONE,ADDRESS,SALARY,SPECIALISATION: ");
        Manager m =new Manager();
        m.name=s.nextLine();
        m.age=s.nextInt();
        m.phone=s.nextDouble();
        s.nextLine();
        m.address=s.nextLine();
        m.salary=s.nextDouble();
        s.nextLine();
        m.specialisation= s.nextLine();
        
        System.out.println("ENTER THE DETAILS OF THE OFFICER: ");
        System.out.println("ENTER THE NAME,AGE,PHONE,ADDRESS,SALARY,DEPARTMENT: ");
        Officer o =new Officer();
        o.name=s.nextLine();
        o.age=s.nextInt();
        o.phone=s.nextDouble();
        s.nextLine();
        o.address=s.nextLine();
        o.salary=s.nextDouble();
        s.nextLine();
        o.department=s.nextLine();

        System.out.println("THE DETAILS OF THE MANAGER: ");
        System.out.println("NAME: "+m.name);
        System.out.println("AGE: "+m.age);
        System.out.println("PHONE: "+m.phone);
        System.out.println("ADDRESS: "+m.address);
        m.printSalary();
        System.out.println("SPECIALISATION: "+m.specialisation);

        System.out.println("THE DETAILS OF THE OFFICER: ");
        System.out.println("NAME: "+o.name);
        System.out.println("AGE: "+o.age);
        System.out.println("PHONE: "+o.phone);
        System.out.println("ADDRESS: "+o.address);
        o.printSalary();
        System.out.println("DEPARTMENT: "+o.department);
    }
}
