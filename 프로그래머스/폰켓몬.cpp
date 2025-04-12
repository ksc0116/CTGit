// https://school.programmers.co.kr/learn/courses/30/lessons/1845
// 시간 복잡도 : O(N)

#include <vector>
#include <unordered_set>
using namespace std;

int solution(vector<int> nums)
{
	unordered_set<int> s(nums.begin(), nums.end());

	return min(nums.size() / 2, s.size());
}