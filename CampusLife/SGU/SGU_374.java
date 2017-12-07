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
    	int a=in.nextInt();
    	int b=in.nextInt();
    	int k=in.nextInt();
    	BigInteger A=new BigInteger(Integer.toString(a));
    	BigInteger B=new BigInteger(Integer.toString(b));
    	BigInteger C=new BigInteger("0");
    	C=C.add(A);
    	C=C.add(B);
    	C=C.pow(k);
    	out.println(C.toString());
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