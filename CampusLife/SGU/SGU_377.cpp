/*****
第一行有2^m种放法。。其中除了010101和101010之外。。
第一行一确定其他行也都确定了。。于是就有2^m-2种。。
又如果第一行是010101或101010。。那么第二行也只能选这两种。。
每一行都有两种选择。。于是就是2^n种。。
*****/
import java.io.InputStreamReader;
import java.io.IOException;
import java.io.BufferedReader;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.util.StringTokenizer;
import java.io.InputStream;
import java.math.BigInteger;

public class Solution {
	public static void main(String[] args) {
		InputStream inputStream = System.in;
		OutputStream outputStream = System.out;
		InputReader in = new InputReader(inputStream);
		PrintWriter out = new PrintWriter(outputStream);
		TaskA solver = new TaskA();
		solver.solve(1, in, out);
		out.close();
	}
}

class TaskA {
    static final int MODULO = (int) 1e9 + 7;

    public void solve(int testNumber, InputReader in, PrintWriter out) {
    	int N=in.nextInt();
    	int M=in.nextInt();
    	BigInteger A=new BigInteger(Integer.toString(2));
    	BigInteger B=new BigInteger(Integer.toString(2));
    	A=A.pow(M);
    	A=A.subtract(new BigInteger(Integer.toString(2)));
    	B=B.pow(N);
    	B=B.add(A);
    	out.print(B.toString());
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
}
