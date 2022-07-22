#include <iostream>
#include <cstring>
#include <map>
#include <string>
#define MAXN 510
using namespace std;
int mm[MAXN][MAXN], gg[MAXN][MAXN], p[MAXN];  // p[i]表示第i个boy已表白人数
// mm[i][j]表示第i个girl对编号为j的boy的好感排位，gg[i][j]表示第i个boy第j喜欢的girl编号，注意意义不同
int gg_match[MAXN], mm_match[MAXN];  // gg_match[i]表示第i个boy已匹配的girl编号
string ss[MAXN*2], str;   // ss[i]表示编号为i的name
map<string, int> mp_mm, mp_gg;  // name映射编号

int main() {
    int n;
    while (cin >> n) {
        mp_gg.clear(); mp_mm.clear();
        int cnt = 0;  // 按照girl出现次序给予编号
        for (int i = 1; i <= n; i++) {
            cin >> ss[i];
            mp_gg[ss[i]] = i;
            for (int j = 1; j <= n; j++) {
                cin >> str;
                if (mp_mm[str] == 0) {
                    mp_mm[str] = ++cnt;
                    ss[n+cnt] = str;
                }
                gg[i][j] = mp_mm[str];
            }
        }
        for (int i = 1; i <= n; i++) {
            cin >> str;
            int a = mp_mm[str];
            for (int j = 1; j <= n; j++) {
                cin >> str;
                int b = mp_gg[str];
                mm[a][b] = j;
            }
        }
        bool flag = true;  // 此处开始为算法核心代码，前面只是将字符串关系处理为编号关系
        for (int i = 1; i <= n; i++) p[i] = 1;
        memset(mm_match, -1, sizeof(mm_match));
        memset(gg_match, -1, sizeof(gg_match));
        while (flag) {
            flag = false;
            for (int i = 1; i <= n; i++) {
                if (gg_match[i] == -1 && p[i] <= n) {
                    int a = gg[i][p[i]++];
                    if (mm_match[a] == -1) mm_match[a] = i, gg_match[i] = a;
                    else if (mm[a][i] < mm[a][mm_match[a]]) {
                        gg_match[i] = a;
                        gg_match[mm_match[a]] = -1;
                        mm_match[a] = i;
                    }
                    flag = true;
                }
            }  // end for
        } // end while
        for (int i = 1; i <= n; i++) cout << ss[i] << ' ' << ss[gg_match[i]+n] << endl;
    }
    return 0;
}