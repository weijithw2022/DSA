#include <iostream>

using namespace std;

int partition(int arr[],int start, int end){
    int pivot= arr[end];
    int i = start-1;
    for(int j=start; j<=end-1;j++ ){
        if(arr[j]<pivot){
            i++;
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j]= temp;
        }
    }
    i++;
    int temp = arr[i];
    arr[i]= arr[end];
    arr[end]= temp;
    return i;
}

void quickSort(int arr[], int start, int end){
    if(end<=start){
        return;
    }
    int pivot = partition(arr, start, end);
    quickSort(arr, start, pivot-1);
    quickSort(arr,pivot+1,end);
}


int main(){
    int arr[6]= {9,8,7,6,5,4};
    quickSort(arr, 0, 5);
    for(int i=0; i<6; i++){
        cout<<arr[i];
    }
    return 0;
}

