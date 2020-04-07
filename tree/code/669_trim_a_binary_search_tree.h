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
	TreeNode* trimBST(TreeNode* root, int L, int R) {

	}

private:
	void traverse(TreeNode* node, int L, int R) {
		if (node == nullptr) return;
		
	}
};