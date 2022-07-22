#include<stdio.h>
#include<iostream>
#include<string.h>
using namespace std;
const int maxn =2e6+5;
int tree[maxn][30];
int sum[maxn];
int tot;
void insert_(char *str)
{
   int  len=strlen(str);
   int root=0;
   for(int i=0;i<len;i++)
   {
       int id=str[i]-'a';
       if(!tree[root][id]) tree[root][id]=++tot;
       sum[tree[root][id]]++;//记录节点访问次数
       root=tree[root][id];
   }
   //root在此对应某个单词，一一对应
}
int find_(char *str)
{
    int len=strlen(str);
    int root=0;
    for(int i=0;i<len;i++)
    {
        int id=str[i]-'a';
        if(!tree[root][id]) return 0;
        root=tree[root][id];
    }
    return sum[root];//返回当前字符串结尾节点的访问次数，也就是作为前缀的出现次数
}
char ss[maxn];
int main()
{
    tot=0;
    while(gets(ss))
    {
        if(ss[0]=='\0') break;
        insert_(ss);
    }
    while(scanf("%s",ss)!=EOF)
    {
        printf("%d\n",find_(ss));
    }
    return 0;
}
