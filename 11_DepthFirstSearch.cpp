#include <iostream>
#include <list>
using namespace std;

class Graph {
  int numVertices;
  list<int> *adjLists;
  bool *visited;

  public:
  Graph(int V);
  void addEdge(int src, int dest);
  void DFS(int vertex);
};

// Initialize graph
Graph::Graph(int vertices) {
  numVertices = vertices;
  adjLists = new list<int>[vertices];
  visited = new bool[vertices];
}

// Add edges
void Graph::addEdge(int src, int dest) {
  adjLists[src].push_front(dest);
}

// DFS algorithm
void Graph::DFS(int vertex) {
  visited[vertex] = true;
  list<int> adjList = adjLists[vertex];

  cout << vertex << " ";

  list<int>::iterator i;
  for (i = adjList.begin(); i != adjList.end(); ++i)
    if (!visited[*i])
      DFS(*i);
}

int main() {

  int n;
  cout<<"\nEnter number of vertices \t: \t";
  cin>>n;
  Graph g(n);

  cout<<"\nEnter source and destination vertices \t : \n";
  for(int i=0; i<n-1; ++i){
      int src, dest;
      cin>>src>>dest;
      g.addEdge(src, dest);
  }

  int startingNode;
  cout<<"\nEnter starting node \t: \t";
  cin>>startingNode;
  // Start DFS with startingNode
  g.DFS(startingNode);

  return 0;
}
