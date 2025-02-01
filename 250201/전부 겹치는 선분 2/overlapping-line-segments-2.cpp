#include <iostream>
#include <climits>

using namespace std;

int n;
int x1[100], x2[100];
int max_x1;
int min_x2 =  INT_MAX;
bool overlapped(int exclude){
    for(int i = 0; i < n; i++){
        if(exclude == i) continue;
        max_x1 = max(max_x1, x1[i]);
        min_x2 = min(min_x2, x2[i]);
        if(min_x2 >= max_x1) return true;
        else return false;
    }
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