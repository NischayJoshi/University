// Create LowBalanceException that occurs when user tries to withdraw some amount that is greater than his 
// current bank balance. To withdraw you have to write a void withdrawal (int amount) method.

class LowBalanceException extends Exception {
  public LowBalanceException(String message) {
    super(message);
  }
}

public class BankExceptions {
  private int balance;

  public BankExceptions(int initialBalance) {
    this.balance = initialBalance;
  }

  public void withdrawal(int amount) throws LowBalanceException {
    if (amount > balance) {
      throw new LowBalanceException(
          "Insufficient balance. Your current balance is " + balance + ", but you tried to withdraw " + amount + ".");
    }
    balance -= amount;
  }

  public int showBalance() {
    return balance;
  }

  public static void main(String[] args) {
    BankExceptions account = new BankExceptions(1000);

    try {
      account.withdrawal(1500);
      System.out.println("Withdrawal successful. Current balance: " + account.showBalance());
    } catch (LowBalanceException e) {
      System.out.println(e.getMessage());
    }

    try {
      account.withdrawal(500);
      System.out.println("Withdrawal successful. Current balance: " + account.showBalance());
    } catch (LowBalanceException e) {
      System.out.println(e.getMessage());
    }
  }
}
