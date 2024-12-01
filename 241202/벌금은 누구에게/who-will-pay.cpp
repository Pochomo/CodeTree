#include <iostream>
using namespace std;

int student[101];
int cheak_rule[101] = {0};
int break_rule[10001];

int rule(int k, int m){
    for(int i = 0; i < m; i++){
        cheak_rule[break_rule[i]]++;
        if(cheak_rule[break_rule[i]] == k){
            return student[break_rule[i] - 1];
        }
    }
    return -1;
}

int main() {
    int n, m, k;
    cin >> n >> m >> k;
    int st_num;
    for(int i = 0; i < n; i++){
        student[i] = i+1;
    }
    //벌칙 어긴 학생
    for(int i = 0; i < m; i++){
        cin >> st_num;
        break_rule[i] = st_num;
    }

    int result = rule(k, m);
    if(result != -1){
        cout << result;
    }
    else{
        cout << -1;
    }

    return 0;
}