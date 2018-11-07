#include<string>

using std::string;

class TreeNode{
	//constructor
	TreeNode():value(),count(0),left(nullptr),right(nullptr){};
	TreeNode(string s,int i,TreeNode* l, TreeNode* r):value(s),count(i),left(l),right(r){}
	TreeNode(const TreeNode& tn):value(tn.value),count(tn.count),left(tn.left),right(tn.right){}

	//operator
	TreeNode& operator=(const TreeNode&);
	
	//friend
	
	//deconstructor
	
	//var
	private:
		string value;
		int count;
		TreeNode *left;
		TreeNode *right;
};

TreeNode& TreeNode::operator=(const TreeNode& tn)
{
	value = tn.value;
	count = tn.count;
	left = tn.left;
	right = tn.right;

	return *this;
}

class BinStrTree{
	//constructor
	public:
		BinStrTree():root(nullptr){}
		BinStrTree(TreeNode tn):root(&tn){}
		BinStrTree(const BinStrTree& bst):root(bst.root){}
	
	//friend
	
	//operator
	public:
		BinStrTree& operator=(const BinStrTree& bst){root = bst.root; return *this;}
	
	//func
	
	//var
	private:
		TreeNode *root;
	
	//deconstructor
	
};
