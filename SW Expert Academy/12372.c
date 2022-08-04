#include<malloc.h>
typedef struct Node{
    int uID, income;
    struct Node *next;
}Node;

Node *head;

void init()
{
    head = NULL;
    
}

int cmp(Node *a, Node *b){
    //printf("%d, %d\n",a,b);
    if(a->income != b->income){
        return a->income > b->income;
    }
       return a->uID < b->uID;
}

void addUser(int uID, int income)
{
    Node *newNode = (Node*)malloc(sizeof(Node));
    newNode->uID = uID;
    newNode->income = income;
    newNode->next = NULL;
    
    Node *curr = head;
    Node *prev = head;
    if(head == NULL){
        head = newNode;
        return;
    }
    if(!cmp(head, newNode)){
        newNode->next = head;
        head = newNode;
        return;
    }
    prev = head;
    curr = curr->next;
    int cnt = 1;
    while(curr!=NULL && cmp(curr, newNode) && cnt<10){
        prev = curr;
        curr = curr->next;
        cnt++;
    }
    if(curr!=NULL){
        
    }
    if(cnt<10){
        prev->next = newNode;
        newNode->next = curr;
    }

}

int getTop10(int result[10])
{
    int i=0;
    
    if(head == NULL){
        return i;
    }
    Node *curr = head;
//    printf("income ");
    while(curr!=NULL && i<10){
        result[i++] = curr->uID;
//        printf("%d ",curr->income);
        curr = curr->next;
    }
//    printf("\n");
    return i;
}
