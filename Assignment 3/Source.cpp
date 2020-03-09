#include<iostream>
#include<string>
#include <sstream>
using namespace std;
//This struct stores information of a node
struct Node {
	int data;
	Node* nextLeft;
	Node* nextRight;
	Node* back;

	//Constructors
	Node() {
		nextLeft = NULL;
		nextRight = NULL;
		back = NULL;
	}
};


class Binary_Tree {
	Node* root;

public:
	Binary_Tree() {};
	Binary_Tree(Node* r) {
		root = r;
	}
	//Getters
	Node* get_root() { return root; }
	int root_data() { return root->data; }

	//Convert int output to string ouput
	string to_string(Node* root) {
		ostringstream os;
		if (root == NULL)
			os << "NULL\n";
		else
			os << root->data;
		return os.str();
	}

	//Output preorder traversal binarytree
	string pre_order(Node* local_root) {
		string result;  
		if (local_root != NULL) {
			result += to_string(local_root);
			if (local_root->nextLeft != NULL) {
				result += " ";
				result += pre_order(local_root->nextLeft);
			}
			if (local_root->nextRight != NULL) {
				result += " ";
				result += pre_order(local_root->nextRight);
			}
		}
		return result;
	}

	//This function calculate the sum of all nodes recursively
	int r_sum(Node* root) {
		int result = 0;
		if (root != NULL) {
			result += root->data;
			//Calculate sum of the left sub-trees
			if (root->nextLeft != NULL)
				result += r_sum(root->nextLeft);
			//Calculate sum of the right sub-trees
			if (root->nextRight != NULL) {
				result += r_sum(root->nextRight);
			}
		}
		return result;
	}
};

//This function gets input for the tree
void get_data(Binary_Tree& tree) {

	int num;
	char choice;
	Node* temp = new Node;
	temp = tree.get_root();

	cout << "Enter data for binary tree" << endl;
	cout << "\t(L)-go to the left side" << endl;
	cout << "\t(R)-go to the right side" << endl;
	cout << "\t(P)-go back to parent node" << endl;
	cout << "\t(Q)-quit" << endl;
	cout << "(L/R/P/Q ?)==> ";
	cin >> choice;
	choice = tolower(choice);

	while (choice != 'q') {
		Node* newNode = new Node;
		switch (choice)
		{
		case 'l':
			cout << "Enter value: ";
			cin >> num;
			//Create new Node
			newNode->data = num;
			//Point the left to new Node
			temp->nextLeft = newNode;
			newNode->back = temp;
			temp = temp->nextLeft;
			break;
		case 'r':
			cout << "Enter value: ";
			cin >> num;
			//Create new Node
			newNode->data = num;
			//Point the right to new Node
			temp->nextRight = newNode;
			newNode->back = temp;
			temp = temp->nextRight;
			break;
		case 'p':
			delete newNode;
			//Go back the parent node
			if (temp->back != NULL) {
				temp = temp->back;
				cout << "You are at parent node" << endl;
			}
			else
				cout << "You are at the root" << endl;
			break;
		}
		//Continue entering data
		cout << "==> ";
		cin >> choice;
		choice = tolower(choice);
	}
}


int main() {
	int num;
	Node* temp = new Node;
	cout << "First, enter the root data: ";
	cin >> num;
	temp->data = num;
	Binary_Tree tree(temp);

	//Input data for binary tree
	get_data(tree);
	cout << endl << "Preorder Traversal: " << tree.pre_order(tree.get_root()) << endl;
	
	//Calculate the sum
	cout << "Sum = " << tree.r_sum(tree.get_root()) << endl;

	system("pause");
	return 0;
}