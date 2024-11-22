#include <iostream>
#include <string>

using namespace std;

class Release{
    public:
        string code;
        char color;
        int second;
        Release(string codeD = " ", char colorD = ' ', int secondD = 0):code(codeD),
        color(colorD), second(secondD){};

};

int main() {
    string code;
    char color;
    int second;
    cin >> code >> color >> second;
    Release ac(code, color, second);

    cout << "code : " << ac.code << endl; 
    cout << "color : " << ac.color << endl; 
    cout << "second : " << ac.second;
    return 0;
}