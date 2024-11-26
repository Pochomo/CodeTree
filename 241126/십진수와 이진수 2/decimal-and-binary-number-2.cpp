#include <iostream>
#include <string>
using namespace std;

int digits[100];
int results[100];

int main() {
    string n;
    cin >> n;
    int cnt = 0;
    int sum = 0;
    for(int i = 0; i < (int) n.size(); i++){
        digits[i] = (n[i] - '0');
        cnt++;
    }

    for(int i = 0; i < cnt; i++){
        sum = sum * 2 + digits[i];
    }

    sum*=17;
    cnt = 0;

    while(true){
        if(sum < 2){
            results[cnt++] = sum % 2;
            break;
        }
        results[cnt] = sum % 2;
        sum /= 2;
        cnt ++;
    }

    for(int i = (cnt-1); i >= 0; i--){
        cout << results[i];
    }

    return 0;
}