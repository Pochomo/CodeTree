#include <iostream>

using namespace std;

int pos[3];

int main() {
    for (int i = 0; i < 3; i++) cin >> pos[i];

    //정렬돼있으면 0번
    //끝자리 하나만 연속되지않으면 1번
    //모두 연속되지 않으면 2번
    //양쪽 끝에 서있는 사람 한 명을 선택해서 중앙에 놓는 거임

    //무조건 답이 1이되는 경우 중앙이랑 한쪽이 2차이 날 때
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
        if(pos[i+1] - pos[i] == 1) cnt++;
        if(cnt == 2){
            cout << 0;
            return 0; 
        }
    }


    cnt = 0;
    for(int i = 0; i < 2; i++){
        if(pos[i+1] - pos[i] != 2) cnt++; 
    }

    cout << cnt;
    return 0;
}