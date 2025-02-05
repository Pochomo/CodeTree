#include <iostream>
#include <climits>

using namespace std;

int n;
char c[100];
int s[100];

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> c[i] >> s[i];
    }
    //c는 A B 둘중 하나, S 는 점수 변동값
    //A, B, C가 게임, 게임 점수가 바뀔 때 마다 1등인 사람을 명전에 올려줌, 조합 몇번 바뀌었는지 출력
    int score_A = 0;
    int score_B = 0;
    int score_C = 0;
    int cnt = 0;
    char king = 'N';
    int max_num = INT_MIN; 
    for (int i = 0; i < n; i++) {
        if (c[i] == 'A') {
            score_A += s[i];
        } else if(c[i] == 'B'){
            score_B += s[i];
        } else if(c[i] == 'C'){
            score_C  += s[i];
        }
        
        char new_king;
        if (score_A > max_num) {
            new_king = 'A';
        } else if (score_B > max_num) {
            new_king = 'B';
        }  else if (score_C > max_num) {
            new_king = 'C';
        }
        else {
            new_king = 'N';
        }
        
        max_num = max(max(score_A, score_B), max_num);
        max_num = max(score_C, max_num);
        
        if (new_king != king) {
            cnt++;
            king = new_king;
        }
    }

    cout << cnt;
    return 0;
}