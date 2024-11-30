#include <iostream>
#include <algorithm>

using namespace std;

int arrA[1000];
int arrB[1000];


void cheack(int max_location){
    for(int i = 0; i < max_location; i++){
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

    int final_location;
    for(int i = 0; i < n; i++){
        cin >> d >> t;
        if(d == 'R'){
            for(int j = 0; j < t; j++){
                arrA[j] = ++location;
                final_location++;
            }
        }
        else if(d == 'L'){
            for(int j = 0; j < t; j++){
                arrA[j] = --location;
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
            for(int j = 0; j < t; j++){
                arrB[j] = ++location;
                final_location++;
            }
        }
        else if(d == 'L'){
            for(int j = 0; j < t; j++){
                arrB[j] = --location;
                final_location++;
            }
        }
    }

    max_location = max(max_location, final_location);

    cheack(max_location);

    return 0;
}