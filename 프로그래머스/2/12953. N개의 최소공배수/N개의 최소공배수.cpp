#include <string>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

int solution(vector<int> arr) 
{
    sort(arr.begin(), arr.end());
    int tmp = lcm(arr[0],arr[1]);
    for(int i = 2; i < arr.size(); ++i)
    {
        tmp = lcm(arr[i],tmp);
    }
    
    return tmp;
}