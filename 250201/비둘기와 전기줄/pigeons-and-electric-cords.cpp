#include <iostream>

using namespace std;

int N;
int pigeon[100];
int position[100];

int main() {
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> pigeon[i] >> position[i];
    }

    //비둘기 왼쪽에 있으면 0 오른쪽에 있으면 1, 비둘기 관찰 횟수 N과 N번 만큼 몇 번 비둘기가 어느 위치에 있는지주어짐
    //최소 몇번 도로 건너갔는지 구하라
    int cnt = 0;
    for (int num = 1; num <= 10; num++){ //1에서 0 or 0에서 1로 바뀌면 cnt++
        int prev = -1;
        int current = -1;
        for(int i = 0; i < N; i++){
            if(pigeon[i] == num && prev == -1){ //처음 발견됐을 때
                prev = position[i];
            }
            else if(pigeon[i] == num && prev != position[i]){
                cnt++;
                prev = position[i];
            }
        }
    }

    cout << cnt;

    return 0;
}