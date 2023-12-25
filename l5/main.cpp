#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <cmath>

using namespace std;

const int TABLE_SIZE = 100; // Розмір хеш-таблиці

class HashTable {
private:
    vector<string> table[TABLE_SIZE];

    int hashFunction(const string &word) {
        int hash = 0;
        for (char ch: word) {
            hash += abs(ch);
        }
        return hash  % TABLE_SIZE;
    }

    int secondHashFunction(const string &word) {
        return 1 + (hashFunction(word) % (TABLE_SIZE - 1));
    }

public:
    void insert(const string &word) {
        int index = hashFunction(word);

        int step = secondHashFunction(word);

        while (!table[index].empty()) {
            index = (index + step) % TABLE_SIZE;
        }

        table[index].push_back(word);
    }

    bool search(const string &word) {
        int index = hashFunction(word);
        int step = secondHashFunction(word);

        while (!table[index].empty()) {
            if (table[index].front() == word) {
                return true; // Знайдено
            }
            index = (index + step) % TABLE_SIZE;
        }

        return false; // Не знайдено
    }

    void display() {
        for (int i = 0; i < TABLE_SIZE; ++i) {
            cout << i << ": ";
            for (const auto &word: table[i]) {
                cout << word << " ";
            }
            cout << endl;
        }
    }
    void serialize(){
        ofstream myfile("output.txt");
        if (myfile.is_open())
        {
            for (int i = 0; i < TABLE_SIZE; ++i) {
                myfile << i << ": ";
                for (const auto &word: table[i]) {
                    myfile << word << " ";
                }
                myfile << endl;
            }
            myfile.close();
        }
        else cout << "Unable to open file";

    }
};

int main() {
    HashTable hashTable;

    ifstream file("input.txt");
    string word;

    while (file >> word) {
        hashTable.insert(word);
    }

    // Вивід хеш-таблиці на екран
    cout << "Hash Table:\n";
    hashTable.display();
    hashTable.serialize();

    string searchWord;
    cout << "\nEnter a word to search: ";
    cin >> searchWord;

    if (hashTable.search(searchWord)) {
        cout << "Word found in the hash table.\n";
    } else {
        cout << "Word not found in the hash table.\n";
    }

    return 0;
}
