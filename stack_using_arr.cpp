#include <iostream>
#include <stdlib.h>
using namespace std;
struct stack {
    int size;
    int top;
    int *arr;
};
int isEmpty(struct stack *s){
    if(s->top==-1){
        return 1;
    }
    return 0;
}
int isFull(struct stack *s){
	if(s->top==s->size-1){
		return 1;
	}
	return 0;
}
void push(struct stack *s,int data){
	if(isFull(s)){
		cout<<"STACK OVERFLOW "<<endl;
	}
	else{
		s->top++;
		s->arr[s->top]=data;
	}
}
void pop(struct stack *s){
	if(isEmpty(s)){
		cout<<"STACK UNDERFLOW "<<endl;
	}
	else{
		int val=s->arr[s->top];
		s->top--;
		cout<<"Value popped is :"<<val<<endl;
	}
}
void peek(struct stack* s,int i){
	int arr_int=s->top-i+1;
	if(arr_int<0){
		cout<<"INVALID POS"<<endl;
	}
	else{
		cout<<"Value at index "<<i<<" is: "<<s->arr[arr_int]<<endl;
	}
}
void stackTop(struct stack *s){
	cout<<"Top ele is "<<s->arr[s->top]<<endl;
	
}
void stackBottom(struct stack *s){
	cout<<"Bottom ele is "<<s->arr[0]<<endl;
}
int main()
{
    struct stack *s;
    s=(struct stack* ) malloc (sizeof(struct stack));
    s->size=10;
    s->top=-1;
    s->arr=(int*) malloc ((s->size)*sizeof(int));
    push(s,20);
    cout<<"DATA is "<<s->arr[s->top]<<endl;
    push(s,30);
    cout<<"DATA is "<<s->arr[s->top]<<endl;
    push(s,40);
    cout<<"DATA is "<<s->arr[s->top]<<endl;
    push(s,50);
    cout<<"DATA is "<<s->arr[s->top]<<endl;
//    cout<<"POP VALUE"<<endl;
//    pop(s);
//    cout<<"DATA is "<<s->arr[s->top]<<endl;
	peek(s,2);
	peek(s,5);
	
   
    return 0;
}

