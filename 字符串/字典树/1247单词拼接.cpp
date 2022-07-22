#include<stdio.h>
#include<iostream>
#include<string.h>
#include<sstream>
#include<set>
//本题题意是问你某个单词是否可以拆成单词表中的其他两个单词。
//我们可以建两颗Trie树，然后分别正序倒序插入每个单词，对每个单词查询的时候，我们分别正序倒序查询，对出现过单词的前缀下标进行标记，对每个出现过单词的后缀进行标记，最后扫描标记数组，如果某个位置前缀后缀均被标记过，则表示可以拆成单词表中的两个其他单词。

using namespace std;
const int maxn =2e6+5;
int tree[maxn][30],tree2[maxn][30];
set<string> s;
bool flagg[maxn],flagg2[maxn];
int sum[55];
int tot,tot2;
void insert_(char *str)
{
   int len=strlen(str);
   int root=0;
   for(int i=0;i<len;i++)
   {
       int id=str[i]-'a';
       if(!tree[root][id]) tree[root][id]=++tot;
       root=tree[root][id];
   }
   flagg[root]=true;
   return ;
}
void find_(char *str)
{
    int len=strlen(str);
    int root=0;
    for(int i=0;i<len-1;i++)
    {
        int id=str[i]-'a';
        root=tree[root][id];
        if(flagg[root]) sum[i]++;//当前前缀是其他单词
    }
    return ;
}
void insert2_(char *str)
{
   int len=strlen(str);
   int root=0;
   for(int i=0;i<len;i++)
   {
       int id=str[i]-'a';
       if(!tree2[root][id]) tree2[root][id]=++tot2;
       root=tree2[root][id];
   }
   flagg2[root]=true;
   return ;
}
void  find2_(char *str)
{
    int len=strlen(str);
    int root=0;
    for(int i=0;i<len-1;i++)
    {
        int id=str[i]-'a';
        root=tree2[root][id];
        if(flagg2[root])
        {
            sum[len-i-2]++;//当前前缀是其他单词，对反转后的位置进行标记
        }
    }
    return ;
}
char ss[50005][55];
int main()
{
    int cnt=0;
    while(scanf("%s",ss[cnt++])!=EOF)
    {
        insert_(ss[cnt-1]);//正序插入到第一棵树
        strrev(ss[cnt-1]);
        insert2_(ss[cnt-1]);//倒叙插入第二颗树
        strrev(ss[cnt-1]);
    }
    for(int i=0;i<cnt;i++)
    {
        int len=strlen(ss[i]);
        for(int j=0;j<len;j++)
        {
            sum[j]=0;
        }
        find_(ss[i]);//在第一棵树上查询并标记
        strrev(ss[i]);
        find2_(ss[i]);//在第二颗树上查询并标记
        strrev(ss[i]);
        for(int j=0;j<len;j++)
        {
            if(sum[j]==2)//两次查询均标记过的位置
            {
                string tmp=ss[i];
                s.insert(tmp);
                break;
            }
        }
    }
    set<string>::iterator it;
    for(it=s.begin();it!=s.end();++it)
    {
        printf("%s\n",(*it).c_str());
    }
    return 0;
}
