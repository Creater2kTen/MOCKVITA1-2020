#include<bits/stdc++.h>
#define int long long
#define r0 return(0);
using namespace std;
int32_t main()
{
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int n;
    cin>>n;
    vector<vector<int>>mat(n,vector<int>(4));
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<3;j++)
        {
            cin>>mat[i][j];
        }
        mat[i][3]=((int)(pow((mat[i][0]*mat[i][0]+mat[i][1]*mat[i][1]),0.5)+0.5))/mat[i][2];
    }
    int count=0;
    for(int i=0;i<n;i++)
        for(int j=i+1;j<n;j++)
    {
        if(mat[i][3]==mat[j][3])
            count++;
    }
    cout<<count;
}
