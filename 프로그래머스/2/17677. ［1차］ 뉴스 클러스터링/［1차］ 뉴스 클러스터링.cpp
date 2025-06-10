#include <string>
#include <map>

using namespace std;

int solution(string str1, string str2) 
{
    int answer = 0;
    
    for(int i = 0; i < str1.size(); ++i)    
    {
        str1[i] = tolower(str1[i]);
    }
    for(int i = 0; i < str2.size(); ++i)    
    {
        str2[i] = tolower(str2[i]);
    }
    map<string,pair<int,int>> m;
    for(int i = 0; i < str1.size() - 1; ++i)
    {
        if(isalpha(str1[i]) && isalpha(str1[i+1]))
        {
            m[str1.substr(i,2)].first++;
        }
    }
    for(int i = 0; i < str2.size() - 1; ++i)
    {
        if(isalpha(str2[i]) && isalpha(str2[i+1]))
        {
            m[str2.substr(i,2)].second++;
        }
    }
    int intersectionSum = 0;
    int unionSum = 0;
    for(const auto& each : m)
    {
        auto pair = each.second;
        intersectionSum += min(each.second.first,each.second.second);
        unionSum += max(each.second.first,each.second.second);
    }
    
    double J = 0.0;
    if(intersectionSum == 0 && unionSum == 0) 
    {
        J = 1.0;
    }
    else
    {
        J = (double)intersectionSum / (double)unionSum;
    }
    
    return J * 65536;
}