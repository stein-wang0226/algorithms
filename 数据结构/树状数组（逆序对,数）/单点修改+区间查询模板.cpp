#include <bits/stdc++.h>
#define LOCAL
using namespace std;//模板题 单点修改 + 区间查询
//动态维护树状数组 c[i]代表a[i]及之前共lowbit[i]个元素
int c[50005],n,t;
int lowbit(int x){
    return x& -x;
}
void update(int i,int val){//单点更新:每次加自身lowbit的元素改变
    while(i<=n){
        c[i]+=val;
        i+=lowbit(i);
    }
}//更新(从小到大)时查询(从大到小)的逆过程
int sum(int i){//求前缀和/
    int ret =0;
    while(i>0){
        ret+=c[i];
        i-=lowbit(i);
    }
    return ret;
}
int main(){
cin>>t;
int Case=0;
while(t--){
    memset(c,0,sizeof c);
    Case++;
printf("Case %d:\n",Case);
scanf("%d",&n);
for(int i=1;i<=n;i++){
    int val;
    scanf("%d",&val);
    update(i,val);
}
string s;
while(cin>>s){
    if(s=="End")break;
    int a,b;
    scanf("%d %d",&a,&b);
    int ans=0;
    if(s=="Query"){
        ans=sum(b)-sum(a-1);
       printf("%d\n",ans);
    }
    else if(s=="Sub"){
        update(a,-b);
    }
    else if(s=="Add"){
        update(a,b);
    }
}


}
    return 0;
}
