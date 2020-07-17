/**
 * @author Creater2k10
 * @create date 2020-06-21 15:23:07
 * @modify date 2020-06-21 15:23:07
 */

#include <bits/stdc++.h>
#define int long long
#define r0 return (0);
#define mod 1000000007
using namespace std;
int combi(int n, int r)
{
    int num = 1, dem = 1;
    for (int i = 1; i <= r; i++)
    {
        num *= n--;
        dem *= i;
    }
    return (num / dem);
}
int mulinv(int q)
{
    q = q % mod;
    for (int i = 1; i < mod; i++)
    {
        if ((i * mod + 1) % q == 0)
            return ((i * mod + 1) / q);
    }
}
int32_t main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        int n, t, m;
        cin >> n >> t >> m;
        int fail = combi(n - m, t);
        int total = combi(n, t);
        int a = total - fail;
        int b = total;
        if (__gcd(p, q) != 1)
        {
            p = a / __gcd(a, b);
            q = b / __gcd(a, b); 
        }
        cout << p;
        cout << q;
        cout << (p * (mulinv(q))) % mod;
    }
}
//end
