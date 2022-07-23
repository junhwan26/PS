#define MAX_NODE 10000

enum { ADD_HEAD = 1, ADD_TAIL, ADD_NUM, REMOVE, PRINT, END = 99 };

struct Node {
    int data;
    Node* next;
};

Node node[MAX_NODE];
int nodeCnt;
Node* head;

Node* getNode(int data) {
    node[nodeCnt].data = data;
    node[nodeCnt].next = nullptr;
    return &node[nodeCnt++];
}

void init()
{
    head = nullptr;
    //printf("init\n");
    return;
}

void addNode2Head(int data)
{
    Node *tmp = getNode(data);
    if(head == nullptr){
        head = tmp;
        //printf("addNode2Head\n");
        return;
    }
    tmp->next = head;
    head = tmp;
    //printf("addNode2Head\n");
    return;
}

void addNode2Tail(int data)
{
    Node *curr, *prev;
    Node *tmp = getNode(data);
    if(head == nullptr){
        head = tmp;
         //printf("addNode2Tail\n");
        return;
    }
    curr = head;
    prev = head;
    while(curr){
        prev = curr;
        curr = curr->next;
    }
    prev->next = tmp;
    //printf("addNode2Tail\n");
     return;

}

void addNode2Num(int data, int num)
{
     Node *curr, *prev;
    Node *tmp = getNode(data);
    if(num == 1){
        addNode2Head(data);
        return;
    }
    curr = head;
    prev = head;
    for(int i = 1; i < num && curr != nullptr; i++){
        prev = curr;
        curr = curr->next;
    }
    prev->next = tmp;
    tmp->next = curr;
    return;
}

void removeNode(int data)
{
     Node *curr, *prev;

    if(head->data == data){
        head = head->next;
    }
    prev = head;
    curr = head;
    while(curr){
        
        if(curr->data == data){
            prev->next = curr->next;
            curr = prev->next;
            continue;
        }
        prev = curr;
        curr = curr->next;
    }
    //printf("removeNode\n");
}

int getList(int output[MAX_NODE])
{
    int n = 0;
    Node *curr;
    curr = head;
    while(curr != nullptr){
        output[n++] = curr->data;
        curr = curr->next;
    }
    //printf("getList\n");
    return n;
}
