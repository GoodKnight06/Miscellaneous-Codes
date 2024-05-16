import java.io.*;

public class Bronzal_Lance_Area_Buffered{
	public static void main(String args[]){
		
		String input  = "";

		double radius = 0.0, perimeter = 0.0, area = 0.0, pi = 3.14;
		BufferedReader bufferedReader = new BufferedReader(new InputStreamReader(System.in));

		try{
			System.out.println("Enter the radius of a circle");
			input = bufferedReader.readLine();
			radius = Float.parseFloat(input);
			perimeter = 2 * pi * radius;
			area = pi * (radius * radius);
		}
		catch(IOException e){
			System.out.println("Error");
		}
		catch(NumberFormatException e){
			System.out.println("Invalid input");
		}
		
		System.out.println("Radius = " + radius);
		System.out.println("Perimeter is = " + perimeter);
		System.out.println("Area is = " + area);

	}
}