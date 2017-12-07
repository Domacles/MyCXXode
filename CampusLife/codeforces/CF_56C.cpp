/****
					Codeforces 56C
TMD,根本没必要恢复树的结构,恢复树的结构就是为了遍历后寻找答案,
而实际上,有了前序遍历(后序,中序同),并且能够通过前序遍历看出树的
结构,便不需要再恢复.......
	基于此思想,实际上题目所给的信息形式已经将题目简化,不需要深搜了.
****/
#include <iostream>
#include <vector>
using namespace std;
vector<string> pars;
string s;

int main()
{
	int cnt = 0;
	cin >> s;
	for (int i = 0; i < s.size(); i++)
	{
		if (s[i] == '.') pars.pop_back();//逗号意味着当前存的最有一个节点叙述完毕,出栈~
		if (s[i] == ',' || s[i] == ':' || s[i] == '.') continue;
		string newS = "";
		while (s[i] >= 'A' && s[i] <= 'Z')//读入单词
			newS += s[i], i++;
		for (int j = 0; j < pars.size(); j++)//当前存的节点都是在同一颗树上
			if (pars[j] == newS) cnt++;//找到答案
		pars.push_back(newS);//入栈
		i--;//退回,用于下次循环判断是入栈还是出栈
	}
	cout << cnt << endl;
	return 0;
}