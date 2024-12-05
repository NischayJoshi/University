import javax.swing.*;
import java.awt.*;

public class FaceDrawing extends JFrame {

    public FaceDrawing() {
        setTitle("Swing Face");
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        setSize(300, 300);
        setVisible(true);
    }

    public void paint(Graphics g) {
        super.paint(g);

        // Head (Square)
        g.drawRect(50, 50, 200, 200);

        // Eyes (White ovals with black center)
        g.setColor(Color.WHITE); // Set fill color to white
        g.fillOval(100, 100, 30, 30); // Draw the white part
        g.fillOval(170, 100, 30, 30); // Draw the white part

        g.setColor(Color.BLACK); // Set fill color back to black
        g.fillOval(110, 110, 10, 10); // Draw the pupil
        g.fillOval(180, 110, 10, 10); // Draw the pupil

        // Nose (Line)
        g.drawLine(150, 150, 150, 170);

        // Mouth (Oval)
        g.drawOval(120, 180, 60, 20);

        // Ears (Rectangles)
        g.fillRect(40, 135, 10, 30);
        g.fillRect(250, 135, 10, 30);
    }

    public static void main(String[] args) {
        SwingUtilities.invokeLater(() -> new FaceDrawing());
    }
}
-