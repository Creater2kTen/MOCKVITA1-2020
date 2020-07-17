#include <iostream>
#include <set>
#include <math.h>
#include <vector>
using namespace std;
int main()
{
    int n;
    int p1, p2;
    long rev;
    int y;
    cin >> n >> p1 >> p2 >> rev;
    int arr[53] = {0};
    for (int i = 1; i <= 12; i = i + 2) //odd month
        for (int j = 1; j <= 31; j++)
        {
            y = int(pow(6 - i, 2) + 0.5) + abs(j - 15);
            arr[y]++;
        }
    for (int i = 4; i <= 12; i = i + 2) //even month
        for (int j = 1; j <= 30; j++)
        {
            y = int(pow(6 - i, 2) + 0.5) + abs(j - 15);
            arr[y]++;
        }
    for (int i = 1; i <= 28; i++) //feb month
    {
        y = 16 + abs(i - 15);
        arr[y]++;
    }
    int l = 0, h = n;
    int sum = 0;
    set<int, less<int>> s1;
    while (l <= h)
    {
        int mid = (l + h) / 2;
        sum = 0;
        for (int i = 0; i < 53; i++)
        {
            sum += min(i, mid) * arr[i] * p1 + (mid - min(i, mid)) * arr[i] * p2;
        }
        if (sum >= rev)
        {
            s1.insert(mid);
            h = mid - 1;
        }

        else
            l = mid + 1;
    }
    if (s1.size() == 0)
        cout << n;
    else
    {
        auto i = s1.begin();
        cout << *i << endl;
    }
    return 0;
}
