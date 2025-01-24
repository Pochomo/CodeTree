#include <iostream>
#include <string>

using namespace std;

int main() {
    int X, Y;
    cin >> X >> Y;
    
    //한 자리 수만 다르면 흥미로운 수
    int cnt = 0;
    
    for(int i = X; i <= Y; i++) {
        string num = to_string(i);
        
        if(num.length() < 2) continue;
        
        char base = num[0];
        char diff = '0';
        int diffCount = 0;

        for(int i = 1; i < num.length(); i++) {
            char digit = num[i];
            if(digit != base) {
                if(diff == '0') {
                    diff = digit;
                    diffCount++;
                }
                else if(digit != diff) {
                    diffCount++;
                    break;
                }
            }
        }
        
        if(diffCount == 1) cnt++;
    }
    
    cout << cnt;
    return 0;
}