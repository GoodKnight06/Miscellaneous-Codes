import java.util.*;
import java.io.*;

public class Bronzal_Lance_Sort_CommandLine {

    public static void main(String[] args) {
        int pos = 0, swap = 0;
        int arr[] = new int[args.length];
        
        for(int i = 0; i < args.length; i++){
            arr[i] = Integer.parseInt(args[i]);
        }
        
        for(int i = 0; i < arr.length-1; i++){
            pos = i;
            
            for(int j = i; j < arr.length; j++){
                if(arr[pos] > arr[j]){
                    pos = j;
                }
            }
            
            if(pos != i){
                swap = arr[i];
                arr[i] = arr[pos];
                arr[pos] = swap;
            }
        }
        
        for(int i = 0; i < arr.length; i++){
            System.out.print(arr[i] + " ");
        }
    }
}
