#include<stdio.h>
#include<iostream>
#include<string.h>
#include<sstream>
#include<map>
using namespace std;
const int maxn =2e6+5;
int tree[maxn][30];
int sum[maxn];
int tot;
int belong[30];
//插入字符串时统计 对应数字前缀序列出现次数
//                并维护该数字前缀对应最大次数的字符串    查询时直接输出即可
map<string,int> mm;//每种数字序列出现次数
map<string,string>mm2;//每种序列对应的最大次数的字符串****
void insert_(char *str,int num)
{
   int len=strlen(str);
   int root=0;
   string strr="";
   string str2="";
   for(int i=0;i<len;i++)
   {
       int id=str[i]-'a';
       strr+=(belong[id]+'0');//将插入的字符串映射成数字序列
       str2+=str[i];//当前前缀
       if(!tree[root][id]) tree[root][id]=++tot;
       root=tree[root][id];
       sum[root]+=num;//统计每个前缀出现次数
       if(mm[strr]<sum[root])//更新map
       {
           mm[strr]=sum[root];
           mm2[strr]=str2;
       }
   }
   return ;
}
char ss[maxn];
void init()//数字与字母间的映射
{
    for(int i=0;i<25;i++)
    {
        if(i<18)
            belong[i]=2+i/3;
        else
            belong[i]=2+(i-1)/3;
    }
    belong[25]=9;
    return ;
}
int main()
{
    init();
    int cnt=1;
    int n,m,t,num;
    scanf("%d",&t);
    while(t--)
    {
        mm.clear();
        mm2.clear();
        scanf("%d",&n);
        while(n--)
        {
            scanf("%s%d",ss,&num);
            insert_(ss,num);
        }
        scanf("%d",&m);
        printf("Scenario #%d:\n",cnt++);
        while(m--)
        {
            scanf("%s",ss);
            string tmp="";
            int len=strlen(ss);
            for(int i=0;i<len-1;i++)
            {
                tmp+=ss[i];//对于每个前缀直接输出
                if(!mm2.count(tmp)) printf("MANUALLY\n");
                else printf("%s\n",mm2[tmp].c_str());
            }
            printf("\n");
        }
        for(int i=0;i<tot;i++)
        {
           sum[i]=0;
            for(int j=0;j<30;j++)
                tree[i][j]=0;
        }
        printf("\n");
    }
    return 0;
}
