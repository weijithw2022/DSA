#include <iostream>
#include <vector>

using namespace std;
// void bubleSort(int arr[],int len){
//   for (int i = 0; i < len; i++) {
//     for (int j = 0; j < len - i; j++) {
//       if (arr[j] > arr[j + 1]) {
//         int temp = arr[j];
//         array[j] = array[j+ 1];
//         array[j+ 1] = temp;
//       }
//     }
//   }
// }
float Median(vector<int>& vect, int len){
    float median;
    int newLen = len+1;
    if (len==0){
        median = vect.at(len);
    }
    else if((newLen)%2 ==0){
        median= (float(vect.at(len/2))+ float(vect.at(newLen/2)))/2;
    }
    else{
        median = float(vect.at(len/2));
    }
    return median;
}

int main(){
    int n;
    cin>>n;
    vector <int> vect;
    cout<<"elements:";
    
    for (int i=0; i<n;i++)
    {
        int ele;
        cin >> ele;
        for(int j=0; j<= i; j++){
            if(i==0){
                vect.push_back(ele);
            }
            if(vect.at(j)>ele){
                vect.insert(vect.begin()+j,ele);
                break;
            }
        }
        float median = Median(vect, i);
        cout<<median<<"\n";
    }
    return 0;
}

