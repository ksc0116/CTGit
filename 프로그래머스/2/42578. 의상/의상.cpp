#include <string>
#include <vector>
#include <unordered_map>
using namespace std;

int solution(vector<vector<string>> clothes) 
{
    int answer = 1;
    
    unordered_map<string,int> um;
    for(int i = 0; i < clothes.size(); ++i)
    {
        um[clothes[i][1]]++;
    }
   
    for(const auto& cloth : um)
    {
        int cnt = cloth.second;
        answer *= (cnt + 1);
    }
    return answer - 1;
}