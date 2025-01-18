#include <iostream>
#include <algorithm>
#include <climits>

using namespace std;

int N, M, D, S;
int p[1000], m[1000], t[1000];
int sick_p[50], sick_t[50];

int main() {
    cin >> N >> M >> D >> S;
    //N명의 사람이 M가지(1 ~ M)의 치즈를 먹었는데 하나의 치즈가 상했다는것을 뒤늦게 알았다.
    //특정 사람이 어떤 치즈를 언제 먹었는지에 대한 기록 D번 (M가지의 치즈 중)
    //상한치즈 or 안상한치즈
    //상한 치즈를 먹게 되면 1초가 지나야 아프다.
    for (int i = 0; i < D; i++) {
        cin >> p[i] >> m[i] >> t[i]; //p번이 m치즈를 t초에 먹었다.
    }
    
    for (int i = 0; i < S; i++) {
        cin >> sick_p[i] >> sick_t[i];
    }
    //특정 사람이 언제 확실히 아팠는지에 대한 기록 S번 -> 완벽하게 기록된건 x 다른사람도 아플 수 있음
    // t 초 후에 sick_p[i] 가 아팠다.
    //상한 치즈를 먹은 사람에게 약을 복용시켜야할 때, 약이 최대 몇 개나 필요한지
    int ans = 0;
    int infection[1000]; //감염될 가능성이 있는 치즈 모두 투입
    //병 걸리게 한 치즈 부터 탐색 그 치즈를 몇 명이 먹었는지 확인
    //안 먹었는데도 아플 수 도 있다.
    int index = 0;
    for (int i = 0; i < S; i++) { // 시간과 아픈 사람을 변수에 담고 탐색 시작 ex) 1번이 3초에 아팠으니 3초전에 1이 먹은 건 모두 감염 될 수 o
        int sick_Person = sick_p[i];
        int sick_Time = sick_t[i];
        for (int j = 0; j < D; j++) {
            if (sick_Person == p[j] && t[j] < sick_Time) {
                // 이 치즈가 모든 아픈 사람들의 케이스를 설명할 수 있는지 확인
                bool possible = true;
                for (int k = 0; k < S; k++) {
                    bool found = false;
                    for (int l = 0; l < D; l++) {
                        if (sick_p[k] == p[l] && m[j] == m[l] && t[l] < sick_t[k]) {
                            found = true;
                            break;
                        }
                    }
                    if (!found) {
                        possible = false;
                        break;
                    }
                }
                if (possible) {
                    infection[index] = m[j];
                    index++;
                }
            }
        }
    }

    sort(infection, infection + index);

    for (int i = 0; i < index; i++) {
        bool counted[51] = {false};
        int cnt = 0;
        for (int j = 0; j < D; j++) {
            if(infection[i] == m[j] && !counted[p[j]]){
                counted[p[j]] = true;
                cnt++;
            }
        }
        ans = max(ans, cnt);
    }
    

    cout << ans;

    return 0;
}