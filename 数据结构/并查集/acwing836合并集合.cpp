#include <bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int pre[N];
int n,m;

int find(int x){
    while(x!=pre[x]){
        pre[x]=pre[pre[x]];
        x=pre[x];
    }
    return x;
}
int main(){
    cin>>n>>m;
    for(int i=1;i<=n;i++)pre[i]=i;
    string s;int a,b;
    for(int i=1;i<=m;i++){
    cin>>s>>a>>b;
    if(s=="M")pre[find(b)]=find(a);//b  连到a上
    else if(s=="Q"){
        if(find(a)==find(b))cout<<"Yes"<<endl;
        else cout<<"No"<<endl;
    }
    }
    
    
    
    
    return 0;
}