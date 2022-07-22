# include <bits/stdc++.h>
using namespace std;
const int MAX = 50001;
struct Node
{
    int to;
    int next;
    int len;
}tree[MAX * 2];
int head[MAX], Len[MAX], node[MAX];
int tol = 0;
int Max = 0, jishu = 0;

void add(int a, int b, int len)
{
    tree[tol].to = b;
    tree[tol].next = head[a];
    tree[tol].len = len;
    head[a] = tol++;
}
void dfs(int root, int f)
{
    Len[root] = 0;
    node[root] = 1;
    for(int i = head[root]; i != -1; i = tree[i].next)
    {
        int son = tree[i].to;
        if(son == f)
            continue;
        dfs(son, root);

        int tep = Len[son] + tree[i].len;
        if(tep + Len[root] > Max)//最长边经过son
        {
            jishu = node[son] * node[root];
            Max = tep + Len[root];
        }
        else if(tep + Len[root] == Max)
            jishu += node[son] * node[root];

        if(Len[root] < tep)
        {
            Len[root] = tep;
            node[root] = node[son];
        }
        else if(Len[root] == tep)
            node[root] += node[son];
    }
}
int main()
{
    int n;
    while(scanf("%d", &n) != EOF)
    {
        tol = 0;
        memset(head, -1, sizeof(head));

        int a, b, len;
        for(int i = 1; i < n; i++)
        {
            scanf("%d%d%d", &a, &b, &len);
            add(a, b, len);
            add(b, a, len);
        }
        Max = 0, jishu = 0;
        dfs(1, -1);
        printf("%d %d\n", Max, jishu);
    }
    return 0;
}