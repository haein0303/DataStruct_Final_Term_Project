#pragma once

typedef struct BinTrNode {
	string data;
	struct BinTrNode* left;
	struct BinTrNode* right;
} TNode;

class BST
{
public:
	TNode* root;
	BST();
	void init_tree();
	int is_empty_tree();
	TNode* get_root();
	TNode* search(TNode* n, string key);
	bool search_BST(string key);
	void delete_node (TNode* parent, TNode* node);
	void delete_BST(string key);
	int insert(TNode* r, TNode* n);
	void insert_BST(string key);
	TNode* create_tree(string val, TNode* l, TNode* r);
};

