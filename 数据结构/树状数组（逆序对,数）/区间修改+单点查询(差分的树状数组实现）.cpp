#include <bits/stdc++.h>
#define LOCAL//由于本题是先修改最后按顺序查询 所以直接用普通数组差分实现区间修改之后按序维护输出前缀和更快(n>nlogn)  ,但如果边改变查或随机查询效率显然不如本方法
using namespace std;//nlog
//树状数组实现 单点查询 区间修改
//   用差分树状数组 d[]实现
//用差分数组将区间修改转化为单点修改   单点查询转化为求前缀和
//区间修改只需改端点的差分值
//  单点查询只需求d[i]的前缀和
//  d[0]=0,d[1]=a[1];d[i]==a[i]-a[i-1],
int n,d[100005];
int lowbit(int i){
    return i& -i;
}
void update(int i,int val){//树状数组单点修改，每次对差值更新   
    while(i<=n)d[i]+=val,i+=lowbit(i);
}
int sum(int i){//求树状数组前缀和***//求sum d[i]实现单点查询
    int ret =0;
    while(i>0){
    ret+=d[i];
    i-=lowbit(i);
    }
    return ret;
}
void  range_update(int l,int r,int x){//差分 实现区间修改
    update(l,x);update(r+1,-x);//
}

int main(){
#ifdef LOCAL
    freopen("data.in","r",stdin);
    freopen("data.out","w",stdout);
#endif
while(cin>>n,n){
    memset(d,0,sizeof d);
    for(int i=1;i<=n;i++){
        int a,b;
        cin>>a>>b;
        range_update(a,b,1);//区间修改
    }
    for(int i=1;i<=n;i++){
        cout<<sum(i);
        if(i!=n)cout<<" ";
    }
    cout<<endl;
}
    return 0;
}
