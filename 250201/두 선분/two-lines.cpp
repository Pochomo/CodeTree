#include <iostream>

using namespace std;

int x1, x2, x3, x4;

int main() {
    cin >> x1 >> x2 >> x3 >> x4;
    bool check = true;
    if(x2 < x3) check = false;
    else if(x4 < x1) check = false;

    if(check) cout << "intersecting";
    else if(!check) cout << "nonintersecting";

    return 0;
}