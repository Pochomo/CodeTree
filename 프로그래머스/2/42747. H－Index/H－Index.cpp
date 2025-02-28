#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool cmd(int a, int b){
    return a > b;
}
//논문 n 편 중 h번 이상 인용된 논문이 h편 이상이고 나머지 논문이 h번 이하 인용됐으면
//h의 최댓값이 이 과학자의 h-index 이다.
int solution(vector<int> citations) {
    int answer = 0;
    sort(citations.begin(), citations.end(), cmd);
    
    for (int i = 0; i < citations.size(); i++) {
        if (citations[i] >= i + 1) {
            answer = i + 1;
        } else {
            break;
        }
    }
    
    return answer;
}