vector<int> quickSort(vector<int> arr) {
    int pivot = arr[0];
    int equal = pivot;
    vector <int> rightVect;
    vector <int> leftVect;
    for(int i=1; i<int(arr.size()); i++){
        if(arr.at(i)<=pivot){
            leftVect.push_back(arr.at(i));
        }
        else{
            rightVect.push_back(arr.at(i));
        }
    }
    leftVect.push_back(equal);
    leftVect.insert(leftVect.end(), rightVect.begin(), rightVect.end());
    return leftVect;
    
}
