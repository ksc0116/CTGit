#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int answer = 0;
vector<vector<int>> g_q;
vector<int> g_ans;

void Comb(int n, int start, vector<int>& current, int depth) 
{
    if (depth == 5) 
    {
        for(int i = 0; i < g_q.size(); ++i)
        {
            int sum = 0;
            for(int j = 0; j < 5; ++j)
            {
                if(find(g_q[i].begin(), g_q[i].end(),current[j]) != g_q[i].end())
                {
                    sum++;
                }
            }
            if(sum != g_ans[i])
            {
                return;
            }
        }
        answer++;
        return;
    }

    for (int i = start; i <= n; ++i) 
    {
        current.push_back(i);                  
        Comb(n, i + 1, current, depth + 1);
        current.pop_back();                     
    }
}

int solution(int n, vector<vector<int>> q, vector<int> ans)
{
    g_q = q;
    g_ans = ans;
    vector<int> current;
    Comb(n,1,current,0);
    
    return answer;
}