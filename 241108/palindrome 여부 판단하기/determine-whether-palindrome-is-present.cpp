#include <iostream>
#include <string>
using namespace std;

bool checkPalindrome(string & a){
    string b = "";
    for(int i = (a.length()-1); i >= 0; i--){
        b += a[i];
    }
    if(a == b){
        return true;
    }
    else{
        return false;
    }
}

int main() {
    string a;
    cin >> a;

    if(checkPalindrome(a) == true){
        cout << "Yes";
    }
    else{
        cout << "No";
    }
    return 0;
}