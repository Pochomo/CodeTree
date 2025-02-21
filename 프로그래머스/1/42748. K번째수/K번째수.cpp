#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> array, vector<vector<int>> commands) {
    vector<int> answer;
    for(int i = 0; i < commands.size(); i++){
        int tempi = commands[i][0];
        int tempj = commands[i][1];
        int tempk = commands[i][2];
        vector<int> temp(array.begin() + tempi - 1, array.begin() + tempj);
        sort(temp.begin(), temp.end());
        answer.push_back(temp[tempk - 1]);
    }
    
    return answer;
}