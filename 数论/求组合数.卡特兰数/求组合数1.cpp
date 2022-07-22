#include<bits/stdc++.h>
using namespace std;
//  a,b 范围小 询问多
 //  预处理所有的C
const int mod =1e9+7;
const int N=2005;
int n,a,b;
int c[2005][2005];

void init(){
    for(int i=0;i<N;i++)
    for(int j=0;j<=i;j++){
        if(!j) c[i][j]=1;//C(n,0)=1
        else c[i][j]=(c[i-1][j]+c[i-1][j-1])%mod;
    }
}

int main(){
    init();
    cin>>n;
    while(n--){
        cin>>a>>b;
        cout<<c[a][b]<<endl;
    }
    
    
    
    return 0;
}
