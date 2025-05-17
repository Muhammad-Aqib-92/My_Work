package Showroom;

public abstract class Vehicle {
    private int id;
    private String model;
    private String color;
    private String brand;
    private String price;

    public Vehicle(int id, String model, String color, String brand, String price) {
        this.id = id;
        this.model = model;
        this.color = color;
        this.brand = brand;
        this.price = price;
    }

    public int getId() {
        return id;
    }

    public void setId(int id) {
        this.id = id;
    }

    public String getModel() {
        return model;
    }
    public void setModel(String model) {
        this.model = model;
    }

    public String getColor() {
        return color;
    }

    public void setColor(String color) {
        this.color = color;
    }

    public String getBrand() {
        return brand;
    }

    public void setBrand(String brand) {
        this.brand = brand;
    }

    public String getPrice() {
        return price;
    }

    public void setPrice(String price) {
        this.price = price;
    }

    @Override
    public abstract String toString();
}
