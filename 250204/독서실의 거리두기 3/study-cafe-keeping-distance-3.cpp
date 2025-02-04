#include <iostream>
#include <string>
#include <climits>

using namespace std;

int N;
string seats;
int start_p;
int end_p;

//가장 먼거리의 쌍이 어딘지 확인
void check_distance(){
    int distance = 0;
    int temp = 0;
    for(int i = 0; i < N; i++){
        for(int j = i + 1; j < N; j++){
            if(seats[i] == '1'){
                if(seats[j] == '1'){
                    temp = j - i;
                    if(distance < temp){
                        distance = temp; 
                        start_p = i; 
                        end_p = j;
                    }
                    break;
                }
            }
        }
    }
}

int main() {
    cin >> N;
    cin >> seats;

    //start랑 end 초기화됨
    check_distance();
    //0을 1로 바꿔가면서 최소의 거리를 최대로 하는 로직
    int ans = INT_MIN;

    for(int i = start_p; i < end_p; i++){
        if(seats[i] == '1') continue;
        seats[i] = '1';

        int min_gap = INT_MAX;
        for(int k = 0; k < N; k++){
            if(seats[k] == '1'){
                for(int j = k + 1; j < N; j++){
                    if(seats[j] == '1'){
                        int gap = j - k;
                        min_gap = min(min_gap, gap);
                        break;
                    }
                }
            }
        }
        ans = max(ans, min_gap);
        seats[i] = '0';
    }

    cout << ans;


    return 0;
}