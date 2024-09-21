// 旋转和拉伸是相对独立的   分别求前缀和即可

#include<bits/stdc++.h>

using namespace std;
int n,m;
const int N = 2e5+5;
double a[N],b[N];
double sum1[N],sum2[N];
int main(){
    cin>>n>>m;
    int op;double val;
    sum1[0]=1; //  
    for(int i=1;i<=n;i++){
        cin>>op>>val;
        if(op==1){
            a[i] = val;
            sum1[i] = sum1[i-1]*a[i];
            sum2[i] = sum2[i-1];
        }else{
            b[i] = val;
            sum2[i] = sum2[i-1]+b[i];
            sum1[i] = sum1[i-1];
        }
    }
    int ii,jj ;double x,y;
    for(int i=1;i<=m;i++){
        cin>>ii>>jj>>x>>y;
        double k = sum1[jj]/sum1[ii-1];
        double theta = sum2[jj] - sum2[ii-1];
        double xx = x*cos(theta) - y*sin(theta);
        double yy = x*sin(theta) + y*cos(theta);
        xx *=k ; yy*=k;
//        cout<<xx<<" "<<yy<<endl;
        printf("%.3lf %.3lf\n",xx,yy);
    }
//10 5
//2 0.59
//2 4.956
//1 0.997
//1 1.364
//1 1.242
//1 0.82
//2 2.824
//1 0.716
//2 0.178
//2 4.094
//1 1 1 1
//1 2 1 1
//4 7 -114758 522223
//1 9 -535079 601597
//8 8 159430 -511187




    return 0;
}
