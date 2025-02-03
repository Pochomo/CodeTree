#include <iostream>

using namespace std;

int n, m, p;
char c[100];
int u[100];
char people[26];
bool read[26];
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

    //p의 숫자에 따라 몇명인지 정해짐, u[i] == 0 일때 빼곤 같거나 커야함
    int nreadPeople = u[p-1];
    for(int i = 0; i < n; i++){ //답이 될 수 있는 모든 경우의 수 탐색, 확실히 읽은 사람이면 nonread = true로 변환
        if(nreadPeople == 0) break; //다 읽음
        for (int j = p-1; j < m; j++) {
            if(people[i] == c[j]) {
                read[people[i] - 'A'] = true;
                break;
            }
        }
    }
    
    for(int i = 0; i < n; i++){
        if(nreadPeople > 0 && !read[i]) cout << people[i] << " ";
    }
    
    
    return 0;
}