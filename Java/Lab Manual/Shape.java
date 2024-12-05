// Create a class “Shape”  having area()  method to calculate area. 
// Overload the area() method for shapes   like triangle, rectangle and circle.

import java.util.*;

public class Shape {
  public double area(double length, double width) {
    return length * width;
  }

  public double area(double base, double height, boolean isTriangle) {
    if (isTriangle) {
      return 0.5 * base * height;
    }
    return -1;
  }

  public double area(double radius) {
    return Math.PI * radius * radius;
  }

  public static void main(String[] args) {
    Shape shape = new Shape();

    double rectangleArea = shape.area(10, 5);
    System.out.println("Area of the rectangle: " + rectangleArea);

    double triangleArea = shape.area(10, 5, true);
    System.out.println("Area of the triangle: " + triangleArea);

    double circleArea = shape.area(7);
    System.out.println("Area of the circle: " + circleArea);
  }
}
