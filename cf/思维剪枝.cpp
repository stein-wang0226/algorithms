#include <bits/stdc++.h>
#define LOCAL
//#define int long long
//如果直接求的话还是挺麻烦，但是我们观察题意，没有被打败的人一定能称为冠军，
//被打败的人一定不能称为冠军。因此我们假定第一个人是冠军，依次遍历，如果被打败了，
//就被将打败我们假定冠军的人假定为冠军，直到最后，第一轮遍历完，除了我们假定的冠军以外的选手都被打败过，
//我们只要再遍历一次，证明这个冠军是否是真的即可。
//先筛一轮 在验证

using namespace std;
const int N=5e5+5;
int T,n,r1[N],r2[N],r3[N],r4[N],r5[N];
int better(int a,int b){
  int res=0;
  if(r1[a]<r1[b])res++;
    if(r2[a]<r2[b])res++;
    if(r3[a]<r3[b])res++;
  if(r4[a]<r4[b])res++;
  if(r5[a]<r5[b])res++;
if(res>=3)return 1;
return 0;
}
signed main(){
#ifdef LOCAL
    freopen("data.in","r",stdin);
    freopen("data.out","w",stdout);
#endif
cin>>T;
while(T--){
cin>>n;
for(int i=1;i<=n;i++){
  cin>>r1[i]>>r2[i]>>r3[i]>>r4[i]>>r5[i];
}

int champ=1;
for(int i=2;i<=n;i++){
  if(better(i,champ))champ=i;
} 
int flag=1;
for(int i=1;i<=n;i++){
  if(i!=champ&&!better(champ,i)){
    flag=0;break;
  }
}
if(flag)cout<<champ<<endl;
else cout<<"-1"<<endl;
}
    return 0;
}
