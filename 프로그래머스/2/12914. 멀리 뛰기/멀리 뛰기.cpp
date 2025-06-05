#include <string>
#include <vector>

using namespace std;

long long solution(int n) 
{
    long long answer = 0;
    
    vector<long long> dp(2001);
    dp[0] = 0;
    dp[1] = 1;
    dp[2] = 2;
    dp[3] = 3;
    dp[4] = 5;
    
    for(int i = 5; i < dp.size(); ++i)
    {
        dp[i] = (dp[i - 1] + dp[i - 2]) % 1234567;
    }
    
    
    return dp[n];
}