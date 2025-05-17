package Showroom;

public class Sedan extends Vehicle {
    public Sedan(int id, String model, String color, String brand, String price) {
        super(id, model, color, brand, price);
    }

     @Override
    public String toString() {
        return "Sedan [ID=" + getId() + ", Model=" +getModel() + ", Color=" + getColor() +
               ", Brand=" + getBrand() + ", Price=" + getPrice() + "]";
    }
}
