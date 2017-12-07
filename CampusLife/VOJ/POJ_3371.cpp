#include<iostream>
#include<cstring>
#include<cstdio>

using namespace std;
const int Max = 100;
int wor = 0, sen = 0, syl = 0;
 
bool isEnd(char c){
    if(c == '!' || c == '?') return true;
    if(c == '.' || c == ':' || c == ';') return true;
    return false;
}
 
bool isVow(char c){
    if(c == 'a' || c == 'e') return true;
    if(c == 'i' || c == 'o') return true;
    if(c == 'u' || c == 'y') return true;
    return false;
}
 
void addSyl(char *word, int l){
    if((word[l-1] == 's' || word[l-1] == 'd') && word[l-2] == 'e')
        l -= 2;
    else if(word[l-1] == 'e' && word[l-2] != 'l')
        l -= 1;
    if(isVow(word[0])) syl ++;
    for(int i = 1; i < l; i ++)
        if(isVow(word[i]) && !isVow(word[i-1])) syl ++;
}
 
int main(){
    int i, l, st, ed;
    char msg[Max], word[Max];
    while(cin >> msg){
        wor ++;
        l = strlen(msg);
        for(i = 0; i < l; i ++)
            if(msg[i] >= 'A' && msg[i] <= 'Z')
                msg[i] = msg[i] - 'A' + 'a';
            else if(isEnd(msg[i])) sen ++;
        ed = l;
        while(!(msg[ed] >= 'a' && msg[ed] <= 'z')) ed --;
        st = 0;
        while(!(msg[st] >= 'a' && msg[st] <= 'z')) st ++;
        for(l = 0, i = st; i <= ed; i ++)
            word[l ++] = msg[i];
        if(l <= 3) syl ++;
        else addSyl(word, l);
    }
    printf("%.2f\n", 206.835 - 1.015*wor/sen - 84.6*syl/wor);
    return 0;
}