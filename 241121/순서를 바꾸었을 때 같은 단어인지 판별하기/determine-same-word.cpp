#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

void checkWord(string a, string b){
    if(a==b){
        cout << "Yes";
    }
    else{
        cout << "No";
    }
}

int main() {
    string a, b;
    cin >> a;
    cin >> b;

    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    
    checkWord(a, b);

    return 0;
}