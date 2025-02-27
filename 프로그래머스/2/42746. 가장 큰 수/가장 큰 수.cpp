#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool cmd(string a, string b){
    return a + b > b + a;
}

string solution(vector<int> numbers) {
    vector<string> str_numbers;
    for (int num : numbers) {
        str_numbers.push_back(to_string(num));
    }
    string answer = "";
    sort(str_numbers.begin(), str_numbers.end(), cmd);
    
    for (string s : str_numbers) {
        answer += s;
    }
    
    if (answer[0] == '0') {
        return "0";
    }
    
    return answer;
}
