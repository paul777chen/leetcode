#pragma once
#include<iostream>
using namespace std;

struct TreeNode {
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
	int rangeSumBST(TreeNode* root, int L, int R) {
		int value = 0;
		traverse2(root, L, R, value);
		return value;
	}

private:
	void traverse(TreeNode* node, int L, int R, int& value) {
		if (node == nullptr)  return;
		if (node->val >= L && node->val <= R) value += node->val;
		if (node->left) traverse(node->left, L, R, value);
		if (node->right) traverse(node->right, L, R, value);
	}

	void traverse2(TreeNode* node, int L, int R, int& value) {
		if (node == nullptr) return;
		if (node->val >= L && node->val <= R) value += node->val;
		if (node->left && node->val>=L) traverse2(node->left, L, R, value);
		if (node->right && node->val<=R) traverse2(node->right, L, R, value);
	}
};

void demo() {
	Solution solution;
	TreeNode* n1 = new TreeNode(10), * n2 = new TreeNode(5), * n3 = new TreeNode(15);
	TreeNode* n4 = new TreeNode(3), * n5 = new TreeNode(7), * n6 = new TreeNode(18);
	n1->left = n2, n1->right = n3, n2->left = n4, n2->right = n5, n3->right = n6;
	int res = solution.rangeSumBST(n1, 7, 15);
	cout << res << endl;
}