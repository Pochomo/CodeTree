#include <iostream>
#include <algorithm>

using namespace std;

int arrA[1000] = {0};
int arrB[1000] = {0};


void cheack(int max_location){
    for(int i = 1; i <= max_location; i++){
        if(arrA[i] == arrB[i]){
            cout << i;
            return;
        }
    }  
    cout << -1;
}

int main(){
    int n, m;
    char d;
    int t;
    cin >> n >> m; // n은 A m은 B
    int cnt = 0;
    int location = 0;
    arrA[0] = 0;
    arrB[0] = 0;
    int indexA = 1;
    int indexB = 1;
    int final_location = 0;
    for(int i = 0; i < n; i++){
        cin >> d >> t;
        if(d == 'R'){
            for(int j = 1; j <= t; j++){
                location++;
                arrA[indexA++] = location;
                final_location++;
            }
        }
        else if(d == 'L'){
            for(int j = 1; j <= t; j++){
                location--;
                arrA[indexA++] = location;
                final_location++;
            }
        }
    }

    int max_location = final_location;
    final_location = 0;
    location = 0;
    for(int i = 0; i < m; i++){
        cin >> d >> t;
        if(d == 'R'){
            for(int j = 1; j <= t; j++){
                location++;
                arrB[indexB++] = location;
                final_location++;
            }
        }
        else if(d == 'L'){
            for(int j = 1; j <= t; j++){
                location--;
                arrB[indexB++] = location;
                final_location++;
            }
        }
    }

    max_location = min(max_location, final_location);

    cheack(max_location);

    return 0;
}