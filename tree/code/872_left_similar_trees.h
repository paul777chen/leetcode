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
	bool leafSimilar(TreeNode* root1, TreeNode* root2) {
		vector<int> seq1, seq2;
		traverse(root1, seq1);
		traverse(root2, seq2);
		if (seq1.size() != seq2.size()) return false;
		return equal(seq1.begin(), seq1.end(), seq2.begin());
	}

private:
	void traverse(TreeNode* node, vector<int>& leaves) {
		if (node == nullptr) return;
		if (node->left == nullptr && node->right == nullptr)
			leaves.push_back(node->val);
		traverse(node->left, leaves);
		traverse(node->right, leaves);
	}
};

void demo() {
	TreeNode* n1 = new TreeNode(3), * n2 = new TreeNode(5), * n3 = new TreeNode(1);
	n1->left = n2, n1->right = n3;
	Solution solution;
	cout << solution.leafSimilar(n1, n2) << endl;
}
