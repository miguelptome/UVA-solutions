package pt.courses.uva;

import java.io.PrintWriter;
import java.util.Scanner;

public class P10773 {
	public static void main(String args[]) {
		Scanner scn = new Scanner(System.in);
		PrintWriter out = new PrintWriter(System.out);
		int n = scn.nextInt();
		for (int i=1; i<=n; i++) {
			double d = scn.nextDouble();
			double v = scn.nextDouble();
			double u = scn.nextDouble();
			if (v == 0 || u == 0 || u <= v) {
				out.println("Case " + i + ": can't determine");
				continue;
			}
			double fastest = d/u;
			double shortest = d / Math.sqrt(u * u - v * v);
			double r = Math.abs(fastest - shortest);
			out.print("Case " + i + ": ");
			out.printf("%.3f\n", r);
		}
		out.flush();
		out.close();
		scn.close();
	}
}
