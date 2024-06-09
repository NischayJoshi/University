import java.awt.*;

class AWTForms extends Frame {
  AWTForms() {
    this.setLayout(null);
    this.setVisible(true);
    this.setSize(500, 600);

    Label l1 = new Label("Registration Form");
    l1.setBounds(50, 50, 100, 30);
    this.add(l1);

    Label l2 = new Label("First Name");
    l2.setBounds(50, 100, 100, 30);
    this.add(l2);

    TextField t1 = new TextField();
    t1.setBounds(200, 100, 200, 30);
    this.add(t1);

    Label l3 = new Label("Last Name");
    l3.setBounds(50, 150, 100, 30);
    this.add(l3);

    TextField t2 = new TextField();
    t2.setBounds(200, 150, 200, 30);
    this.add(t2);

    Label l4 = new Label("Address");
    l4.setBounds(50, 200, 100, 30);
    this.add(l4);

    TextField t3 = new TextField();
    t3.setBounds(200, 200, 200, 30);
    this.add(t3);

    Label l5 = new Label("Gender");
    l5.setBounds(50, 250, 100, 30);
    this.add(l5);

    CheckboxGroup cbg = new CheckboxGroup();
    Checkbox cb1 = new Checkbox("Male", cbg, false);
    cb1.setBounds(200, 250, 100, 30);
    Checkbox cb2 = new Checkbox("Female", cbg, false);
    cb2.setBounds(350, 250, 100, 30);
    this.add(cb1);
    this.add(cb2);

    Label l6 = new Label("Hobbies");
    l6.setBounds(50, 300, 100, 30);
    this.add(l6);

    Checkbox cb3 = new Checkbox("Chess");
    cb3.setBounds(200, 300, 100, 30);
    Checkbox cb4 = new Checkbox("Cricket");
    cb4.setBounds(200, 350, 100, 30);
    Checkbox cb5 = new Checkbox("Coding");
    cb5.setBounds(200, 400, 100, 30);
    this.add(cb3);
    this.add(cb4);
    this.add(cb5);

    Label l7 = new Label("City");
    l7.setBounds(50, 450, 100, 30);
    this.add(l7);

    Choice c = new Choice();
    String s1 = "Dehradun";
    c.add(s1);
    String s2 = "Bheemtal";
    c.add(s2);
    String s3 = "Haldwani";
    c.add(s3);
    c.setBounds(200, 450, 100, 30);
    this.add(c);

    Button b = new Button("Submit");
    b.setBounds(50, 500, 100, 30);
    this.add(b);
  }

  public static void main(String args[]) {
    AWTForms obj = new AWTForms();
  }
}
