#include<iostream>
using namespace std;
struct elem
{
	int key;
	elem *right;
	elem *left;
}*root = NULL,*root_tocno=NULL,*root_netochno=NULL;
void add(int n, elem*&t)
{
	if (t == NULL)
	{
		t = new elem;
		t->key = n;
		t->right = t->left = NULL;
	}
	else
		if (t->key > n)
			add(n, t->left);
		else
			add(n, t->right);
}
void preorder(elem *t)
{
	
	if (t)
	{
		cout << t->key << "\t";
		preorder(t->left);
		preorder(t->right);
	}
}
void Funkciq(elem *t)
{
	int num;
	if (t)
	{
		
		num = t->key;

		if (num % 2 == 0)
			add(num, root_tocno);
		else
			add(num, root_netochno);


		Funkciq(t->left);
		Funkciq(t->right);
	}
}
void main()
{
	int n;
	do
	{
		cout << "Vuvedi elmenti: ";
		cin >> n;
		if (n > 0)
			add(n, root);
	} while (n!=0);

	Funkciq(root);
	cout << "Chetni: ";
	preorder(root_tocno);
	cout << endl;
	cout << "Nechetni: ";
	preorder(root_netochno);
	system("pause");
}
