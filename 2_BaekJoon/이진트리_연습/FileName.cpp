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

	//����
	Node* insert(Node* root, int val) {
		if (!root) 
			return new Node(val); //��Ʈ�� ������ val�� ��Ʈ���
		if (val < root->data) //��Ʈ���� ������ ���ʻ���
			root->left = insert(root->left, val);
		else //������ ����
			root->right = insert(root->right, val);
		return root;
	}

	void inorder(Node* root) { //���� ��ȸ
		if (!root) return;
		inorder(root->left);
		cout << root->data << " ";
		inorder(root->right);
	}

	void pre_order(Node* root) { //���� ��ȸ
		if (!root) return;
		cout << root->data << " ";
		pre_order(root->left);
		pre_order(root->right);
	}

	void post_order(Node* root) { //������ȸ
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