#include <iostream>
#include <string>

using namespace std;

int sizeA, sizeB;

int check(const string & a, const string & b){
    int n = 1;
    bool match = true;
    for(int i = 0; i < sizeA; i++){
        if(a[i] == b[0]){
            match = true;
            for(int j = 1; j < sizeB; j++){
                if(a[i + n] == b[j]){
                    n++;
                }
                else{
                    match = false;
                    n = 1;
                    break;
                }
            }
            if(match) {
                return i;
            }
        }
    }
    return -1;
}

int main() {
    string a, b;
    cin >> a;
    cin >> b;

    sizeA = a.length();
    sizeB = b.length();

    cout << check(a, b);
    
    return 0;
}