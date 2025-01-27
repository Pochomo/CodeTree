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
    for (int len = 1; len <= N; len++) {
        bool found = true;
        for (int i = 0; i <= N - len; i++) {
            string temp;
            for (int j = i; j < i + len; j++) {
                temp += str[j];
            }
            if(!check(temp)) {
                found = false;
            }
            if(check(temp)) {
                found = true;
                break;
            }
        }
        if(!found) {
            ans = len;
            break;
        }
    }

    cout << ans;
    return 0;
}