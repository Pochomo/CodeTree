#include <iostream>
#include <string>

using namespace std;

class Code{
    public:
        string name;
        string code;
        string location;
        Code(string nameD, string codeD, string locationD):name(nameD),
        code(codeD), location(locationD){};
        Code(){}; //위 생성자에 디폴트값 지정하니깐 메모리 초과 오류 발생

};

int main() {
    int n;
    cin >> n;
    string name;
    string code;
    string location;
    Code arr[n];
    
    for(int i = 0; i < n; i++){
        cin >> name >> code >> location;
        arr[i] = Code(name, code, location);
    }

    int min_index = 0;
    for(int i = 1; i < n; i++){
        if(arr[min_index].name < arr[i].name){
            min_index = i;
        }
    }
    
    cout << "name " << arr[min_index].name <<endl; 
    cout << "addr " << arr[min_index].code <<endl; 
    cout << "city " << arr[min_index].location; 

    return 0;
}