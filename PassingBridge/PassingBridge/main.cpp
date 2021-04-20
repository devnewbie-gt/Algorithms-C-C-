#include <iostream>
#include <string>
#include <vector>
#include<queue>

using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights) {
    int answer = 0;
    int bridge_weight = 0;
    int remains = truck_weights.size();

    queue<int> bridge;
    while (remains != 0) {
        answer++;
        std::cout << "경과 시간 : " << answer << "\n";

        if (bridge.size() == bridge_length) {
            bridge_weight -= bridge.front();
            std::cout << "현재 pop하는 값 : " << bridge.front() << "\n";

            if (bridge.front() != 0) {
                remains--;
            }

            bridge.pop();
        }

        if (!truck_weights.empty()) {

            if (bridge.empty()) {
                bridge.push(truck_weights.front());
                std::cout << "현재 push하는 값 : " << bridge.front() << "\n";
                bridge_weight += truck_weights.front();
                truck_weights.erase(truck_weights.begin() + 0);
            }
            else {
                if (weight - bridge_weight >= truck_weights.front()) {
                    bridge.push(truck_weights.front());
                    std::cout << "현재 push하는 값 : " << bridge.back() << "\n";
                    bridge_weight += truck_weights.front();
                    truck_weights.erase(truck_weights.begin() + 0);
                }
                else {
                    bridge.push(0);
                }
                
            }
            
        }
        else {
            bridge.push(0);
        }

    }

    return answer;
}

void main() {

    int result = 0;
    vector<int> input;
    input.push_back(10);
    //input.push_back(4);
    //input.push_back(5);
    //input.push_back(6);
    
    result = solution(100, 100, input);

    std::cout << "result = " << result;

}