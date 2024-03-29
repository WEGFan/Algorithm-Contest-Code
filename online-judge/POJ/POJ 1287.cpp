#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

const int MAXN = 110; //最大点数
const int MAXM = 10007; //最大边数
int F[MAXN]; //并查集使用

struct Edge
{
    int u, v, w;
} edge[MAXM]; //存储边的信息，包括起点/终点/权值

int tol; //边数，加边前赋值为0

void addedge(int u, int v, int w)
{
    edge[tol].u = u;
    edge[tol].v = v;
    edge[tol++].w = w;
}

bool cmp(const Edge &a, const Edge &b)
{
    return a.w < b.w;
}

int find(int x)
{
    if (F[x] == -1)
        return x;
    else
        return F[x] = find(F[x]);
}

int Kruskal(int n) //传入点数，返回最小生成树的权值，如果不连通返回-1
{
    memset(F, -1, sizeof(F));
    sort(edge, edge + tol, cmp);
    int cnt = 0; //计算加入的边数
    int ans = 0;
    for (int i = 0; i < tol; i++)
    {
        int u = edge[i].u;
        int v = edge[i].v;
        int w = edge[i].w;
        int t1 = find(u);
        int t2 = find(v);
        if (t1 != t2)
        {
            ans += w;
            F[t1] = t2;
            cnt++;
        }
        if (cnt == n - 1)
            break;
    }
    if (cnt < n - 1)
        return -1; //不连通
    else
        return ans;
}

int main()
{
    int n;
    while (cin >> n && n)
    {
        tol = 0;
        int m;
        cin >> m;
        for (int i = 1; i <= m; i++)
        {
            int u, v, w;
            cin >> u >> v >> w;
            addedge(u, v, w);
        }
        cout << Kruskal(n) << endl;
    }
    return 0;
}