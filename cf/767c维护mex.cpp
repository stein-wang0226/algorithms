#include <bits/stdc++.h>
#define LOCAL
using namespace std;
const int MAX = 2e5 + 5;
int t, n, cnt1[MAX], cnt2[MAX], a[MAX], ans[MAX];
//��2��Ͱһ��һ�� ������mex

int main() {
  std::ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  clock_t c1 = clock();
#ifdef LOCAL
  freopen("data.in", "r", stdin);
  freopen("data.out", "w", stdout);
#endif
  cin >> t;
  while (t--) {
    cin >> n;
    memset(cnt1, 0, sizeof cnt1);
    memset(cnt2, 0, sizeof cnt2);
    memset(a, 0, sizeof a);
    memset(ans, 0, sizeof ans);
    for (int i = 1; i <= n; i++) {
      cin >> a[i];
      cnt1[a[i]]++;
    }
    int len = 0;
    vector<int> vec;               //��ǰԪ�� �������cnt2
    int MEX = 0; 
    for (int i = 1; i <= n; i++) {  //��̬ά��
      vec.push_back(a[i]);
      cnt2[a[i]]++;  //��ǰ
      cnt1[a[i]]--;  //ʣ��
      while(cnt2[MEX])MEX++;//���MEX
      if (!cnt1[MEX]) {  //*****���ʣ��û��mex,����mex<=MEX,�ʲ���һ����
        ans[++len] = MEX;
        for (int j=0;j<vec.size();j++) {  //���Ͱ
          cnt2[j] = 0;
          MEX=0;//�Ż�  ֻ�е�һ�β�����������
        }
        vec.clear();
      }
    }
    cout << len << endl;
    for (int i = 1; i <= len; i++) cout << ans[i] << " ";
    cout << endl;
  }
  return 0;
}
