#include <bits/stdc++.h>
using namespace std;
struct node
{
    int value,weight;
};
int dis[100],parent[100],visit[100];
#define inf 100000
vector<node> adj[100];
int vertex,edge,source;;
int get_min()
{
    int i,min = inf,index;
    for(i = 0;i < vertex;i++)
    {
        if(visit[i] == 0 && min > dis[i])
        {
            min = dis[i];
            index = i;
        }
    }
    return index;
}
void dijkstra()
{
    int i,j;
    for(j = 0;j < vertex;j++)
    {
        int u = get_min();
        for(i = 0;i < adj[u].size();i++)
        {
            node v = adj[u][i];
            if(visit[v.value] == 0 && dis[v.value] > dis[u] + v.weight)
            {
                dis[v.value] = dis[u] + v.weight;
            }
        }
        visit[u] = 1;
        cout << "Distance of vertex " << u << "from source vertex " << source << " is: " << dis[u] << endl;
    }
    

}
void initialization(int vertex)
{
    int i;
    for(i = 0;i < vertex;i++)
    {
        visit[i] = 0;
        dis[i] = inf;
        parent[i] = -1;
    }
}
void get_edge(int edge)
{
    int i,u,v,w;
    for(i = 0;i < edge;i++)
    {
        cin >> u >> v >> w;
        node temp;
        temp.value = v;
        temp.weight = w;
        adj[u].push_back(temp);
    }

}
int main()
{
    cout << "Number of vertexes: ";
    cin >> vertex;
    cout << "Number of edges: ";
    cin >> edge;
    initialization(vertex);
    get_edge(edge);
    cin >> source;
    dis[source] = 0;
    dijkstra();
    return 0;
}
