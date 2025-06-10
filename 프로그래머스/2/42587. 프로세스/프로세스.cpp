#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(vector<int> priorities, int location)
{
    int answer = 0;
    
    priority_queue<int> pq;
    queue<pair<int,int>> q;
    
    for(int i = 0; i < priorities.size(); ++i)
    {
        pq.push(priorities[i]);
        q.push({priorities[i],i});
    }
    
    while(true)
    {
        int curPriority = q.front().first;
        int curLoc = q.front().second;
        int priority = pq.top();
        
        if(curPriority < priority)
        {
            q.pop();
            q.push({curPriority,curLoc});
        }
        else
        {
            answer++;
            if(curLoc == location)
            {
                break;
            }
            else
            {
                q.pop();
                pq.pop();
            }
        }
    }

    return answer;
}