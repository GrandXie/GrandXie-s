// biSearchTree.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
using namespace std;

class node {
	
private:
	int key;
	node *left = NULL;
    node *right = NULL;
    node *parent = NULL;

public:
	//构造函数
	node()
	{
      //
	};

	node(int akey)
	{
		key = akey;
	}

     ~node()
	{
		if (left != NULL)
		{
			delete left;
		}

		if (right != NULL)
		{
			delete right;
		}
	}

	 int getKey(){
		 return key;
	}

	 void addChild(node* aChild)
	 {
		 if (aChild->getKey() < key)
		 {
			 if (left != NULL) {
				 left->addChild(aChild);
			 }
			 else {
				 left = aChild;
				 aChild->parent = this;
			 }
			 
		 }
		 else if (aChild->getKey() > key)
		 {
			 if (right != NULL)
			 {
				 right->addChild(aChild);
			 }
			 else
			 {
				 right = aChild;
				 aChild->parent = this;
			 }
			 
		 }
	}

	 void mid_walk()
	 {
		 if (left != NULL)
		 {
			 left->mid_walk();
		 }
		 cout << key << endl;
		 if (right != NULL)
		 {
			 right->mid_walk();
		 }
	}

	 int look_up(int a)
	 {
		 if (key == a)
		 {
			 return key;
		 }
		 else if (key < a)
		 {
			 if (right == NULL)
			 {
				 return -1;
			 }
			 else
			 {
				 right->look_up(a);
			 }
		 }
		 else if (key > a)
		 {
			 if (left == NULL)
			 {
				 return -1;
			 }
			 else
			 {
				 left->look_up(a);
			 }
		 }

   }

};

int main()
{
	int i = 0;
	int a;
	node *root = new node(200);
	for (i = 0; i < 5; i++)
	{
		cin >> a;
		node* x = new node(a);
		root->addChild(x);
	}
	cout << "mid walk start" << endl;
	root->mid_walk();
	cin >> a;
	cout << root->look_up(a) << endl;
	cin >> a;
	cout << root->look_up(a) << endl;
	cin >> a;
	cout << root->look_up(a) << endl;
	cin >> a;
	cout << root->look_up(a) << endl;


	system("pause");
    return 0;
}

