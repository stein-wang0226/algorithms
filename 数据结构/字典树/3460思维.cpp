#include <bits/stdc++.h>
#define LOCAL
using namespace std;
int t;
//首先我们把全部字符串用字典树保存。此时这棵树的每个节点都要打印，除了根（不包括字母），如今全部节点都要打印和删除。可是最后一个字符串不删除，该字符串肯定是最长的了。所以公式=res=2 * （n (节点数)） + m（打印次数） - maxlen(最长字符串)。
const int MAX =2e6+5;//如果是64MB可以开到2e6+5，尽量开大
int tree[MAX][30];//tree[i][j]表示节点i的第j个儿子的节点编号
int flag[MAX];//表示以该节点结尾是一个单词
int sum[MAX];
int tot=0;//总节点数
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
    for(int i=0;i<=tot+5;i++)//?
    {
       flag[i]=false;
       sum[i]=0;
       for(int j=0;j<30;j++)
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
int n;
while(cin>>n){
    int maxx=0;
for(int i=1;i<=n;i++){
    string s;
    cin>>s;
    int len=s.size();
    maxx=max(maxx,len);
    insert_(s);
   
}
int ret=2*tot+n-maxx;
cout<<ret<<endl;
 init();
} 
    return 0;
}
