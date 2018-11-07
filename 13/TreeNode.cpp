#pragma once

#include<iostream>
#include<string>
 
using namespace std;

class TreeNode{
	// constructor
	public:
		TreeNode(const string& s = " ", const int i = 0, TreeNode* const le = nullptr, TreeNode* const ri = nullptr):value(s),count(i),left(le),right(ri){}
		TreeNode(const TreeNode&);
	
		~TreeNode() = default;
	// operator
		TreeNode& operator=(const TreeNode&);
	
	// func
	
	// friend
	
	// var
	private:
		string value;
		int count;
		TreeNode *left;
		TreeNode *right;

		//int *use;
	
};

//who controls the free of left and right?
TreeNode::TreeNode(const TreeNode& tn){
	//could not delete before check
	/*
	++*tn.use;
	--*use;
	if(use == 0){
		//wow no need to delete
		//you just refresh the right and left pointer of it's
		//delete
	 * }
	 */

	value = tn.value;
	count = tn.count;
	//concentrate
	//emm seems no need to change too?
	//left -> right = 
	left = tn.left;
	right = tn.right;
}

TreeNode& TreeNode::operator=(const TreeNode& tn){
	value = tn.value;
	count = tn.count;
	//left = tn.left;
	//right = tn.right;
}

class BinTreeNode{
	//constructor
	public:
		BinTreeNode(TreeNode* const ro = nullptr):root(ro){}
		BinTreeNode(const BinTreeNode& bt): root(bt.root){}
	
	//operator
		BinTreeNode operator=(const BinTreeNode& bt){root = bt.root;}
	
	//func
	
	//friend
	
	//var
	private:
		TreeNode *root;
};

int main()
{
	system("pause");
	return 0;
}
