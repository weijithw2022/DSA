#include <iostream>
#include <vector>
using namespace std;
int findMinVertex(vector<int> &vertices, vector<bool> &visited){
    int minVertex;
    int minimumAdjEdge = INT_MAX;

    for(int i=0;i<vertices.size();i++){
        if(visited[i]== false && minimumAdjEdge>vertices[i]){
            minimumAdjEdge = vertices[i];
            minVertex = i;
        }
    }
    return minVertex;
}

void PrimMST(vector<vector<int > > graph, int startNode){
    int V = graph.size();
    //Array to store the Minimum spanning tree
    vector<int> MST(V);
    //Array of visited nodes
    vector<bool> visited(V, false);
    //Array of vertices
    vector<int> vertices(V,INT_MAX);
    
    vertices[startNode]= 0;
    MST.at(startNode) = -1;

    int spanTreeEdges = 0;
    //Iterate through until the minimum spanning tree is obtained
    while(spanTreeEdges<(V-1)){
        int minNextVertex = findMinVertex(vertices, visited);
        visited[minNextVertex] = true;
        for(int v=0; v<V; v++){
            if(graph[minNextVertex][v] != 0 && visited[v] == false && graph[minNextVertex][v] < vertices[v]){
                MST.at(v) = minNextVertex;
                vertices[v]= graph[minNextVertex][v];
            }
        }
        
        spanTreeEdges++;
    }
    int minimumCost = 0;
    //Print MST
    for(int i=1; i<V;i++){
        cout<<MST.at(i)<<" - "<<i<<" : "<< graph.at(i).at(MST.at(i))<<endl;
        minimumCost += graph.at(i).at(MST.at(i));
    }
    cout<<"Minimum cost of the tree is: "<< minimumCost;


}

int main(){
    vector<vector<int > > graph={{0,3,0,0,0,1}, 
                                {3,0,2,1,10,0},
                                {0,2,0,3,0,5},
                                {0,1,3,0,5,0},
                                {0,10,0,5,0,4},
                                {1,0,5,0,4,0}};
    PrimMST(graph,0);
    return 0;
}

