
public class RunnableInterface {

  public static void main(String args[]) {
    MultiThreading one = new MultiThreading(1);
    MultiThreading two = new MultiThreading(2);
    MultiThreading three = new MultiThreading(3);

    Thread T_one = new Thread(one);
    Thread T_two = new Thread(two);
    Thread T_three = new Thread(three);

    T_one.start();
    T_two.start();
    T_three.start();
  }
}

class MultiThreading implements Runnable {
  private int num;

  MultiThreading(int num) {
    this.num = num;
  }

  @Override
  public void run() {
    for (int i = 1; i <= 5; i++) {
      System.out.println(("Task : " + num + ", Line: " + i));
      try {
        Thread.sleep(500);
      } catch (InterruptedException e) {
        System.out.println("Task : " + num + " was interrupted.");
      }
    }
    System.out.println("Task : " + num + " completed.");
  }
}
