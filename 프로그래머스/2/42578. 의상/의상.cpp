#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

int solution(vector<vector<string>> clothes) {
    unordered_map<string, int> counting_clothes;

    //의상 개수 저장
    for (const auto& item : clothes) {
        string name = item[1];
        counting_clothes[name]++;
    }
    
    int answer = 1;
    for (const auto& pair : counting_clothes) {
        answer *= (pair.second + 1);
    }
    
    return answer - 1;
}
