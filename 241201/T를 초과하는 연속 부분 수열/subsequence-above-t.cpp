#include <iostream>
#include <algorithm>

using namespace std;

int arrA[1000];

int main() {
    int n, t, elm;
    cin >> n >> t;

    for(int i = 0; i < n; i++){
        cin >> elm;
        arrA[i] = elm;
    }

    int cnt = 0;
    int max_c = 0;
    for(int i = 0; i < n; i++){
        if(arrA[i] > t){
            cnt++;
        }
        else{
            cnt = 0;
        }
        max_c = max(max_c, cnt);
    }

    cout << max_c;
    return 0;
}