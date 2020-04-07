#pragma once
#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

struct TreeNode {
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
	vector<double> averageOfLevels(TreeNode* root) {
		vector<double> res;
		vector<int> cnt;
		traverse(root, 0, res, cnt);
		return res;
	}

private:
	void traverse(TreeNode* node, int level, vector<double>& res, vector<int>& cnt) {
		if (node == nullptr) return;
		if (level >= res.size()) {
			res.push_back(node->val);
			cnt.push_back(1);
		}
		else {
			res[level] = (res[level] * cnt[level] + node->val) / static_cast<double>(cnt[level] + 1);
			cnt[level] += 1;
		}
		traverse(node->left, level + 1, res, cnt);
		traverse(node->right, level + 1, res, cnt);
	}
};

void demo() {
	TreeNode* n1 = new TreeNode(3), * n2 = new TreeNode(9), * n3 = new TreeNode(20);
	TreeNode* n4 = new TreeNode(15), * n5 = new TreeNode(7);
	n1->left = n2, n1->right = n3, n3->left = n4, n3->right = n5;
	Solution solution;
	vector<double> res = solution.averageOfLevels(n1);
	for (auto r : res)
		cout << r << " ";
	cout << endl;
}