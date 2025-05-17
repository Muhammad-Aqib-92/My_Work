import java.util.Scanner;


public class Main{

    public static void main(String [] args)
    {
        Scanner in = new Scanner(System.in);
        try
        {
            System.out.println("Enter the integer");
            String ar = in.nextLine();
            int aj = Integer.parseInt(ar);
            System.out.println("NO error of Number Format");
            try
            {
                int [] array = new int[5];

                System.out.println("Enter the index :");
                int index = in.nextInt();
                System.out.println("Enter the value :");
                int value = in.nextInt();
                array[index] = value;   
                System.out.println("No Index out of Bound error");                  
            }
            catch(ArrayIndexOutOfBoundsException ex)
            {
                System.out.println("Array Index Out of bound");
            }
            finally
            {
                System.out.println("Inner Finally Block");
            }

            
        }
        catch(NumberFormatException ex)
        {
            System.out.println("You entered incorrect format");

        }
        finally
        {
            System.out.println("Outer Finally block");
        }
    }
}