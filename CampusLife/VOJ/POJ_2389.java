import java.math.BigDecimal;  
import java.math.BigInteger;
import java.util.*;

public class Main {
	public static void main(String[] args) {
		Scanner sin=new Scanner(System.in);
		String str1=sin.next();
		String str2=sin.next();
		BigInteger A=new BigInteger(str1);
		BigInteger B=new BigInteger(str2);
		BigInteger C=B.multiply(A);
		System.out.println(C.toString());
	}
}
