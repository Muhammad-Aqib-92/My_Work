#include <iostream>
using namespace std;

int recursiveLinearSearch(int arr[], int size, int target) {
   
    if (size == 0) {
        return -1;
    }

        if (arr[size - 1] == target) {
        return size - 1; 
    }

    return recursiveLinearSearch(arr, size - 1, target);
}

int main() {
    int arr[] = {3, 5, 7, 9, 11};
    int size = sizeof(arr) / sizeof(arr[0]);
    int target;

    cout << "Enter the target element to search for: ";
    cin >> target;

    int result = recursiveLinearSearch(arr, size, target);

    if (result != -1) {
        cout << "Element found at index " << result << endl;
    } else {
        cout << "Element not found in the array." << endl;
    }

    return 0;
}
