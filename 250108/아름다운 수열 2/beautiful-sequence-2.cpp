#include <iostream>

using namespace std;

int N, M;
int A[100], B[100];

int main() {
    cin >> N >> M;

    for (int i = 0; i < N; i++) cin >> A[i];

    for (int i = 0; i < M; i++) cin >> B[i];

    //순서 상관없이 요소들이 연속적으로 있으면됨
    int cnt = 0;
    int correct = 0; //이게 B의 크기랑 같으면 cnt 1
    int index = 0;
    int cIndex;
    //M개씩 묶어서 비교
    for (int i = 0; i <= N-M; i++){
        //bool used[100] = {true}; //사용한 부분은 또 사용해서는 안된다. 이렇게 하면 첫번째 부분만 true가 됨
        bool used[100] = {false};
        correct = 0;
        index = 0;
        for (int j = i; j < i+M; j++){ //M번반복
            for(int k = 0; k < M; k++){
                if(!used[k] && B[k] == A[j]){
                    correct++;
                    used[k] = true;
                    break;
                }
            }
        }
        if(correct == M){
            cnt++;
        }
    }
    
    cout << cnt;

    return 0;
}

//답지는 정렬을 활용함, 지금 생각하니 정렬을 활용하는게 훨씬 쉬움
//두개 배열을 서로 정렬해서 같으면 같은거임