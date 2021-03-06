#include <iostream>

using namespace std;

struct Node {
	string data;
	Node *left;
	Node *right;
		
	Node(string d) {
		data = d;
		left = NULL;
		right = NULL;
	}
};

class BST {
	private:
		Node *root;
		void Insert(string data, Node *aNode);
		Node* Search(string data, Node *aNode);
		void preOrder(Node *aNode);
		void inOrder(Node *aNode);
		void postOrder(Node *aNode);
		
	public:
		BST();
	  void Insert(string data);
		Node* Search(string data);
		void preOrder();
		void inOrder();
		void postOrder();
};

BST::BST() {
	root = NULL;
}

// private insert
void BST::Insert(string data, Node *aNode) {
	if(data < aNode->data) {
		if(aNode->left != NULL) 
			Insert(data, aNode->left);
		else {
			aNode->left = new Node(data);
		}
	} else if(data >= aNode->data) {
		if(aNode->right != NULL) 
			Insert(data, aNode->right);
		else {
			aNode->right = new Node(data);
		}
	}
}

// public insert
void BST::Insert(string data) {
	if(root != NULL) {
		Insert(data, root);
	} else {
		root = new Node(data);
	}
}

// private search
Node* BST::Search(string data, Node *aNode){
	if(aNode != NULL) {
		if(data == aNode->data) {
			return aNode;
		}
		if(data < aNode->data) {
			return Search(data, aNode->left);
		} else {
			return Search(data, aNode->right);
		}
	} else {
		return NULL;
	}
}

// public search
Node* BST::Search(string data){
	return Search(data, root);
}

/* Root, Left, Right */
void BST::preOrder(){
	preOrder(root);
}

void BST::preOrder(Node *aNode) {
	if(aNode != NULL) {
		cout << aNode->data <<" ";
		preOrder(aNode->left);
		preOrder(aNode->right);
	}
}

/* Left, Root, Right */
void BST::inOrder() {
	inOrder(root);
}

void BST::inOrder(Node *aNode) {
	if(aNode != NULL) {
		inOrder(aNode->left);
		cout << aNode->data <<" ";
		inOrder(aNode->right);
	}
}

/* Left, Right, Root */
void BST::postOrder() {
	postOrder(root);
}

void BST::postOrder(Node *aNode) {
	if(aNode != NULL) {
		postOrder(aNode->left);
		postOrder(aNode->right);
		cout << aNode->data <<" ";
	}
}


int main() {
	BST *btree = new BST();
	
	btree->Insert("apple");
	btree->Insert("mango");
	btree->Insert("kiwi");
	
	btree->preOrder(); cout<<endl;
	btree->inOrder(); cout<<endl;
	btree->postOrder(); cout<<endl;
	
	// or 
	/* BST btree;
	
	btree.Insert("apple");
	btree.Insert("mango");
	btree.Insert("kiwi");
	
	btree.preOrder(); cout<<endl;
	btree.inOrder(); cout<<endl;
	btree.postOrder(); cout<<endl;*/
	return 0;
}
