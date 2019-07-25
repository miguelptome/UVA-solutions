import java.io.PrintWriter;
import java.util.LinkedList;
import java.util.Scanner;

public class P256 {
	public static void main(String args[]) {
		Scanner scn = new Scanner(System.in);
		PrintWriter out = new PrintWriter(System.out);
		LinkedList<String[]> list = new LinkedList<>();
		String arr[] = {"00","01","81"};
		list.add(arr);
		String arr2[] = {"0000","0001","2025","3025","9801"};
		list.add(arr2);
		String arr3[] = {"000000","000001","088209","494209","998001"};
		list.add(arr3);
		String arr4[] = {"00000000","00000001","04941729","07441984","24502500","25502500","52881984","60481729","99980001"};
		list.add(arr4);
		while (scn.hasNextInt()) {
			Integer x = scn.nextInt();
			arr = list.get(x/2-1);
			for (int i=0; i<arr.length;i++)
				out.println(arr[i]);
		}
		out.flush();
		out.close();
		scn.close();
	}
}
