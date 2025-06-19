#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string solution(int n)
{
    string answer = "";
    int origin = n;
    while(n > 0)
    {
        int tmp = n % 3;
        if(tmp == 0)
        {
            tmp = 4;
            n = (n / 3) - 1;
        }
        else
        {
            n /= 3;
        }
        
        answer += to_string(tmp);
    }
    
    reverse(answer.begin(), answer.end());
    return answer;
}

// 0 -> 1
// 1 -> 2
// 2 -> 4


// 10
//