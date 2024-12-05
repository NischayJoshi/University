import java.awt.*;
import java.awt.event.*;

public class AWTCalculator extends Frame implements ActionListener {
  TextField num1Field, num2Field;
  Label resultLabel;
  Button addButton, closeButton;

  public AWTCalculator() {
    setTitle("AWT Calculator");
    setLayout(new FlowLayout());

    // Input fields
    num1Field = new TextField(10);
    num2Field = new TextField(10);
    add(new Label("Number 1:"));
    add(num1Field);
    add(new Label("Number 2:"));
    add(num2Field);

    // Result label
    resultLabel = new Label("Result: ");
    add(resultLabel);

    // Buttons
    addButton = new Button("Add");
    addButton.addActionListener(this);
    add(addButton);

    closeButton = new Button("Close");
    closeButton.addActionListener(this);
    add(closeButton);

    setSize(300, 150);
    setVisible(true);
  }

  @Override
  public void actionPerformed(ActionEvent e) {
    if (e.getSource() == addButton) {
      try {
        int num1 = Integer.parseInt(num1Field.getText());
        int num2 = Integer.parseInt(num2Field.getText());
        int sum = num1 + num2;
        resultLabel.setText("Result: " + sum);
      } catch (NumberFormatException ex) {
        resultLabel.setText("Invalid input!");
      }
    } else if (e.getSource() == closeButton) {
      dispose(); // Close the window
    }
  }

    new AWTCalculator();
  }
}
