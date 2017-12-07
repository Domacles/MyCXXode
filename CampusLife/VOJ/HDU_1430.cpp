#include <queue>
#include <string>
#include <cstring>
#include <iostream>
#include <cstdio>

using namespace std;
const int maxn=55555;

struct Node{int s;string str;};
int f[]={1,1,2,6,24,120,720,5040};
int vis[maxn];
string ans[maxn];

int State(string s){
	int val=0;
	for(int i=0;i<8;i++) for(int j=i+1;j<8;j++)
		if(s[i]>s[j]) val+=f[7-i];
	return val;	
}

string GetS(string s,int flag){
	string val=s;
	if(flag==0){
		for(int i=0;i<4;i++){
			val[3-i]=s[4+i];
			val[4+i]=s[3-i];
		}
	}
	if(flag==1){
		for(int i=0;i<3;i++)  
        {  
            val[i+1]=s[i];  
            val[i+4]=s[i+5];  
        }  
        val[0]=s[3];  
        val[7]=s[4];
	}
	if(flag==2){
		val[1]=s[6]; 
        val[2]=s[1]; 
        val[5]=s[2]; 
        val[6]=s[5];
	}
	return val;
}

void BFS()//求最短路
{
	queue<Node>q;
	Node zero;
	int now=State("12345678");
	vis[now]=1;  ans[now]="";
	zero.s=now,zero.str="12345678";
	q.push(zero);
	
	while(!q.empty()){
		zero=q.front(); q.pop();
		for(int i=0;i<3;i++){
			char s='A'+i;
			string str1=GetS(zero.str,i);
			now=State(str1);
			if(!vis[now]){
				ans[now]=ans[zero.s]+s;
				Node Now;
				vis[now]=1;
				Now.s=now , Now.str=str1;
				q.push(Now);
			}
		}
	}
}

char s1[10],s2[10],pos[10];

int main()
{
	BFS();
	while(~scanf("%s%s",s1,s2)){
		for(int i=0;i<8;i++) pos[s1[i]-'0'] = i+1+'0';//置换思路
		for(int i=0;i<8;i++) s2[i] = pos[s2[i]-'0'];
		int Ans=State(string(s2));
		cout<<ans[Ans]<<endl;
	}
	return 0;
}