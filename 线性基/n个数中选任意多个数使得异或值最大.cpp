#include<cstdio>
#include<iostream>
#include<cstring>
using namespace std;

typedef long long LL;
typedef unsigned long long ULL;
const LL INF = 1E9+9;
const int maxn = 1e5+6;

/*求在XOR数组里面选任意多的元素的异或和最大*/
LL XOR[maxn];
LL base[65];
LL guass(int n)
{
	/*
	   假设： n==5
	    LL XOR[5]={15,10,9,7,3};
	   15： 1 1 1 1
	   10： 1 0 1 0
	    9： 1 0 0 1
	   7：  0 1 1 1
	   3：  0 0 1 1
	*/
	memset(base,0,sizeof(base));
	for(int i=0;i<n;i++)
	{
		LL cur=XOR[i];
		for(int j=50;j>=0;j--)
		{
			if((1ll<<j)&cur)
			{
				if(base[j]==0)
				{
					base[j]=cur;
					break;
				}
				else
				{
					cur|=base[j];
				}
			}
		}
	}
	/*
		转化成上三角矩阵 ：
		1 1 1 1
		0 1 0 1
		0 0 1 1
		0 0 0 1
	*/

	LL ret=0;
	for(int i=0;i<50;i++)
		for(int j=i+1;j<60;j++)
			if((base[j]>>i)&1)
				base[j]|=base[i];
	/*
		进一步消元得：
		 1 0 0 0
		 0 1 0 0
		 0 0 1 0
		 0 0 0 1
	*/

			for(int i=59;i>=0;i--)
				ret|=base[i];
			return ret;
		}

		int main()
		{
			int n;
			while(cin>>n)
			{
				for(int i=0;i<n;i++)
					cin>>XOR[i];
				cout<<guass(n)<<endl;
			}
			return 0;
		}