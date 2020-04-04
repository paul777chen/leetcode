#pragma once
#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;


// Definition for a Node.
class Node {
public:
	int val;
	vector<Node*> children;

	Node() {}

	Node(int _val) {
		val = _val;
	}

	Node(int _val, vector<Node*> _children) {
		val = _val;
		children = _children;
	}
};

class Solution {
public:
	int maxDepth(Node* root) {
		if (root == nullptr) return 0;
		int max_val = 0;
		traverse(root, 0, max_val);
		return max_val;
	}

private:
	void traverse(Node* node, int val, int& max_val) {
		if (node->children.size() == 0) {
			max_val = max(val + 1, max_val);
			return;
		}
		for (auto n : node->children)
			traverse(n, val + 1, max_val);
	}
};

void demo() {
	Node* n5 = new Node(5), * n6 = new Node(6);
	Node* n3 = new Node(3, { n5, n6 }), * n2 = new Node(2), * n4 = new Node(4);
	Node* n1 = new Node(1, { n3, n2, n4 });
	Solution solution;
	int depth = solution.maxDepth(n1);
	cout << depth << endl;
}