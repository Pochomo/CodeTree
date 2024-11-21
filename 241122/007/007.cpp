#include <iostream>
#include <string>
using namespace std;

class C007{
    private:
        string code;
        string place;
        int time;
    public:
        C007(const string& code, const string &place, int time):code(code), place(place), time(time){}
        void setCode(const string& code1){
            code = code1;
        }
        void setPlace(const string& place1){
            place = place1;
        }
        void setTime(int time1){
            time = time1;
        }
        string getCode() const{
            return code;
        }
        string getPlacee() const{
            return place;
        }
        int getTime() const{
            return time;
        }
        void printInfo(){
            cout << "secret code : " << code << endl;
            cout << "meeting point : " << place << endl;
            cout << "time : " << time;
        }
};

int main() {
    string code, place;
    int time;

    cin >> code >> place >> time;
    C007 ac(code, place, time);

    ac.printInfo();
    
    return 0;
}