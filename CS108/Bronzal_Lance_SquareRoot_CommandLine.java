import java.util.*;
import java.io.*;

public class Bronzal_Lance_SquareRoot_CommandLine{
	public static void main(String args[]){
		int num = 0;
		double ans = 0, temp = 0;
		
		num = Integer.parseInt(args[0]);

		if(num==1){
			ans = 1;
		}
		else {
			ans = num/2;

			while(temp-ans!=0){
				temp = ans;
				ans = (temp+(num/temp))/2;
			}
		}

		System.out.println(ans);
	}
}