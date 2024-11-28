#include <iostream>
using namespace std;

int OFFSET = 100000;
int x1[1000] = {0};
int x2[1000] = {0};
int lOrR[200000] = {0};
int result[200000] = {0};
char dire[1000] = {' '};

int main() {
    int n;
    int x;
    char direction;
    cin >> n;

    int cur = OFFSET;
    for(int i = 0; i < n; i++){

        cin >> x >> direction;
        dire[i] = direction;
        if(direction == 'L'){
            while(x--){
                lOrR[cur] = 1;
                if(x){
                    cur--;
                }
            }
        }
        if(direction == 'R'){
            while(x--){
                lOrR[cur] = 2;
                if(x){
                    cur++;
                }
            }
        }
    }

    int l = 0;
    int r = 0;

    for(int i = 0; i < 200000; i++){
        if(lOrR[i] == 1){
            l++;
        }
        else if(lOrR[i] == 2){
            r++;
        }
    }

    cout << l << " " << r;
    
    return 0;
}