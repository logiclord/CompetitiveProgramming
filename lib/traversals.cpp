#include<iostream>
#include<stack>
using namespace std;


struct  node
{
	int val;
	node * left;
	node * right;
	node *parent;
};

class BST
{
	node * root;
	node * getNode(int val)
	{
		node * current = new node;
		current->left = NULL;
		current->right = NULL;
		current->val = val;
		return current;
	}
	void deleteNode(node * &current)
	{
		delete current;
		current = NULL;
	}
public:
	BST()
	{
		root = NULL;
	}
	void insert(int val)
	{
		if(root == NULL)
		{
			root = getNode(val);
			root->parent = NULL;
		}
		else
		{
			node * temp = root, * parent = NULL;
			while(temp !=NULL)
			{
				parent = temp;
				if(temp->val > val)
				{
					temp = temp->left;
				}
				else
				{
					temp = temp->right;
				}
			}
			if(parent->val > val)
			{
				parent->left = getNode(val);
				parent->left->parent = parent;
			}
			else
			{
				parent->right= getNode(val);
				parent->right->parent = parent;
			}
		}
	}

	node * search(int val)
	{
		node * ret = NULL;
		node * temp = root;
		while(temp !=NULL)
		{
			if(temp->val > val)
			{
				temp = temp->left;
			}
			else if(temp->val < val)
			{
				temp = temp->right;
			}
			else
			{
				ret = temp;
				break;
			}
		}
		return ret;
	}

	void deleteTree(int val)
	{
		node * temp = root, * parent = NULL;
		while(temp!= NULL && temp->val != val)
		{
			parent = temp;
			if(temp->val > val)
			{
				temp = temp->left;
			}
			else if(temp->val < val)
			{
				temp = temp->right;
			}
		}

		// element exists in BST
		if(temp!=NULL)
		{
			if(temp->left == NULL || temp->right == NULL)
			{
				node * child = (temp->left == NULL) ? temp->right : temp->left;
				if(parent == NULL)
				{
					root = child;
				}
				else if(parent->left == temp)
				{
					parent->left = child;
				}
				else
				{
					parent->right = child;
				}
				deleteNode(temp);
			}
			else
			{
				node * predecessor = temp->left;
				parent = NULL;
				while(predecessor->right !=NULL)
				{
					parent = predecessor;
					predecessor = predecessor->right;
				}
				temp->val = predecessor->val;
				parent->right = predecessor->left;
				deleteNode(predecessor);
			}
		}
	}


	void inorder()
	{
		stack<node *> st;
		node * cur = root;
		while(cur!=NULL || !st.empty())
		{
			if(cur!=NULL)
			{
				st.push(cur);
				cur = cur->left;
			}
			else
			{
				cur = st.top();
				st.pop();
				cout<<cur->val<<" ";
				cur = cur->right;
			}
		}
		cout<<endl;
	}

	void preorder()
	{
		stack<node *> st;
		node * cur = root;
		while(cur!=NULL || !st.empty())
		{
			if(cur!=NULL)
			{
				cout<<cur->val<<" ";
				st.push(cur->right);
				cur = cur->left;
			}
			else
			{
				cur = st.top();
				st.pop();
			}
		}
		cout<<endl;
	}


	void postorder()
	{
		stack<node *> st;
		node *current = root;
		node * parent = NULL;
		st.push(root);
		while(!st.empty())
		{
			current = st.top();
			if(parent==NULL || parent->left == current || parent->right==current)
			{
				if(current->left!=NULL)
				{
					st.push(current->left);
				}
				else if(current->right!=NULL)
				{
					st.push(current->right);
				}
				else
				{
					cout<<current->val<<" ";
					st.pop();
				}
			}
			else if(parent==current->left)
			{
				if(current->right!=NULL)
				{
					st.push(current->right);
				}
				else
				{
					cout<<current->val<<" ";
					st.pop();
				}
			}
			else
			{
				cout<<current->val<<" ";
				st.pop();
			}

			parent = current;
		}
		cout<<endl;
	}



