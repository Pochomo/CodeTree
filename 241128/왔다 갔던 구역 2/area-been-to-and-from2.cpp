#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int inputN[100] = {0};
char inputL[100];
int result[2000] = {0};
int MAXN = 2000;

int main() {
    int n;
    char x;
    int x1;
    int OFFSET = 1000;
    cin >> n;
    inputN[0] = 1000;

    for(int i = 1; i <= n; i++){
        cin >> x1 >> x;
        inputN[i] = x1 + OFFSET;
        inputL[i-1] = x;
    }

    int num = 1;
    while(n != 0){
        if(inputL[num-1] == 'R'){
            if(inputN[num-1] > inputN[num]){
                for(int i = inputN[num-1]; i > inputN[num]; i--){
                result[OFFSET]++;
                OFFSET++;
                }
                OFFSET++;
            }
            else if(inputN[num-1] < inputN[num]){
                for(int i = inputN[num]; i > inputN[num-1]; i--){
                    result[OFFSET]++;
                    OFFSET++;
                }
                OFFSET++;
            }
        }
        if(inputL[num-1] == 'L'){
            if(inputN[num-1] > inputN[num]){
                for(int i = inputN[num-1]; i > inputN[num]; i--){
                    result[OFFSET]++;
                    OFFSET--;
                }
            }
            else if(inputN[num-1] < inputN[num]){
                for(int i = inputN[num]; i > inputN[num-1]; i--){
                    result[OFFSET]++;
                    OFFSET--;
                }
            }
        }
        num++;
        n--;
    }

    int cnt = 0;
    for(int i = 0; i < MAXN; i++){
        if(result[i] > 1){
            cnt++;
        }
    }

    cout << cnt;

    return 0;
}