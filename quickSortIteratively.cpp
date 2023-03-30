#include <iostream>

using namespace std;

int partition(int arr[], int start, int end){
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


void quickSortIteratively(int arr[], int start, int end){
    int stack[end-start+1];
    int top = -1;
    stack[++top]= start;
    stack[++top]=end;
    while(top>= 0){
        end = stack[top--];
        start = stack[top--];
        int tempQuick = partition(arr,start, end);
        if(tempQuick-1>start){
            stack[++top]=start;
            stack[++top]=tempQuick-1;
        }
        if(tempQuick+1<end){
            stack[++top]=tempQuick+1;
            stack[++top] = end;
        }
    }
    
}

int main(){
    int arr[20]= {20,19,18,17,16,15,14,13,12,11,10,9,8,7,6,5,4,3,2,1};
    quickSortIteratively(arr, 0,19);
    for(int i=0; i<20; i++){
        cout<<arr[i];
    }
    return 0;
}

