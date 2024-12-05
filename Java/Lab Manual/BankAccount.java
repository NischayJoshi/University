import java.util.Scanner;

class Bank {
  int accountNumber;
  String name;
  int balance;

  Bank(int accountNumber, String name) {
    this.accountNumber = accountNumber;
    this.name = name;
    this.balance = 0;
    System.out.println("Account created successfully.");
    display();
  }

  public void display() {
    System.out.println("Account Number : " + accountNumber);
    System.out.println("Account Holder Name : " + name);
    System.out.println("Current Balance : " + balance);
  }

  public void deposit(int amount) {
    balance += amount;
    System.out.println("Amount deposited successfullly.");
    System.out.println("Current Balance: " + balance);
  }

  public void withdraw(int amount) {
    if (amount > balance) {
      System.out.println("Insufficient Balance.");
    } else {
      balance -= amount;
      System.out.println("Amount withdrawn successfully.");
    }
    System.out.println("Current Balance: " + balance);
  }
}

class rough {
  public static void main(String args[]) {
    Bank account = new Bank(1001, "Nischay");
    Scanner sc = new Scanner(System.in);
    int status = 1;
    while (status != 0) {
      System.out.println("Enter 1) To display account details 2) To deposit 3) To Withdraw 0) To Exit");
      status = sc.nextInt();
      switch (status) {
        case 0:
          break;
        case 1: {
          account.display();
          break;
        }
        case 2: {
          System.out.println("Enter amount to deposit: ");
          int amount = sc.nextInt();
          account.deposit(amount);
          break;
        }
        case 3: {
          System.out.println("Enter amount to withdraw: ");
          int amount = sc.nextInt();
          account.withdraw(amount);
          break;
        }
        default: {
          System.out.println("Invalid input, try again.");
          break;
        }
      }
    }
    sc.close();
  }
}