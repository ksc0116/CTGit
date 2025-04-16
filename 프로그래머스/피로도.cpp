// https://school.programmers.co.kr/learn/courses/30/lessons/87946
// 시간 복잡도 : O(N^2)

#include <string>
#include <vector>

using namespace std;
int answer = 0;
vector<bool> visit;
void BackTrack(int K, int depth, const vector<vector<int>>& dungeons)
{
	if (answer < depth) answer = depth;

	for (int i = 0; i < dungeons.size(); ++i)
	{
		if (visit[i] || K < dungeons[i][0]) continue;

		visit[i] = true;
		BackTrack(K - dungeons[i][1], depth + 1, dungeons);
		visit[i] = false;
	}
}

int solution(int k, vector<vector<int>> dungeons)
{
	visit.resize(dungeons.size(), false);

	BackTrack(k, 0, dungeons);

	return answer;
}