import java.math.*;
import java.util.Scanner;
import java.io.BufferedInputStream;
import java.lang.System;

public class ZOJ2604 {
	public static void main(String[] args) {
		BigInteger[][] dp;
		dp = new BigInteger[55][55];
		for (int i = 0; i <= 54; i++) {
			for (int j = 0; j <= 54; j++)
				dp[j][i] = BigInteger.ZERO;
		}
		for (int i = 0; i <= 54; i++)
			dp[0][i] = BigInteger.ONE;
		for (int i = 1; i <= 54; i++)
			for (int j = 1; j <= 54; j++) {
				for (int k = 1; k <= i; k++) {
					dp[i][j] = dp[i][j].add(dp[i - k][j].multiply(dp[k - 1][j - 1]));
				}
			}
		int i = 0;
		Scanner cin = new Scanner(new BufferedInputStream(System.in));
		while (cin.hasNext()) {
			i++;
			int n, k; 
			n = cin.nextInt();
			k = cin.nextInt();
			if (n == 0 && k == 0)
				break;
			System.out.print("Case "+i+": ");
			System.out.print(dp[n][k].subtract(dp[n][k-1]));
			System.out.printf("\n");
		}
	}
}
/**
15 15
dtpbfpabizlkgan
npybkhyu
jqyhismeyf
nab
kobmcjvqgfmij
fh
dmontj
lggmbfcwecn
wrwguzebezdqe
nmmnozy
tzrcodnu
vbekfhdkxkultgs
dnenm
hbpe
czfdmvwtqdj
gftkkevg

54
89
20
128
6
32
92
127
57
54
125
34
10
94
52


*/