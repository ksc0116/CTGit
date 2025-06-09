#include <string>
#include <vector>
#include <list>
#include <algorithm>
#include <cctype>

using namespace std;

int solution(int cacheSize, vector<string> cities)
{
    int answer = 0;
    
    for(int i = 0; i < cities.size(); ++i)
    {
        string city = cities[i];
        for(int j = 0; j < city.size(); ++ j)
        {
            city[j] = tolower(city[j]);
        }
        cities[i] = city;
    }
    
    
    list<string> cache;
    for(int i = 0; i < cities.size(); ++i)
    {
        string city = cities[i];
        auto findIter = find(cache.begin(),cache.end(), city);
        if(findIter == cache.end())
        {
            answer += 5;
            
            if(cacheSize <= 0) continue;
            
            if(cache.size() < cacheSize)
            {
                cache.push_back(city);
            }
            else
            {
               
                cache.erase(cache.begin());
                cache.push_back(city);    
            }
        }
        else
        {
            answer += 1;
            
            cache.erase(findIter);
            cache.push_back(city);
        }
    }
    
    return answer;
}