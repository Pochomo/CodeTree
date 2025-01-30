#include <iostream>

using namespace std;

int n;
int adjacent[1001];
int elements[1001];

bool isDuplicate(int index) {
    //중복 검사
    for (int i = 1; i < index; i++) {
        if (elements[i] == elements[index]) {
            return true;
        }
    }
    return false;
}

//1이상 N이하의 숫자들이 단 한 번씩만 등장하는 길이가 N인 수열 A
//이 수열에서 인접한 원소의 합을 순서대로 구한 N-1개의 숫자가 주어졌을때, 초기 수열 A를 복원하는 프로그램
int main() {
    cin >> n;

    for (int i = 1; i < n; i++) {
        cin >> adjacent[i];
    }

    for (int first = n; first >= 1; first--) {
        elements[1] = first;
        bool valid = false;
        for (int i = 2; i < n + 1; i++) { //elements 정하는 loop
            for(int j = 1; j <= n; j++){
                elements[i] = j;
                if(isDuplicate(i)){
                    continue;
                }
                if(elements[i] ==(adjacent[i - 1] - elements[i - 1])){
                    valid = true;
                    break; //맞는 값 찾음
                }
                else{
                    valid = false;
                }
            }
            if(!valid){ //맞는 값을 끝까지 못찾음 fisrt 값을 새로 받음
                break;
            }
        }
        if(valid) break;
    }

    for (int i = 1; i < n + 1; i++) {
        cout << elements[i] << " ";
    }

    return 0;
}
