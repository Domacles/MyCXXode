import java.util.*;

public class CF_56D {
	public static void main(String[] args) {
		Scanner s = new Scanner(System.in);
		String a = s.nextLine(), b = s.nextLine();
		int n = a.length(), m = b.length();
		int[][] dp = new int[n + 1][m + 1];
		int[][] pre[] = new int[n + 1][m + 1][];
		for (int i = 0; i <= n; ++i) {
			dp[i][0] = i;
			pre[i][0] = new int[] { i - 1, 0, 0 };
		}
		for (int j = 0; j <= m; ++j) {
			dp[0][j] = j;
			pre[0][j] = new int[] { 0, j - 1, 1 };
		}
		for (int i = 1; i <= n; ++i) {
			for (int j = 1; j <= m; ++j) {
				int cost = a.charAt(i - 1) == b.charAt(j - 1) ? 0 : 1;
				int d1 = dp[i - 1][j] + 1;
				int d2 = dp[i][j - 1] + 1;
				int d3 = dp[i - 1][j - 1] + cost;
				int type = min(d1, d2, d3);
				if (type == 0) {
					dp[i][j] = d1;
					pre[i][j] = new int[] { i - 1, j, type };
				} else if (type == 1) {
					dp[i][j] = d2;
					pre[i][j] = new int[] { i, j - 1, type };
				} else {
					dp[i][j] = d3;
					pre[i][j] = new int[] { i - 1, j - 1, type + cost };
				}
			}
		}

		Deque<String> q = new ArrayDeque<String>();
		for (int i = n, j = m, ti, tj; i >0 || j > 0; i = ti, j = tj) {
			int type = pre[i][j][2];
			if (type == 1) {
				q.push("INSERT " + j + " " + b.charAt(j - 1));
			} else if (type == 0) {
				q.push("DELETE " + (j + 1));
			} else if (type == 3) {
				q.push("REPLACE " + j + " " + b.charAt(j - 1));
			}
			ti = pre[i][j][0];
			tj = pre[i][j][1];
		}
		System.out.println(dp[n][m]);
		while (!q.isEmpty()) {
			System.out.println(q.pop());
		}
	}

	static int min(int... is) {
		int r = Integer.MAX_VALUE, ri = -1;
		for (int i = 0; i < is.length; ++i) {
			if (r > is[i]) {
				r = is[i];
				ri = i;
			}
		}
		return ri;
	}
}