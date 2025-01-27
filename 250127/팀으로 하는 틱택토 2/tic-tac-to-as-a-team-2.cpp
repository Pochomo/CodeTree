#include <iostream>
#include <string>

using namespace std;

string inp[3];
string arr[100] = {};

bool duplicated(string team){
    for(int i = 0; i < 100; i++){
        if(arr[i] == team) return true;
    }
    return false;
}

string makeTeam(char a, char b) {
    if (a > b) swap(a, b); //작은 문자 -> 큰 문자 순 정렬
    return to_string(a - '0') + to_string(b - '0');
}

int main() {
    for (int i = 0; i < 3; i++) cin >> inp[i];

    int cnt = 0;

    //2명이 한팀, 한 줄에 팀을 이루고 있는 2개의 숫자가 적어도 하나씩은 등장해야 이긴거임
    //111은 개인이 이긴거임
    //대각선, x, y에서 하나 숫자가 2개 나오면 이긴거임 886 8,6 이 승리
    //첫 번째 줄에 2명이 한팀이 되어 진행했을때 이길 수 있었던 팀의 수
    //팀이 똑같은 팀인지 아닌지 확인하는 로직 필요
    int index = 0;
    //가로 검사
    for (int i = 0; i < 3; i++) {
        if (inp[i][0] == inp[i][1] && inp[i][0] != inp[i][2]) {
            string team = makeTeam(inp[i][0], inp[i][2]);
            if (!duplicated(team)) {
                arr[index++] = team;
                cnt++;
            }
        }
        if (inp[i][0] == inp[i][2] && inp[i][0] != inp[i][1]) {
            string team = makeTeam(inp[i][0], inp[i][1]);
            if (!duplicated(team)) {
                arr[index++] = team;
                cnt++;
            }
        }
        if (inp[i][1] == inp[i][2] && inp[i][1] != inp[i][0]) {
            string team = makeTeam(inp[i][1], inp[i][0]);
            if (!duplicated(team)) {
                arr[index++] = team;
                cnt++;
            }
        }
    }

    //세로 검사
    for (int j = 0; j < 3; j++) {
        if (inp[0][j] == inp[1][j] && inp[0][j] != inp[2][j]) {
            string team = makeTeam(inp[0][j], inp[2][j]);
            if (!duplicated(team)) {
                arr[index++] = team;
                cnt++;
            }
        }
        if (inp[0][j] == inp[2][j] && inp[0][j] != inp[1][j]) {
            string team = makeTeam(inp[0][j], inp[1][j]);
            if (!duplicated(team)) {
                arr[index++] = team;
                cnt++;
            }
        }
        if (inp[1][j] == inp[2][j] && inp[1][j] != inp[0][j]) {
            string team = makeTeam(inp[1][j], inp[0][j]);
            if (!duplicated(team)) {
                arr[index++] = team;
                cnt++;
            }
        }
    }

    //대각선 검사
    if (inp[0][0] == inp[1][1] && inp[0][0] != inp[2][2]) {
        string team = makeTeam(inp[0][0], inp[2][2]);
        if (!duplicated(team)) {
            arr[index++] = team;
            cnt++;
        }
    }
    if (inp[0][0] == inp[2][2] && inp[0][0] != inp[1][1]) {
        string team = makeTeam(inp[0][0], inp[1][1]);
        if (!duplicated(team)) {
            arr[index++] = team;
            cnt++;
        }
    }
    if (inp[1][1] == inp[2][2] && inp[1][1] != inp[0][0]) {
        string team = makeTeam(inp[1][1], inp[0][0]);
        if (!duplicated(team)) {
            arr[index++] = team;
            cnt++;
        }
    }

    //오른쪽 위 -> 왼쪽 아래 대각선
    if (inp[0][2] == inp[1][1] && inp[0][2] != inp[2][0]) {
        string team = makeTeam(inp[0][2], inp[2][0]);
        if (!duplicated(team)) {
            arr[index++] = team;
            cnt++;
        }
    }
    if (inp[0][2] == inp[2][0] && inp[0][2] != inp[1][1]) {
        string team = makeTeam(inp[0][2], inp[1][1]);
        if (!duplicated(team)) {
            arr[index++] = team;
            cnt++;
        }
    }
    if (inp[1][1] == inp[2][0] && inp[1][1] != inp[0][2]) {
        string team = makeTeam(inp[1][1], inp[0][2]);
        if (!duplicated(team)) {
            arr[index++] = team;
            cnt++;
        }
    }

    cout << cnt << endl;
    return 0;
}