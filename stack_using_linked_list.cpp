#include<iostream>
#include<stdlib.h>
using namespace std;
struct Node{
	int data;
	struct Node *next;
};
void traversal(struct Node* top){
	while(top!=NULL){
		cout<<"Element is "<<top->data<<endl;
		top=top->next;
	}
}
int isEmpty(struct Node* top){
	if(top==NULL){
		return 1;
	}
	return 0;
}
int isFull(struct Node* top){
	struct Node* p= (struct Node*)malloc(sizeof(struct Node));
	if(p==NULL){
		return 1;
	}
	return 0;	
}
struct Node* push(struct Node* top,int data){
	if(isFull(top)){
		return NULL;
	}
	else{
		struct Node* n= (struct Node*) malloc(sizeof(struct Node));
		n->data=data;
		n->next=top;
		return n;
	}
}
void stackBottom(struct Node* top){
	struct Node* ptr=top;
	while(ptr->next!=NULL){
		ptr=ptr->next;
	}
	cout<<"End of stack is"<<ptr->data<<endl;
}
void stackTop(struct Node* top){
	cout<<"Element at top of the stack is"<<top->data;
}
void peek(struct Node* top,int pos){
	struct Node* ptr=top;
	for(int i=0;i<pos-1 && ptr!=NULL;i++){
		ptr=ptr->next;
	}
	if(ptr==NULL){
		cout<<"Invalid Index"<<endl;
	}
	else{
		cout<<"Element at position "<<pos<<" is "<<ptr->data;
	}
}
struct Node* pop(struct Node* top){

		struct Node *ptr=top;
		cout<<"Poped element is "<<ptr->data;
		top=top->next;
		free(ptr);
		return top;

}

int main(){
	struct Node *top=NULL;
//	top= (struct Node*) malloc(sizeof(struct Node));
	top=push(top,20);
	top=push(top,40);
	top=push(top,60);
	top=push(top,80);
	top=push(top,100);
	traversal(top);
	
	
}
