#include <bits/stdc++.h>
#define LOCAL
using namespace std;
int t;
//统计不同单词数
//flag =1 结点数
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
       if(!tree[root][id]) tree[root][id]=++tot;//新子树 编号tot+1
       sum[tree[root][id]]++;//
       root=tree[root][id];
   }
   if(!flag[root]){flag[root]=1;ans++;}//未出现
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
    for(int i=0;i<=tot+5;i++)//?
    {
       flag[i]=false;
       sum[i]=0;
       for(int j=0;j<35;j++)
           tree[i][j]=0;
           
    }
   tot=0;
}

int main(){
std::ios::sync_with_stdio(false);
cin.tie(0); 
cout.tie(0);

#ifdef LOCAL
    freopen("data.in","r",stdin);
    freopen("data.out","w",stdout);
#endif
string s;
while(getline(cin,s)){
    if(s=="#"){
    break;
    }
    string s1="";
    for(int i=0;i<s.size();i++){//注意输入
        if(i>0&&s[i]==' '&&s[i-1]!=' '){insert_(s1);s1="";}//
        else if(s[i]!=' '){
            s1+=s[i];
            if(i==s.size()-1&&s1!=" ")insert_(s1);//最后也要
             }
    }
    cout<<ans<<endl;
    init();
} 
    return 0;
}
