#include<iostream>
using namespace std;

void BubbleSort(int arr[],int n){
    for(int i=0; i<n-1; i++){
        for(int j=0; j<n-i-1; j++){
            if(arr[j]>arr[j+1]){
                int temp=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=temp;
            }
        }
    }
}
void printArray(int arr[], int n){
cout << "Sorted Array: ";
    for(int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main(){
    int n, arr[10], k;
    cout<<"Enter the Array Size<=10: ";
    cin>>n;
    if(n > 10 || n <= 0) {
        cout << "Invalid size. Please enter a size between 1 and 10." << endl;
        return 1;
    }
    cout<<"Enter the array elements: ";
    for(int i=0; i<n; i++){
        cout<<"->";
        cin>>arr[i];
    }
    BubbleSort(arr, n);
    printArray(arr, n);
    return 0;
}
