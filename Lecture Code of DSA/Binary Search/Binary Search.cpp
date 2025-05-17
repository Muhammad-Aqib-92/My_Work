#include <iostream>
using namespace std;

int binarySearch(int arr[], int size, int target) {
    int low = 0;
    int right = size - 1;

    while (low <= right) {
        int mid = low + (right - low) / 2;

        // Check if the target is present at mid
        if (arr[mid] == target)
            return mid;

        // If target is greater, ignore the left half
        if (arr[mid] < target)
            low = mid + 1;
        // If target is smaller, ignore the right half
        else
            right = mid - 1;
    }

    // Target not found
    return -1;
}

int main() {
    int arr[] = {1, 3, 5, 7, 9, 11};  // Static array
    int size = sizeof(arr) / sizeof(arr[0]);
    int target = 7;

    int result = binarySearch(arr, size, target);
    if (result != -1)
        cout << "Element found at index " << result << endl;
    else
        cout << "Element not found" << endl;

    return 0;
}
    