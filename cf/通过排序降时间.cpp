#include <bits/stdc++.h>
using namespace std;
//先将a记录下标，排序 巧妙降复杂度位O(n)
const int N=1e5+10;
typedef pair<int,int> p;
int b[N];
p a[N];
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,ans=0x3f3f3f3f;
        cin>>n;
        for(int i=1;i<=n;i++)cin>>a[i].first,a[i].second=i;
        for(int i=1;i<=n;i++)cin>>b[i];
        sort(a+1,a+n+1);
        for(int i=1,j=1;i<=n;i++)
        {
            while(a[i].first>=b[j])j++;//由于a[]数组为升序排序,所以
            //如果此时b[j]>a[i]的话，那么b[j]之前的数一定无法和a[i]之后
            //的数进行匹配，所以这里就不用再重新从j=1开始j++了。*****
            ans=min(ans,a[i].second+j-2);
        }
        cout<<ans<<endl;
    }
}