	void morrisInorder()
	{
		node * current = root;
		while(current!=NULL)
		{
			if(current->left==NULL)
			{
				cout<<current->val<<" ";
				current = current->right;
			}
			else
			{
				node * temp = current->left;
				while(temp->right!=NULL && temp->right!=current)
				{
					temp = temp->right;
				}


				if(temp->right==NULL)
				{
					temp->right = current;
					current = current->left;
				}
				else
				{
					temp->right = NULL;
					cout<<current->val<<" ";
					current = current->right;
				}
			}
		}
		cout<<endl;
	}


	void morrisPreorder()
	{
		node * current = root;
		while(current!=NULL)
		{
			if(current->left==NULL)
			{
				cout<<current->val<<" ";
				current = current->right;
			}
			else
			{
				node * temp = current->left;
				while(temp->right!=NULL && temp->right!=current)
				{
					temp = temp->right;
				}


				if(temp->right==NULL)
				{
					temp->right = current;
					cout<<current->val<<" ";
					current = current->left;
				}
				else
				{
					temp->right = NULL;
					current = current->right;
				}
			}
		}
		cout<<endl;
	}

	void morrisPostorder()
	{
	}

	void parentInorder()
	{
		node *parent = NULL;
		node * temp = root;

		while(temp!=NULL || parent!=NULL)
		{
			if(temp!=NULL)
			{
				parent = temp;
				temp = temp->left;
			}
			else
			{
				cout<<parent->val<<" ";
				temp = parent->right;

				if(temp == NULL)
				{
					temp = parent;
					while(temp->parent!=NULL && temp->parent->left != temp)
					{
						temp = temp->parent;
					}

					if(temp->parent == NULL)
					{
						parent = temp = NULL;
					}
					else if(temp->parent->left  == temp)
					{
						parent = temp->parent;
						cout<<parent->val<<" ";
						temp = parent->right;
					}

				}
			}
		}
		cout<<endl;
	}

	void parentPreorder()
	{
		node *parent = NULL;
		node * temp = root;

		while(temp!=NULL || parent!=NULL)
		{
			if(temp!=NULL)
			{
				cout<<temp->val<<" ";
				parent = temp;
				temp = temp->left;
			}
			else
			{
				temp = parent->right;

				if(temp == NULL)
				{
					temp = parent;
					while(temp->parent!=NULL && temp->parent->left != temp)
					{
						temp = temp->parent;
					}

					if(temp->parent == NULL)
					{
						parent = temp = NULL;
					}
					else if(temp->parent->left  == temp)
					{
						parent = temp->parent;
						temp = parent->right;
					}

				}
			}
		}
		cout<<endl;
	}

	void parentPostorder()
	{
		node *parent = NULL;
		node * temp = root;

		while(temp!=NULL || parent!=NULL)
		{
			if(temp!=NULL)
			{
				parent = temp;
				temp = temp->left;
			}
			else
			{
				temp = parent->right;

				if(temp == NULL)
				{
					temp = parent;
					while(temp->parent!=NULL && temp->parent->left != temp)
					{
						cout<<temp->val<<" ";
						temp = temp->parent;
					}
					cout<<temp->val<<" ";
					if(temp->parent == NULL)
					{
						parent = temp = NULL;
					}
					else if(temp->parent->left  == temp)
					{
						parent = temp->parent;
						temp = parent->right;
					}

				}
			}
		}
		cout<<endl;
	}

	void parentPostorder2()
	{
		node * current = root;
		while(current!=NULL)
		{
			if(current->left !=NULL)
				current = current->left;
			else if(current->right !=NULL)
			{
				current = current->right;
			}
			else
			{
				cout<<current->val<<" ";
				while(current!=NULL)
				{
					if(current->parent!=NULL && current->parent->left == current && current->right!=NULL)
					{
						current = current->parent->right;
						break;
					}
					else if(current->parent!=NULL && current->parent->right == current )
					{
						cout<<current->parent->val<<" ";
					}
					current = current->parent;
				}
			}
		}
		cout<<endl;
	}
};

int main()
{	BST tree;
int t, n;
cin>>t;
while(t--)
{
	cin>>n;
	tree.insert(n);
}
tree.preorder();
tree.inorder();
tree.postorder();
tree.morrisPreorder();
tree.morrisInorder();
tree.parentInorder();
tree.parentPreorder();
tree.parentPostorder();
tree.parentPostorder2();
return 0;
}


