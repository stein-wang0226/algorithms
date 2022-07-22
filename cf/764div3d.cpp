#include <bits/stdc++.h>
#define LOCAL
using namespace std;
int t,n,k;
string s;
int main(){
#ifdef LOCAL
    freopen("data.in","r",stdin);
    freopen("data.out","w",stdout);
#endif
cin>>t;
while(t--){
    map<char,int >mp;
    mp.clear();
    cin>>n>>k;
    cin>>s;
    for(auto i:s){
        mp[i]++;
    }
    int cnt1=0,cnt2=0;// 落单数   偶数对数
    for(auto i:mp){
        cnt2+=(i.second/2);
        cnt1+=(i.second%2);   
         }

int n1=cnt2/k;//最大最小值的偶数对数
int ans=n1*2;
//差一点 :(
//剩余部分字母数大于=要分成的回文串数时，给最短回文串长度加1
//剩余--> 落单数+未用的成对数
if(cnt1+cnt2%k*2>=k)ans++;
cout<<ans<<endl;


}

    return 0;
}
