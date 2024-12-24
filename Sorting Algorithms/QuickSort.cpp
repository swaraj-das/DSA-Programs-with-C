#include<iostream>
using namespace std;

int partition(int *arr, int low, int high){
    int pivot;
    pivot=*(arr+low);
    int j=low;
    for(int i=low+1; i<=high; i++) {
        if(*(arr+i)<pivot) {
            j++;
            int temp=*(arr+i);
            *(arr+i)=*(arr+j);
            *(arr+j)=temp;
        }
    }
    int temp=*(arr+low);
    *(arr+low)=*(arr+j);
    *(arr+j)=temp;

    return j;
}

void QuickSort(int *arr, int low, int high){
    int j;
    if(high>low){
        j=partition(arr, low, high);
        QuickSort(arr, low, j-1);
        QuickSort(arr, j+1, high);
    }
}

int main() {
    int n;
    cout << "Enter the size of the array: ";
    cin >> n;
    int *arr;
    arr=(int*)malloc(n*sizeof(int));
    
    cout << "Enter the elements of the array: ";
    for(int i=0; i<n; i++) {
        printf("-> ");
        cin >> *(arr+i);
    }
    QuickSort(arr,0,n-1);
    cout<<"Before sorting The array: ";
    for(int i=0;i<n;i++) {
        cout<<*(arr+i)<<" ";
    }
    delete[] arr;
return 0;
}