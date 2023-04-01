#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <fstream>

using namespace std;
int lilysHomeWork(vector <int>arr){
    // int n = arr.size();
    // int i = 0; 
    // int swaps = 0;
    // bool flag = false;
    // vector <int> sumVect;
    // // int firstSum = 0;
    // while(i<n and !flag){
    //     int minIndex = i;
    //     flag = true;
    //     int sum = 0;
    //     for (int j=i+1; j<n; j++)
    //     {
    //         sum += abs(arr.at(j)-arr.at(j-1));
    //         // if(i==0){
    //         //     firstSum = sum;
    //         // }
    //         if (arr.at(j)<arr.at(minIndex))
    //         {
    //             minIndex = j;
    //             flag = false;
    //         }
            
    //     }
    //     sumVect.push_back(sum);
    //     if(flag){
    //         break;
    //     }
    //     // swaps++;
    //     swap(arr.at(minIndex), arr.at(i));
    //     // if (firstSum> sum){
    //     //     break;
    //     // }
    //     i++;
    // }
    // int minimal = *min_element(sumVect.begin(), sumVect.end());
    // auto itr = find(sumVect.begin(),  sumVect.end(), minimal);
    // swaps = itr-sumVect.begin();
    // return swaps;
    int n = arr.size();
    int i = 0; 
    int swaps = 0;
    bool flag = false;
    int firstSum = 0;
    while(i<n and !flag){
        int minIndex = i;
        flag = true;
        int sum = 0;
        for (int j=i+1; j<n; j++)
        {
            sum += abs(arr.at(j)-arr.at(j-1));
            if(i==0){
                firstSum = sum;
            }
            if (arr.at(j)<arr.at(minIndex))
            {
                minIndex = j;
                flag = false;
            }
            
        }
        if(flag){
            break;
        }
        swaps++;
        swap(arr.at(minIndex), arr.at(i));
        if (firstSum> sum){
            break;
        }
        i++;
    }
    return swaps;            

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
    int swaps = lilysHomeWork(arr);
    cout<<swaps;
    return 0;
}