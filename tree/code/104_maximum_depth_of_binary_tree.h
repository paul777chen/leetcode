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
	int maxDepth(TreeNode* root) {
		int max_val = 0;
		traverse(root, 0, max_val);
		return max_val;
	}

	void traverse(TreeNode* node, int val, int& max_val) {
		if (node == nullptr) {
			max_val = max(val, max_val);
			return;
		}
		traverse(node->left, val + 1, max_val);
		traverse(node->right, val + 1, max_val);
	}
};

void demo() {
	TreeNode* n1 = new TreeNode(3), * n2 = new TreeNode(9), * n3 = new TreeNode(20);
	TreeNode* n4 = new TreeNode(15), * n5 = new TreeNode(7);
	n1->left = n2, n1->right = n3, n3->left = n4, n3->right = n5;
	Solution solution;
	int res = solution.maxDepth(n1);
	cout << res << endl;
}