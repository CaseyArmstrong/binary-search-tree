#include <vector> 
#include <string>
#include <iostream>
#include <algorithm>
#include <fstream>
#include <sstream>

// Binary Search Tree

using namespace std;

class Action {
public:
	Action();

	/*create an Action object storing a vector*/
	Action(vector<string> vec) : v(vec) {}

	/*push strings into vector v*/
	void act(string str) {
		v.push_back(str);
	}

	/*count the number of characters in each word*/
	int num_chars() {
		count = 0;
		for (int i = 0; i < v.size(); i++) {
			for (int a = 0; a < v[i].size(); a++) {
				count++;
			}
		}
		return count;
	}

	vector<string> getv() {
		return v;
	}

private:
	vector<string> v;
	int count;

};

class TreeNode
{
public:
	void insert_node(TreeNode* new_node);
	void inorder_nodes(Action& v);
	void preorder_nodes(Action& v);
	void postorder_nodes(Action& v);
private:
	string data;
	TreeNode* left;
	TreeNode* right;
	friend class BinarySearchTree;
};


class BinarySearchTree : public Action
{
public:
	BinarySearchTree();
	void insert(string data);
	void inorder(Action& a);
	void preorder(Action& a);
	void postorder(Action& a);
	void print(vector<string> vec);
private:
	TreeNode* root;
};

Action::Action() {
	v = {};
	count = 0;
}

BinarySearchTree::BinarySearchTree()
{
	root = NULL;
}

void BinarySearchTree::inorder(Action& a)
{
	if (root != NULL)
		root->inorder_nodes(a);
}

void BinarySearchTree::preorder(Action& a)
{
	if (root != NULL)
		root->preorder_nodes(a);
}

void BinarySearchTree::postorder(Action& a)
{
	if (root != NULL)
		root->postorder_nodes(a);
}

void BinarySearchTree::insert(string data)
{
	TreeNode* new_node = new TreeNode;
	new_node->data = data;
	new_node->left = NULL;
	new_node->right = NULL;
	if (root == NULL) root = new_node;
	else root->insert_node(new_node);
}

void TreeNode::insert_node(TreeNode* new_node)
{

	if (new_node->data < data)
	{
		if (left == NULL) left = new_node;
		else left->insert_node(new_node);
	}
	else if (data < new_node->data)
	{
		if (right == NULL) right = new_node;
		else right->insert_node(new_node);
	}
}

void TreeNode::inorder_nodes(Action& v)
{
	if (left != NULL)
		left->inorder_nodes(v);
	v.act(data);
	if (right != NULL)
		right->inorder_nodes(v);
}

void TreeNode::preorder_nodes(Action& v)
{
	v.act(data);
	if (left != NULL) {
		left->preorder_nodes(v);
	}
	if (right != NULL) {
		right->preorder_nodes(v);
	}
}

void TreeNode::postorder_nodes(Action& v)
{
	if (left != NULL) {
		left->postorder_nodes(v);
	}
	if (right != NULL) {
		right->postorder_nodes(v);
	}
	v.act(data);
}

void BinarySearchTree::print(vector<string> vec) {
	for (int i = 0; i < vec.size(); i++) {
		cout << vec[i] << endl;
	}
}


int main()
{
	string fileName = "C:\\Users\\Casey Armstrong\\Desktop\\data4.txt";
	fstream data;
	data.open(fileName.c_str());
	string word;
	BinarySearchTree t;
	vector<string> words1;
	vector<string> words2;
	vector<string> words3;
	Action a1(words1);
	Action a2(words2);
	Action a3(words3);

	while (data >> word) {
		t.insert(word);
	}

	t.inorder(a1);
	
	cout << "The sum of all lengths of the strings stored in a tree: " << a1.num_chars() << endl;
	cout << endl << "Printing the elements of the tree inorder: " << endl;
	t.print(a1.getv());

	t.preorder(a2);
	cout << endl << "Printing the elements of the tree preorder: " << endl;
	t.print(a2.getv());

	t.postorder(a3);
	cout << endl << "Printing the elements of the tree postorder: " << endl;
	t.print(a3.getv());

	return 0;
}