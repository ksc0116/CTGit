#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(int x, int y, int n)
{
    vector<int> visited(y + 1, -1); 
    queue<int> q;
    
    q.push(x);
    visited[x] = 0;
    
    while (!q.empty()) 
    {
        int cur = q.front();
        q.pop();
        
        if (cur == y)
            return visited[cur];
        
        vector<int> next = {cur + n, cur * 2, cur * 3};
        
        for (int num : next)
        {
            if (num <= y && visited[num] == -1) 
            {
                visited[num] = visited[cur] + 1;
                q.push(num);
            }
        }
    }
    
    return -1; 
}