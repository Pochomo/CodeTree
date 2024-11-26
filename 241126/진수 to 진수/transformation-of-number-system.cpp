#include <iostream>
#include <string>
using namespace std;

int digits[100];

int main() {
    int a, b; //a진수로 주어진 n을 b진수로 변환
    string n;
    cin >> a >> b;
    cin >> n;
    int sum = 0;
    int cnt = 0;

    for(int i = 0; i < (int) n.size(); i++){
        digits[i] = (n[i] - '0');
        cnt ++;
    }
    
    for(int i = 0; i < cnt; i++){
        sum  = sum * a + digits[i];
    }

    cnt = 0;

    while(true){
        if(sum < b){
            digits[cnt++] = sum % b;
            break;
        }
        digits[cnt++] = sum % b;
        sum /= b;
    }

    for(int i = (cnt-1); i >= 0; i--){
        cout << digits[i];
    }

    return 0;
}