#include <iostream>

using namespace std;

const int N = 100010;
//   i j
//   1 2
int q[N];

void quick_sort(int q[], int l, int r)
{
    if (l >= r) return;

    int i = l , j = r , x = q[l + r >> 1];
    while (i < j)
    {
        while (q[i] < x)  i ++ ;
        while (q[j] > x) j -- ;
        if (i < j) swap(q[i], q[j]);
    }

    quick_sort(q, l, i-1);
    quick_sort(q, j + 1, r);
}

int main()
{
    int n;
    scanf("%d", &n);

    for (int i = 0; i < n; i ++ ) scanf("%d", &q[i]);

    quick_sort(q, 0, n - 1);

    for (int i = 0; i < n; i ++ ) printf("%d ", q[i]);

    return 0;
}

