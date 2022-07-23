
#define MAX_NODE 10000

struct Node {
    int data;
    Node* prev;
    Node* next;
};

Node node[MAX_NODE];
int nodeCnt;
Node* head;
Node* tail;

Node* getNode(int data) {
    node[nodeCnt].data = data;
    node[nodeCnt].prev = nullptr;
    node[nodeCnt].next = nullptr;
    return &node[nodeCnt++];
}

void init()
{
    head = nullptr;
    tail = nullptr;
}

void addNode2Head(int data)
{
    Node *tmp = getNode(data);
    if(head == nullptr){
        head = tmp;
        tail = tmp;
        //printf("addNode2Head\n");
        return;
    }
    head->prev = tmp;
    tmp->next = head;
    head = tmp;
    //printf("addNode2Head\n");
    return;
}

void addNode2Tail(int data)
{
    Node *tmp = getNode(data);
    if(head == nullptr){
        head = tmp;
        tail = tmp;
        //printf("addNode2Head\n");
        return;
    }
    tmp->prev = tail;
    tail->next = tmp;
    tail = tmp;
    //printf("addNode2Head\n");
    return;
}

void addNode2Num(int data, int num)
{
    Node *curr;
   Node *tmp = getNode(data);
   if(num == 1){
       addNode2Head(data);
       return;
   }
    curr = head;
    int i = 1;
   for(; i < num && curr->next != nullptr; i++){
       curr = curr->next;
   }
    if(i!=num && curr->next == nullptr){
        curr->next = tmp;
        tmp->prev = curr;
        tail = tmp;
        return;
    }
        
   curr->prev->next = tmp;
    tmp->prev = curr->prev;
    tmp->next = curr;
    curr->prev = tmp;
   return;
}

int findNode(int data)
{
    Node *curr;
    int n = 1;
   curr = head;
   while(curr){
       if(curr->data == data){
           break;
       }
       n++;
       curr = curr->next;
   }
    return n;
}

void removeNode(int data)
{
    Node *curr;

   if(head->data == data){
       head = head->next;
       head->prev = nullptr;
   }
   curr = head;
   while(curr){
       if(curr->data == data){
           curr->prev->next = curr->next;
           if(curr->next == nullptr)
               tail = curr->prev;
           else
               curr->next->prev = curr->prev;

       }
       curr = curr->next;
   }
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
    return n;
}

int getReversedList(int output[MAX_NODE])
{
    int n = 0;
    Node *curr;
    curr = tail;
    while(curr != nullptr){
        output[n++] = curr->data;
        curr = curr->prev;
    }
    return n;
}
