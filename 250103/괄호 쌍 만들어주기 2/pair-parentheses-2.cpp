#include <iostream>
#include <string>

using namespace std;

string A;

int main() {
    cin >> A;
    int cnt = 0;

    //난 이렇게 풀었지만 답지는 && 사용함, &&사용 방법도 생각해보면 코드가 더 깔끔한 거 확인
    for(int i = 0; i < (int)A.size(); i++){
        if(A[i] == '('){
            if(A[i+1] == '('){
                for(int j = i + 2; j < (int)A.size(); j++){
                    if(A[j] == ')'){
                        if(A[j+1] == ')'){
                            cnt++;
                        }
                    }
                }
            }
        }
        else{
            continue;
        } 
    }

    cout << cnt;
    return 0;
}