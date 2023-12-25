#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

class Graph {
private:
    int vertices;
    vector<vector<int>> adjacencyMatrix;

public:
    Graph(int v) : vertices(v), adjacencyMatrix(v, vector<int>(v, 0)) {}

    void addEdge(int v1, int v2) {
        if (v1 >= 0 && v1 < vertices && v2 >= 0 && v2 < vertices) {
            adjacencyMatrix[v1][v2] = 1;
            adjacencyMatrix[v2][v1] = 1; // для неорієнтованого графа
        } else {
            cout << "Невірні індекси вершин" << endl;
        }
    }

    void printAdjacencyMatrix() {
        cout << "Матриця суміжності:" << endl;
        for (int i = 0; i < vertices; ++i) {
            for (int j = 0; j < vertices; ++j) {
                cout << adjacencyMatrix[i][j] << " ";
            }
            cout << endl;
        }
    }

    void buildComplementList() {
        cout << "Список зв'язків доповнення графа:" << endl;

        for (int i = 0; i < vertices; ++i) {
            cout << "Вершина " << i + 1 << ": ";
            for (int j = 0; j < vertices; ++j) {
                if (i != j && adjacencyMatrix[i][j] == 0) {
                    cout << j + 1 << " ";
                }
            }
            cout << endl;
        }
    }

    void readGraphFromFile(const string& filename) {
        ifstream inputFile(filename);
        if (!inputFile.is_open()) {
            cerr << "Помилка відкриття файлу" << endl;
            return;
        }

        int edges;
        inputFile >> vertices >> edges;

        adjacencyMatrix.resize(vertices, vector<int>(vertices, 0));

        for (int i = 0; i < edges; ++i) {
            int v1, v2;
            inputFile >> v1 >> v2;
            addEdge(v1-1, v2-1);
        }

        inputFile.close();
    }
};

int main() {
    Graph graph(0);  // 0 vertices initially

    // Зчитування графа з файлу
    graph.readGraphFromFile("graph.txt");

    // Виведення матриці суміжності та списку зв'язків доповнення графа
    graph.printAdjacencyMatrix();
    graph.buildComplementList();

    return 0;
}
