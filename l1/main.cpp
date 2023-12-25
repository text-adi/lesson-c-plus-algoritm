#include <iostream>
#include <time.h>

using namespace std;

int comparisons = 0;
int rearrangement=0;


/// Fill massive random value
void fillMassiveRand(int data[], int &size) {
    srand(time(0));
    for (int countA = 0; countA < size; countA++) {
        data[countA] = rand() % 40;
    }
}

/// Show mass
void showMassive(int data[], int &size) {
    for (int countA = 0; countA < size; countA++) {
        cout << data[countA] << " ";
    }
}
void swap(int& a, int& b) {
    int temp = a;
    a = b;
    b = temp;
    ++rearrangement;
}


int partitionDescOddIndices(int arr[], int low, int high) {
    int pivot = arr[low];
    int left = low + 2;
    int right = high;

    while (true) {
        while (left <= right && arr[left] > pivot) {
            left += 2;
            ++comparisons;
        }

        while (left <= right && arr[right] < pivot) {
            right -= 2;
            ++comparisons;
        }

        if (left <= right) {
            swap(arr[left], arr[right]);
            left += 2;
            right -= 2;
        } else {
            break;
        }
    }

    swap(arr[low], arr[right]);
    return right;
}

void quickSortColumns(int arr[], int low, int high) {
    if (low < high) {
        int pivotIndex = partitionDescOddIndices(arr, low, high );

        quickSortColumns(arr, low, pivotIndex - 2);
        quickSortColumns(arr, pivotIndex + 2, high);
    }
}


int main() {
    int size = 10;
    int data[size];
    fillMassiveRand(data, size);

    cout << "Masive before sorting: \n";
    showMassive(data, size);
    cout << " \n";

    //quick sort
    quickSortColumns(data, 0, size - 1);


    cout << "Masive after quick sorting: \n";
    showMassive(data, size);
    cout << " \n";
    cout << "Comparing:" << comparisons << "\n";
    cout << "Rearrangement:" << rearrangement << "\n";
    cout << " \n";

    return 0;
}