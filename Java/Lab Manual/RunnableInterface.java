// Write a program to use Runnable interface in multi-threaded programming.

class Task implements Runnable {
  private String taskName;

  public Task(String taskName) {
    this.taskName = taskName;
  }

  public void run() {
    for (int i = 1; i <= 5; i++) {
      System.out.println(taskName + " - Count: " + i);
      try {
        Thread.sleep(500);
      } catch (InterruptedException e) {
        System.out.println(taskName + " was interrupted.");
      }
    }
    System.out.println(taskName + " is completed.");
  }
}

public class RunnableInterface {
  public static void main(String[] args) {
    Task task1 = new Task("Task 1");
    Task task2 = new Task("Task 2");
    Task task3 = new Task("Task 3");
    Thread thread1 = new Thread(task1);
    Thread thread2 = new Thread(task2);
    Thread thread3 = new Thread(task3);

    thread1.start();
    thread2.start();
    thread3.start();
  }
}
