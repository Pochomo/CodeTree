#include <iostream>
#include <algorithm>

using namespace std;

int arrPeoPle[101];
int infection_P[101] = {0};

int main() {
    int n, k, p, T; //n명의 개발자 t번에 걸처 t초에, x개발자가 y개발자와 악수를 나눈 정황이 주어진다.
    //1명의 개발자 감염, "한명의 개발자가" k번의 악수 동안만 전염병을 옮기고 그 이후 옮기진 x
    //p -> 처음 전염병이 걸린 개발자, 
    //전염된 사람끼리 만나도 전염시킨 것으로 간주해야함. (감염횟수에만 포함)
    cin >> n >> k >> p >> T;
    int t, x, y;
    for(int i = 1 ; i <= n; i++){
        arrPeoPle[i] = 0;
    }

    arrPeoPle[p] = 1;

    int *time_arr = new int[T+1];
    int *temp_time_arr = new int[T+1];
    int *arrX = new int[T+1];
    int *arrY = new int[T+1];
 
    int cnt = 1; //k번동안 감염됐는지 체크
    for(int i = 1; i <= T; i++){
        cin >> t >> x >> y; //t초에 x개발자와 y개발자가 악수를 나눴음.
        temp_time_arr[i] = t;
        time_arr[i] = t;
        arrX[i] = x;
        arrY[i] = y;
    }

    sort(temp_time_arr, temp_time_arr + T + 1); //시간 순으로 정렬했고 오름차순임

    int index = 1;
    for(int i = 1; i <= T; i++){
        while(temp_time_arr[i] != time_arr[index]){ //index가 몇인지 알아내서 time 제일 먼저인거 찾아옴
            ++index;
        }
        //index 맞게 출력되는거 확인
        if(arrPeoPle[arrX[index]] == 1 && infection_P[arrX[index]] < k){
            if(arrPeoPle[arrY[index]] == 1){
                infection_P[arrX[index]]++;
                infection_P[arrY[index]]++;
            }
            else {
                arrPeoPle[arrY[index]] = 1;
                infection_P[arrX[index]]++;
            }
        }
        else if(arrPeoPle[arrY[index]] == 1 && infection_P[arrY[index]] < k){
            if(arrPeoPle[arrX[index]] == 1){
                infection_P[arrX[index]]++;
                infection_P[arrY[index]]++;
            }
            else {
                arrPeoPle[arrX[index]] = 1;
                infection_P[arrY[index]]++;
            }
        }

        index = 1;
    }

    for(int i = 1; i <= n; i ++){
        cout << arrPeoPle[i];
    }


    return 0;
}