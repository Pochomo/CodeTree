#include <iostream>
#include <algorithm>
#include <climits>

using namespace std;

int N;
int sequence[100];
int sorted_sequence[100];

int main() {
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> sequence[i];
        sorted_sequence[i] = sequence[i];
    }

    sort(sorted_sequence, sorted_sequence + N);

    bool correct = false;
    int cnt = 0;
    while(true){
        int temp = sequence[0];
        if(temp > sequence[N-1]){ //맨 뒤 숫자보다 크면 맨 뒤 숫자 뒤에 배치
            for(int i = 0; i < N-1; i++){
                sequence[i] = sequence[i+1];
            }
            sequence[N-1] = temp;
            cnt++;
        }
        else if(temp < sequence[N-1]){ //맨 뒤 숫자보다 작으면 그 앞에 배치
            for(int i = 0; i < N-2; i++){
                sequence[i] = sequence[i+1];
            }
            sequence[N-2] = temp;
            cnt++;
        }
        for(int i = 0; i < N; i++){
            if(sorted_sequence[i] != sequence[i]){
                correct = false;
                break;
            }
            else correct = true;
        }

        if(correct) break;
    }

    cout << cnt;

    return 0;
}