#include <iostream>

using namespace std;
// void bubleSort(int arr[],int len){
//   for (int i = 0; i < len; i++) {
//     for (int j = 0; j < len - i; j++) {
//       if (arr[j] > arr[j + 1]) {
//         int temp = arr[j];
//         array[j] = array[ij+ 1];
//         array[j+ 1] = temp;
//       }
//     }
//   }
// }
int sortForMedian(int arr[], int len, int New){
    int arrNew[len+1];
    int i=0;
    int j=0;
    int temp = len;
    while(i<len+1){
        if(j<=len-1){
            if(arr[j]>New){
                arrNew[i]= New;
                i++;
            }
            else{
                arrNew[i]= arr[j];
                i++;
                j++;
            }
        }
        else{
           arr[i]=New;
        }
    }
    for(int i=0;i<=len; i++){
        arr[i]=arrNew[i];
    }

    int median;
    if((len+1)%2 ==0){
        median= (arrNew[(len+1)/2] + arrNew[((len+1)/2)+1])/2;
        return median;
    }
    else{
        median = arrNew[((len+1)/2)+1];
        return median;
    }
}

int main(){
    int n;
    cout<<"n:";
    cin>>n;
    int arr[n];
    cout<<"elements:";
    for(int i=0; i<n;i++){
        int ele;
        cin>>ele;
        arr[i]=ele;
        cout<<arr[i];
        int median = sortForMedian(arr, i+1, arr[i+1]);
        cout<<median<<"\n";
    }
    return 0;
}

