
// Main class
public class BankAccountMultiThreading {
  public static void main(String[] args) {
    BankAccount account = new BankAccount();

    DepositThread deposit1 = new DepositThread(account, 100);
    DepositThread deposit2 = new DepositThread(account, 50);
    WithdrawThread withdraw1 = new WithdrawThread(account, 120); // Starts before deposits
    WithdrawThread withdraw2 = new WithdrawThread(account, 80);

    deposit1.start();
    deposit2.start();
    withdraw1.start();
    withdraw2.start();

    System.out.println("Final Balance: " + account.getBalance());
  }
}

class BankAccount {
  private double balance = 0;

  public synchronized void deposit(double amount) {
    balance += amount;
    System.out.println(Thread.currentThread().getName() + " deposited " + amount + ", new balance: " + balance);
    notifyAll();
  }

  public synchronized void withdraw(double amount) throws InterruptedException {
    while (balance < amount) {
      System.out.println(Thread.currentThread().getName() + " wants to withdraw " + amount +
          ", but balance is only " + balance + ". Waiting...");
      wait();
    }
    balance -= amount;
    System.out.println(Thread.currentThread().getName() + " withdrew " + amount + ", new balance: " + balance);
  }

  public double getBalance() {
    return balance;
  }
}

// DepositThread class
class DepositThread extends Thread {
  private BankAccount account;
  private double amount;

  public DepositThread(BankAccount account, double amount) {
    this.account = account;
    this.amount = amount;
  }

  @Override
  public void run() {
    account.deposit(amount);
  }
}

// WithdrawThread class
class WithdrawThread extends Thread {
  private BankAccount account;
  private double amount;

  public WithdrawThread(BankAccount account, double amount) {
    this.account = account;
    this.amount = amount;
  }

  @Override
  public void run() {
    try {
      account.withdraw(amount);
    } catch (InterruptedException e) {
      e.printStackTrace();
    }
  }
}
