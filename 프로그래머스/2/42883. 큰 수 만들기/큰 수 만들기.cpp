#include <string>
#include <vector>
#include <algorithm>

using namespace std;


string solution(string number, int k) 
{
   string answer = "";
    auto iter = number.begin();

    for (int i = 0; i < number.size() - k; ++i)
    {
        auto tmpIter = number.begin() + k + i + 1;
        iter = max_element(iter, tmpIter);
        answer += *iter;
        ++iter;
    }

    return answer;
}