#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights)
{
	int answer = 0;
    int idx = 0;
    int sum = 0;
	queue<int> curQ;

    while(true)
    {
        if(idx == truck_weights.size())
        {
            answer += bridge_length; 
            break;
        }
        answer++;
        if(curQ.size() == bridge_length)
        {
            sum -= curQ.front();
            curQ.pop();
        }
        int curWeight = truck_weights[idx];
        if(sum + curWeight <= weight)
        {
            curQ.push(curWeight);
            sum += curWeight;
            idx++;
        }
        else
        {
            curQ.push(0);
        }
    }
	

	return answer;
}