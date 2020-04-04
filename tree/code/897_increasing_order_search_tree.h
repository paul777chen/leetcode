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
	TreeNode* increasingBST(TreeNode* root) {
		if (root == nullptr) return root;
		vector<int> vec;
		traverse(root, vec);
		TreeNode* res = new TreeNode(vec[0]);
		TreeNode* tmp = res;
		for (int i = 1; i < vec.size(); ++i) {
			tmp->right = new TreeNode(vec[i]);
			tmp = tmp->right;
		}
		return res;
	}

private:
	void traverse(TreeNode* node1, vector<int>& vec) {
		if (node1 == nullptr) return;
		traverse(node1->left, vec);
		vec.push_back(node1->val);
		traverse(node1->right, vec);
	}
};

void printTree(TreeNode* node) {
	if (node) {
		cout << node->val << " ";
		printTree(node->right);
	}
}

void demo() {
	TreeNode* n1 = new TreeNode(5), * n2 = new TreeNode(3), * n3 = new TreeNode(6);
	n1->left = n2, n1->right = n3;
	Solution solution;
	TreeNode* res = solution.increasingBST(n1);
	printTree(res);
}