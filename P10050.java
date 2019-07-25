import java.io.PrintWriter;
import java.util.Scanner;

public class P10050 {
	
	public static void main(String args[]) {
		Scanner scn = new Scanner(System.in);
		PrintWriter out = new PrintWriter(System.out);
		Integer testCaseCount = scn.nextInt();
		for (Integer testCase=0; testCase<testCaseCount; testCase++) {
			Integer N = scn.nextInt();
			Integer P = scn.nextInt();
			Integer h[] = new Integer[P];
			for (Integer i=0; i<P; i++) 
				h[i] = scn.nextInt();
			
			Integer daysCount = 0;
			for (Integer i=1; i<=N; i++) {
				if (i%7!=6 && i%7!=0) {
					for (Integer i2=0; i2<h.length; i2++) {
						if (i%h[i2] == 0) {
							daysCount++;
							break;
						}
					}
				}
			}
			out.println(daysCount);
		}
		out.flush();
		out.close();
		scn.close();
	}
}
