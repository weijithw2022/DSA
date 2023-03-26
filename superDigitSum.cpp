#include <string>
#include <iostream>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

/*
 * Complete the 'superDigit' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts following parameters:
 *  1. STRING n
 *  2. INTEGER k
 */

int superDigit(string n, int k) {
    if(n.length()==1){
        return stoi(n);
    }
    int len = n.length();
    long sum = 0;
    for(int j =0; j< len; j++){
        sum += (long)(n[j])-48;
    }
    if(k>1){
        sum *= k;
    }
    return superDigit(to_string(sum), 1);
}

int main()
{

    int ans = superDigit("9875", 4);
    cout<< ans;
    return 0;
}

