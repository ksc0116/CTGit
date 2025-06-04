#include <string>
#include <vector>

using namespace std;

int solution(int n)
{
    int nSum = 0;
    int tmpBit = 1;
    while(n > tmpBit)
    {
        if((n & tmpBit))
            nSum++;
        
        tmpBit = tmpBit << 1;
    }
    int answer = 0;
    int num = n;
    while(true)
    {
        num++;
        int bit = 1;
        int sum = 0;
        while((num > bit))
        {
            if((num & bit))
                sum++;
            
            bit = bit << 1;
        }
        
        if(nSum == sum)
        {
            answer = num;
            break;
        }
        
    }
    
    return answer;
}