#include<bits/stdc++.h>
using namespace std;
//运用公式即可
int n;
int main(){
        cin>>n;
        int ans=n;
        for(int i=2;i<=n/i;i++){
            if(n%i==0){
                ans=ans/i*(i-1);      //公式  注意写法  防止不整除
                while(n%i==0)n/=i;
            }
        }
        //  别漏了
        if(n>1)ans=ans/n*(n-1);
        cout<<ans<<endl;
    return 0;
}
