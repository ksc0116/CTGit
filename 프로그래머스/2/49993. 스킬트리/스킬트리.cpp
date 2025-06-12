#include <string>
#include <vector>
#include <limits.h>

using namespace std;

bool Check(const string& skill, const string& skillTree)
{
    vector<int> idxVec(skill.size(),INT_MAX);
    
    for(int i = 0; i < skill.size(); ++i)
    {
        for(int j = 0; j < skillTree.size(); ++j)
        {
            if(skill[i] == skillTree[j])
            {
                idxVec[i] = j;
            }
        }
    }
    
    bool flag = true;
    for(int i = 0; i < idxVec.size() - 1; ++i)
    {
        if(idxVec[i] > idxVec[i+1])
        {
            flag = false;
            break;
        }
    }
    return flag;
}

int solution(string skill, vector<string> skill_trees)
{
	int answer = 0;

	for(int i = 0; i < skill_trees.size(); ++i)
    {
        if(Check(skill,skill_trees[i]))
        {
            answer++;
        }
    }

	return answer;
}