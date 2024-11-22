#include <iostream>
#include <string>

using namespace std;

class Code{
    public:
        string ymd;
        string date;
        string weather;
        Code(string ymdD, string dateD, string weatherD):ymd(ymdD),
        date(dateD), weather(weatherD){};
        Code(){}; //위 생성자에 디폴트값 지정하니깐 메모리 초과 오류 발생

};

int main() {
    int n;
    cin >> n;
    string ymd;
    string date;
    string weather;
    Code arr[n];
    
    for(int i = 0; i < n; i++){
        cin >> ymd >> date >> weather;
        arr[i] = Code(ymd, date, weather);
    }

    int find_index = 0;
    int temp = 0;
    for(int i = 0; i < n; i++){
        if(arr[i].weather == "Rain" && temp == 0){
            find_index = i;
            temp = 1;
        }
        if(arr[i].weather == "Rain" && arr[find_index].ymd > arr[i].ymd){
            find_index = i;
        }
    }
    
    cout << arr[find_index].ymd << " " << arr[find_index].date << " " << arr[find_index].weather;

    return 0;
}