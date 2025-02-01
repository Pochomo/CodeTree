#include <iostream>
#include <climits>

using namespace std;

int n;
int x1[100], x2[100];

bool overlapped(int exclude) {
    int cur_max_x1 = 0;
    int cur_min_x2 = INT_MAX;
    
    for (int i = 0; i < n; i++) {
        if (i == exclude) continue;
        cur_max_x1 = max(cur_max_x1, x1[i]);
        cur_min_x2 = min(cur_min_x2, x2[i]);
    }
    
    return cur_min_x2 >= cur_max_x1;
}

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> x1[i] >> x2[i];

    }

    //한개 선분 지워서 전부 만나는 지점 있는지 확인, 하나 지우고 확인하고 겹치면 break 하고 출력

    bool check = false;
    for (int i = 0; i < n; i++) { //지울 선분
        if(overlapped(i)){
            check = true;
            break;
        }
    }   

    if(check) cout << "Yes";
    else cout << "No";

    return 0;
}