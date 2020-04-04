#pragma once
#include<iostream>
#include<vector>

using namespace std;

struct TreeNode {
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};


class Solution {
public:
	bool isUnivalTree(TreeNode* root) {
		if (root == nullptr) return true;
		int value = root->val;
		return traverse(root, value);
	}

private:
	bool traverse(TreeNode* node, int value) {
		if (node == nullptr) return true;
		if (node->val != value) return false;
		else
			return traverse(node->left, value) && traverse(node->right, value);
	}
};

void demo() {
	TreeNode* n1 = new TreeNode(1), * n2 = new TreeNode(2), * n3 = new TreeNode(1);
	n1->left = n2, n1->right = n3;
	Solution solution;
	cout << solution.isUnivalTree(n1) << endl;
}