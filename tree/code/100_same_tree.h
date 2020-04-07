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
	bool isSameTree(TreeNode* p, TreeNode* q) {
		return traverse(p, q);
	}

private:
	bool traverse(TreeNode* p, TreeNode* q) {
		if (p == nullptr && q == nullptr) return true;
		if ((p == nullptr && q != nullptr) || (p != nullptr && q == nullptr) || (p->val != q->val)) return false;
		return traverse(p->left, q->left) && traverse(p->right, q->right);
	}
};

void demo() {
	TreeNode* a1 = new TreeNode(1), * a2 = new TreeNode(2), * a3 = new TreeNode(3);
	TreeNode* b1 = new TreeNode(1), * b2 = new TreeNode(2), * b3 = new TreeNode(3);
	a1->left = a2, a1->right = a3;
	b1->left = b2, b1->right = b3;
	Solution solution;
	cout << solution.isSameTree(a1, b1) << endl;
}