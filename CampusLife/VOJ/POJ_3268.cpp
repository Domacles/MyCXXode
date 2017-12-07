 /****
	巧用反向边
 ****/
 #include <iostream>
 #include <cstdio>
 #include <algorithm>
 #include <cstring>
 #include <queue>
 using namespace std;
 const int M=100010;
 const int INF=2000000;
 struct Node{
     int v,w;
     Node *next;
 }edge[M],redge[M],tmp[M*2];
 int pos=0;
 int ecost[M];
 int n,m,src,Q[M];
 bool vis[M];
 void SPFA(int dir){
     int h,t,u,i;
     Node *ptr;
     h=0;t=1;
     memset(vis,0,sizeof(vis));
     for(i=0;i<=n;i++) ecost[i]=INF;
     Q[0]=src;
     ecost[src]=0;
     while(h!=t){
         u=Q[h++];
         vis[u]=0;
         if(dir!=0) ptr=edge[u].next;//正向边
         else ptr=redge[u].next;//反向边
         while(ptr){
             if(ecost[ptr->v]>ecost[u]+ptr->w){
                 ecost[ptr->v]=ecost[u]+ptr->w;
                 if(!vis[ptr->v]){
                     Q[t++]=ptr->v;
                     vis[ptr->v]=1;
                 }
             }
             ptr=ptr->next;
         }
     }
 }
 void insert(int x,int y,int w){
     Node *ptr=&tmp[pos++];
     ptr->v=y;
     ptr->w=w;
     ptr->next=edge[x].next;
     edge[x].next=ptr;
     ptr=&tmp[pos++];
     ptr->v=x;
     ptr->w=w;
     ptr->next=redge[y].next;
     redge[y].next=ptr;
 }
 int main(){
     int i,x,y,w;
     int ans[M],MaxTime;
     while(scanf("%d%d%d",&n,&m,&src)!=EOF){
         pos=0;
         for(i=0;i<=n;i++){
             edge[i].next=redge[i].next=NULL;
         }
         for(i=0;i<m;i++){
             scanf("%d%d%d",&x,&y,&w);
             insert(x,y,w);
         }
         MaxTime=0;
         memset(ans,0,sizeof(ans));
         SPFA(0);//求的是回来的最短路
         for(i=1;i<=n;i++){
             if(i!=src) ans[i]+=ecost[i];
         }
         SPFA(1);//求的是去时的最短路
         for(i=1;i<=n;i++){
             if(i!=src){
                 ans[i]+=ecost[i];
                 MaxTime=max(MaxTime,ans[i]);
             }
         }
         printf("%d\n",MaxTime);
     }
     return 0;
 }