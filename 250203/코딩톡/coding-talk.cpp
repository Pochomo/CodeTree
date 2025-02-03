#include <iostream>

using namespace std;

int n, m, p;
char c[100];
int u[100];
char people[26];
bool nonread[26];
int main() {
    cin >> n >> m >> p;

    for(int i = 0; i < 26; i++){
        people[i] = 'A' + i;
    }

    for (int i = 0; i < m; i++) {
        cin >> c[i] >> u[i];
    }
    //m개의 해당하는 메세지 정보가 주어졌을 때, p번째 메세지를 읽지 않았을 가능성이 있는 사람들의 이름을 찾아내는 프로그램
    //m개의 메세지 저보는 시간 순서대로 주어짐, 각 상황마다 어떤 사람이 보냈고, 그 메세지를 읽지 않은 사람이 몇명인지 주어짐

    //첫번째 줄 코딩톡 방에 있는 사람 n 메시지 정보 수 m 확인 필요한 메시지 번호 p
    
    //두번째 줄부터, m개의 줄에 걸쳐 메세지 정보c, u가 공백을 사이에 두고 주어짐, 사람 c가 올린 메시지,
    //아직 메시지를 읽지 않은 사람 수 가 u

    //읽으면 true로(메시지를 보내면 읽은것으로 간주)
    for (int i = p-1; i < m; i++) {
        nonread[c[i] - 'A'] = true;
    }

    for(int i = 0; i < n; i++){
        if(!nonread[i]) cout << people[i] << " ";
    }

    return 0;
}