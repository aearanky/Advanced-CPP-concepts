#include <iostream>
#include <list>

using namespace std;

class Graph{
	private:
		int V;
		list<int> *adj; // pointer to an array containing the adjacency
	public:
		Graph(int v);
		void addEdge(int v, int w);
		void BFS(int s);
};

Graph::Graph(int v){
	V=v;
	
	// Memory refresher: Allocates size bytes of storage, suitably aligned to represent any 		 object of that size, and returns a non-null pointer to the first byte of this block. 
	adj = new list<int>[V]; 
}

void Graph::addEdge(int v, int w) {
	adj[v].push_back(w);	
}

void Graph::BFS(int startNode) {
	bool *visited = new bool[V];
	for(int i=0; i<V; i++){
		visited[i] = false;
	}
	
	// Create a BFS queue for the visisted elements
	list<int> queue;
	
	// Visit and push back start node
	visited[startNode] = true;
	queue.push_back(startNode);
	
	list<int>::iterator i;
	
	while(!queue.empty()) {
		startNode = queue.front();
		cout << startNode << " ";
		queue.pop_front();
		
		for(i = adj[startNode].begin(); i != adj[startNode].end(); i++){
			if(!visited[*i]){
				visited[*i] = true;
				queue.push_back(*i);
			}
		}
	}
	cout<<endl;
}

int main(){
   Graph g(4); 
    g.addEdge(0, 1); 
    g.addEdge(0, 2); 
    g.addEdge(1, 2); 
    g.addEdge(2, 0); 
    g.addEdge(2, 3); 
    g.addEdge(3, 3); 
	g.BFS(2);
	return 0;
}
