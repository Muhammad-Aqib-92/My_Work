import java.io.*;

class DeserializeDemo {
  public static void main(String[] args) {
    try {
      FileInputStream fileIn = new FileInputStream("product.txt");
      ObjectInputStream in = new ObjectInputStream(fileIn);

      while (true){
        try {
          Product e = (Product) in.readObject();
          if (e.quantity < 10){
          System.out.println("Name: " + e.productId);
          System.out.println("Address: " + e.productName);
          System.out.println("SSN: " + e.price);
          System.out.println("Quantity: " + e.quantity);
            }
        } catch (EOFException eof) {
          System.out.println("End of file reached.");
          break;
        } catch (ClassNotFoundException c) {
          System.out.println("Product class not found");
          c.printStackTrace();
          break;
        }
      }

      in.close();
      fileIn.close();

    } catch (IOException i) {
      i.printStackTrace();
    }
  }
}
