import java.io.*;

public class Bronzal_Lance_Binary_Buffered{
	public static void main(String args[]){
		
		String input = "", ans = "";
		int num = 0;
		BufferedReader bufferedReader = new BufferedReader(new InputStreamReader(System.in));

		try{
			System.out.println("Enter a number to convert to binary");
			input = bufferedReader.readLine();
			num = Integer.parseInt(input);
			ans = Integer.toBinaryString(num);
		}
		catch(IOException e){
			System.out.println("Error");
		}
		catch(NumberFormatException e){
			System.out.println("Invalid input");
		}
		
		System.out.println("Binary number is: " + ans);
		
	}
}