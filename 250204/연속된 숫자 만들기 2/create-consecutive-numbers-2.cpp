#include <iostream>

using namespace std;

int pos[3];

int main() {
    for (int i = 0; i < 3; i++) cin >> pos[i];

    //정렬돼있으면 0번
    //끝자리 하나만 연속되지않으면 1번
    //모두 연속되지 않으면 2번
    int cnt = 0;
    for(int i = 0; i < 2; i++){
        if(pos[i+1] - pos[i] == 2){
            cnt++;
            cout << cnt;
            return 0; 
        }
    }
    cnt = 0;
    for(int i = 0; i < 2; i++){
        if(pos[i+1] - pos[i] != 1) cnt++; 
    }

    cout << cnt;
    return 0;
}