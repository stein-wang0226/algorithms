#include<bits/stdc++.h>
using namespace std;
//运用公式即可
int n,a;
int main(){
    cin>>n;
    while(n--){
        cin>>a;
        int ans=a;
        for(int i=2;i<=a/i;i++){
            if(a%i==0){
                ans=ans/i*(i-1);      //公式  注意写法  防止不整除
                while(a%i==0)a/=i;
            }
        }
        //  别漏了
        if(a>1)ans=ans/a*(a-1);
        cout<<ans<<endl;
    }
    return 0;
}