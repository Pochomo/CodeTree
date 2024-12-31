#include <iostream>
#include <algorithm>
#include <string>
using namespace std;


int main() {
    string a;
    cin >> a;
    int num = 0;
    int temp = 1;
    int s_length = (int)a.size();
    int cnt = 0;
    for(int i = 0; i < s_length; i++){
        for(int j = 0; j < s_length; j++){
            if(a[j] == '0'){
                a[j] = '1';
                cnt++;
                break;
            }
        }
        if(cnt != 1){
            if(a[s_length - 1] == '0'){
                a[s_length - 1] = '1';
            }
            else if(a[s_length - 1] == '1'){
                a[s_length - 1] = '0';
            }
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