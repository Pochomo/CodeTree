#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int main() {
    string a;
    cin >> a;
    int num = 0;
    int temp = 1;
    int s_length = (int)a.size();
    int cnt = 0;
    for(int i = 0; i < s_length; i++){
        if(a[i] == '0'){
            a[i] = '1';
            cnt++;
            break;
        }
        if(cnt == 0 && i == (s_length-1)){
            if(a[s_length - 1] == '0'){
                a[s_length - 1] = '1';
            }
            else if(a[s_length - 1] == '1'){
                a[s_length - 1] = '0';
            }
        }
    }

    int b = stoi(a);
    
    while(b > 0){
        num = num + (b % 10) * temp;
        b = b / 10;
        temp = temp * 2;
    }

    cout << num;

    return 0;
}

// #include <iostream>
// #include <climits>

// using namespace std;

// int main() {
//     // 변수 선언 및 입력
//     string binary;
//     cin >> binary;
	
// 	// 각 i번째 자릿수를 바꾸었을 때의 십진수 값을 구해줍니다.
// 	int ans = INT_MIN;
//     for(int i = 0; i < (int) binary.size(); i++) {
// 		// i번째 자릿수를 바꿉니다.
// 		binary[i] = '0' + '1' - binary[i];
// 		// 십진수로 변환합니다.
//     	int num = 0;
//     	for(int j = 0; j < (int) binary.size(); j++)
//         	num = num * 2 + (binary[j] - '0');
		
// 		// 가능한 십진수 값 중 최댓값을 구해줍니다.
// 		ans = max(ans, num);
		
// 		// i번째 자릿수를 원래대로 돌려놓습니다.
// 		binary[i] = '0' + '1' - binary[i];
// 	}
    
//     // 출력
//     cout << ans;
	
//     return 0;
// }