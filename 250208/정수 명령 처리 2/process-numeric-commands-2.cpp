#include <iostream>
#include <queue>
#include <string>

using namespace std;

int n;
queue<int> q;  

int main() {
    cin >> n;

    for(int i = 0; i < n; i++) {
        string command;
        cin >> command;
        if(command == "push") {
            int x;
            cin >> x;
            q.push(x);
        }
        else if(command == "pop") {
            int v = q.front();
            q.pop();
            cout << v << endl;
        }
        else if(command == "size") {
            cout << q.size() << endl;
        }
        else if(command == "empty") {
            if(q.empty())
                cout << 1 << endl;
            else
                cout << 0 << endl;
        }
        else {
            cout << q.front() << endl;
        }
    }
    return 0;
}
