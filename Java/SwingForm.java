import javax.swing.*;

class SwingForm extends JFrame {
  SwingForm() {
    this.setLayout(null);
    this.setVisible(true);
    this.setSize(1000, 1000);

    JLabel l1 = new JLabel("Registration Form");
    l1.setBounds(50, 50, 100, 30);
    this.add(l1);

    JLabel l2 = new JLabel("First Name");
    l2.setBounds(50, 100, 100, 30);
    this.add(l2);

    JTextField t1 = new JTextField();
    t1.setBounds(200, 100, 200, 30);
    this.add(t1);

    JLabel l3 = new JLabel("Last Name");
    l3.setBounds(50, 150, 100, 30);
    this.add(l3);

    JTextField t2 = new JTextField();
    t2.setBounds(200, 150, 200, 30);
    this.add(t2);

    JLabel l4 = new JLabel("Address");
    l4.setBounds(50, 200, 100, 30);
    this.add(l4);

    JTextField t3 = new JTextField();
    t3.setBounds(200, 200, 200, 30);
    this.add(t3);

    JLabel l5 = new JLabel("Gender");
    l5.setBounds(50, 250, 100, 30);
    this.add(l5);

    JRadioButton cb1 = new JRadioButton("Male", false);
    cb1.setBounds(200, 250, 100, 30);
    JRadioButton cb2 = new JRadioButton("Female", false);
    cb2.setBounds(350, 250, 100, 30);
    ButtonGroup bg = new ButtonGroup();
    bg.add(cb1);
    bg.add(cb2);
    this.add(cb1);
    this.add(cb2);

    JLabel l6 = new JLabel("Hobbies");
    l6.setBounds(50, 300, 100, 30);
    this.add(l6);

    JCheckBox cb3 = new JCheckBox("Chess");
    cb3.setBounds(200, 300, 100, 30);
    JCheckBox cb4 = new JCheckBox("Cricket");
    cb4.setBounds(200, 350, 100, 30);
    JCheckBox cb5 = new JCheckBox("Coding");
    cb5.setBounds(200, 400, 100, 30);
    this.add(cb3);
    this.add(cb4);
    this.add(cb5);

    JLabel l7 = new JLabel("City");
    l7.setBounds(50, 450, 100, 30);
    this.add(l7);

    String[] cities = { "Dehradun", "Bheemtal", "Haldwani" };
    JComboBox<String> cb = new JComboBox<>(cities);
    cb.setBounds(200, 450, 100, 30);
    this.add(cb);

    JButton b = new JButton("Submit");
    b.setBounds(50, 500, 100, 30);
    this.add(b);
  }

  public static void main(String args[]) {
    SwingForm obj = new SwingForm();
  }
}
