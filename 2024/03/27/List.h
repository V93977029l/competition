#ifndef NULL
#define NULL 0
#endif

template <typename T>
class List
{
public:
    List(T data);
    ~List();

private:
    struct node
    {
        T data;
        List *next = NULL;
    };

    node *ptr_first;
    node *ptr_last;
    node *current;
    int length = 0;

public:
    const int current_num = 0;

    void push_back(T data);
    void move(int location);
    void insert(T data, int location);
    void insert(T data);
    void del(int location);
    void del_next();
    void inversion();
};