import java.io.PrintWriter;
import java.util.Scanner;

public class P12356 {
    
    public static void main(String args[]) {
	
		Scanner scn = new Scanner(System.in);
		PrintWriter pw = new PrintWriter(System.out);
		
		int S = scn.nextInt();
		int B = scn.nextInt();
		
		while (!(S == 0 && B == 0)) {

			int arrL[] = new int[S+1];
			int arrR[] = new int[S+1];
			
			for (int i = 1; i<=S; i++) {
				arrL[i] = i-1;
			}
			for (int i = 1; i<S; i++) {
				arrR[i] = i+1;
			}
			arrR[S] = 0;
			
			for (int i = 1; i<=B; i++) {
					
				int L = scn.nextInt();
				int R = scn.nextInt();
				
				String ml = arrL[L]==0 ? "*" : ""+arrL[L]; 
				String mr = arrR[R]==0 ? "*" : ""+arrR[R];
				
				pw.println(ml + " " + mr);
				
				setMostLeft(arrL, arrR, L, R);
				setMostRight(arrL, arrR, L, R);
				
			}
			
			S = scn.nextInt();
			B = scn.nextInt();
				
			pw.println("-");
		}
		
		pw.flush();
		scn.close();
	}  
		
	private static void setMostLeft(int arrL[], int arrR[], int L, int R) {
		
		int mr = arrR[R]; 
		if (mr != 0) {
			arrL[mr] = arrL[L];
		}
		 
	}
		
	private static void setMostRight(int arrL[], int arrR[], int L, int R) {
		
		int ml = arrL[L]; 
		if (ml != 0) {
			arrR[ml] = arrR[R];
		}
		 
	}
}
