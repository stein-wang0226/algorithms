#include<bits/stdc++.h>
#define ll long long
using namespace std;
//dp ����ʱ
//˼·��ÿһ���³�����֮ǰĳ����*2/*5/*7/*3 ,����ÿ�� ��¼֮ǰĳ��*2��3 5 7�������λ�ã�
//�³����ض�Ϊ��Ӧ���λ��+1 *��Ӧֵ��2 3 5 7���Ľ�С�ߣ��ҵ���������λ�ã�+1��
ll a[6000];
int main () {
	a[1]=1;
	int n,k1=1,k2=1,k3=1,k4=1;
	for(int i=2; i<= 5842; i++) {//�ȴ������г������Ա����
		a[i]=min(a[k1]*2,min(a[k2]*3,min(a[k3]*5,a[k4]*7)));
		if(a[i]==a[k1]*2)k1++;//eg.��ǰ�������ɵ�k1 ������*2����������³��������ɵ�k1+1 λ*2������
		if(a[i]==a[k2]*3)k2++;
		if(a[i]==a[k3]*5)k3++;
		if(a[i]==a[k4]*7)k4++;
	}
	while(~scanf("%d",&n)&&n) {
		if(n%10==1&&n % 100!=11)printf("The %dst humble number is %lld.\n",n,a[n]);
		else if(n%10==2&&n % 100!=12)printf("The %dnd humble number is %lld.\n",n,a[n]);
		else if(n%10==3&&n % 100!=13)printf("The %drd humble number is %lld.\n",n,a[n]);
		else
			printf("The %dth humble number is %lld.\n",n,a[n]);
	}
	return 0;
}
