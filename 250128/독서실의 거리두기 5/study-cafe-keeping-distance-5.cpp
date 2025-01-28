#include <iostream>
#include <string>
#include <climits>

using namespace std;

int N;
string seat;

int main() {
    cin >> N;
    cin >> seat;
    //좌석의 개수 N개, 공석 여부가 주어지면 한 명의 인원 배치 후 최대한 거리두기를 실행한 간격을 출력하는 프로그램

    //1은 이미 차있는 곳 최소 1개의 1이 주어짐
    //거리는 0의 개수 + 1
    int ans = INT_MIN;
    for(int i = 0; i < N; i++){
        int distanceb = 0;
        int distance = 0;
        int distancef = 0;
        if(seat[i] == '1') continue;
        for(int j = i; j < N; j++){
            if(seat[j] == '1'){
                break;
            }
            else{
                distancef++;
            }
        }
        for(int k = i; k >= 0; k--){//k=0부터 i까지 distance 구하고 //j = i부터 N 까지의 distance 구해서 비교
            if(seat[k] == '1'){
                break;
            }
            else{
                distanceb++;
            }
        }
        distance = min(distanceb, distancef);
        if(i == N-1){
            distance = distanceb;
        }
        else if(i == 0){
            distance = distancef;
        }
        ans = max(distance, ans);
    }

    cout << ans;

    return 0;
}