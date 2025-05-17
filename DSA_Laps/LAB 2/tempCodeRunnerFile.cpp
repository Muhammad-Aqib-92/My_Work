#include<iostream>

using namespace std;

bool binarySearch(int arr[], int n, int key) {
    int low = 0, high = n - 1;
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (arr[mid] == key) {
            return true;
        } else if (arr[mid] < key) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    return false;
}

int intersection2(int A[], int B[], int C[], int n) {
    int count = 0;
    for (int i = 0; i < n; i++) {
        if (binarySearch(B, n, A[i])) {
            C[count++] = A[i];
      }
    }
    return count;
}

int main(){

    int num ;

    cout<<"Enter the integer Array Size:"<<endl;
    cin>>num;

    int first[num], second[num] , third[num];

    for(int i = 0 ; i < num ; i++){
        if(i == 0){
        cout<<"Enter the elements of First Array["<<i+1<<"]"<<endl;
        }
        cin>>first[i];
    }
      for(int i = 0 ; i < num ; i++){
        if(i == 0){
        cout<<"Enter the elements of Second Array["<<i+2<<"]"<<endl;
        }
        cin>>second[i];
    }

    int j = intersection2(first,second,third,num);

    cout<< "Sorted Common = [ ";
    
    for(int i = 0 ;  i  <j ; i++){
        cout<<third[i]<<" ";
    }
    cout<<" ]"<<endl;



}