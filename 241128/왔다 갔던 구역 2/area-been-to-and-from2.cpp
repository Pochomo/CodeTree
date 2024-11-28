#include <iostream>
using namespace std;

int list[2000] = {0};

int main() {
    int n, x;
    cin >> n;
    char dir;
    int loc = 1000;

    for(int i = 0; i < n; i++){
        cin >> x >> dir;
        if(dir == 'L'){
            for(int j = loc; j >= loc - x; j--){
                list[j]++;
            }
            loc -= (x+1);
        }
        else if(dir == 'R'){
            for(int j = loc; j <= loc + x; j++){
                list[j]++;
            }
            loc += (x-1);
        }
    }

    int cnt=0;
    for(int i = 0; i < 2000; i++){
        if(list[i] > 1) {
            cnt++;
        }
    }
    cout << cnt;
    return 0;
}