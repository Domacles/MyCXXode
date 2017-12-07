#include<cstring>
#include<iostream>
using namespace std;

char map[10][16];
bool vist[10][15];
int MaxSize=-1;
char MaxColor;
int MaxR,MaxC;

void SearchMaxArea(void); //搜索当前地图的最大区域
int BFSArea(int i,int j);  //同色区域搜索，返回该区域的大小
void DelMaxArea(void); //删除最大区域
void RefreshMap(void);  //刷新地图

int main(void)
{
	int Game;
	cin>>Game;
	for(int g=1;g<=Game;g++)
	{
		for(int k=9;k>=0;k--)
			cin>>map[k];
		cout<<"Game "<<g<<':'<<endl<<endl;

		int step=0;
		int RemainBalls=150;
		int SumScore=0;
		while(true)
		{
			MaxSize=-1;
			SearchMaxArea();

			if(MaxSize==0 || MaxSize==1)
				break;

			DelMaxArea();
			RefreshMap();
			
			int score=(MaxSize-2)*(MaxSize-2);
			cout<<"Move "<<++step<<" at ("<<MaxR+1<<','<<MaxC+1<<"): ";
			cout<<"removed "<<MaxSize<<" balls of color "<<MaxColor<<", got "<<score<<" points."<<endl;

			RemainBalls-=MaxSize;
			SumScore+=score;
		}
		if(RemainBalls==0)
			SumScore+=1000;
		cout<<"Final score: "<<SumScore<<", with "<<RemainBalls<<" balls remaining."<<endl<<endl;
	}
	return 0;
}

/*搜索当前地图的最大区域*/
void SearchMaxArea(void)
{
	memset(vist,false,sizeof(vist));
	MaxSize=0;

	for(int j=0;j<15;j++)   //从左下角开始搜索
		for(int i=0;i<10;i++)
		{
			int size=0;
			if(!vist[i][j] && map[i][j])
			{
				size=BFSArea(i,j);
				if(MaxSize<size)      //记录最大区域的左下角坐标
				{
					MaxSize=size;
					MaxR=i;
					MaxC=j;
				}
			}
		}
	return;
}

/*同色区域搜索*/
int BFSArea(int i,int j)
{
	class
	{
	public:
		int x,y;
	}queue[151];

	int head,tail;
	queue[head=tail=0].x=i;
	queue[tail++].y=j;
	vist[i][j]=true;

	int size=0;
	char color=map[i][j];
	while(head<tail)
	{
		int x=queue[head].x;
		int y=queue[head++].y;
		size++;

		if(x+1<10 && !vist[x+1][y] && map[x+1][y]==color)  //上
		{
			vist[x+1][y]=true;
			queue[tail].x=x+1;
			queue[tail++].y=y;
		}
		if(x-1>=0 && !vist[x-1][y] && map[x-1][y]==color)  //下
		{
			vist[x-1][y]=true;
			queue[tail].x=x-1;
			queue[tail++].y=y;
		}
		if(y-1>=0 && !vist[x][y-1] && map[x][y-1]==color)  //左
		{
			vist[x][y-1]=true;
			queue[tail].x=x;
			queue[tail++].y=y-1;
		}
		if(y+1<15 && !vist[x][y+1] && map[x][y+1]==color)  //右
		{
			vist[x][y+1]=true;
			queue[tail].x=x;
			queue[tail++].y=y+1;
		}
	}
	return size;
}

/*删除最大区域*/
void DelMaxArea(void)
{
	class
	{
	public:
		int x,y;
	}queue[151];

	int head,tail;
	queue[head=tail=0].x=MaxR;
	queue[tail++].y=MaxC;

	MaxColor=map[MaxR][MaxC];
	map[MaxR][MaxC]=0;  //删除该格上的球

	while(head<tail)
	{
		int x=queue[head].x;
		int y=queue[head++].y;
		map[x][y]=0;

		if(x+1<10 && map[x+1][y]==MaxColor)  //上
		{
			map[x+1][y]=0;
			queue[tail].x=x+1;
			queue[tail++].y=y;
		}
		if(x-1>=0 && map[x-1][y]==MaxColor)  //下
		{
			map[x-1][y]=0;
			queue[tail].x=x-1;
			queue[tail++].y=y;
		}
		if(y-1>=0 && map[x][y-1]==MaxColor)  //左
		{
			map[x][y-1]=0;
			queue[tail].x=x;
			queue[tail++].y=y-1;
		}
		if(y+1<15 && map[x][y+1]==MaxColor)  //右
		{
			map[x][y+1]=0;
			queue[tail].x=x;
			queue[tail++].y=y+1;
		}
	}
	return;
}

/*刷新地图*/
void RefreshMap(void)
{
	bool empty[15]={false};
	int i,j;

	/*处理从上到下的移动*/
	for(j=0;j<15;j++)
	{
		bool flag=false;  //标记第j列是否全列为空
		int pi=-1;
		for(i=0;i<10;i++)
		{
			if(map[i][j])
			{
				flag=true;
				if(pi!=-1)
				{
					map[pi][j]=map[i][j];
					map[i][j]=0;
					i=pi;
					pi=-1;
				}
			}
			else
			{
				pi=i;
				while(i+1<10 && !map[i+1][j])
					i++;
			}
		}
		if(!flag)
			empty[j]=true;  //第j列为空
	}

	/*处理从右到左的移动*/
	int k=-1;
	for(j=0;j<15;j++)
	{
		if(!empty[j])
		{
			if(k!=-1)
			{
				for(int x=0;x<10;x++)
				{
					map[x][k]=map[x][j];
					map[x][j]=0;
				}
				empty[j]=true;
				j=k;
				k=-1;
			}
		}
		else
		{
			k=j;
			while(j+1<15 && empty[j+1])
				j++;
		}
	}

	return;
}