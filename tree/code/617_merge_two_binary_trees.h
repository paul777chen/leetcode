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
	TreeNode* mergeTrees(TreeNode* t1, TreeNode* t2) {
		if (t1 == nullptr) return t2;
		traverse(t1, t2);
		return t1;
	}

private:
	void traverse(TreeNode* t1, TreeNode* t2) {
		if (t1 == nullptr) return;
		if (t2) t1->val += t2->val;
		else return;
		if (t1->left) {
			traverse(t1->left, t2->left);
		}
		else {
			t1->left = t2->left;
		}
		if (t1->right) {
			traverse(t1->right, t2->right);
		}
		else {
			t1->right = t2->right;
		}
	}
};

void printTree(TreeNode* node) {
	if (node == nullptr) return;
	cout << node->val << endl;;
	printTree(node->left);
	printTree(node->right);

}

void demo() {
	Solution solution;
	TreeNode* a1 = new TreeNode(1), * a2 = new TreeNode(3), * a3 = new TreeNode(2), * a4 = new TreeNode(5);
	TreeNode* b1 = new TreeNode(2), * b2 = new TreeNode(1), * b3 = new TreeNode(3), * b4 = new TreeNode(4), * b5 = new TreeNode(7);
	a1->left = a2, a1->right = a3, a2->left = a4;
	b1->left = b2, b1->right = b3, b2->right = b4, b3->right = b5;
	TreeNode* out = solution.mergeTrees(a1, b1);
	printTree(out);
}