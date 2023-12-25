#include <iostream>
#include <vector>
#include <algorithm>
#include <random>
using namespace std;

void viewVector(vector<int>& vec){
    for (const auto& element : vec) {
        cout << element << " ";
    }
}
void fillVectorWithRandomValues(vector<int>& vec, size_t size, unsigned seed = 0, int minValue = 0, int maxValue = 100) {
    // Встановлення seed для генератора випадкових чисел
    default_random_engine generator;
    if (seed == 0) {
        generator.seed(static_cast<unsigned>(time(nullptr)));
    } else {
        generator.seed(seed);
    }

    uniform_int_distribution<int> distribution(minValue, maxValue);

    // Очищаємо вектор перед заповненням
    vec.clear();

    // Заповнюємо вектор випадковими значеннями у заданому діапазоні
    for (std::size_t i = 0; i < size; ++i) {
        int randomValue = distribution(generator);
        vec.push_back(randomValue);
    }
}

vector<int> findMissingElements(const vector<int>& A, const vector<int>& B) {
    vector<int> missingElements;

    // Для кожного елементу у масиві B
    for (const auto& elementB : B) {
        // Використовуємо стандартний алгоритм пошуку у масиві A
        auto it = std::find(A.begin(), A.end(), elementB);

        // Якщо елемент не знайдений, додаємо його до списку пропущених
        if (it == A.end()) {
            missingElements.push_back(elementB);
        }
    }

    return missingElements;
}

int main() {
    vector<int> arrayA;
    vector<int> arrayB;
    size_t vectorSize = 10;

    fillVectorWithRandomValues(arrayA,vectorSize, 10);
    fillVectorWithRandomValues(arrayB, vectorSize, 1);

    cout << "A: "; viewVector(arrayA); cout << endl;

    cout << "B: "; viewVector(arrayB);  cout << endl;

    vector<int> result = findMissingElements(arrayA, arrayB);

    cout << "Елементи, що присутні в масиві B, але відсутні в масиві A: ";
    viewVector(result);

    return 0;
}
