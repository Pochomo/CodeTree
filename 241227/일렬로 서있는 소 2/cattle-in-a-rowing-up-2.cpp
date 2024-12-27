#include <iostream>
#include <cstdlib>
#include <algorithm>

using namespace std;

int arrA[100];

int main() {
    int n;
    int cow;
    cin >> n;
    int cnt = 0;

    for(int i = 0; i < n; i++){
        cin >> cow;
        arrA[i] = cow;
    }

    for(int i = 0; i < n; i++){ 
        for(int j = i + 1; j < n; j++){
            for(int k = j + 1; k < n; k++){
                if((arrA[i] <= arrA[j]) &&(arrA[j] <= arrA[k])){
                    cnt++;
                }
            }
        }
    }
    
    cout << cnt;


    return 0;
}