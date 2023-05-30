#include <iostream>
#include <vector>
#include <queue>
#include <limits>

using namespace std;

// Structure to represent a node in the graph
struct Node {
    int id;
    int distance;

    Node(int _id, int _distance) : id(_id), distance(_distance) {}

    // Overloading the comparison operator for priority queue
    bool operator>(const Node& other) const {
        return distance > other.distance;
    }
};

// Function to find the shortest path from a given source node to all other nodes using Dijkstra's algorithm
void dijkstraShortestPath(vector<vector<int>>& graph, int source, vector<int>& distances) {
    int numNodes = graph.size();

    // Initialize the distances to infinity except for the source node
    distances.resize(numNodes, numeric_limits<int>::max());
    distances[source] = 0;

    // Create a priority queue to store the nodes with their distances
    priority_queue<Node, vector<Node>, greater<Node>> pq;
    pq.push(Node(source, 0));

    while (!pq.empty()) {
        Node curr = pq.top();
        pq.pop();

        int currNode = curr.id;
        int currDist = curr.distance;

        // If the current distance is greater than the stored distance, skip it
        if (currDist > distances[currNode])
            continue;

        // Explore the neighbors of the current node
        for (int i = 0; i < numNodes; i++) {
            // Check if there is an edge between the current node and its neighbor
            if (graph[currNode][i] > 0) {
                int neighbor = i;
                int weight = graph[currNode][i];

                // Calculate the new distance
                int newDist = currDist + weight;

                // If the new distance is shorter, update the distance and enqueue the neighbor
                if (newDist < distances[neighbor]) {
                    distances[neighbor] = newDist;
                    pq.push(Node(neighbor, newDist));
                }
            }
        }
    }
}

int main() {
    int numNodes = 6;  // Number of nodes in the graph

    // Create an adjacency matrix to represent the weighted undirected graph
    vector<vector<int>> graph = {
        { 0, 10, 0, 0, 15, 5 },
        { 10, 0, 10, 30, 0, 0 },
        { 0, 10, 0, 12, 5, 0 },
        { 0, 30, 12, 0, 0, 20 },
        { 15, 0, 5, 0, 0, 0 },
        { 5, 0, 0, 20, 0, 0 }
    };

    int source = 5;  // Source node index

    // Calculate the shortest path from the source node to all other nodes
    vector<int> distances;
    dijkstraShortestPath(graph, source, distances);

    // Print the shortest distances from the source node to all other nodes
    cout << "Shortest distances from node " << source << ":\n";
    for (int i = 0; i < numNodes; i++) {
        cout << "Node " << i << ": " << distances[i] << endl;
    }

    return 0;
}
