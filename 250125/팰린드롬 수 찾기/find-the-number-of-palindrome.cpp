#include <iostream>
#include <string>
using namespace std;

int X, Y;

int main() {
    cin >> X >> Y;

    //거꾸로 읽어도 제대로 읽은 것과 같은 수를 찾아라
    int cnt = 0;
    for(int i = X; i <= Y; i++){
        string num = to_string(i);
        int length = num.length();
        //맨 처음이랑 맨 끝 비교 홀수면  7-1/2번 비교
        //5577755
        int correct = true;
        for(int j = 0; j < (length) / 2; j++){
            if(num[j] != num[length - 1 - j]){
                correct = false;
                break;
            }
        }
        if(correct) cnt ++;
    }

    cout << cnt;

    return 0;
}