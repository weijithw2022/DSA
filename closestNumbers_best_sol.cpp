#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
#include <map>
#include <fstream>

using namespace std;
void merge(int arr[], int left, int mid, int right){
    int leftarrElements = mid-left+1;
    int rightarrELements = right-mid;
    int leftArr[leftarrElements];
    int rightArr[rightarrELements];
    for(int i=0; i<leftarrElements; i++){
        leftArr[i]= arr[left+i];
    }
    for(int j=0; j< rightarrELements; j++){
        rightArr[j]= arr[mid + 1+ j];
    }
    int i= 0;
    int j = 0;
    int k = left;
    while(leftarrElements>i && rightarrELements>j){
        if(leftArr[i]<= rightArr[j]){
            arr[k]= leftArr[i];
            i++;
        }
        else{
            arr[k] = rightArr[j];
            j++;
        }
        k++;
    }
    while(leftarrElements>i){
        arr[k]= leftArr[i];
        i++;
        k++;
    }
    while(rightarrELements>j){
        arr[k]= rightArr[j];
        j++;
        k++;
    }
}


void mergeSort(int arr[], int left, int right){
    
    if (left<right){
        int mid = (right+left)/2;
        mergeSort(arr, left, mid);
        mergeSort(arr, mid+1, right);
        merge(arr, left, mid, right);
    }
    
}
vector<int> closestNumbers(vector<int> arr) {
    int size = arr.size();
    int ar[size];
    copy(arr.begin(),arr.end(),ar);
    mergeSort(ar,0, size-1);
    arr.clear();
    for(int i= 0; i<size; i++){
        arr.push_back(ar[i]);
    }
    vector <int> vect1;
    int min=0;
    for(int i=1; i<size; i++){
        int temp =  abs(arr.at(i) - arr.at(i-1));
        if(i==1 or temp<=min){
            if(temp<min){
                vect1.clear();
            }
            min = temp;
            vect1.push_back(arr.at(i-1));
            vect1.push_back(arr.at(i));
        }
    }

    return vect1;
}

int main(){
    int n;
    cin>> n;
    vector <int> arr;
    string inFileName = "inputs.txt";
    ifstream inFile;
    inFile.open(inFileName.c_str());

    if (inFile.is_open())
    {
        for (int i = 0; i < n; i++)
        {
            int x;
            inFile >> x;
            arr.push_back(x);
        }

        inFile.close(); // CLose input file
    }
    else { //Error message
        cerr << "Can't find input file " << inFileName << endl;
    }
    vector <int> result = closestNumbers(arr);
    for(int i=0; i<result.size();i++){
        cout<< result.at(i)<<" ";
    }
    return 0;
}