import java.util.Scanner;

class Health {
    String name;
    float weight;
    float height;
    float bmi;

    Health(String name, float weight, float height) {
        this.name = name;
        this.weight = weight;
        this.height = height;
        this.bmi = calculate();
    }

    float calculate() {
        return weight / (height * height);
    }
}

class IndexOccupiedException extends Exception {
    private String message;

    public IndexOccupiedException(String message) {
        this.message = message;
    }

    public String getCustomMessage() {
        return message;
    }

    @Override
    public String toString() {
        return "IndexOccupiedException: " + message;
    }
}

class IndexException extends Exception {
    private String message;

    public IndexException(String message) {
        this.message = message;
    }

    public String getCustomMessage() {
        return message;
    }

    @Override
    public String toString() {
        return "IndexException: " + message;
    }
}

class Driver {
    static Scanner c = new Scanner(System.in);
    static Health[] h;

    static void save() throws IndexOccupiedException {
        System.out.println("Enter the index where you want to store data:");
        int ne = c.nextInt();

        if (ne < 0 || ne >= h.length) {
            System.out.println("Invalid index. Please enter a valid index.");
            return;
        }

        if (h[ne] != null) {
            throw new IndexOccupiedException("Index " + ne + " is already occupied.");
        } else {
            c.nextLine();
            System.out.println("Enter the Name:");
            String na = c.nextLine();
            System.out.println("Enter the Weight:");
            float wa = c.nextFloat();
            System.out.println("Enter the Height:");
            float he = c.nextFloat();

            h[ne] = new Health(na, wa, he);  
        }
    }

    static void retrieve() throws IndexException {
        System.out.println("Enter the index:");
        int ind = c.nextInt();

        if (ind < 0 || ind >= h.length) {
            throw new IndexException("Invalid index: " + ind);
        }

        if (h[ind] == null) {
            throw new IndexException("No data found at index " + ind);
        } else {
       
            System.out.println("Name: " + h[ind].name +
                               ", Weight: " + h[ind].weight +
                               ", Height: " + h[ind].height +
                               ", BMI: " + h[ind].calculate());
        }
    }
}

public class Main {
    public static void main(String[] args) {
        try {
            System.out.println("Enter the number of people you want to add:");
            int n = Driver.c.nextInt();

           
            if (n < 0) {
                throw new NegativeArraySizeException();
            }

           
            Driver.h = new Health[n];

        } catch (NegativeArraySizeException e) {
            System.out.println("You entered a negative value, which is invalid.");
            return;
        }

        while (true) {
            System.out.println("Select one of the options in the menu:");
            System.out.println("1. Add value in the array");
            System.out.println("2. Retrieve and print the information of a specific user at index n");
            System.out.println("3. Exit");
            int choice = Driver.c.nextInt();

            switch (choice) {
                case 1:
                    try {
                        Driver.save();
                    } catch (IndexOccupiedException ex) {
                        System.out.println(ex);
                    }
                    break;
                case 2:
                    try {
                        Driver.retrieve();
                    } catch (IndexException ex) {
                        System.out.println(ex);
                    }
                    break;
                case 3:
                    System.out.println("Thanks for using our service!");
                    Driver.c.close();
                    return;
                default:
                    System.out.println("Invalid choice.");
            }
        }
    }
}
