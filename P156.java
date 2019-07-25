import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;
import java.util.Scanner;
import java.util.StringTokenizer;
import java.util.TreeMap;

public class P156 {

	public static void main(String args[]) {
		Scanner scn = new Scanner(System.in);
		PrintWriter out = new PrintWriter(System.out);
		TreeMap<String, String> map = new TreeMap<>();
		
		while(true) {
			String s = scn.nextLine();
			if (s.equals("#"))
				break;
			StringTokenizer st = new StringTokenizer(s);
			while(st.hasMoreTokens()) {
				String t = st.nextToken();
				String an = trans(t);
				String pre = map.get(an);
				
				if (pre == null)
					map.put(an, t);
				else if (!pre.equals(t))
					map.put(an, "?");	
			}
		}
		ArrayList<String> ans = new ArrayList<>();
		for (String t: map.values())
			if (!t.equals("?"))
				ans.add(t);
		Collections.sort(ans);
		for (String t: ans) 
			out.println(t);
		out.flush();
		out.close();
		scn.close();
	}
	
	static String trans(String s) {
		char t[] = s.toLowerCase().toCharArray();
		Arrays.sort(t);
		return new String(t);
	}
}
