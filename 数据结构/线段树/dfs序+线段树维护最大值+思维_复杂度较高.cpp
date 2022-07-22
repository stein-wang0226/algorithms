#include <bits/stdc++.h>
#define LOCAL
using namespace std;//dfs序将树转化为线性区间-->in[x] ~out[x] 之间都为x子节点
// 题意：一家公司公司有n-1个员工和一个老板，老板的编号是0，员工是1-n，每个员工都有忠诚度和能力值
//去一个人，现在就需要从这个员工的下属里这出一个人来顶替他，顶替的员工要满足能力值不小于辞去的员工，
//有多个员工满足要求，输出这些员工里忠诚度最大的员工的编号，没有满足输出-1。

//按 能力sort 后 再插入插入能力强的，再插入能力弱的。那么，前面的在查询的时候就不会查询到能力比自己弱的了
//  预处理：1.同时记录一个人的能力，忠诚度和编号。由于用线段树维护的是loyalty，那么最后询问出来的肯定也是loyalty的值，所以用map对loyalty和编号id进行一一映射（loyalty唯一，所以才能有一一映射的关系）。   2.将一棵树映射为一个线性序列，分别用两个数组去记录每个节点进去的时间和出去的时间。用深度优先搜索，有那么一点像线序遍历。3.按照能力值进行排序。
// 4.按能力值从大到小一一批量处理，能力相同的为同一批。将答案存入一个数组当中。最后以O（1）的复杂度进行询问。
//**(按能力)插入一个就更新一次  得到所有答案  
const int MAX=50010;
int cnt;
int t,m,n,ans[MAX],in[MAX],out[MAX],head[MAX],tot;
struct node{
    int loy,abl,id;
    bool operator<(const node &b)const{//
        return abl>b.abl;
    }
}node[MAX];

struct Edge{
    int to,next;
}edge[MAX];//链式前相信 存图

void add (int u,int v){
    edge[cnt].to=v;
    edge[cnt].next=head[u];
    head[u]=cnt++;
}

void dfs(int rt){//链式前相信的dfs   生成dfs序--***
    in[rt]=tot++;//入栈位置
    for(int i=head[rt];i!=-1;i=edge[i].next){//图的遍历
        dfs(edge[i].to);
    }
    out[rt]=tot;//（等价）出栈位置
}

map<int ,int>mp;//建立 id与loy的映射()

struct segtreenode{
    int maxx;//维护忠诚度
}segtree[MAX<<2];//线树

void build(int l,int r,int rt){
    segtree[rt].maxx=-1;//初始化为-1，表示未更新
    if(l==r)return ;
    int mid=(l+r)>>1;
    build(l,mid,rt<<1);
    build(mid+1,r,rt<<1|1);
    //此处无需pushup求和
}
void update(int t,int c,int l,int r,int rt){
    if(l==r){
        segtree[rt].maxx=c;
        return;
    }
    int mid =(l+r)/2;
    if(t<=mid)  update(t,c,l,mid,rt<<1);
    else  update(t,c,mid+1,r,rt<<1|1);
    segtree[rt].maxx=max(segtree[rt<<1].maxx,segtree[rt<<1|1].maxx);

}
int querymax(int L,int R,int l,int r,int rt){
    if(L<=l&&r<=R)
    return segtree[rt].maxx;

    if(L>r||R<l) return -1;

    int mid=(l+r)/2;
    return max(querymax(L,R,l,mid,rt<<1),querymax(L,R,mid+1,r,rt<<1|1));
}

void init(){
    mp.clear();
    mp[-1]=-1;//未更新
    tot=cnt=0;
    memset(head,-1,sizeof head);//
    memset(in,0,sizeof in);
    memset(out,0,sizeof out);
    memset(ans,-1,sizeof ans);
}
int main(){
#ifdef LOCAL
    freopen("data.in","r",stdin);
    freopen("data.out","w",stdout);
#endif
cin>>t;
while(t--){
    cin>>n>>m;
    init();
    int u;//父节点
    for(int i=1;i<n;i++){//n-1 个员工编号
        cin>>u>>node[i].loy>>node[i].abl;
        add(u,i);//建图
        mp[node[i].loy]=i;//建立映射
        node[i].id=i;
    }
    dfs(0);//根节点从0开始
    build(0,tot-1,1);//下标从0开始，线段树节点编号从1开始
    sort(node+1,node+n);//注意区间长度
    //排序后按序更新
     for(int i=1,j;i<n;i=j)//****能力从大到小 能力相同的为同一批
        {
            j=i;
            while(j<n&&node[i].abl==node[j].abl)//能力相同
            {
                int id=node[j].id;
                int loy=querymax(in[id]+1,out[id]-1,0,n-1,1);//查询当前(只插入比他能力值大的结点)该节点子树的loy max值
                if(loy!=-1)
                    ans[id]=mp[loy];
                else
                    ans[id]=-1;
                j++;
            }
            j=i;
            while(j<n&&node[i].abl==node[j].abl)
            {
                int id=node[j].id;
                update(in[id],node[j].loy,0,n-1,1);
                j++;
            }
        }
        while(m--)
        {  int x;
            scanf("%d",&x);
            printf("%d\n",ans[x]);
        }
}
    return 0;
}
