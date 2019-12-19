#include <iostream>
#include <cstdio>

using namespace std;

#define lson (root << 1)
#define rson (root << 1 | 1)

const int N = 1e5 + 7;
const int maxdigit = 22;

long long arr[N];

struct SegTree
{
    int l, r;
    long long dig[maxdigit]; // 区间各位上有多少个1
    int lazyxor[maxdigit]; // 懒惰标记，为1向下异或
} tr[N << 2];

void pushup(int root)
{
    for (int i = 0; i < maxdigit; i++)
    {
        tr[root].dig[i] = tr[lson].dig[i] + tr[rson].dig[i];
    }
}

void pushdown(int root)
{
    for (int i = 0; i < maxdigit; i++)
    {
        if (tr[root].lazyxor[i])
        {
            tr[lson].dig[i] = (tr[lson].r - tr[lson].l + 1) - tr[lson].dig[i];
            tr[rson].dig[i] = (tr[rson].r - tr[rson].l + 1) - tr[rson].dig[i];
            tr[lson].lazyxor[i] ^= tr[root].lazyxor[i];
            tr[rson].lazyxor[i] ^= tr[root].lazyxor[i];
            tr[root].lazyxor[i] = 0;
        }
    }
}

void build(int root, int l, int r)
{
    tr[root].l = l, tr[root].r = r;
    if (l == r)
    {
        for (int i = 0; i < maxdigit; i++)
        {
            if (arr[l] & (1LL << i))
            {
                tr[root].dig[i]++;
            }
        }
        return;
    }
    int mid = (l + r) >> 1;
    build(lson, l, mid);
    build(rson, mid + 1, r);
    pushup(root);
}

void update(int root, int l, int r, long long val)
{
    if (l <= tr[root].l && r >= tr[root].r)
    {
        for (int i = 0; i < maxdigit; i++)
        {
            if (val & (1LL << i))
            {
                tr[root].dig[i] = (tr[root].r - tr[root].l + 1) - tr[root].dig[i];
                tr[root].lazyxor[i] ^= 1;
            }
        }
        return;
    }
    pushdown(root);
    int mid = (tr[root].l + tr[root].r) >> 1;
    if (l <= mid)
        update(lson, l, r, val);
    if (r > mid)
        update(rson, l, r, val);
    pushup(root);
}

long long query(int root, int l, int r)
{
    if (l <= tr[root].l && r >= tr[root].r)
    {
        long long tmp = 0;
        for (int i = 0; i < maxdigit; i++)
        {
            tmp += tr[root].dig[i] * (1LL << i);
        }
        return tmp;
    }
    pushdown(root);
    int mid = (tr[root].l + tr[root].r) >> 1;
    long long ans = 0;
    if (l <= mid)
        ans += query(lson, l, r);
    if (r > mid)
        ans += query(rson, l, r);
    return ans;
}

int main()
{
    int n, m;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
    {
        scanf("%lld", &arr[i]);
    }
    build(1, 1, n);
    scanf("%d", &m);
    while (m--)
    {
        int op, l, r;
        scanf("%d %d %d", &op, &l, &r);
        if (op == 2)
        {
            int val;
            scanf("%d", &val);
            update(1, l, r, val);
        }
        else
        {
            printf("%lld\n", query(1, l, r));
        }
    }
    return 0;
}