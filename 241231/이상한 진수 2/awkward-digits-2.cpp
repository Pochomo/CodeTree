#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

//int arrA[10];

int main() {
    string a;
    cin >> a;
    int num = 0;
    int temp = 1;
    int s_length = (int)a.size();

    // for(int i = 0; i < s_length; i++) {
    //     arrA[i] = a[i] - '0';
    // }

    for(int i = 0; i < s_length; i++){
        if(a[i] == '0'){
            a[i] = '1';
            break;
        }
    }

    int b = stoi(a);

    while(b > 0){
        num = num + (b % 10) * temp;
        b = b / 10;
        temp = temp * 2;
    }

    cout << num;

    return 0;
}