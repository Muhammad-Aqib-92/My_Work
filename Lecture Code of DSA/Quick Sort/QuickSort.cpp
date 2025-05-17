//Quick Sort
#include <iostream>

using namespace std;

/* Partition the list into two halves based 
   on pivot and return partition index */
int partition(int A[], int left, int right)
{
	int p = left;  // Choosing the first element as the pivot

	// Rearrange elements based on pivot p
	while (left < right)
	{
		// Move left index forward until an element greater than pivot is found
		while (A[p] >= A[left] && left < right)
			left++;

		// Move right index backward until an element less than or equal to pivot is found
		while (A[p] < A[right])
			right--;

		// Swap elements at left and right if they are out of order and left is still less than right
		if (left < right)
		{
			swap(A[left], A[right]);
		}		
	}

	// Place the pivot element in its correct sorted position
	swap(A[right], A[p]);

	return right;  // Return the index where the pivot is positioned
}

// Quick Sort function to sort the array using divide and conquer approach
void quickSort(int A[], int left, int right)
{
	if (left < right)  // Check if there are more than one element to sort
	{	
		// Find the partition index after rearranging elements around pivot
		int pi = partition(A, left, right);

		// Recursively sort elements before and after the partition index
		quickSort(A, left, pi - 1);   // Left subarray with elements less than pivot
		quickSort(A, pi + 1, right);  // Right subarray with elements greater than pivot
	}
}

int main()
{
	int A[] = { 3, 7, 8, 5, 2, 1, 9 };  // Initialize the array to be sorted
	int n = sizeof(A) / sizeof(A[0]);   // Calculate the number of elements in the array

	// Display the original list
	cout << "List:\t\t";
	for (int i = 0; i < n; i++)
	{
		cout << A[i] << "\t";
	}
	cout << endl;

	// Sort the array using Quick Sort
	quickSort(A, 0, n - 1);

	// Display the sorted list
	cout << "Sorted List:\t";
	for (int i = 0; i < n; i++)
	{
		cout << A[i] << "\t";
	}
	cout << endl << endl;

	return 0;
}