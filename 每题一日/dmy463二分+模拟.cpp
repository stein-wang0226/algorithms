#include <bits/stdc++.h>
#define LOCAL
#define int long long
// 二分后模拟
// 二分查k份一共打了几(整)轮 (每个人对k的贡献易得)
//模拟第k+1轮即可
using namespace std;
const int N=1e5+5;
int T,n,k;
int a[N];

int check(int x){
    int sum=0;
    for(int i=1;i<=n;i++){
        if(a[i]>x)sum +=x;   // 大于轮数则加轮数
        else  sum+=a[i];    // 小于则加
    }
    return k>=sum;
}
signed main(){
#ifdef LOCAL
    freopen("data.in","r",stdin);
    freopen("data.out","w",stdout);
#endif
cin>>n>>k;
int S=0;
for(int i=1;i<=n;i++){
cin>>a[i];S+=a[i];
}
if(S<k){
    cout<<"-1"<<endl;
    return 0;
}

int l=0,r=1e9;
while(l<r){//  最多打满几轮
    int mid=(l+r+1)>>1;
    if(check(mid))//能打满mid轮
        l=mid;
    else 
        r=mid-1;
}
// l轮后剩下的
int cnt=0;// 
int last=k;

for(int i=1;i<=n;i++)
{
    if(a[i]>l)cnt++,last-=l;
    else last-=a[i];
}
queue<int>que;//队列模拟
for(int i=1;i<=n;i++){
    if(a[i]>l)que.push(i); // 打完后还在
}
for(int i=1;i<=last;i++){//剩下打完
    int k=que.front();
    que.pop();
    if(a[k]>l+1)que.push(k);
}
vector<int>ans;
while(que.size()){
    int tt=que.front();
    ans.push_back(tt);
    que.pop();
}
for(auto i:ans){
    cout<<i<<" ";
}
cout<<endl;


    return 0;
}
