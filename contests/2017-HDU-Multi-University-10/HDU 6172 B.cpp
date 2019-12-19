#include <bits/stdc++.h>

using namespace std;

#define SZ(x) ((long long)(x).size())

typedef long long ll;

const ll mod = 1e9 + 7;

ll qpow(ll x, ll n)
{
    ll s = 1;
    while (n)
    {
        if (n & 1)
            s = s * x % mod;
        x = x * x % mod;
        n >>= 1;
    }
    return s;
}

namespace linear_seq
{

    const int N = 10010;
    ll res[N], base[N], _c[N], _md[N];
    vector<long long> Md;

    void mul(ll *a, ll *b, ll k)
    {
        for (int i = 0; i < k + k; i++)
            _c[i] = 0;
        for (int i = 0; i < k; i++)
            if (a[i])
                for (int j = 0; j < k; j++)
                    _c[i + j] = (_c[i + j] + a[i] * b[j]) % mod;
        for (ll i = k + k - 1; i >= k; i--)
            if (_c[i])
                for (int j = 0; j < SZ(Md); j++)
                    _c[i - k + Md[j]] = (_c[i - k + Md[j]] - _c[i] * _md[Md[j]]) % mod;
        for (int i = 0; i < k; i++)
            a[i] = _c[i];
    }

    ll solve(ll n, vector<ll> a, vector<ll> b)
    {
        ll ans = 0, pnt = 0, k = SZ(a);
        assert(SZ(a) == SZ(b));
        for (int i = 0; i < k; i++)
            _md[k - 1 - i] = -a[i];
        _md[k] = 1;
        Md.clear();
        for (int i = 0; i < k; i++)
            if (_md[i] != 0)
                Md.push_back(i);
        for (int i = 0; i < k; i++)
            res[i] = base[i] = 0;
        res[0] = 1;
        while ((1LL << pnt) <= n)
            pnt++;
        for (ll p = pnt; p >= 0; p--)
        {
            mul(res, res, k);
            if ((n >> p) & 1)
            {
                for (ll i = k - 1; i >= 0; i--)
                    res[i + 1] = res[i];
                res[0] = 0;
                for (int j = 0; j < SZ(Md); j++)
                    res[Md[j]] = (res[Md[j]] - res[k] * _md[Md[j]]) % mod;
            }
        }
        for (int i = 0; i < k; i++)
            ans = (ans + res[i] * b[i]) % mod;
        if (ans < 0)
            ans += mod;
        return ans;
    }

    vector<ll> BM(vector<ll> s)
    {
        vector<ll> C(1, 1), B(1, 1);
        ll L = 0, m = 1, b = 1;
        for (int n = 0; n < SZ(s); n++)
        {
            ll d = 0;
            for (int i = 0; i < L + 1; i++)
                d = (d + (ll)C[i] * s[n - i]) % mod;
            if (d == 0)
                ++m;
            else if (2 * L <= n)
            {
                vector<ll> T = C;
                ll c = mod - d * qpow(b, mod - 2) % mod;
                while (SZ(C) < SZ(B) + m)
                    C.push_back(0);
                for (int i = 0; i < SZ(B); i++)
                    C[i + m] = (C[i + m] + c * B[i]) % mod;
                L = n + 1 - L;
                B = T;
                b = d;
                m = 1;
            }
            else
            {
                ll c = mod - d * qpow(b, mod - 2) % mod;
                while (SZ(C) < SZ(B) + m)
                    C.push_back(0);
                for (int i = 0; i < SZ(B); i++)
                    C[i + m] = (C[i + m] + c * B[i]) % mod;
                ++m;
            }
        }
        return C;
    }

    ll gao(vector<ll> a, ll n)
    {
        vector<ll> c = BM(a);
        c.erase(c.begin());
        for (int i = 0; i < SZ(c); i++)
            c[i] = (mod - c[i]) % mod;
        return solve(n, c, vector<ll>(a.begin(), a.begin() + SZ(c)));
    }
};

long long t, n;

int main()
{
    vector<ll> seq{31, 197, 1255, 7997, 50959, 324725, 2069239};
    scanf("%lld", &t);
    while (t--)
    {
        scanf("%lld", &n);
        printf("%lld\n", linear_seq::gao(seq, n - 2) % mod);
    }
    return 0;
}