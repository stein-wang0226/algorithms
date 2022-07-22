#include <stdio.h>
#include <string.h>

int v[1005], a[1005], n;//v标记
void dfs(int c) {
	if (c == n) {
		for (int i = 0; i < n; i++)
			printf("%d", a[i]);
		printf("\n");
	} else {
		for (int i = 1; i <= n; i++) {//使ai 向后遍历i到n
			if (!v[i]) {//对未标记的进行处理 ，从第一个未标记的i进入，前i-1项已标记从小到大
				v[i] = 1;
				a[c] = i;//找到第一个未标记的将i填入
				dfs(c + 1);
				v[i] = 0;//还原回溯 ,(第一次dfs（3）中i=4， v4=0，下一个循环使a【3】=5（下标从零开始）
			}//回溯并进行下一循环，按序实现全排列
		}
	}
}
int main() {
	while (scanf("%d",&n) != EOF) {
		memset(v, 0, sizeof(v));
		memset(a, 0, sizeof(a));
		dfs(0);
	}
	return 0;
}

