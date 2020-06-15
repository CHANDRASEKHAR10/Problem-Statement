#include<bits/stdc++.h>
#define pb push_back
#define mp make_pair
using namespace std;
int N;
bool isvalid(int i,int j)
{
    if(i>=0 && i<N && j>=0 && j<N)
        return true;
    return false;
}
int deadly_spread(vector<vector<int>>& grid)
{
    int count=0;
    queue<pair<pair<int,int>,int>> q;
    for(int i=0;i<N;i++)
    {
        for(int j=0;j<N;j++)
        {
            if(grid[i][j]==2)
                q.push(mp(mp(i,j),0));
        }
    }
    while(!q.empty())
    {
        int a=q.front().first.first;
        int b=q.front().first.second;
        int days=q.front().second;
        count=days;
        if(isvalid(a+1,b) && grid[a+1][b]==1)
        {
            q.push(mp(mp(a+1,b),days+1));
            grid[a+1][b]=2;
        }
        if(isvalid(a-1,b) && grid[a-1][b]==1)
        {
            q.push(mp(mp(a-1,b),days+1));
            grid[a-1][b]=2;
        }
        if(isvalid(a,b+1) && grid[a][b+1]==1)
        {
            q.push(mp(mp(a,b+1),days+1));
            grid[a][b+1]=2;
        }
        if(isvalid(a,b-1) && grid[a][b-1]==1)
        {
            q.push(mp(mp(a,b-1),days+1));
            grid[a][b-1]=2;
        }
        q.pop();
    }
    for(int i=0;i<N;i++)
    {
        for(int j=0;j<N;j++)
        {
            if(grid[i][j]==1)
                return -1;
        }
    }
    return count;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin>>N;
    vector<vector<int>> grid(N,vector<int>(N));
    for(int i=0;i<N;i++)
    {
        for(int j=0;j<N;j++)
            cin>>grid[i][j];
    }
    cout<<deadly_spread(grid);
    return 0;
}