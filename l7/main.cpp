#include <iostream>
#include <fstream>
#include <vector>
#include <list>
#include <queue>

using namespace std;

class Graph {
public:
    Graph(int vertices);
    void addEdge(int v, int w);
    void topologicalSort();
    void printGraph();
    void printLabels();

private:
    int vertices;
    vector<list<int>> adjList;
    vector<int> inDegree;
};

Graph::Graph(int vertices) : vertices(vertices), adjList(vertices), inDegree(vertices, 0) {}

void Graph::addEdge(int v, int w) {
    adjList[v].push_back(w);
    inDegree[w]++;
}

void Graph::topologicalSort() {
    queue<int> q;

    for (int i = 0; i < vertices; ++i) {
        if (inDegree[i] == 0) {
            q.push(i);
        }
    }

    while (!q.empty()) {
        int current = q.front();
        q.pop();

        cout << current << " ";

        for (const auto& neighbor : adjList[current]) {
            if (--inDegree[neighbor] == 0) {
                q.push(neighbor);
            }
        }
    }
}

void Graph::printGraph() {
    cout << "Graph representation:\n";
    for (int i = 0; i < vertices; ++i) {
        cout << i << ": ";
        for (const auto& neighbor : adjList[i]) {
            cout << neighbor << " ";
        }
        cout << "\n";
    }
}

void Graph::printLabels() {
    cout << "Vertex labels:\n";
    for (int i = 0; i < vertices; ++i) {
        cout << i << " ";
    }
    cout << "\n";
}

int main() {
    // Читання графа з файлу
    ifstream inputFile("graph.txt");
    if (!inputFile) {
        cerr << "Error opening file.\n";
        return 1;
    }

    int vertices, edges;
    inputFile >> vertices >> edges;

    Graph graph(vertices);

    for (int i = 0; i < edges; ++i) {
        int v, w;
        inputFile >> v >> w;
        graph.addEdge(v, w);
    }

    inputFile.close();

    // Виведення представлення графа та міток вершин
    graph.printGraph();
    graph.printLabels();

    // Виконання топологічного сортування
    cout << "Topological Sorting:\n";
    graph.topologicalSort();

    return 0;
}
