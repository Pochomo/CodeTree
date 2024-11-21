#include <iostream>
#include <algorithm>
using namespace std;

int* arrA;
int* arrB;
int a;

bool cheak(){
    for(int i = 0; i < a; i++){
        if(arrA[i] != arrB[i]){
            return false;
        }
    }
    return true;
}

void yOrN(){
    if(cheak()){
        cout << "Yes";
    }
    else{
        cout << "No";
    }
}

int main() {
    cin >> a;
    arrA = new int[a];
    arrB = new int[a];

    for(int i = 0; i < a; i++){
        cin >> arrA[i];
    }

    for(int i = 0; i < a; i++){
        cin >> arrB[i];
    }

    sort(arrA, arrA + a);
    sort(arrB, arrB + a);

    yOrN();

    return 0;
}