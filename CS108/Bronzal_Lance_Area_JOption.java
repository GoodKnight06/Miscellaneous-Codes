import javax.swing.JOptionPane;

public class Bronzal_Lance_Area_JOption{
	public static void main(String args[]){
	
		String input = "", message = "";
		double radius = 0.0, perimeter = 0.0, area = 0.0, pi = 3.14;

		input = JOptionPane.showInputDialog("Enter the radius of a circle");
		radius = Float.parseFloat(input);

		perimeter = 2 * pi * radius;
		area = pi * (radius * radius);
		message = "Radius = " + radius + ", Perimeter = " + perimeter + ", and Area = " + area;

		JOptionPane.showMessageDialog(null, message);

	}
}