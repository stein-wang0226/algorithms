#include <bits/stdc++.h>
//我的解法   前缀和
#define LOCAL
using namespace std;
int t,n,a[200005],sum1[200005],sum2[200005];
int main(){
#ifdef LOCAL
    freopen("data.in","r",stdin);
    freopen("data.out","w",stdout);
#endif

  cin>>n;
  sum1[0]=0;
  sum2[1]=0;
  for(int i=1;i<=n;i++){
    cin>>a[i];
    if(i==1){
      sum1[i]=a[i];
    continue;
    }
    if(i%2){
     sum1[i]=sum1[i-2]+a[i]; 
     sum2[i]=sum2[i-1];
    }
    else {
      sum2[i]=sum2[i-2]+a[i];
      sum1[i]=sum1[i-1];
    }
  }
  int cnt=0;
  for(int i=1;i<=n;i++){
    int s1=sum1[i-1]+sum2[n]-sum2[i];//ji
    int s2=sum2[i-1]+sum1[n]-sum1[i];
    if(s1==s2)cnt++;
  }
  cout<<cnt<<endl;
    return 0;
}


//答案解法  类似之前768mex  先正序求总前缀和再从后往前减去，同时累计后缀和 判断  计案  
#include <bits/stdc++.h>

using namespace std;

int main() {
#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
#endif

	int n;
	cin >> n;
	
	vector<int> a(n);
	
	int ePref = 0, oPref = 0, eSuf = 0, oSuf = 0;
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
		if (i & 1) eSuf += a[i];
		else oSuf += a[i];
	}
	
	int ans = 0;
	for (int i = 0; i < n; ++i) {
		if (i & 1) eSuf -= a[i];
		else oSuf -= a[i];
		if (ePref + oSuf == oPref + eSuf) {
			++ans;
		}
		if (i & 1) ePref += a[i];
		else oPref += a[i];
	}
	
	cout << ans << endl;
	
	return 0;
}