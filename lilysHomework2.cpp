#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
#include <map>
#include <fstream>

using namespace std;
void merge(vector<int> &arr, int left, int mid, int right){
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


void mergeSort(vector<int> &arr, int left, int right){
    
    if (left<right){
        int mid = (right+left)/2;
        mergeSort(arr, left, mid);
        mergeSort(arr, mid+1, right);
        merge(arr, left, mid, right);
    }
    
}
int lilysHomework(vector<int> arr)  {
    int size = arr.size();
    vector<int> originalArr = arr;
    vector<int> originalArr2 = arr;
    map<int, int> mp;
    int ascSwaps=0;
    int dscSwaps = 0;
    mergeSort(arr,0,size-1);
    for(int i=0; i<size; ++i){
        mp[originalArr[i]] = i;
    }
    vector <int> vect1 = arr;
    reverse(vect1.begin(), vect1.end());
    map<int, int> mp2;
    for(int i=0; i<size; ++i){
        mp2[originalArr2[i]] = i;
    }
    for(int i = 0; i<size;i++){
        int temp = arr.at(i);
        if(temp!=originalArr.at(i)){
            ascSwaps++;
            int index = mp[temp];
            mp[originalArr.at(i)]= index;
            swap(originalArr.at(i), originalArr.at(index));
        }
    }
    for(int j = 0; j<size;j++){
        int temp = vect1.at(j);
        if(temp!=originalArr2.at(j)){
            dscSwaps++;
            int index = mp2[temp];
            mp2[originalArr2.at(j)]= index;
            swap(originalArr2.at(j), originalArr2.at(index));
        }
    }
    if(ascSwaps<= dscSwaps){
        return ascSwaps;
    }
    else{
        return dscSwaps;
    }
    
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
    int  swaps = lilysHomework(arr);
    cout<<swaps;
}