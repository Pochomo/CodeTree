#include <iostream>
#include <string>

using namespace std;

class Code{
    public:
        string name;
        int code;
        Code(string nameD = "codetree", int codeD = 50):name(nameD),
        code(codeD){};

};

int main() {
    string name;
    int code;
    cin >> name >> code;
    Code ax;
    Code ac(name, code);

    cout << "product " << ax.code << " is " << ax.name << endl; 
    cout << "product " << ac.code << " is " << ac.name; 
    return 0;
}