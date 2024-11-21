#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

string* arr;
string* checkArr;
int n, k;
string t;
int z;

void checkCorrect(){
    z = 0;
    for(int i = 0; i < n; i++){
        string temp = arr[i];
        int count = 0;
        for(int j = 0; j < t.size(); j++){
            if(t[j] == temp[j]){
                count++;
            }
            else{
                break;
            }
            if(count == t.size()){
                checkArr[z] = temp;
                z++;
            }
        }
    }
}

int main() {
    cin >> n >> k >> t;
    arr = new string[n];
    checkArr = new string[n];
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }
    checkCorrect();
    sort(checkArr, checkArr + z);

    cout << checkArr[k-1] << endl;

    
    delete[] arr;
    delete[] checkArr;

    return 0;
}