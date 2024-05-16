import java.util.*;
import java.io.*;

public class Bronzal_Lance_MultidimensionalArray{
	public static void main(String args[]){
		int arr[][][][][][][][][][] = new int[3][2][2][2][2][2][2][2][2][2];
		int ctr = 0;

		for(int a = 0; a < 3; a++){
			for(int b = 0; b < 2; b++){
				for(int c = 0; c < 2; c++){
					for(int d = 0; d < 2; d++){
						for(int e = 0; e < 2; e++){
							for(int f = 0; f < 2; f++){
								for(int g = 0; g < 2; g++){
									for(int h = 0; h < 2; h++){
										for(int i = 0; i < 2; i++){
											for(int j = 0; j < 2; j++){
												arr[a][b][c][d][e][f][g][h][i][j] = ctr;
												ctr++;
											}
										}
									}
								}
							}
						}
					}
				}
			}
		}
		for(int a = 0; a < 3; a++){
			for(int b = 0; b < 2; b++){
				for(int c = 0; c < 2; c++){
					for(int d = 0; d < 2; d++){
						for(int e = 0; e < 2; e++){
							for(int f = 0; f < 2; f++){
								for(int g = 0; g < 2; g++){
									for(int h = 0; h < 2; h++){
										System.out.println(a + "->" + b + "->" + c + "->" + d + "->" + e + "->" + f + "->" + g + "->" + h);
										System.out.println("\t0\t1");
										for(int i = 0; i < 2; i++){
											System.out.print(i + "\t");
											for(int j = 0; j < 2; j++){
												System.out.print(arr[a][b][c][d][e][f][g][h][i][j] + "\t");
											}
											System.out.println();
										}
										System.out.println();
									}
								}
							}
						}
					}
				}
			}
		}
	}
}