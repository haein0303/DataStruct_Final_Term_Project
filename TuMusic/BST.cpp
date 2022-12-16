#include "stdafx.h"
#include "BST.h"


BST::BST() {
	root = nullptr;
}
void BST::init_tree()
{
	root = nullptr;
}
int BST::is_empty_tree()
{
	return root == nullptr;
}
TNode* BST::get_root()
{
	 return root;
}
TNode* BST::search(TNode* n, string key)
{
	if (n == nullptr) return nullptr;
	else if (key == n->data) return n;
	else if (key < n->data) return search(n->left, key);
	else return search(n->right, key);
}

bool BST::search_BST(string key)
{
	TNode* n = search(root, key);
	if (n != nullptr)
		return true;
	else
		return false;
}

void BST::delete_node(TNode* parent, TNode* node)
{
	TNode* child, * succ, * succp;

	// case 1
	if ((node->left == NULL && node->right == NULL)) {
		if (parent == NULL) root = NULL;
		else {
			if (parent->left == node)
				parent->left = NULL;
			else parent->right = NULL;
		}
	}
	// case 2
	else if (node->left == NULL || node->right == NULL) {
		child = (node->left != NULL) ? node->left : node->right;
		if (node == root) root = child;
		else {
			if (parent->left == node)
				parent->left = child;
			else parent->right = child;
		}
	}
	// case 3
	else {
		succp = node;
		succ = node->right;
		while (succ->left != NULL) {
			succp = succ;
			succ = succ->left;
		}
		if (succp->left == succ)
			succp->left = succ->right;
		else succp->right = succ->right;

		node->data = succ->data;
		node = succ;
	}
	free(node);
}

void BST::delete_BST(string key)
{
	TNode* parent = NULL;
	TNode* node = root;

	if (node == NULL) return;
	while (node != NULL && node->data != key) {
		parent = node;
		node = (key < node->data) ? node->left : node->right;
	}
	if (node == NULL)
		printf(" Error: key is not in the tree!\n");
	else delete_node (parent, node);
}

int BST::insert(TNode* r, TNode* n)
{
	if (n->data == r->data) return 0;
	else if (n->data < r->data) {
		if (r->left == NULL) r->left = n;
		else insert(r->left, n);
	}
	else {
		if (r->right == NULL) r->right = n;
		else insert(r->right, n);
	}
	return 1;
}

void BST::insert_BST(string key)
{
	TNode* n = create_tree(key, NULL, NULL);
	if (is_empty_tree())
		root = n;
	else if (insert(root, n) == 0)
		free(n);
}

TNode* BST::create_tree(string val, TNode* l, TNode* r)
{
	TNode* n = new TNode;
	//n->data.copy(val);
	//n->data = nullptr;
	n->data = val;
	n->left = l;
	n->right = r;
	return n;
}
