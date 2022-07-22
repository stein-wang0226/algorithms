#include <bits/stdc++.h>
#define LOCAL
using namespace std;
int T,n;
signed main(){
#ifdef LOCAL
    freopen("data.in","r",stdin);
    freopen("data.out","w",stdout);
#endif
cin>>T;
while(T--){
cin>>n;
string s;
cin>>s;
int cnt0=0;
for(int i=0;i<n;i++){
  if(s[i]=='0')cnt0++;
}
//   0个数为偶  bob胜
    //    否则  alice win
//
// prooof   :偶数个0原先已经回文 所以Alice先花钱 之后bob一定能维持string为回文   当0剩2个时bob再选择反正即可，这样就能保证比Alice少花2coin ，win
//    奇数个0，因为为回文所以 中间为0  alice 第一步将其变为1， 之后按偶数bob策略即可，保证比bob少花1元
if(cnt0==1){//特判
  cout<<"BOB"<<endl;
  continue;
}
if(cnt0%2==0){
  cout<<"BOB"<<endl;
}
else {
  cout<<"ALICE"<<endl;
}

}
    return 0;
}
