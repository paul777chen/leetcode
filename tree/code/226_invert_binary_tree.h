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
	TreeNode* invertTree(TreeNode* root) {
		traverse(root);
		return root;
	}

private:
	void traverse(TreeNode* node) {
		if (node == nullptr) return;
		TreeNode* tmp;
		traverse(node->left);
		traverse(node->right);
		tmp = node->left;
		node->left = node->right;
		node->right = tmp;
	}
};

void printTree(TreeNode* node) {
	if (node) {
		cout << node->val << " ";
		printTree(node->left);
		printTree(node->right);
	}
}

void demo() {
	TreeNode* n1 = new TreeNode(4), * n2 = new TreeNode(2), * n3 = new TreeNode(7);
	TreeNode* n4 = new TreeNode(1), * n5 = new TreeNode(3), * n6 = new TreeNode(6), * n7 = new TreeNode(9);
	n1->left = n2, n1->right = n3, n2->left = n4, n2->right = n5, n3->left = n6, n3->right = n7;
	Solution solution;
	TreeNode* res = solution.invertTree(n1);
	printTree(res);
}