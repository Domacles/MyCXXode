#include<iostream>
#include<cstring>
#include<cstdio>

using namespace std;

int c[27][27]={0};

/*打表，利用杨辉三角计算每一个组合数nCm*/

void play_table()
{
	for(int i=0;i<=26;i++)
		for(int j=0;j<=i;j++)
			if(!j || i==j)
				c[i][j]=1;
			else
				c[i][j]=c[i-1][j-1]+c[i-1][j];
	c[0][0]=0;
}

int main(int i,int j)
{
	play_table();

	char str[11];
	while(cin>>str)
	{
		int len=strlen(str);

		/*检查str是否符合升序排列*/

		for(i=1;i<len;i++)
			if(str[i-1]>=str[i])
			{
				cout<<0<<endl;   //本题只要求输入一次就允许结束程序
				return 0;        //因此若使用循环输入，一旦str不符合字典要求（如aab,ba等）就要结束程序
			}                    //这是与POJ1496的最隐蔽区别
		
		int sum=0;  //str的值，初始为0
			
		/*计算长度比str小的字符串个数*/
			
		for(i=1;i<len;i++)
			sum+=c[26][i];  //c[26][i]表示 长度为i的字符串的个数
			
		/*计算长度等于len，但值比str小的字符串个数*/
			
		for(i=0;i<len;i++)  //i为str的指针，对每一个位置枚举 允许选择的字符ch
		{
			char ch= (!i)?'a':str[i-1]+1;   //ch = str[i-1]+1 根据升序规则，当前位置的ch至少要比str前一位置的字符大1
			while(ch<=str[i]-1)   //ch<=str[i]-1 根据升序规则，当前位置的ch最多只能比 str这个位置实际上的字符 小1
			{
				sum+=c['z'-ch][len-1-i];  //'z'-ch ： 小于等于ch的字符不允许再被选择，所以当前能够选择的字符总数为'z'-ch
				ch++;                     //len-1-i  ： ch位置后面（不包括ch）剩下的位数，就是从'z'-ch选择len-1-i个字符
			}
		}
			
		cout<<++sum<<endl;     // 此前的操作都是寻找比str小的所有字符串的个数，并不包括str本身，因此这里要+1
	}
	return 0;
}