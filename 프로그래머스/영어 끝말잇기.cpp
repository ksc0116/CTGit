// https://school.programmers.co.kr/learn/courses/30/lessons/12981
// 시간 복잡도 : O(N)

#include <string>
#include <vector>
#include <unordered_set>

using namespace std;

vector<int> solution(int n, vector<string> words)
{
	vector<int> answer(2, 0);

	unordered_set<string> wordSet;
	string prevWord = words[0];
	wordSet.insert(prevWord);
	for (int i = 1; i < words.size(); ++i)
	{
		string curWord = words[i];

		if (wordSet.find(curWord) != wordSet.end() || prevWord[prevWord.size() - 1] != curWord[0])
		{
			// 실패
			answer[0] = (i % n) + 1;
			answer[1] = (i / n) + 1;
			return answer;
		}

		wordSet.insert(curWord);
		prevWord = curWord;
	}


	return answer;
}