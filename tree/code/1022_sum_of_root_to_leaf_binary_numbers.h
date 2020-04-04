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
	int sumRootToLeaf(TreeNode* root) {
		int res = 0;
		traverse(root, 0, res);
		return res;
	}

private:
	void traverse(TreeNode* node, int val, int& res) {
		if (node == nullptr) return;
		if (node->left == nullptr && node->right == nullptr) {
			res += ((val << 1) + node->val);
			return;
		}
		val = (val << 1) + node->val;
		traverse(node->left, val, res);
		traverse(node->right, val, res);
	}
};

void demo() {
	TreeNode* n1 = new TreeNode(1), * n2 = new TreeNode(0), * n3 = new TreeNode(1);
	TreeNode* n4 = new TreeNode(0), * n5 = new TreeNode(1), * n6 = new TreeNode(0), * n7 = new TreeNode(1);
	n1->left = n2, n1->right = n3, n2->left = n4, n2->right = n5, n3->left = n6, n3->right = n7;
	Solution solution;
	int res = solution.sumRootToLeaf(n1);
	cout << res << endl;
}