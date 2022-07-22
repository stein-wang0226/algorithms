/*1���޻���(����ͼ->��Ψһ)
2�����˸������е����Ϊ1�������Ϊ0��
3������ṹֻ��һ��������Ȼ��ɭ���ˡ���ע���������Ҳ������
*/
#include <bits/stdc++.h>
using namespace std;
const int MAX = 1e6 + 10;
int a, b,cnt=0;
int pre[MAX];  ///���鼯��¼���׽ڵ�
int in[MAX];   ///���
int vis[MAX];  ///�ڵ��Ƿ����
void init() {
  for (int i = 1; i <= MAX; i++) {
    pre[i] = i;
  }
}
int find_r(int x) {  //Ѱ�Ҹ��ڵ�
  while (pre[x] != x) {
    x = pre[x];
  }
  return x;
}
void merge(int x, int y) {
  int root_x = find_r(x);
  int root_y = find_r(y);
  if (root_x != root_y) {
    pre[root_x] = root_y;
  }
}
int main() {
  while (1) {
    int flag = 1;
    cnt++;
    memset(vis, 0, sizeof vis);
    memset(in, 0, sizeof in);
    init();
    int Flag=1;
    while (~scanf("%d %d", &a, &b) && a && b)  //ÿ�ζ���00Ϊֹ
    {
      if (a < 0 || b < 0) return 0;  // a��bΪ����ʱ����������
	  vis[a] = 1;
      vis[b] = 1;
      in[b]++;
      merge(a, b);  //
    }
    int cnt1 = 0, cnt2 = 0;  //����  ������
    for (int i = 1; i <= MAX; i++) {
      if (vis[i] && in[i] == 0) cnt1++;  //����
      if (vis[i] && find_r(i) == i) cnt2++;
      if (in[i] >= 2)  ///�����ڵ��⣬�����������Ϊ1
      {
        flag = 0;
      }
    }
    if (!(cnt1 == 1 && cnt2 == 1) )flag = 0;
    if (flag)
     printf("Case %d is a tree.\n",cnt);
    else
    printf("Case %d is not a tree.\n",cnt);
  }
  return 0;
}
