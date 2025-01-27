#include <iostream>
#include <string>
#include <climits>

using namespace std;

int N;
string str;

bool check(const string& t_str) {
    int count = 0;
    for(int i = 0; i <= N - t_str.length(); i++) {
        bool found = true;
        for(int j = 0; j < t_str.length(); j++) {
            if(str[i + j] != t_str[j]) {
                found = false;
                break;
            }
        }
        if(found) count++;
        if(count > 1) return true;  //2번 이상 발견되면 true 반환
    }
    return false;
}

int main() {
    cin >> N;
    cin >> str;

    //연속부분문자열로서 두 번 이상 나타나지 않는 문자열의 최소 길이
    //ABCDABC 는 ABC는 2번씩 있으니 답은 4
    int ans = N;
    bool found = false;
    for(int i = 0; i < N; i++){
        int cnt = 0;
        for(int k = i; k < N; k++){
            string temp;
            for(int j = i; j <= k; j++){
                temp += string(1, str[j]);
            }
            if (!check(temp)) {
                if((int)temp.length() < ans) {
                    ans = temp.length();
                    i = N;
                    break;
                }
            }
        }
    }

    cout << ans;
    return 0;
}