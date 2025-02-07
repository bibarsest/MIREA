#include <iostream>
#include <vector>
#include <set>
#include "windows.h"
using namespace std;

const int NULL_VERTEX = -1;

class Graph {

    int vertices;
    vector<set<int>> adjacencyList;
    vector<string> nodeLabels;
    vector<vector<int>> incidenceMatrix; 
    int cycleCount; 

public:
    explicit Graph(int v) : vertices(v), adjacencyList(v), nodeLabels(v), incidenceMatrix(v, vector<int>(v, NULL_VERTEX)), cycleCount(0) {}

    int FIRST(int v) const {
        if (v >= 0 && v < adjacencyList.size() && !adjacencyList[v].empty()) {
            return *adjacencyList[v].begin();
        }
        return NULL_VERTEX;
    }

    int NEXT(int v, int i) const {
        if (v >= 0 && v < adjacencyList.size()) {
            auto it = adjacencyList[v].upper_bound(i);
            if (it != adjacencyList[v].end()) {
                return *it;
            }
        }
        return NULL_VERTEX;
    }

    int VERTEX(int v, int i) const {
        if (v >= 0 && v < adjacencyList.size()) {
            auto it = adjacencyList[v].begin();
            advance(it, i);
            return it != adjacencyList[v].end() ? *it : NULL_VERTEX;
        }
        return NULL_VERTEX;
    }

    void ADD_V(const string& name, const string& label) {
        nodeLabels.push_back(label);
        adjacencyList.emplace_back();

    }

    void ADD_E(int v, int w, int c) {
        if (v >= 0 && v < adjacencyList.size() && w >= 0 && w < adjacencyList.size()) {
            adjacencyList[v].insert(w);
            incidenceMatrix[v][w] = c; 
            incidenceMatrix[w][v] = c; 
        }
    }


    void DEL_V(int v) {
        if (v >= 0 && v < adjacencyList.size()) {
            nodeLabels.erase(nodeLabels.begin() + v);
            adjacencyList.erase(adjacencyList.begin() + v);
            for (auto& neighbors : adjacencyList) {
                neighbors.erase(v);

            }
        }
    }


    void DEL_E(int v, int w) {
        if (v >= 0 && v < adjacencyList.size() && w >= 0 && w < adjacencyList.size()) {
            adjacencyList[v].erase(w);
            incidenceMatrix[v][w] = NULL_VERTEX;
            incidenceMatrix[w][v] = NULL_VERTEX;
        }
    }

    void EDIT_V(int v, const string& newLabel) {
        if (v >= 0 && v < nodeLabels.size()) {
            nodeLabels[v] = newLabel;
        }
    }

    void EDIT_E(int v, int w, int newWeight) {

        if (v >= 0 && v < adjacencyList.size() && w >= 0 && w < adjacencyList[v].size()) {

        }
    }

    void findCycles() {
        vector<bool> visited(vertices, false);
        vector<bool> recursionStack(vertices, false);

        for (int v = 0; v < vertices; ++v) {
            if (!visited[v]) {
                if (dfsCycle(v, visited, recursionStack)) {
                    ++cycleCount; 
                }
            }
        }

        cout << "Общее количество циклов: " << cycleCount << endl;
    }

    void printIncidenceMatrix() {
        for (int i = 0; i < incidenceMatrix.size(); ++i) {
            for (int j = 0; j < incidenceMatrix[i].size(); ++j) {
                if (incidenceMatrix[i][j] == -1 or incidenceMatrix[i][j] >= 10) { cout << incidenceMatrix[i][j] << " "; }
                else { cout << " " << incidenceMatrix[i][j] << " "; }
            }
            cout << endl;
        }
        cout << endl;
    }

    void printGraph(const Graph& graph) {
        for (int v = 0; v < graph.adjacencyList.size(); ++v) {
            cout << "Node " << v << " (Label: " << graph.nodeLabels[v] << "): ";
            for (int neighbor : graph.adjacencyList[v]) {
                cout << neighbor << " ";
            }
            cout << endl;
        }
        cout << endl;
    }

private:
    bool dfsCycle(int v, vector<bool>& visited, vector<bool>& recursionStack) {
        visited[v] = true;
        recursionStack[v] = true;
        for (int neighbor : adjacencyList[v]) {
            if (!visited[neighbor]) {
                if (dfsCycle(neighbor, visited, recursionStack)) {
                    return true;
                }
            }
            else if (recursionStack[neighbor]) {
                cout << "Цикл найден: " << v << " -> ";
                for (int u = neighbor; u != v; u = adjacencyList[u].empty() ? -1 : *adjacencyList[u].begin()) {
                    cout << u << " -> ";
                }
                cout << v << endl;

                return true;
            }
        }

        recursionStack[v] = false;
        return false;
    }
};



int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    Graph test(6);
    // Добавление вершин
    test.ADD_V("A", "Label_A");
    test.ADD_V("B", "Label_B");
    test.ADD_V("C", "Label_C");
    test.ADD_V("D", "Label_D");
    test.ADD_V("E", "Label_E");

    // Изменение метки вершины
    test.EDIT_V(6, "New_Label");
    // Изменение веса дуги
    test.EDIT_E(3, 4, 10); 
    // Удаление вершины
    test.DEL_V(3);
    // Удаление дуги
    test.DEL_E(2, 0);

    cout << "Первый пример. Граф с двумя циклами." << endl;
    Graph graph(6);
    graph.ADD_E(0, 1, 1);
    graph.ADD_E(1, 2, 2);
    graph.ADD_E(2, 0, 3);
    graph.ADD_E(2, 3, 4);
    graph.ADD_E(3, 4, 5);
    graph.ADD_E(4, 5, 6);
    graph.ADD_E(5, 3, 7);

    cout << "Матрица инцидентности:" << endl;
    graph.printIncidenceMatrix();

    cout << "Циклы в графе:" << endl;
    graph.findCycles();


    cout << endl << endl << "Второй пример. Граф с одним циклом." << endl;
    Graph graph2(5);
    graph2.ADD_E(0, 1, 1);
    graph2.ADD_E(0, 2, 2);
    graph2.ADD_E(1, 3, 3);
    graph2.ADD_E(3, 4, 4);
    graph2.ADD_E(4, 0, 5);

    cout << "Матрица инцидентности:" << endl;
    graph2.printIncidenceMatrix();

    cout << "Циклы в графе:" << endl;
    graph2.findCycles();


    cout << endl << endl << "Третий пример. Граф без циклов." << endl;
    Graph graph3(6);
    graph3.ADD_E(0, 1, 1);
    graph3.ADD_E(1, 2, 2);
    graph3.ADD_E(0, 3, 3);
    graph3.ADD_E(0, 4, 4);
    graph3.ADD_E(3, 5, 5);
    graph3.ADD_E(4, 5, 6);

    cout << "Матрица инцидентности:" << endl;
    graph3.printIncidenceMatrix();

    cout << "Циклы в графе:" << endl;
    graph3.findCycles();


    system("pause");

    return 0;
}