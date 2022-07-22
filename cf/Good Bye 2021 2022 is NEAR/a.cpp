#include <bits/stdc++.h>
#define LOCAL
using namespace std;
map<int ,int>mp;
int t,n,a[105];
int main(){
#ifdef LOCAL
    freopen("data.in","r",stdin);
    freopen("data.out","w",stdout);
#endif
cin>>t;
while(t--){
    cin>>n;
    mp.clear();
    for(int i=1;i<=n;i++){
        cin>>a[i];
        if(!mp.count(abs(a[i]))||a[i]==0)
            mp.insert(pair<int,int>{abs(a[i]),1});
        else mp[abs(a[i])]++;
    }
    int ans=0;
    for(auto i:mp){
        if(i.second>=2)ans+=2;
        else ans+=1;
    }
    cout<<ans<<endl;
}
    return 0;
}
