#include <iostream>

using namespace std;

int n;
int x1[100], x2[100];

int main() {
    cin >> n;

    //1차원 직선 상에 n개의 선분, 모든 선분이 겹치는 지점이 있는지 판단하는 프로그램 경계에서 만나도 겹치는거임
    for (int i = 0; i < n; i++) {
        cin >> x1[i] >> x2[i];
    }

    //하나라도 안겹치면 false
    bool overlapped = true;
    for (int i = 0; i < n-1; i++) {
        if(x1[i] > x2[i+1]) overlapped = false;
        else if(x2[i] < x1[i+1]) overlapped = false;
    }

    if(overlapped) cout << "Yes";
    else if(!overlapped) cout << "No";

    return 0;
}