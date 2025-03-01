#include <string>
#include <vector>
#include <algorithm>
#include <utility>

using namespace std;
// 1 2 3 4 5
// 2 1 2 3 2 4 2 5
// 33 11 22 44 55
bool compare(const pair<int, int>& a, const pair<int, int>& b) {
    if (a.first == b.first) {
        return a.second < b.second;
    }
    return a.first > b.first;
}
vector<int> solution(vector<int> answers) {
    vector<int> answer;
    vector<int> a = {1, 2, 3, 4, 5}; //총 5개
    vector<int> b = {2, 1, 2, 3, 2, 4, 2, 5}; //총 8개
    vector<int> c = {3, 3, 1, 1, 2, 2, 4, 4, 5, 5};// 총 10개
    int correct_a = 0;
    int correct_b = 0;
    int correct_c = 0;
    int index_a = 0;
    int index_b = 0;
    int index_c = 0;
    //pair로 번호, 맞춘 갯수 저장
    for(int i = 0; i < answers.size(); i++){
        if(a.size() <= index_a){
            index_a %= a.size();
        } 
        if(b.size() <= index_b){
            index_b %= b.size();
        } 
        if(c.size() <= index_c){
            index_c %= c.size();
        }
        if(a[index_a] == answers[i]) correct_a++;
        if(b[index_b] == answers[i]) correct_b++;
        if(c[index_c] == answers[i]) correct_c++;
        index_a++;
        index_b++;
        index_c++;
    }
    
    int max_score = max({correct_a, correct_b, correct_c});

    if (correct_a == max_score) answer.push_back(1);
    if (correct_b == max_score) answer.push_back(2);
    if (correct_c == max_score) answer.push_back(3);

    return answer;
}