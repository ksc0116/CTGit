// https://school.programmers.co.kr/learn/courses/30/lessons/42892
// 시간 복잡도 :O(N^2)

#include <string>
#include <vector>
#include <algorithm>

using namespace std;


struct Node
{
	int id, x, y;
	Node* left = nullptr;
	Node* right = nullptr;

	Node(int id, int x, int y) : id(id), x(x), y(y) {}
};

bool Cmp(Node* a, Node* b)
{
	if (a->y != b->y)
		return a->y > b->y;

	return a->x < b->x;
}

struct Tree
{
	Node* root = nullptr;

	Node* insert(Node* curNode, Node* newNode)
	{
		if (curNode == nullptr)
			return newNode;

		if (curNode->x < newNode->x)
		{
			curNode->right = insert(curNode->right, newNode);
		}
		else
		{
			curNode->left = insert(curNode->left, newNode);
		}

		return curNode;
	}

	void BuildTree(const vector<vector<int>>& v)
	{
		vector<Node*> nodes;
		for (int i = 0; i < v.size(); ++i)
		{
			nodes.push_back(new Node(i + 1, v[i][0], v[i][1]));
		}

		sort(nodes.begin(), nodes.end(), Cmp);

		for (int i = 0; i < nodes.size(); ++i)
		{
			root = insert(root, nodes[i]);
		}
	}


	void Pre(Node* node, vector<int>& v)
	{
		if (node == nullptr)
			return;

		v.push_back(node->id);
		Pre(node->left, v);
		Pre(node->right, v);
	}

	void Post(Node* node, vector<int>& v)
	{
		if (node == nullptr)
			return;

		Post(node->left, v);
		Post(node->right, v);
		v.push_back(node->id);
	}

	vector<int> PreTrival()
	{
		vector<int> v;

		Pre(root, v);

		return v;
	}

	vector<int> PostTrival()
	{
		vector<int> v;

		Post(root, v);

		return v;
	}
};

vector<vector<int>> solution(vector<vector<int>> nodeinfo)
{
	vector<vector<int>> answer;

	// 트리 구축
	Tree tree;
	tree.BuildTree(nodeinfo);

	vector<int> pre = tree.PreTrival();
	vector<int> post = tree.PostTrival();



	return { pre,post };
}