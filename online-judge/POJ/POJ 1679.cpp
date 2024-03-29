#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

const int MAXN = 110;
const int INF = 0x3f3f3f3f;

bool vis[MAXN];
int lowc[MAXN];
int pre[MAXN];
int Max[MAXN][MAXN];
int cost[MAXN][MAXN];
bool used[MAXN][MAXN];
int ans;

int Prim(int cost[][MAXN], int n)
{
    int ans = 0;
    memset(vis, false, sizeof(vis));
    memset(Max, 0, sizeof(Max));
    memset(used, false, sizeof(used));
    vis[0] = true;
    pre[0] = -1;
    for (int i = 1; i < n; i++)
    {
        lowc[i] = cost[0][i];
        pre[i] = 0;
    }
    lowc[0] = 0;
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
            return -1;
        ans += minc;
        vis[p] = true;
        used[p][pre[p]] = used[pre[p]][p] = true;
        for (int j = 0; j < n; j++)
        {
            if (vis[j])
                Max[j][p] = Max[p][j] = max(Max[j][pre[p]], lowc[p]);
            if (!vis[j] && lowc[j] > cost[p][j])
            {
                lowc[j] = cost[p][j];
                pre[j] = p;
            }
        }
    }
    return ans;
}

int secondprim(int cost[][MAXN], int n)
{
    int ans2 = INF;
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (cost[i][j] != INF && !used[i][j])
            {
                ans2 = min(ans2, ans + cost[i][j] - Max[i][j]);
            }
        }
    }
    if (ans2 == INF)
    {
        return -1;
    }
    else
    {
        return ans2;
    }
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, m;
        cin >> n >> m;
        memset(cost, INF, sizeof(cost));
        for (int i = 0; i < n; i++)
        {
            cost[i][i] = 0;
        }
        while (m--)
        {
            int u, v, w;
            cin >> u >> v >> w;
            cost[u - 1][v - 1] = cost[v - 1][u - 1] = w;
        }
        ans = Prim(cost, n);
        if (ans == secondprim(cost, n))
        {
            cout << "Not Unique!" << endl;
        }
        else
        {
            cout << ans << endl;
        }
    }
    return 0;
}