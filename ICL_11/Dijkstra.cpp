#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

float dijikstra (vector<vector<int > > graph, int startNode){
    int sizeOfGraph = graph.size();
    vector<int> distances(sizeOfGraph, INT_MAX);
    int total_distance = 0;
    vector <bool> visited(sizeOfGraph, false);
    distances[startNode] = 0;
    for(int i=0;i<sizeOfGraph-1; i++){
        int min_distance = INT_MAX;
        int minIndex = -1;

        for (int j = 0; j < sizeOfGraph; ++j) {
            if (!visited[j] && distances[j] < min_distance) {
                min_distance = distances[j];
                minIndex = j;
            }
        }
        visited[minIndex] = true;
        for (int j = 0; j < sizeOfGraph; ++j) {
            if (!visited[j] && graph[minIndex][j] != 0 && distances[minIndex] != INT_MAX && distances[minIndex] + graph[minIndex][j] < distances[j]) {
                distances[j] = distances[minIndex] + graph[minIndex][j];
            }
        }
    }
    cout << "Shortest distances from vertices " << startNode << endl;
    for (int i = 0; i < sizeOfGraph; ++i) {
        cout << "Hospital " << i << ": " << distances[i] << "\n";
    }
    
    for(int i=0; i<distances.size();i++){
        total_distance += distances.at(i);
    }
    float avgDistance = (float)total_distance/(float)(sizeOfGraph-1);
    cout << "Average Distance from  " << startNode << ": "<< avgDistance<<endl;
    return avgDistance;
}
int main(){
    int graphSize = 6;
    vector<vector<int > > graph = {
        {0,10,0,0,15,5},
        {10,0,10,30,0,0},
        {0,10,0,12,5,0},
        {0,30,12,0,0,20},
        {15,0,5,0,0,0},
        {5,0,0,20,0,0}
    };
    vector<float> minDistances;
    for(int i=0;i<graphSize;i++){
        minDistances.push_back(dijikstra(graph,i));
    }
    int minNum = INT_MAX;
    for(float i: minDistances){
        if(minNum>i){
            minNum = i;
        }
    }
    vector <int> occurences;
    auto it = minDistances.begin();
    while ((it = find_if(it, minDistances.end(), [&] (int const &e) { return e == minNum; }))
        != minDistances.end())
    {
        occurences.push_back(std::distance(minDistances.begin(), it));
        it++;
    }
    cout<<"Best cities to make the hospital are: ";
    for(int i: occurences){
        cout<<i<<" ";
    }
    /* loat dist1 = dijikstra(graph,0);
    float dist2 = dijikstra(graph,1);
    float dist3 = dijikstra(graph,2);
    float dist4 = dijikstra(graph,3);
    float dist5 = dijikstra(graph,4);
    float dist6 = dijikstra(graph,5); */
    return 0;
}

