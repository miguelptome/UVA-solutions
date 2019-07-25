import java.io.PrintWriter;
import java.util.Scanner;

public class P280 {
	static boolean visited[];
	static int visitedCount =0;
	
	public static void main(String args[]) {
		Scanner scn = new Scanner(System.in);
		PrintWriter out = new PrintWriter(System.out);
		while (true) {
			int n = scn.nextInt();
			if (n == 0)
				break;
			scn.nextLine();
			int edge[][] = new int[n+1][];
			while (true) {
				String oneLine[] = scn.nextLine().split(" ");
				int index = Integer.parseInt(oneLine[0]);
				if (index == 0)
					break;
				edge[index] = new int[oneLine.length - 2];
				for (int i=1; i<oneLine.length-1; i++) {
					edge[index][i-1] = Integer.parseInt(oneLine[i]);
				}
			}
			// input reading done
			// next is to read start index and output answer
			int count = scn.nextInt();
			for (int i=0; i<count; i++) {
				visited = new boolean[n+1];
				visitedCount = 0;
				int startVertex = scn.nextInt();
				// process
				dfs(startVertex, edge);
				// output
				int unvisitedCount = n-visitedCount;
				out.print(unvisitedCount);
				for (int j=1; j<=n; j++) {
					if (!visited[j])
						out.print(" " + j);
				}
				out.println();
			}
		}
		out.flush();
		out.close();
		scn.close();
	}
	
	static void dfs(int startVertex, int edge[][]) {
		for (int i=0; edge[startVertex] != null && i<edge[startVertex].length; i++) {
			if (!visited[edge[startVertex][i]]) {
				visited[edge[startVertex][i]] = true;
				visitedCount += 1;
				dfs(edge[startVertex][i], edge);
			}
		}
	}
}
