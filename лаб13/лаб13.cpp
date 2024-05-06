#include <iostream>
#include <cmath>

using namespace std;


void fillArray(int arr[], int size) {
    int num = 100000;
    int index = 0; 

    while (index < size) {

        int firstHalf = num / 1000;
        int secondHalf = num % 1000;
        int sumFirstHalf = (firstHalf / 100) + ((firstHalf % 100) / 10) + (firstHalf % 10);
        int sumSecondHalf = (secondHalf / 100) + ((secondHalf % 100) / 10) + (secondHalf % 10);

       
        if (sumFirstHalf == sumSecondHalf) {
            arr[index] = num;
            index++;
        }

        num++; 
    }
}


int interpolationSearch(int arr[], int size, int key) {
    int low = 0;
    int high = size - 1;

    while (low <= high && key >= arr[low] && key <= arr[high]) {
        if (low == high) {
            if (arr[low] == key)
                return low;
            return -1;
        }


        int pos = low + ((key - arr[low]) * (high - low)) / (arr[high] - arr[low]);

        if (arr[pos] == key)
            return pos;

        if (arr[pos] < key)
            low = pos + 1;
        else
            high = pos - 1;
    }
    return -1;
}

int main() {
    const int size = 100;
    int arr[size];


    fillArray(arr, size);


    int key;
    cout << "Enter the number to search for: ";
    cin >> key;


    int index = interpolationSearch(arr, size, key);


    if (index != -1)
        cout << "Number found at index: " << index << endl;
    else
        cout << "Number not found in the array." << endl;

    return 0;
}
