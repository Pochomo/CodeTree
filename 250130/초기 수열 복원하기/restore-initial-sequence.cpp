#include <iostream>

using namespace std;

int n;
int adjacent[1001];
int elements[1001];

//1이상 N이하의 숫자들이 단 한 번씩만 등장하는 길이가 N인 수열 A
//이 수열에서 인접한 원소의 합을 순서대로 구한 N-1개의 숫자가 주어졌을때, 초기 수열 A를 복원하는 프로그램
int main() {
    cin >> n;

    for (int i = 1; i < n; i++) {
        cin >> adjacent[i];
    }
    
    elements[1] = adjacent[1] - 1;
    for (int i = 2; i < n + 1; i++) { //elements 정하는 loop
        for (int j = 1; j <= n; j++) { 
            if(elements[i-1] + j == adjacent[i-1]){
                elements[i] = j;
                break;
            }
        }
    }

    for (int i = 1; i < n + 1; i++) {
        cout << elements[i] << " ";
    }
    return 0;
}