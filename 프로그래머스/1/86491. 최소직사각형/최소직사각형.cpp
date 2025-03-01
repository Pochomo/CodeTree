#include <string>
#include <vector>
#include <climits>
#include <algorithm>
using namespace std;

int solution(vector<vector<int>> sizes) {
    int max_width = INT_MIN;
    int max_height = INT_MIN;
    
    for(int i = 0; i < sizes.size(); i++) {
        //가로가 세로보다 작으면 회전
        if(sizes[i][0] < sizes[i][1]) {
            swap(sizes[i][0], sizes[i][1]);
        }
        
        //최대 가로, 세로 길이 찾기
        max_width = max(max_width, sizes[i][0]);
        max_height = max(max_height, sizes[i][1]);
    }
    
    return max_width * max_height;
}