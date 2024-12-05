// A cloth showroom has announced the following seasonal discounts on purchase of items: (given in file)
// Write a program using switch and if statements to compute the net amount to be paid by a customer.

import java.util.*;

public class Showroom {
  public static void main(String[] args) {
    Scanner sc = new Scanner(System.in);

    System.out.print("Enter the item type: \n1. Mill Cloth \n2. Handloom Items \n");
    int itemType = sc.nextInt();

    System.out.print("Enter the purchase amount: ");
    double amount = sc.nextDouble();

    double discount = 0.0;
    switch (itemType) {
      case 1:
        if (amount >= 101 && amount <= 200) {
          discount = 0.05;
        } else if (amount >= 201 && amount <= 300) {
          discount = 0.075;
        } else if (amount > 300) {
          discount = 0.10;
        }
        break;

      case 2:
        if (amount >= 1 && amount <= 100) {
          discount = 0.05;
        } else if (amount >= 101 && amount <= 200) {
          discount = 0.075;
        } else if (amount >= 201 && amount <= 300) {
          discount = 0.10;
        } else if (amount > 300) {
          discount = 0.15;
        }
        break;

      default:
        System.out.println("Invalid item type entered.");
        sc.close();
        return;
    }

    double discountAmount = amount * discount;
    double netAmount = amount - discountAmount;

    System.out.println("The original amount is: " + amount);
    System.out.println("The discount amount is: " + discountAmount);
    System.out.println("The net amount to be paid is: " + netAmount);

    sc.close();
  }
}
