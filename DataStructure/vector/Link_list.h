
struct Link_Node
{
       Link_Node* pre;
       Link_Node* next;
       int value;
};

struct Link_List
{
       Link_Node head;
};

bool insert(int value,Link_List* A);
bool delete_by_value(int value,Link_List* A);
bool delete_by_place(int index,Link_List* A);
bool change_by_place(int index,Link_List* A);
bool change_by_value(int value,Link_List* A);