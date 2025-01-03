#include <iostream>
#include <string>

using namespace std;

int n;
string str;

int main() {
    cin >> n;
    cin >> str;

    int cnt = 0;
    for(int i = 0; i < n; i++){
        if(str[i] == 'C'){
            for(int j = i+1; j < n; j++){
                if(str[j] == 'O'){
                    for(int k = j+1; k < n; k++){
                        if(str[k] == 'W'){
                            cnt++;
                            continue;
                        }
                    }
                    continue;
                }
            }
        }
    }

    // 답지코드
    // for(int i = 0; i < n; i++)
    //     for(int j = i + 1; j < n; j++)
    //         for(int k = j + 1; k < n; k++)
    //             if(str[i] == 'C' && str[j] == 'O' && str[k] == 'W')
    //                 cnt++;
    

    cout << cnt;

    return 0;
}