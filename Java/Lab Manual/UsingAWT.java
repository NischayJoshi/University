// Write a Java program to create a frame and add a button which shows “click me”.

import java.awt.*;
import java.awt.event.*;

public class UsingAWT extends Frame {
  public UsingAWT() {
    Button button = new Button("Click Me");
    setLayout(null);
    button.setBounds(100, 80, 100, 30);
    add(button);
    setSize(300, 200);

    addWindowListener(new WindowAdapter() {
      public void windowClosing(WindowEvent e) {
        dispose();
      }
    });
    setLocationRelativeTo(null);
    setVisible(true);
  }

  public static void main(String[] args) {
    new UsingAWT();
  }
}
