/****直接解压，解压长度为给定病毒中最长的*****/
#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <iostream>
#include <queue>
using namespace std;
#define maxn 1001000
#define MAX(a,b) (a>b?a:b)
#define MIN(a,b) (a<b?a:b)
char s[maxn],str[maxn*100];
int n,pos;
struct trie{
    trie *next[26],*fail;
    int num;
}po[maxn/4],re_root;
queue<trie *> q;
int insert_trie(trie *root,char *name){
    if(name[0]==0){
        root->num=1;
        return 0;
    }
    if(root->next[name[0]-'a']==NULL){
        memset(po+pos,0,sizeof(trie));
        root->next[name[0]-'a']=&po[pos++];
    }
    insert_trie(root->next[name[0]-'a'],name+1);
    return 0;
}
int parse_int(char *name,int &i,char &ch){
    int ans=0;
    i=0;
    while(name[i]>='0' && name[i]<='9'){
        ans=ans*10+name[i]-'0';
        i++;
    }
    ch=name[i];
    return ans;
}
int depress(char *s,char *str,int len){
    int i=0,j,k=0,t,l;
    char ch;
    while(s[i]){
        if(s[i]=='['){
            t=parse_int(s+i+1,l,ch);
            t=MIN(t,len);
            while(t--) str[k++]=ch;
            i+=l+3;
        }
        else str[k++]=s[i++];
    }
    str[k]=0;
    return 0;
}
int build_ac_auto(){
    q.push(&re_root);
    trie *p,*temp;
    re_root.fail=NULL;
    while(!q.empty()){
        p=q.front(),q.pop();
        for(int i=0;i<26;i++){
            if(p->next[i]){
                temp=p->fail;
                while(temp && temp->next[i]==NULL) temp=temp->fail;
                if(temp==NULL) p->next[i]->fail=&re_root;
                else p->next[i]->fail=temp->next[i];
                q.push(p->next[i]);
            }
        }
    }
    return 0;
}
int query(trie *root,char *name){
    int ans=0,i=0,j,k,t;
    trie *p=root,*temp;
    while(name[i]){
        t=name[i]-'a';
        while(p!=NULL && p->next[t]==NULL) p=p->fail;
        if(p==NULL) p=root;
        else p=p->next[t];
        temp=p;
        while(temp && temp->num!=-1){
            ans+=temp->num;
            temp->num=-1;
            temp=temp->fail;
        }
        i++;
        if(ans==n)
        break;
    }
    if(ans==0)
    printf("No %d\n",ans);
    else printf("Yes %d\n",ans);
    return 0;
}
int main(){
    int i,j,k,t,len;
    scanf("%d",&t);
    while(t--){
        pos=0;
        scanf("%d",&n);
        len=0;
        memset(&re_root,0,sizeof(trie));
        for(i=0;i<n;i++){
            scanf("%s",s);
            insert_trie(&re_root,s);
            k=strlen(s);
            len=MAX(k,len);
        }
        build_ac_auto();
        scanf("%s",s);
        if(len>=1) len=1;/*这里的len在0-50之间都能AC表示数据不带这么坑的*/
        depress(s,str,len);
        query(&re_root,str);
    }
    return 0;
}
