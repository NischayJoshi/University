// Create a class “Student” having following instance variables and methods. 
// Instance variables: ID, Name, Branch, city and university While creating constructors 
// with one, two, three, four and five arguments reuse the constructors by construction chaining.

import java.util.*;

public class Student {
    private int ID;
    private String Name;
    private String Branch;
    private String City;
    private String University;

    public Student(int ID, String Name, String Branch, String City, String University) {
        this.ID = ID;
        this.Name = Name;
        this.Branch = Branch;
        this.City = City;
        this.University = University;
    }

    public Student(int ID, String Name, String Branch, String City) {
        this.ID = ID;
        this.Name = Name;
        this.Branch = Branch;
        this.City = City;
        this.University = "";
    }

    public Student(int ID, String Name, String Branch) {
        this.ID = ID;
        this.Name = Name;
        this.Branch = Branch;
        this.City = "";
        this.University = "";
    }

    public Student(int ID, String Name) {
        this.ID = ID;
        this.Name = Name;
        this.Branch = "";
        this.City = "";
        this.University = "";
    }

    public Student(int ID) {
        this.ID = ID;
        this.Name = "";
        this.Branch = "";
        this.City = "";
        this.University = "";
    }

    public void displayDetails() {
        System.out.println("ID: " + ID);
        System.out.println("Name: " + Name);
        System.out.println("Branch: " + Branch);
        System.out.println("City: " + City);
        System.out.println("University: " + University);
    }

    public static void main(String[] args) {
        Student s1 = new Student(001);
        s1.displayDetails();
        System.out.println();

        Student s2 = new Student(001, "Nischay");
        s2.displayDetails();
        System.out.println();

        Student s3 = new Student(001, "Nischay", "CSE");
        s3.displayDetails();
        System.out.println();

        Student s4 = new Student(001, "Nischay", "CSE", "Dehradun");
        s4.displayDetails();
        System.out.println();

        Student s5 = new Student(001, "Nischay", "CSE", "Dehradun", "Graphic Era Hill University");
        s5.displayDetails();
    }
}
