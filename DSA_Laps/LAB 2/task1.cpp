#include<iostream>
using namespace std;

int intersection1(int A[], int B[], int  C[], int n) {
    int count = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (A[i] == B[j]) {
                C[count++] = A[i];
                break; 
            }
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
        if(i ==0){
        cout<<"Enter the elements of First Array["<<i+1<<"]"<<endl;
        }
        cin>>first[i];
    }

      for(int i = 0 ; i < num ; i++){
        if(i ==0){
        cout<<"Enter the elements of Second Array["<<i+2<<"]"<<endl;
        }
        cin>>second[i];
    }

int f = intersection1(first,second,third,num);
cout<<"Intersection of the Two Arrays: "<<intersection1(first,second,third,num)<<endl;
for(int i = 0 ; i < f ; i++){
    if(i == 0 ){
        cout<<"C = [ ";
    }
    cout<<third[i];
    if(i == f-1){
        cout<<" ]";  
    }
    }


}