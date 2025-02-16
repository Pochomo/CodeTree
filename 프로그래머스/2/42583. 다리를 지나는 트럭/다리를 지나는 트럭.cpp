#include <string>
#include <vector>
#include <queue>
#include <utility>

using namespace std;

//bridge_length 대 만큼 올라갈 수 있음
int solution(int bridge_length, int weight, vector<int> truck_weights) {
    queue<pair<int,int>> truck; //다리를 건너는 트럭, 트럭이 지나가는데 얼마나 걸리는지, 1씩 업데이트
    int sum = 0;
    int index = 0;
    int time = 0;
    //올라가데는 1만큼 내려가는데는 bridge_length 만큼
    while(index < truck_weights.size() || !truck.empty()){
        time++;
        
        //트럭 제거
        if (!truck.empty() && truck.front().second == time) {
            sum -= truck.front().first;
            truck.pop();
        }
        
        //다음 트럭이 다리에 올라갈 수 있는지 확인
        if (index < truck_weights.size() && sum + truck_weights[index] <= weight) {
            truck.push({truck_weights[index], time + bridge_length}); 
            sum += truck_weights[index];
            index++;
        }
        
    }
    return time;
}