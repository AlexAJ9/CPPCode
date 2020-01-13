#include<iostream>.h
using namespace std;
const int n = 15;
struct link { char key; link *next; }*gr[n];
void init(link *gr[n])
{
	for (int i = 0; i < n; i++)
		gr[i] = NULL;
}
int search_node(link *gr[], char c)
{
	int flag = 0;
	for (int  i = 0; i < n; i++)
	{
		if (gr[i])
		{
			if (gr[i]->key==c)
			{
				flag = 1;
			}

		}
	}
	return flag;
}
int search_arc(link*gr[5], char c1, char c2)
{
	int flag = 0;
	if (search_node(gr, c1) && search_node(gr, c2))
	{
		int i = 0;
		while (gr[i]->key != c1)
			i++;
		link *p = gr[i];
		while (p->key != c2&&p->next != NULL)
			p = p->next;
		if (p->key == c2)
			flag = 1;
	}
	return flag;
}
void add_node(link *gr[n], char c)
{
	if (search_node(gr,c))
	{
		cout << "Exsisting node \n";
	}
	else
	{
		int j = 0;
		while (gr[j] && (j < n))
			j++;
		if (gr[j] == NULL)
		{
			gr[j] = new link;
			gr[j]->key = c;
			gr[j]->next = NULL;
		}
		else
			cout << "\n OVERFLOW \n";
	}
}
void add_arc(link *gr[n], char c1, char c2)
{
	int i = 0;
	link *p;
	if(search_arc(gr,c1,c2))
	{
		cout << " \n Existing arc!";
	}
	else
	{
		if (!(search_node(gr, c1)))
			add_node(gr, c1);
		if (!(search_node(gr, c2)))
			add_node(gr, c2);
		while (gr[i]->key != c1)
			i++;
		p = new link;
		p->key = c2;
		p->next = gr[i]->next;
		gr[i]->next = p;



	}
}
void print(link *gr[n])
{
	cout << "\n";
for (int  i = 0; i < n; i++)
{
	if (gr[i])
		cout << gr[i]->key;
}
}
void rang(link *arg[n]) {
	int count = 0;
	int max = 0;
	int a = 0;
		for (int i=0; i < n; i++)
	{
		
		if (arg[i])
		{
			link *start = arg[i];
			while (start->next)
			{
				start = start->next;
				count++;
				
			}
			for (int x = 0; x < n; x++)
			{
				if (arg[x])
				{
					link *start = arg[x];
					while (start->next)
					{
						start = start->next;
						if (start->key ==arg[i]->key  ) { a++; }
					}
				}
			}
			
			count = count + a;
			if (count>max)
			{
				max = count;
			}
			count = 0;
			a = 0;
		}
	}
cout << "Max stepen na graph e : ";
	cout << max;
}

void main()
{
	int max = 0;
	char c;
	char k;
	char m;
	init(gr);
	cout << "\n Enter node ";
	while (cin >> c&& c != '0')
add_node(gr, c);
	cout << "\n Vuvedi Dugi \n ";
	do {
		cout << "purvi vruh ";
		cin >> k;
		cout << "vtori vruh ";
		cin >> m;
		if(k != '0'&&m != '0')
			add_arc(gr, k, m);
	} while (k != '0'&&m != '0');
	
 rang(gr);
	

	print(gr);
	system("pause");
}
