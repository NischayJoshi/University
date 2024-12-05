// Write a program to show the use of abstract class.

abstract class Shape {
  abstract double calculateArea();

  abstract double calculatePerimeter();
}

class Circle extends Shape {
  double radius;

  public Circle(double radius) {
    this.radius = radius;
  }

  double calculateArea() {
    return Math.PI * radius * radius;
  }

  double calculatePerimeter() {
    return 2 * Math.PI * radius;
  }
}

class Rectangle extends Shape {
  double length, width;

  public Rectangle(double length, double width) {
    this.length = length;
    this.width = width;
  }

  double calculateArea() {
    return length * width;
  }

  double calculatePerimeter() {
    return 2 * (length + width);
  }
}

public class AbstractClass {
  public static void main(String[] args) {
    Shape circle = new Circle(5.0);
    Shape rectangle = new Rectangle(4.0, 6.0);

    System.out.println("Circle:");
    System.out.println("Area: " + circle.calculateArea());
    System.out.println("Perimeter: " + circle.calculatePerimeter());

    System.out.println("\nRectangle:");
    System.out.println("Area: " + rectangle.calculateArea());
    System.out.println("Perimeter: " + rectangle.calculatePerimeter());
  }
}
