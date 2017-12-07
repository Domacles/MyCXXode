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

class VECTOR {
	public double x;
	public double y;

	public VECTOR() {
	}

	public VECTOR(double xx, double yy) {
		x = xx;
		y = yy;
	}

	public VECTOR Rotate(double d) {
		VECTOR ret = new VECTOR();
		ret.x = x * Math.cos(d) - y * Math.sin(d);
		ret.y = x * Math.sin(d) + y * Math.cos(d);
		return ret;
	}

	public VECTOR Mutiple(double d) {
		VECTOR ret = new VECTOR();
		ret.x = d * x;
		ret.y = d * y;
		return ret;
	}

	public VECTOR Add(VECTOR d) {
		VECTOR ret = new VECTOR(x + d.x, y + d.y);
		return ret;
	}
}

class TaskA {
	static final int mod = (int) 1e9 + 7;
	static final int INF = 0x3fffffff;
	static final double eps = 1e-15;
	static final int maxn = (int) 1e6;

	// 声明全局变量
	public double dis(double x1, double y1, double x2, double y2) {
		return Math.sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1));
	}

	public void solve(int testNumber, InputReader in, PrintWriter out) {
		int N = in.nextInt();
		int n1 = in.nextInt(), n2 = in.nextInt();
		double x1 = in.nextDouble(), y1 = in.nextDouble();
		double x2 = in.nextDouble(), y2 = in.nextDouble();
		double p = 2 * Math.PI / (double) N;
		if (n1 > n2) {
			int t = n1;
			n1 = n2;
			n2 = t;
			double t1 = x1;
			x1 = x2;
			x2 = t1;
			double t2 = y1;
			y1 = y2;
			y2 = t2;
		}
		double arg = p * (n2 - n1);
		double R = 0.5 * dis(x1, y1, x2, y2) / Math.sin(arg / 2);//三角函数求半径
		VECTOR midP = new VECTOR((x1 + x2) / 2, (y1 + y2) / 2);//求两点连线的中点
		VECTOR ZX = midP
				.Add(new VECTOR(0.5 * (y2 - y1) / Math.tan(arg / 2), 0)).Add(
						new VECTOR(0, -0.5 * (x2 - x1) / Math.tan(arg / 2))); //求出多边形重心坐标
		double arg0 = Math.asin((y1 - ZX.y) / R);//求出旋转的角度
		if (Math.acos((x1 - ZX.x) / R) > Math.PI / 2) {
			if (arg0 >= -1e10)//如果这个角的角度大于平角,那么显然我们要把它化为<pi/2的
				arg0 = Math.PI - arg0;
			else
				arg0 = -Math.PI - arg0;
		}
		for (int i = 1; i <= N; i++) {//out
			double ax = arg0 + p * (n1 - i);
			VECTOR ans = ZX.Add(new VECTOR(R * Math.cos(ax), R * Math.sin(ax)));
			out.printf("%.6f ", ans.x + eps);
			out.printf("%.6f\n", ans.y + eps);
		}
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
