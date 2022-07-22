#include <bits/stdc++.h>
#define LOCAL
using namespace std;
//   3要尽量多   发现1和2不会超过2个 (3个1可用1 2 取代 3个2可用1 2 3取代)暴力取最小即可 c1+c2*2+c3+3=maxx
int n,t,a[105];
int main(){
#ifdef LOCAL
    freopen("data.in","r",stdin);
    freopen("data.out","w",stdout);
#endif
cin>>t;
while(t--){
	cin>>n;
	int maxx=0;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		maxx=max(maxx,a[i]);
	}
int ans=0x3f3f3f3f;
		for(int n1=0;n1<=2;n1++){//表示maxx
			for(int n2=0;n2<=2;n2++){
				if((maxx-n1-n2*2)%3)continue;
				int n3=(maxx-n1-n2*2)/3;
				int num=n1+n2+n3;
			
				int flag1=1;//全能表示
				for(int i=1;i<=n;i++){
						int flag=0;
					for(int j=0;j<=n1;j++){//暴力尝试
						for(int k=0;k<=n2;k++){
							int left=a[i]-j-2*k;//剩余
							if(left>=0&&left%3==0&&left/3<=n3)flag=1;//能表示a[i]	
							if(flag)break;		
						}
						if(flag)break;
					}
					flag1&=flag;
					if(!flag1)break;
				}
				if(flag1)ans=min(ans,num);
			}
		}
	cout<<ans<<endl;





}
    return 0;
}
