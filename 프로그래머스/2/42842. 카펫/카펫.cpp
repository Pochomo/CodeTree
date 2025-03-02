#include <string>
#include <vector>
#include <cmath>
using namespace std;

vector<int> solution(int brown, int yellow) {
    vector<int> answer;
    
    //전체 격자 수
    int total = brown + yellow;
    
    //가능한 모든 가로(w), 세로(h) 조합 찾기
    for (int h = 3; h <= sqrt(total); h++) {
        if (total % h == 0) {
            int w = total / h;
            
            //테두리가 갈색이므로 2w + 2h - 4 = brown이 성립해야 함
            if (2*w + 2*h - 4 == brown) {
                answer.push_back(w);
                answer.push_back(h);
                break;
            }
        }
    }
    
    return answer;
}