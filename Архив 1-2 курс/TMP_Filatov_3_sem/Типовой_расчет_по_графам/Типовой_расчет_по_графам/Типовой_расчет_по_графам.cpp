#include <iostream>
#include <vector>
#include <fstream>

using namespace std;

class Graph {
    int vertices;
    vector<vector<int>> AdjList;
public:
    Graph(int V) {
        vertices = V;
        AdjList.resize(vertices);
    }

    void addEdge(int u, int v) {
        AdjList[u].push_back(v);
    }

    void printAdjacencyList() {
        for (int i = 0; i < vertices; i++) {
            cout << i << " -> ";
            for (int j = 0; j < AdjList[i].size(); j++) {
                cout << AdjList[i][j] << " ";
            }
            cout << endl;
        }
    }

    int countTreesDFS() {
        int count = 0;
        vector<bool> visited(vertices, false);

        for (int i = 0; i < vertices; i++) {
            if (!visited[i]) {
                count++;
                dfs(i, visited);
            }
        }

        return count;
    }

    void dfs(int vertex, vector<bool>& visited) {
        visited[vertex] = true;
        for (int neighbor : AdjList[vertex]) {
            if (!visited[neighbor]) {
                dfs(neighbor, visited);
            }
        }
    }

    void countReverseAndCrossEdges() {
        vector<bool> visited(vertices, false);
        vector<int> entry(vertices, 0);
        vector<int> lower(vertices, 0);
        int timer = 0;
        int reverse_edges = 0;
        int cross_edges = 0;

        for (int i = 0; i < vertices; i++) {
            if (!visited[i]) {
                dfsCountEdges(i, visited, entry, lower, timer, reverse_edges, cross_edges);
            }
        }

        cout << "Number of reverse edges: " << reverse_edges << endl;
        cout << "Number of cross edges: " << cross_edges << endl;
    }

    void dfsCountEdges(int vertex, vector<bool>& visited, vector<int>& entry, vector<int>& lower, int& timer,
        int& reverse_edges, int& cross_edges) {
        visited[vertex] = true;
        entry[vertex] = lower[vertex] = ++timer;

        for (int neighbor : AdjList[vertex]) {
            if (!visited[neighbor]) {
                dfsCountEdges(neighbor, visited, entry, lower, timer, reverse_edges, cross_edges);
                lower[vertex] = min(lower[vertex], lower[neighbor]);

                if (lower[neighbor] > entry[vertex]) {
                    cross_edges++;
                }
                else {
                    reverse_edges++;
                }
            }
            else {
                lower[vertex] = min(lower[vertex], entry[neighbor]);
                if (entry[neighbor] < entry[vertex]) {
                    reverse_edges++;
                }
            }
        }
    }
    void kosaraju() {
        vector<vector<int>> transposed_graph(vertices);
        for (int i = 0; i < vertices; i++) {
            for (int j = 0; j < AdjList[i].size(); j++) {
                transposed_graph[AdjList[i][j]].push_back(i);
            }
        }

        vector<bool> visited(vertices, false);
        vector<int> order;
        for (int i = 0; i < vertices; i++) {
            if (!visited[i]) {
                dfsOrder(i, visited, order);
            }
        }

        vector<bool> visited2(vertices, false);
        vector<vector<int>> strongly_connected_components;
        for (int i = vertices - 1; i >= 0; i--) {
            int vertex = order[i];
            if (!visited2[vertex]) {
                vector<int> strongly_connected;
                dfsSCC(vertex, visited2, strongly_connected, transposed_graph);
                strongly_connected_components.push_back(strongly_connected);
            }
        }

        int scc_count = strongly_connected_components.size();
        cout << "Number of strongly connected components: " << scc_count << endl;
        for (int i = 0; i < scc_count; i++) {
            cout << "Strongly connected component " << i + 1 << ": ";
            for (int j = 0; j < strongly_connected_components[i].size(); j++) {
                cout << strongly_connected_components[i][j] << " ";
            }
            cout << endl;
        }

        vector<vector<int>> reduced_graph(scc_count);

        for (int i = 0; i < scc_count; i++) {
            for (int vertex : strongly_connected_components[i]) {
                for (int neighbor : AdjList[vertex]) {
                    int neighbor_scc = -1;
                    for (int j = 0; j < scc_count; j++) {
                        if (find(strongly_connected_components[j].begin(), strongly_connected_components[j].end(), neighbor) != strongly_connected_components[j].end()) {
                            neighbor_scc = j;
                            break;
                        }
                    }
                    if (neighbor_scc != -1 && neighbor_scc != i) {
                        reduced_graph[i].push_back(neighbor_scc);
                    }
                }
            }
        }

        cout << "Reduced graph:" << endl;
        for (int i = 0; i < scc_count; i++) {
            cout << i << " -> ";
            for (int j = 0; j < reduced_graph[i].size(); j++) {
                cout << reduced_graph[i][j] << " ";
            }
            cout << endl;
        }
    }

    void dfsOrder(int vertex, vector<bool>& visited, vector<int>& order) {
        visited[vertex] = true;
        for (int neighbor : AdjList[vertex]) {
            if (!visited[neighbor]) {
                dfsOrder(neighbor, visited, order);
            }
        }
        order.push_back(vertex);
    }

    void dfsSCC(int vertex, vector<bool>& visited, vector<int>& strongly_connected, vector<vector<int>>& transposed_graph) {
        visited[vertex] = true;
        strongly_connected.push_back(vertex);
        for (int neighbor : transposed_graph[vertex]) {
            if (!visited[neighbor]) {
                dfsSCC(neighbor, visited, strongly_connected, transposed_graph);
            }
        }
    }
};

int main() {
    int V = 8;
    vector<pair<int, int>> E = { {0,1}, {1,0}, {0,2}, {0,3}, {2,1}, {2,4}, {3,1}, {3,2}, {3,4}, {3,5}, {3,6}, {4,0}, {5,7}, {6,5}, {6,7}, {7,5} };
    Graph graph(V);
    for (auto edge : E) {
        graph.addEdge(edge.first, edge.second);
    }

    graph.printAdjacencyList();
    
    cout << endl << "Number of trees: " << graph.countTreesDFS() << endl;
    graph.countReverseAndCrossEdges();

    graph.kosaraju();
    system("pause");
    return 0;
}

