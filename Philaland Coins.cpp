#include <bits/stdc++.h>
#define int long long
#define r0 return (0);
using namespace std;
int32_t main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        int price;
        cin >> price;
        int count=0;
        while(price>=1)
        {
            price=price/2;
            count++;
        }
        cout<<count<<endl;
    }
}
