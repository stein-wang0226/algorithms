#include <bits/stdc++.h>
#define LOCAL
using namespace std;
//c
//分析易知：转化为等差数列
//数据小暴力 遍历每个差值，看满足改差值的两点最多的差   组合数

int t,n;
double a[80],dis[80][80];
set<double>st;
int main(){
#ifdef LOCAL
    freopen("data.in","r",stdin);
    freopen("data.out","w",stdout);
#endif
cin>>t;
while(t--){
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    if(n==1||n==2){cout<<"0"<<endl;continue;}
    st.clear();
    for(int i=1;i<=n;i++){//遍历任意两点
        for(int j=i+1;j<=n;j++){
            double c=(a[j]-a[i])/(j-i);
            dis[i][j]=dis[j][i]=c;
            if(!st.count(c)){
                st.insert(c);
            }
        }
    }
    int MAX=0;//最大重复点数
   
    for(auto i:st){
       for( int j=1;j<=n;j++){//遍历每个点作定点
       int cnt=0;
            for(int k=1;k<=n&&k!=j;k++){
                if(dis[j][k]==i)cnt++;
            }
            MAX=max(cnt,MAX);
        } 
    }


    cout<<n-MAX-1<<endl;



}
    return 0;
}
