#include <bits/stdc++.h>
#define LOCAL
using namespace std;
int t;
//不存在前缀
//对于字符串比较多的要统计个数的，map被卡的情况下，直接用字典树
//很多题都是要用到节点下标来表示某个字符串
const int MAX =2e6+5;//如果是64MB可以开到2e6+5，尽量开大
int tree[MAX][30];//tree[i][j]表示节点i的第j个儿子的节点编号
int flag[MAX];//表示以该节点结尾是一个单词
int sum[MAX];
int tot=0;//总节点数
int ans=0;
void insert_(string s)
{
   int  len=s.size();
   int root=0;
   for(int i=0;i<len;i++)
   {
       int id=s[i]-'0';
       if(flag[root]==1)ans=1;//出现前缀
       if(!tree[root][id]) tree[root][id]=++tot;//新子树 编号tot+1
       sum[tree[root][id]]++;//
       root=tree[root][id];
   }
   flag[root]=1;//结尾
}
int  find_(string s)//查询操作，按具体要求改动
{
    int len=s.size();
    int root=0;
    for(int i=0;i<len;i++)
    {
        int id=s[i]-'0';
        if(!tree[root][id]) return 0;
        root=tree[root][id];
    }
    return sum[root];////返回当前字符串结尾节点的访问次数，也就是作为前缀的出现次数
}
void init()//最后清空，节省时间
{
    ans=0;  
    for(int i=0;i<=tot;i++)
    {
       flag[i]=false;
       sum[i]=0;
       for(int j=0;j<10;j++)
           tree[i][j]=0;
           
    }
   tot=0;
}

int main(){
#ifdef LOCAL
    freopen("data.in","r",stdin);
    freopen("data.out","w",stdout);
#endif
int n;
cin>>t;
while(t--){
string s;
cin>>n;
for(int i=1;i<=n;i++){
cin>>s;insert_(s);
}
if(find_(s)>1)ans=1;//当前字符串结尾节点的访问次数，也就是作为前缀的出现次数>1
if(ans)cout<<"NO"<<endl;
else cout<<"YES"<<endl;
init();
} 

    return 0;
}
