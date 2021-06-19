#include <bits/stdc++.h>
#include<vector>
using namespace std;

int minipath[100],tempPath[100];
void minimal_cost(int graph[100][100],vector<bool> &marked,int city,int n,int count,int cost,int &travel)
{
    int i;
    for(i=0;i<n;i++)
    {
        if(!marked[i]&&graph[city][i])
        {
            marked[i]=true;
            tempPath[count]=i;
            minimal_cost(graph,marked,i,n,count+1,cost+graph[city][i],travel);
            marked[i]=false;
        }
    }
    if(count==n && graph[city][0])
    {
        if(travel>cost+graph[city][0])
        {
            for(i=0;i<n;i++)
            {
                minipath[i]=tempPath[i];
            }
        }
        travel=min(travel,cost+graph[city][0]);
    }

}

int main()
{
    int i,j,n,graph[100][100];
    cout<<"Enter number of cities: ";
    cin>>n;
    cout<<"\nEnter the cost matrix "<<endl;
    for(i=0; i<n; i++)
    {
        cout<<"\nEnter elements of row "<<i+1<<" : "<<endl;
        for(j=0; j<n; j++)
        {
            cin>>graph[i][j];
        }
    }
    cout<<"\n\nThe cost list is:"<<endl;
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
            cout<<"   "<<graph[i][j];

        cout<<endl;
    }
    vector<bool>marked(n);
    for(i=0;i<n;i++)
    {
    marked[i]=false;
    }
    marked[0]=true;
    int travel=INT_MAX;
    tempPath[0]=0;
    minimal_cost(graph,marked,0,n,1,0,travel);
    cout<<"\nThe Path is: \n";
    for(int i=0; i<n; i++)
    {
        cout<<minipath[i]+1<<" --> ";
    }
    cout<<"1";
    cout<<endl;
    cout <<"\nMinimum cost is "<<travel<<"   \n";
    cout<<endl;
    return 0;
}
    /*
    4
    0 4 1 3
    4 0 2 1
    1 2 0 5
    3 1 5 0
    */
/*
5
0 2 0 12 5
2 0 4 8 0
0 4 0 3 3
12 8 3 0 10
5 0 3 10 0
*/


