#include <iostream>

using namespace std;

int OFFSET = 100000;
int x1[1000] = {0};
int x2[1000] = {0};
int black[200000] = {0};
int white[200000] = {0};
int result[200000] = {0};
char dire[1000] = {' '};

//아무 타일에서 실행 
//현재타일을 포함해서 칠한다.
//L -> 흰색으로
//R -> 검은색으로
//덧칠해지면 마지막에 칠해진 색으로 변경
//흰색, 검은색이 2번이상이면 회색

// 흰 검 표시하는 배열
// 흰 검 배열

int main() {
    int n;
    int x;
    char direction;
    cin >> n;
    int cur = 0; //현재 위치
    // 1 L 1 L 이면 위치 이동 x 색만 변하게함 (0 , -1], [0, 1)
    for(int i = 0; i < n; i++){
        cin >> x >> direction;
        dire[i] = direction;
        if(direction == 'R'){
            x1[i] = cur;
            x2[i] = cur + x;
            cur += (x - 1); //1 0, cur 0 x1->x2 로 칠하고, 0칠하면된다.
        }
        if(direction == 'L'){
            x1[i] = cur - x;
            x2[i] = cur;
            cur -= (x - 1); //-1 0, cur 0 반대로 칠해야함 , 0에 칠하고 -1은 칠하면 x
        }
        x1[i] += OFFSET;
        x2[i] += OFFSET;
    }

    //흰 검 회 로직, 흰색일때, 검은색일때 나눠서 +1 해주고, 둘다 2를 넘어가면 회색
    //result에는 1 = 검, 2 = 흰 3 = 회색으로 임의로 표현
    for(int i = 0; i < n; i++){
        if(dire[i] == 'R'){
            for(int j = x1[i]; j < x2[i]; j++){
                black[j]++;
                result[j] = 1;
            }
        }
        if(dire[i] == 'L'){
            for(int j = x2[i]; j > x1[i]; j--){
                white[j]++;
                result[j] = 2;
            }
        }
    }
    
    for(int i = 0; i < 200000; i++){
        if(white[i] >= 2 && black[i] >= 2){
            result[i] = 3;
        }    
    }

    int w = 0;
    int b = 0;
    int g = 0;
    for(int i = 0; i < 200000; i++){
        if(result[i] == 1){
            b++;
        }
        else if(result[i] == 2){
            w++;
        }    
        else if(result[i] == 3){
            g++;
        }        
    }


    cout << w << " " << b << " " << g;


    return 0;
}