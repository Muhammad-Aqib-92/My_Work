import java.util.Scanner;

class Student {
    int id, age;
    float cgpa;
    String name, gender;

    public Student(int id, int age, float cgpa, String name, String gender) {
        this.id = id;
        this.age = age;
        this.cgpa = cgpa;
        this.name = name;
        this.gender = gender;
    }
}

public class Command{
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        System.out.print("Enter the number of Students: ");
        int size = scanner.nextInt();
        Student[] students = new Student[size];

        while (true) {
            System.out.println("Please choose one of the options" +
                    "\n1. Add Student." +
                    "\n2. View Student." +
                    "\n3. Delete Student." +
                    "\n4. Update Student." +
                    "\n5. Exit Now");

            int choice = scanner.nextInt();

            switch (choice) {
                case 1:
                    addStudent(students, scanner);
                    break;
                case 2:
                    viewStudent(students, scanner);
                    break;
                case 3:
                    deleteStudent(students, scanner);
                    break;
                case 4:
                    updateStudent(students, scanner);
                    break;
                case 5:
                    System.exit(0);
                    break;
                default:
                    System.out.println("Your choice is Invalid");
            }
        }
    }

    private static void addStudent(Student[] students, Scanner scanner) {
        for (int i = 0; i < students.length; i++) {
            if (students[i] == null) { // Check for empty index
                System.out.print("Enter Student ID: ");
                int id = scanner.nextInt();
                scanner.nextLine();  // Consume newline
                System.out.print("Enter Student Name: ");
                String name = scanner.nextLine();
                System.out.print("Enter Student Age: ");
                int age = scanner.nextInt();
                System.out.print("Enter Student CGPA: ");
                float cgpa = scanner.nextFloat();
                scanner.nextLine();  // Consume newline
                System.out.print("Enter Student Gender: ");
                String gender = scanner.nextLine();

                students[i] = new Student(id, age, cgpa, name, gender);
                System.out.println("Student Added Successfully!");
                return; // Exit after adding a student
            }
        }
        System.out.println("No space available for new student.");
    }

    private static void viewStudent(Student[] students, Scanner scanner) {
        System.out.print("Enter Student ID to View: ");
        int id = scanner.nextInt();

        for (int i = 0; i < students.length; i++) {
            if (students[i] != null && students[i].id == id) {
                String record = "ID: " + students[i].id +
                                ", Name: " + students[i].name +
                                ", Age: " + students[i].age +
                                ", CGPA: " + students[i].cgpa +
                                ", Gender: " + students[i].gender;
                System.out.println(record);
                return;
            }
        }
        System.out.println("Student not found.");
    }

    private static void deleteStudent(Student[] students, Scanner scanner) {
        System.out.print("Enter Student ID to Delete: ");
        int id = scanner.nextInt();

        for (int i = 0; i < students.length; i++) {
            if (students[i] != null && students[i].id == id) {
                students[i] = null; // Remove student by setting it to null
                System.out.println("Student Deleted Successfully!");
                return;
            }
        }
        System.out.println("Student not found.");
    }

    private static void updateStudent(Student[] students, Scanner scanner) {
        System.out.print("Enter Student ID to Update: ");
        int id = scanner.nextInt();

        for (int i = 0; i < students.length; i++) {
            if (students[i] != null && students[i].id == id) {
                System.out.print("Enter New Name: ");
                scanner.nextLine();  // Consume newline
                String newName = scanner.nextLine();
                System.out.print("Enter New Age: ");
                int newAge = scanner.nextInt();
                System.out.print("Enter New CGPA: ");
                float newCgpa = scanner.nextFloat();
                scanner.nextLine();  // Consume newline
                System.out.print("Enter New Gender: ");
                String newGender = scanner.nextLine();

                students[i].name = newName;
                students[i].age = newAge;
                students[i].cgpa = newCgpa;
                students[i].gender = newGender;

                System.out.println("Student Updated Successfully!");
                return;
            }
        }
        System.out.println("Student not found.");
    }
}
