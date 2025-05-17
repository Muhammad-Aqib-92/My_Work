import java.io.*;

class Product implements Serializable {
  public String productId;
  public String productName;
  public int price;
  public int quantity;
  
  Product(String pId, String pName, int p, int q)
  {
	productId = pId;
	productName = pName;
	price = p;
	quantity = q; 
  }


}


