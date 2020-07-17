#include <bits/stdc++.h>
#define r0 return (0);
using namespace std;
int prime_check(int val)
{

    //prime check
    int flag = 0;
    for (int i = 2; i <= val / 2; i++)
    {
        if (val % i == 0)
        {
            flag = 1;
            break;
        }
    }
    if (flag == 0)
        return val;
    else
    {
        return -1;
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n1, n2;
    cin >> n1 >> n2;
    int prime[n2 - n1] = {0};
    int flag = 0;
    int count = 0;
    for (int i = n1; i != n2; i++)
    {
        flag = 0;
        if (i == 1 || i == 0)
            continue;
        for (int j = 2; j <= i / 2; j++)
        {
            if (i % j == 0)
            {
                flag = 1;
                break;
            }
        }
        if (flag == 0)
        {
            prime[count++] = i;
        }
    }
    //find min_val for prime
    int min_val = -1;
    int max_val = -1;
    set<int, less<int>> s1;
    for (int i = 0; i < count; i++)
    {
        int flag = 1;
        for (int j = 0; j < count; j++)
        {
            if (i != j)
            {
                int e = prime[i];
                int f = prime[j];

                string a = to_string(e);
                string b = to_string(f);
                string c = a + b;
                int val = stoi(c);
                s1.insert(prime_check(val));
            }
        }
    }
    // prime check for max_val
    for (int i = count - 1; i >= 0; i--)
    {
        int flag = 1;
        for (int j = count - 1; j >= 0; j--)
        {
            if (i != j)
            {
                int e = prime[i];
                int f = prime[j];
                string a = to_string(e);
                string b = to_string(f);
                string c = a + b;
                int val = stoi(c);
                s1.insert(prime_check(val));
            }
        }
    }
    s1.erase(-1);
    auto it = s1.begin();
    long long  a = *it;
    auto ip = s1.rbegin();
    long long  b = *ip;
    int size = s1.size() - 2;
    long long  fin;
    while (size--)
    {
        fin = a + b;
        a = b;
        b = fin;
    }
    cout << fin;
}
