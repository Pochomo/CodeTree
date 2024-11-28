#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int inputN[100] = {0};
char inputL[100];
int result[2001] = {0};
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
    int current = OFFSET;
    for(int i = 0; i < n; i++){
        if(inputL[num-1] == 'R'){
            for(int i = OFFSET; i < inputN[num]; i++){
                result[current]++;                
                current++;     
                }         
            }             
        if(inputL[num-1] == 'L'){             
            for(int i = OFFSET; i < inputN[num]; i++){
                current--;
                result[current]++;                 
            }         
        }               
        num++;     
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