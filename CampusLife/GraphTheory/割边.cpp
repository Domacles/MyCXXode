/*************
����һ����<u,v>��v��u�ĺ���������Ӽ����ӵ������û��ָ��u�����ȵĺ����ʱ��
<u,v>�Ǹ�ߡ���LOW[v]>DFN[u]��
*************/
void CutEdge(int cur,int par)
 {    dfn[cur]=low[cur]=++Index;
      
      for(int i=head[cur];i;i=buf[i].next)
     {
         int v=buf[i].v;
         if(v==par)continue;
         if(!dfn[v])
         {
             CutEdge(v,cur);
             if(low[cur]>low[v])
                 low[cur]=low[v];
             if(low[v]>dfn[cur])
             {    
                     ans[nAns++]=buf[i].id;
             }
         }
         else if(low[cur]>dfn[v])
             low[cur]=dfn[v];
     }
 }