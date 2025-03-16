#include <iostream>
#include <fstream>
#include "dijkstras.h"

vector<int> dijkstra_shortest_path(Graph& G, int source, vector<int>& previous) {
    int num = G.numVertices;
    G.distances.resize(num, INF);
    vector<int> before (num, -1);
    previous = before;
    G.visited.resize(num, false);
    priority_queue<Vertex, vector<Vertex>, greater<Vertex>> priorityq;
    priorityq.push(Vertex{source, 0});
    G.distances[source] = 0;
    while (!priorityq.empty()) {
        int tmp = priorityq.top().vertex;
        priorityq.pop();
        if (!G.visited[tmp]) {
            G.visited[tmp] = true;
            for (Edge &e : G[tmp] ) {
                int vertex = e.dst;
                int weight = e.weight;
                if (!G.visited[vertex] && G.distances[tmp] + weight < G.distances[vertex]) {
                //if (G.distances[tmp] + weight < G.distances[vertex]) {
                    G.distances[vertex] = G.distances[tmp] + weight;
                    previous[vertex] = tmp;
                    priorityq.push(Vertex{vertex, G.distances[vertex]});
                }
                }
        }
    }

    return G.distances;
}

vector<int> extract_shortest_path(const vector<int>& distances, const vector<int>& previous, int destination) {
    stack<int> path;
    vector<int> result;
    int parent = previous[destination];
    path.push(destination);
    while (parent >= 0) {
        path.push(parent);
        parent = previous[parent];
    }
    while (!path.empty()) {
        int first = path.top();
        path.pop();
        result.push_back(first);
    }
    return result;
    
}

void print_path(const vector<int>& v, int total) {
    for (auto e : v) {
        cout << e << " ";
    }
    cout << endl;
    cout << "Total cost is " << total << endl;
}