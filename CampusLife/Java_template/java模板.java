import java.io.*;
import java.util.*;

public class Main {
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
    static final int INF = 0x7fffffff;
    static final double eps = 1e-7;

    
    
    
    public void solve(int testNumber, InputReader in, PrintWriter out) {
    	/****   ///无法预知有多少组数据时,使用下面的方法
    	try{
    		while(true){
    			//Input
    			
    			
    			//solve
    			
    			
    			//Output
    			//out.print(iCase);
    		}
    	}catch(Exception e){
    		return;
    	}
    	*****/
    	try{
    		int CaseS=in.nextInt();
    		for(int iCase=1;iCase<=CaseS;iCase++){
    			//Input
    			
    			
    			//solve
    			
    			
    			//Output
    			//out.print(iCase);
    		}
    	}catch(Exception e){
    		return ;
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

    public String next() throws Exception{
        while (tokenizer == null || !tokenizer.hasMoreTokens()) {
            try {
                tokenizer = new StringTokenizer(reader.readLine());
            } catch (IOException e) {
                throw new RuntimeException(e);
            }
        }
        return tokenizer.nextToken();
    }

    public int nextInt() throws Exception{
        return Integer.parseInt(next());
    }
    
    public double nextDouble() throws Exception{
    	return Double.parseDouble(next());
    }
    
}
