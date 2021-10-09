#include <stdio.h>
#include<stdlib.h>

struct node {
    int data;
    struct node * next;
    
};

void fun(struct node *head){
    
    // head=(struct node *)malloc(sizeof(struct node));
      while(head!=NULL){
      printf("%d\n",head->data);
      head=head->next;}
      printf("\n");
}
void fun1(struct node*key,int n){
    struct node *ptr=key;
    struct node *end=(struct node *)malloc(sizeof(struct node));
    end->data=n;
    while(key->next!=NULL){
        key=key->next;
        
    }
    key->next=end;
    end->next=NULL;
    // key=ptr;
    fun(ptr);
}


void fun2(struct node*mid,int key,int pos){
    struct node*test=mid;
    struct node*inbetween=(struct node*)malloc(sizeof(struct node));
    inbetween->data=key;
        int i=0;
    while(i!=pos-2){
test=test->next;
i++;
    }
    inbetween->next=test->next;
    test->next=inbetween;
    fun(mid);
}



void deletion(struct node*del){
    struct node*key=del;
    key=key->next;
    free(del);
    fun(key);
}

void deletion1(struct node*del,int key){
    int i=0;
    struct node*test=del;
    struct node*q;
    while(test->data!=key){
        q=test;
        test=test->next;
    }
   q->next=test->next;
   free(test);
   fun(del);

}
void deletion2(struct node*ptr){
    struct node*key=ptr;
     struct node*test;
    while(key->next!=NULL){
       test=key;
        key=key->next;
    }
    // struct node*test=key;
     test->next=NULL;
    free(key);
    fun(ptr);
    
}

int main()
{
    struct node *head=(struct node *)malloc(sizeof(struct node));
    struct node *second=(struct node *)malloc(sizeof(struct node));
    head->data=20;
   
     head->next=second;
      second->data=40;
     second->next=NULL;
    
     
//   fun(head);
   struct node *new=(struct node *)malloc(sizeof(struct node));
new->data=12;
new->next=head;
 head=new;
// fun(head);

// fun1(head,15);


fun2(head,23,3);

 



 deletion1(head,23);
 deletion2(head);
 deletion(head);
    return 0;
}