#include <iostream>
using namespace std;

struct Node {
	int data;
	Node* left;
	Node* right;

	Node(int value) : data(value), left(nullptr), right(nullptr) {}
};

class BinaryTree {
public:

	//삽입
	Node* insert(Node* root, int val) {
		if (!root) 
			return new Node(val); //루트가 없으면 val이 루트노드
		if (val < root->data) //루트보다 작으면 왼쪽삽입
			root->left = insert(root->left, val);
		else //오른쪽 삽입
			root->right = insert(root->right, val);
		return root;
	}

	void inorder(Node* root) { //중위 순회
		if (!root) return;
		inorder(root->left);
		cout << root->data << " ";
		inorder(root->right);
	}

	void pre_order(Node* root) { //전위 순회
		if (!root) return;
		cout << root->data << " ";
		pre_order(root->left);
		pre_order(root->right);
	}

	void post_order(Node* root) { //후위순회
		if (!root) return;
		post_order(root->left);
		post_order(root->right);
		cout << root->data << " ";
	}
};


int main() {

	BinaryTree tree;
	Node* root = nullptr;
	root = tree.insert(root, 5);
	tree.insert(root, 3);
	tree.insert(root, 7);
	tree.insert(root, 2);
	tree.insert(root, 4);

	tree.inorder(root);
	cout << endl;
	tree.pre_order(root);
	cout << endl;
	tree.post_order(root);


	return 0;
}