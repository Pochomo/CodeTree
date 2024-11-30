#include <iostream>
#include <algorithm>
using namespace std;

int arrA[1000];

int main() {
    int n, num;
    cin >> n;

    for(int i = 0; i < n; i++){
        cin >> num;
        arrA[i] = num;
    }

    int m_num = 0;
    int cnt = 0;
    for(int i = 0; i < n; i++){
        if(i == 0 || (arrA[i] > arrA[i-1])){
            cnt ++;
        }
        else{
            cnt = 1;
        }

        m_num = max(m_num, cnt);
    }

    cout << m_num;

    return 0;
}