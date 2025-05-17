import java.util.Scanner;

class OutOfStockException extends Exception
{
    String Name;
    int Quantity;

    OutOfStockException(String name, int quantity)
    {
        Name = name;
        Quantity = quantity;
    }

    public String toString()
    {
      return Name +" Items"+Quantity+" get out of Stock";
    }
}

class Driver
{
    String Name ;
    int Quantity;
    int Available;

    Driver(String name,int quantity,int available)
    {
        Name = name;
        Quantity = quantity;
        Available = available;
    }

    void check()throws OutOfStockException
    {
        if(Quantity > Available)
        {
            throw new OutOfStockException(Name,Quantity);
        }
        else
        {
            System.out.println("Quantity Available");
        }

    }

    public static void main(String[] args)
    {

        Scanner in = new Scanner(System.in);
        try{
        System.out.println("Enter the name of Item");
        String na = in.nextLine();
        System.out.println("Enter the Quantity");
        int qa = in.nextInt();
        System.out.println("Enter the stock Available");
        int sto = in.nextInt();
        Driver A = new Driver(na,qa,sto);
        A.check();
        }
        catch(OutOfStockException ex)
        {
            System.out.println(ex);
        }
        
    }
}