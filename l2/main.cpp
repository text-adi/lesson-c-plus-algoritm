#include <iostream>
#include <time.h>

using namespace std;

int comparisons = 0;
int rearrangement = 0;

/// Fill massive random value
void fillMassiveRand(int data[], int size) {
    srand(time(0));
    for (int countA = 0; countA < size; countA++) {
        data[countA] = rand() % 40;
    }
}

/// Show mass
void showMassive(int data[], int size) {
    for (int countA = 0; countA < size; countA++) {
        cout << data[countA] << " ";
    }
    cout << endl;
}


void insertionSort(int arr[], int size) {
    int buff = 0;
    int j;
    for (int i = 1; i < size; i++) {
        buff = arr[i];
        for (j = i - 1; j >= 0 && arr[j] > buff; j--)
        {
            comparisons++;
            arr[j + 1] = arr[j];
            rearrangement++;
        }

        arr[j + 1] = buff;

    }
}

void geNotParData(const int arr[], int tmp[], int tmp_size) {
    int j;
    for (int i = 0; i < tmp_size; ++i) {
        j = i * 2+1;
        tmp[i] = arr[j];
    }

}

void installNotParData(const int old_mass[], int new_mass[], int old_size) {
    for (int i = 0; i < old_size; ++i) {
        new_mass[i * 2 + 1] = old_mass[i];
    }
}


void reverseArray(int arr[], int size) {
    int start = 0;
    int end = size - 1;

    while (start < end) {
        // Обмін елементів на початку та кінці масиву
        int temp = arr[start];
        arr[start] = arr[end];
        arr[end] = temp;

        // Збільшення індексу початку та зменшення індексу кінця
        start++;
        end--;
    }
}

void sortMas(int arr[], int size) {
    int tmp_size = size / 2;
    int tmp[size];
    geNotParData(arr, tmp, tmp_size);

    insertionSort(tmp, tmp_size);
    reverseArray(tmp, tmp_size);
    installNotParData(tmp, arr, tmp_size);

}

int main() {
    int size = 10;
    int data[size];
    fillMassiveRand(data, size);

    cout << "Masive before sorting: \n";
    showMassive(data, size);
    cout << " \n";


    sortMas(data, size);
    cout << "Masive after sorting: \n";
    showMassive(data, size);
    cout << " \n";
    cout << "Comparing:" << comparisons << "\n";
    cout << "Rearrangement:" << rearrangement << "\n";
    cout << " \n";

    return 0;
}