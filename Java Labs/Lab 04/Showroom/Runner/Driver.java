
package Showroom.Runner;

import Showroom.SUV;
import Showroom.Sedan;
import Showroom.Vehicle;

import java.util.Scanner;

public class Driver {



    public static void main(String[] args) {
        Vehicle[] vehicles = new Vehicle[4];
        vehicles[0] = new Sedan(1, "Model S", "Red", "Tesla", "$80,000");
        vehicles[1] = new Sedan(2, "Civic", "Blue", "Honda", "$25,000");
        vehicles[2] = new SUV(1, "GTR", "Yellow", "Bull", "$80,000");
        vehicles[3] = new SUV(2, "LAMBO", "Green", "Horse", "$25,000");
        

        Scanner scanner = new Scanner(System.in);
        while (true) {
            System.out.println("Welcome to the Car Showroom!");
            System.out.println("1. View Sedans");
            System.out.println("2. View SUVs");
            System.out.println("3. Exit");
            System.out.print("Please select an option: ");
            int choice = scanner.nextInt();

            switch (choice) {
                case 1:
                    System.out.println("Sedans available:");
                    for (Vehicle vehicle : vehicles) {
                        if (vehicle instanceof Sedan) {
                            System.out.println(vehicle);
                        }
                    }
                    break;
                case 2:
                    System.out.println("SUVs available:");
                    for (Vehicle vehicle : vehicles) {
                        if (vehicle instanceof SUV) {
                            System.out.println(vehicle);
                        }
                    }
                    break;
                case 3:
                    System.out.println("Thank you for visiting!");
                    scanner.close();
                    return;
                default:
                    System.out.println("Invalid option. Please try again.");
            }
        }
    }
}
