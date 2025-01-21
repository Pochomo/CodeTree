#include <iostream>
using namespace std;

int n;
int l[10], r[10];

int main() {
    cin >> n;
    
    for (int i = 0; i < n; i++) {
        cin >> l[i] >> r[i];
    }
    
    int cnt = 0;
    
    //i, j, k는 제거할 3개의 선분을 선택하는 인덱스
    for (int i = 0; i < n; i++) {
        for (int j = i+1; j < n; j++) {
            for (int k = j+1; k < n; k++) {
                bool isValid = true;
                
                //남은 선분들끼리 겹치는지 확인
                for (int x = 0; x < n; x++) {
                    if (x == i || x == j || x == k) continue;  //제거된 선분은 건너뛰기
                    
                    for (int y = x+1; y < n; y++) {
                        if (y == i || y == j || y == k) continue;  //제거된 선분은 건너뛰기
                        
                        //두 선분이 겹치는지 확인
                        //한 선분의 오른쪽 끝점이 다른 선분의 왼쪽 끝점보다 크거나 같고,
                        //동시에 한 선분의 왼쪽 끝점이 다른 선분의 오른쪽 끝점보다 작거나 같으면 겹침
                        if (!(r[x] < l[y] || l[x] > r[y])) {
                            isValid = false;
                            break;
                        }
                    }
                    if (!isValid) break;
                }
                
                
                if (isValid) {
                    cnt++;
                }
            }
        }
    }
    
    cout << cnt << endl;  //결과 출력
    return 0;
}