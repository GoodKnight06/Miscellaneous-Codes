import javax.swing.JOptionPane;

public class Bronzal_Lance_Binary_JOption{
	public static void main(String args[]){
		
		String input = "", ans = "";
		int num = 0;

		input = JOptionPane.showInputDialog("Enter a number to convert to binary");
		num = Integer.parseInt(input);

		ans = Integer.toBinaryString(num);

		JOptionPane.showMessageDialog(null, "Binary number is: " + ans);

	}
}