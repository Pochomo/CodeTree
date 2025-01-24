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
    
    bool isInteresting = false;
    for(int j = 0; j < num.length(); j++) {
        char base = num[j];
        int diffCount = 0;
        
        for(int k = 0; k < num.length(); k++) {
            if(num[k] != base) {
                diffCount++;
            }
        }
        
        if(diffCount == 1) {
            isInteresting = true;
            break;
        }
    }
    
    if(isInteresting) {
        cnt++;
    }
}
    
    cout << cnt;
    return 0;
}