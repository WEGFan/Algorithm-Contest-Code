#include <iostream>
#include <cstring>
using namespace std;

const int INF = 0x3f3f3f3f;
const int MAXN = 110;

int cost[MAXN][MAXN]; // 耗费矩阵，标号从0开始，0~n-1

bool vis[MAXN];
int lowc[MAXN];

int Prim(int n)
{
    int ans = 0;
    memset(vis, false, sizeof(vis));
    vis[0] = true;
    for (int i = 1; i < n; i++)
        lowc[i] = cost[0][i];
    for (int i = 1; i < n; i++)
    {
        int minc = INF;
        int p = -1;
        for (int j = 0; j < n; j++)
            if (!vis[j] && minc > lowc[j])
            {
                minc = lowc[j];
                p = j;
            }
        if (minc == INF)
            return -1; // 原图不连通
        ans += minc;
        vis[p] = true;
        for (int j = 0; j < n; j++)
            if (!vis[j] && lowc[j] > cost[p][j])
                lowc[j] = cost[p][j];
    }
    return ans;
}

int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> cost[i][j];
        }
    }
    int q;
    cin >> q;
    while (q--)
    {
        int u, v;
        cin >> u >> v;
        cost[u - 1][v - 1] = cost[v - 1][u - 1] = 0;
    }
    cout << Prim(n) << endl;
    return 0;
}