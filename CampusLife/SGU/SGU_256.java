import java.io.*;
import java.util.*;
import java.math.*;

@SuppressWarnings("unused")
public class Main {
	public static void main(String[] args) throws FileNotFoundException {
		InputStream inputStream = System.in;
		// InputStream inputStream = new FileInputStream(new File(
		// "C:\\Users\\Administrator\\Codeblocks\\First\\1.in"));
		OutputStream outputStream = System.out;
		InputReader in = new InputReader(inputStream);
		PrintWriter out = new PrintWriter(outputStream);
		TaskA solver = new TaskA();
		solver.solve(1, in, out);
		out.close();
	}
}

// 使用对象时,首先考虑是否要采用深复制
class TaskA {
	static final int mod = (int) 1e9 + 7;
	static final int INF = 0x3fffffff;
	static final double eps = 1e-7;
	static final int maxn = (int) 1e6;

	// 声明全局变量
	int M,N;
	int[] A=new int[11];
	int[] B=new int[11];
	int[][][][][] dp=new int[11][11][11][11][222];
	boolean[][][][][] has=new boolean[11][11][11][11][222];
	/*
	 * 从当前状态达到满足条件的状态的最小值
	 * 设dp[a1][a2][a3][a4][Sum]为前面4天的分别由a1,a2,a3,a4来做所得的气球数位Sum的最小天数
	 * 从(x1,x2,x3,x4,M) -> (0,0,0,0,0)  */
	int DFS(int a1,int a2,int a3,int a4,int Sum){
		if(has[a1][a2][a3][a4][Sum])
			return dp[a1][a2][a3][a4][Sum];
		has[a1][a2][a3][a4][Sum]=true;
		if(Sum>=M) return 0;
		dp[a1][a2][a3][a4][Sum]=INF;

		dp[a1][a2][a3][a4][Sum]=DFS(a2,a3,a4,0,Sum)+1;
		for(int i=1;i<=N;i++){
			boolean flag=true;
			if(a1==i && B[i]>3) flag=false;
			if(a2==i && B[i]>2) flag=false;
			if(a3==i && B[i]>1) flag=false;
			if(a4==i && B[i]>0) flag=false;
			if(!flag) continue;
			int temp=DFS(a2,a3,a4,i,Sum+A[i])+1;//当前天为a4，明天要做的是i
			dp[a1][a2][a3][a4][Sum]=Math.min(temp,dp[a1][a2][a3][a4][Sum]);
		}
		return dp[a1][a2][a3][a4][Sum];
	}

	public void solve(int testNumber, InputReader in, PrintWriter out) {
		 M=in.nextInt();
		 N=in.nextInt();
		 for(int i=1;i<=N;i++){
			 A[i]=in.nextInt();
			 B[i]=in.nextInt();
		 }
		 out.println(DFS(0,0,0,0,0));
	}

}

class InputReader {
	public BufferedReader reader;
	public StringTokenizer tokenizer;

	public InputReader(InputStream stream) {
		reader = new BufferedReader(new InputStreamReader(stream), 32768);
		tokenizer = null;
	}

	public String next() {
		while (tokenizer == null || !tokenizer.hasMoreTokens()) {
			try {
				tokenizer = new StringTokenizer(reader.readLine());
			} catch (IOException e) {
				throw new RuntimeException(e);
			}
		}
		return tokenizer.nextToken();
	}

	public int nextInt() {
		return Integer.parseInt(next());
	}

	public double nextDouble() {
		return Double.parseDouble(next());
	}

}
