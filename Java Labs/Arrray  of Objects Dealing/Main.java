import java.util.Scanner;

class PersonInfo {
    private String name;
    private String phoneNumber;
    private String address;

    public PersonInfo(String name, String phoneNumber, String address) {
        this.name = name;
        this.phoneNumber = phoneNumber;
        this.address = address;
    }

    public String getName() {
        return name;
    }

    @Override
    public String toString() {
        return "Name: " + name + "\nPhone Number: " + phoneNumber + "\nAddress: " + address;
    }
}

class Store {
    private PersonInfo[] records;
    private int count;

    public Store(int size) {
        records = new PersonInfo[size];
        count = 0;
    }

    public void addInfo(Scanner scanner) {
        if (count >= records.length) {
            System.out.println("Array is full, cannot add more records.");
            return;
        }

        System.out.print("Enter the name: ");
        String name = scanner.nextLine().trim();
        while (name.isEmpty()) {
            System.out.print("Name cannot be empty. Enter again: ");
            name = scanner.nextLine().trim();
        }

        System.out.print("Enter the phone number: ");
        String phone = scanner.nextLine().trim();
        while (phone.isEmpty()) {
            System.out.print("Phone number cannot be empty. Enter again: ");
            phone = scanner.nextLine().trim();
        }

        System.out.print("Enter the address: ");
        String address = scanner.nextLine().trim();
        while (address.isEmpty()) {
            System.out.print("Address cannot be empty. Enter again: ");
            address = scanner.nextLine().trim();
        }

        records[count++] = new PersonInfo(name, phone, address);
        System.out.println("Record added successfully!\n");
    }

    public PersonInfo getInfoByName(Scanner scanner) {
        System.out.print("Enter the name to search: ");
        String name = scanner.nextLine().trim();

        for (PersonInfo person : records) {
            if (person != null && person.getName().equalsIgnoreCase(name)) {
                return person;
            }
        }

        System.out.println("No record found with the provided name.\n");
        return null;
    }
}

public class Main {
    public static void main(String[] args) {
        try (Scanner scanner = new Scanner(System.in)) {
            System.out.print("Enter the number of records you want to save: ");
            int numRecords;

            while (true) {
                String input = scanner.nextLine();
                try {
                    numRecords = Integer.parseInt(input);
                    if (numRecords > 0) break;
                    else System.out.print("Enter a positive number: ");
                } catch (NumberFormatException e) {
                    System.out.print("Invalid input! Enter a valid number: ");
                }
            }

            Store store = new Store(numRecords);

            while (true) {
                System.out.println("\nMenu:");
                System.out.println("1 - Save a record");
                System.out.println("2 - Retrieve a record");
                System.out.println("3 - Exit");
                System.out.print("Enter your choice: ");

                String input = scanner.nextLine();
                int choice;
                try {
                    choice = Integer.parseInt(input);
                } catch (NumberFormatException e) {
                    System.out.println("Invalid choice! Enter a number between 1 and 3.");
                    continue;
                }

                switch (choice) {
                    case 1:
                        store.addInfo(scanner);
                        break;
                    case 2:
                        PersonInfo person = store.getInfoByName(scanner);
                        if (person != null) {
                            System.out.println(person);
                        }
                        break;
                    case 3:
                        System.out.println("Exiting program.");
                        return;
                    default:
                        System.out.println("Invalid choice! Please enter a valid option.");
                }
            }
        }
    }
}
