#include <iostream>
#include <vector>

using namespace std;

class Graph {
	public:
	 Graph(){}
		void addEdge(vector<int> adj[], int a, int b);
		void printGraph(vector<int> adj[], int length);
};

void Graph::addEdge(vector<int> adj[], int a, int b){
	adj[a].push_back(b);
	adj[b].push_back(a);
}

void Graph::printGraph(vector<int> adj[], int len){

	for(int i=0; i<len; i++){
		vector<int>::iterator it = adj[i].begin();
		cout<<"Head: "<<i<<"->";
		for(; it<adj[i].end(); it++){
			cout<<*it<<"->";
		}
		cout<<endl;
	}
}


int main(){
	
	int V=6;
	vector<int> adj[V];
	
	Graph graph;
	
	graph.addEdge(adj, 5, 1);
	graph.addEdge(adj, 1, 2);
	graph.printGraph(adj, V);
	return 0;
}
