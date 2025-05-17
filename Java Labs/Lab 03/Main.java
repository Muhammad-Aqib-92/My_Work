import java.util.*;

abstract class Employee {

    String firstname, lastname;
    int socialSecurity;

    Employee(String firstname, String lastname, int socialSecurity) {
        this.firstname = firstname;
        this.lastname = lastname;
        this.socialSecurity = socialSecurity;
    }
	
    public abstract float earning();

    public String toString() {
        return ("First name: " + firstname + " lastname: " + lastname + " Social-security: " + socialSecurity);
    }
}


class SalariedEmployee extends Employee {

    int weeklySalary;

    SalariedEmployee(String firstname, String lastname, int socialSecurity, int weeklySalary) {
        super(firstname, lastname, socialSecurity);
        this.weeklySalary = weeklySalary;
    }

    public float earning() {
        return weeklySalary;
    }

    public String toString() {
        return super.toString() + " Weekly Salary: " + weeklySalary;
    }
}

class HourlyEmployee extends Employee {

    int hourlyWage;
    int hoursWorked;

    HourlyEmployee(String firstname, String lastname, int socialSecurity, int hourlyWage, int hoursWorked) {
        super(firstname, lastname, socialSecurity);
        this.hourlyWage = hourlyWage;
        this.hoursWorked = hoursWorked;
    }

    public float earning() {
        if (hoursWorked <= 40) {
            return hoursWorked * hourlyWage;
        } else {
            return (40 * hourlyWage) + (hoursWorked - 40) * hourlyWage * 1.5f;
        }
    }

    public String toString() {
        return super.toString() + " Hourly Wage: " + hourlyWage + " Hours Worked: " + hoursWorked;
    }
}

class CommissionEmployee extends Employee {

    int grossSales;
    float commissionRate;

    CommissionEmployee(String firstname, String lastname, int socialSecurity, int grossSales, float commissionRate) {
        super(firstname, lastname, socialSecurity);
        this.grossSales = grossSales;
        this.commissionRate = commissionRate;
    }

    public float earning() {
        return commissionRate * grossSales;
    }

    public String toString() {
        return super.toString() + " Gross Sales: " + grossSales + " Commission Rate: " + commissionRate;
    }
}

class BasePlusCommissionEmployee extends CommissionEmployee {

    int baseSalary;

    BasePlusCommissionEmployee(String firstname, String lastname, int socialSecurity, int grossSales, float commissionRate, int baseSalary) {
        super(firstname, lastname, socialSecurity, grossSales, commissionRate);
        this.baseSalary = baseSalary;
    }

    public float earning() {
        return super.earning() + baseSalary;
    }

    public String toString() {
        return super.toString() + " Base Salary: " + baseSalary;
    }
}

public class Main{
	
    public static void main(String[] args) {
        SalariedEmployee salariedEmployee = new SalariedEmployee("John", "Doe", 123456789, 1000);
      
        System.out.println(salariedEmployee);
        System.out.println("Earnings: " + salariedEmployee.earning());

    		
    }
	
}
