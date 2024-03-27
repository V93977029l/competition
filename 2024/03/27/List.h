#ifndef NULL
#define NULL	0
#endif

template <typename T>
class list
{
public:
	list(T data)
	{
		ptr_first = new node;
		ptr_first->data = data;
		length = 1;
	}
	~list()
	{
		current = ptr_first;
		while (current != NULL)
		{
			node* temp = current;
			current = current->next;
			delete temp;
		}
	}
private:
	struct node
	{
		T data;
		list* next = NULL;
	};

	node* ptr_first;
	node* ptr_last;
	node* current;
	int length = 0;

	const setLast()
	{
		last = ptr_first;
	}
public:
	const node* last;
	const int current_num = 0;

	void push_back(T data)
	{
		ptr_last->next = new node;
		ptr_last = ptr_last->next;
		ptr_last.data = data;
		length++;
	}
	void insert(T data, int location)
	{
		if (location > current)
		{
			node* temp = current;
			int count = current_num;
		}
		else
		{
			node* temp = ptr_first;
			int count = 0;
		}
		while (count < location)
		{
			temp = temp->next;
			count++;
		}
		insert(data);
	}
	void insert(T data);
	void del_current();
	friend void inversion();
};