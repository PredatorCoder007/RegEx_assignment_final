//printing BFS traversal from a given source vertex

#include<bits/stdc++.h>
using namespace std;

//class: directed graph using adjacency list rep

class Graph{

    //no. of vertices
    int V;

    //pointer to array
    vector<list<int>> adj;


public:

    Graph(int V);

    void add_Edge(int v, int w);

    void BFS(int s);

};

Graph::Graph(int V)
{
    this->V = V;
    adj.resize(V);
}

void Graph::add_Edge(int v, int w)
{
    //add w to v's list
    adj[v].push_back(w);
}

void Graph::BFS(int s)
{
    //mark all vertices not visited
    vector<bool> visited;
    visited.resize(V, false);

    //create a queue for BFS
    list<int> queue;

    //mark the current node as visited and enqueue it
    visited[s] = true;
    queue.push_back(s);

    while(!queue.empty())
    {
        //dequeue a vertex from queue and print it
        s = queue.front();
        cout<< s << " ";
        queue.pop_front();

        //get all adjacent vertices of dequeud vertex s
        //if adj not visited then mark it visited and enqueue it
        for(auto adjacent : adj[s]){
            if(!visited[adjacent]){
                visited[adjacent] = true;
                queue.push_back(adjacent);
            }
        }
    }
}

//driver  code
int main()
{
    //create graph
    Graph g(4);
    g.add_Edge(0,1);
    g.add_Edge(0,2);
    g.add_Edge(1,2);
    g.add_Edge(2,0);
    g.add_Edge(2,3);
    g.add_Edge(3,3);

    cout<<" following is BFT "<<"(starting from vertex 2) \n";
    g.BFS(2);

    return 0;
}

