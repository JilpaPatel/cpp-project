#include<iostream>
#include<queue>
using namespace std;

int adj[10][10];
int visited[10];
int n;

void DFS(int v)
{
    cout<<v<<" ";
    visited[v] = 1;
    
    for(int i=0; i<n; i++)
    {
        if(adj[v][i]==1 && visited[i]==0)
        {
            DFS(i);
        }
    }
}

void BFS(int v)
{
    queue<int> q;
    visited[v] = 1;
    q.push(v);
    
    while(!q.empty())
    {
        int t = q.front();
        q.pop();
        cout<<t<<" ";
        
        for(int i=0; i<n; i++)
        {
            if(adj[t][i]==1 && visited[i]==0)
            {
                visited[i] = 1;
                q.push(i);
            }
        }
    }
}

int main()
{
    int i, j, start;
    
    cout<<"Enetr the number of verticies : "<<endl;
    cin>>n;
    
    cout<<"Enetr the adjecent metrix : "<<endl;
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
            cin>>adj[i][j];
        }
    }
    
    cout<<"Enetr the starting verticies : "<<endl;
    cin>>start;
    
    for(int i=0; i<n; i++)
    {
        visited[i] = 0;
    }
    cout<<"DFS traversal : "<<endl;
    DFS(start);
    
    for(int i=0; i<n; i++)
    {
        visited[i] = 0;
    }
    cout<<"BFS traversal : "<<endl;
    BFS(start);
    
    return 0;
}