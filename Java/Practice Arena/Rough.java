class LowBalanceException extends Exception {
  LowBalanceException(String message) {
    super(message);
  }
}

class BankAccount {
  private int balance;

  BankAccount(int balance) {
    this.balance = balance;
  }

  public void withdraw(int amount) {
    try {
      if (amount > balance) {
        throw new LowBalanceException("Insufficient Balance");
      }
      balance = amount;
      System.out.println("Amount Withdrawn");
    } catch (LowBalanceException e) {
      System.out.println(e.getMessage());
    }
  }
}

class Rough {
  public static void main(String args[]) {
    BankAccount acc = new BankAccount(5000);
    acc.withdraw(6000);
  }
}