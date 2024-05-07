#include <iostream>
#include <vector>

using namespace std;

#define V 5 // Number of vertices in the graph

// Function to check if the vertex can be added to the path
bool isSafe(int v, vector<vector<int>>& graph, vector<int>& path, int pos) {
    // Check if the vertex is adjacent to the last added vertex
    if (graph[path[pos - 1]][v] == 0) {
        return false;
    }

    // Check if the vertex has already been added to the path
    for (int i = 0; i < pos; ++i) {
        if (path[i] == v) {
            return false;
        }
    }

    return true;
}

// Function to find Hamiltonian cycle starting from a specific vertex
bool hamCycleUtil(vector<vector<int>>& graph, vector<int>& path, int pos) {
    // Base case: If all vertices are included in the path
    if (pos == V) {
        // Check if the last vertex is adjacent to the start vertex
        if (graph[path[pos - 1]][path[0]] == 1) {
            return true; // Hamiltonian cycle found
        }
        return false; // Hamiltonian cycle not found
    }

    // Try adding different vertices to the path
    for (int v = 0; v < V; ++v) {
        if (isSafe(v, graph, path, pos)) {
            path[pos] = v;

            // Recur to find Hamiltonian cycle using the next vertex
            if (hamCycleUtil(graph, path, pos + 1)) {
                return true;
            }

            path[pos] = -1; // Backtrack
        }
    }

    return false; // Hamiltonian cycle not found
}

// Function to find and print Hamiltonian cycle in the graph
void hamiltonianCycle(vector<vector<int>>& graph) {
    vector<int> path(V, -1); // Initialize path array

    // Start from each vertex and try to find Hamiltonian cycle
    for (int startVertex = 0; startVertex < V; ++startVertex) {
        path[0] = startVertex;

        if (hamCycleUtil(graph, path, 1)) {
            cout << "Hamiltonian cycle found starting from vertex " << startVertex << ": ";
            for (int vertex : path) {
                cout << vertex << " ";
            }
            cout << startVertex << endl;
            return; // Exit after finding the first Hamiltonian cycle
        }
    }

    cout << "No Hamiltonian cycle found.\n";
}

int main() {
    vector<vector<int>> graph = {
        {0, 1, 0, 1, 0},
        {1, 0, 1, 1, 1},
        {0, 1, 0, 0, 1},
        {1, 1, 0, 0, 1},
        {0, 1, 1, 1, 0}
    };

    hamiltonianCycle(graph);

    return 0;
}
