vector<int> closestNumbers(vector<int> arr) {
    int size = arr.size();
    int min=0;
    vector <int> vect1;
    for(int i=0; i<size-1; i++){
        for(int j=i+1; j<size; j++){
            int temp =  abs(arr.at(i) - arr.at(j));
            if(i==0 and j==1){
                min = temp;
                if(arr.at(j)>arr.at(i)){
                    vect1.push_back(arr.at(i));
                    vect1.push_back(arr.at(j));
                }
                else{
                    vect1.push_back(arr.at(j));
                    vect1.push_back(arr.at(i));
                }
            }
            if(temp==min){
                if(arr.at(j)>arr.at(i)){
                    vect1.push_back(arr.at(i));
                    vect1.push_back(arr.at(j));
                }
                else{
                    vect1.push_back(arr.at(j));
                    vect1.push_back(arr.at(i));
                }
            }
            if(temp<min){
                min = temp;
                vect1.clear();
                if(arr.at(j)>arr.at(i)){
                    vect1.push_back(arr.at(i));
                    vect1.push_back(arr.at(j));
                }
                else{
                    vect1.push_back(arr.at(j));
                    vect1.push_back(arr.at(i));
                }
            }
        }
    }
    sort(vect1.begin(), vect1.end());
    return vect1;
}
