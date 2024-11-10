#include <iostream>
#include <string>

using namespace std;

bool difference(const string& a){
    int n = a.length();
    int cnt = 1;
    for(int i = 0; i < n; i++){
        if(a[0] != a[i]){ //a[0] 부터 문자열 끝까지 비교해서 다르면 1증가
            cnt ++;
        }
    }
    if(cnt >= 2){
        return 1;
    }
    else{
        return 0;
    }
}

int main() {
    string a;

    cin >> a;
    
    if(difference(a) == true){
        cout << "Yes";
    }
    else{
        cout << "No";
    }

    return 0;
}