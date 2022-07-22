#include <bits/stdc++.h>
#define LOCAL
using namespace std;
//从前往后判断(保证尝试最多次)  考虑no的情况
//若到第i个数不能删   则前i-1个数可删(否则no,跳出) 
//且其2~i+1都整除，则no跳出，否则向后遍历
// 估计  只要判断到 min(20,i+1)即可   不可能前20都整除   20!
const int MAX=1e5+5;
int t,n,a[MAX];
int main(){
#ifdef LOCAL
    freopen("data.in","r",stdin);
    freopen("data.out","w",stdout);
#endif
cin>>t;
while(t--){
        cin>>n;
        int cnt=0;
        for(int i=1;i<=n;i++){
                cin>>a[i];
        }
        int flag=1;
        for(int i=1;i<=min(n,20);i++){//不可能前1~20都整除  第20个之后都可删 
                int flag1=0;
                for( int j=2;j<=i+1;j++){//
                        if(a[i]%(j)!=0){flag1=1;break;}//存在不能整除 可删
                }
                if(flag1==0){
                        flag=0;break;//no
                }

        }
        if(flag)cout<<"yes"<<endl;
        else cout<<"no"<<endl;
   

}
    return 0;
}
