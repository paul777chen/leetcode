#pragma once
#include<vector>
#include<iostream>

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
	vector<int> postorder(Node* root) {
		vector<int> res;
		traverse(root, res);
		return res;
	}

private:
	void traverse(Node* node, vector<int>& res) {
		if (node == nullptr) return;
		for (auto n : node->children)
			traverse(n, res);
		res.push_back(node->val);
	}
};

void demo() {
	Node* n5 = new Node(5), * n6 = new Node(6);
	Node* n3 = new Node(3, { n5, n6 }), * n2 = new Node(2), * n4 = new Node(4);
	Node* n1 = new Node(1, { n3, n2, n4 });
	Solution solution;
	vector<int> res = solution.postorder(n1);
	for (auto v : res)
		cout << v << " ";
	cout << endl;
}