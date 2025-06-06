#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool Check(vector<int>& citations, int mid)
{
    auto iter = lower_bound(citations.begin(), citations.end() , mid);
    if(iter == citations.end()) return false;
    
    int idx = iter - citations.begin();
    if(citations.size() - idx >= mid) return true;
    
    return false;
}

int solution(vector<int> citations) 
{
    sort(citations.begin(), citations.end());
    int n = citations.size();

    int left = 0;
    int right = 10000;
    
    while(left < right)
    {
        int mid = (left + right + 1) / 2; 
        
        if (Check(citations,mid)) 
            left = mid;
        else
            right = mid - 1;
    }
    
    return left;
}