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
	TreeNode* searchBST(TreeNode* root, int val) {
		if (root == nullptr) return root;
		if (root->val == val) return root;
		else if (root->val < val) return searchBST(root->right, val);
		else return searchBST(root->left, val);
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
	TreeNode* n4 = new TreeNode(1), * n5 = new TreeNode(3);
	n1->left = n2, n1->right = n3, n2->left = n4, n2->right = n5;
	Solution solution;
	TreeNode* out = solution.searchBST(n1, 2);
	printTree(out);
}