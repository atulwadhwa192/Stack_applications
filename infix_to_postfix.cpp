#include<iostream>
#include<stdlib.h>
#include<string>
using namespace std;
struct stack{
	int top;
	int size;
	char *arr;
};
int isEmpty(struct stack *s){
	if(s->top==-1){
		return 1;
	}
	return 0;	
}
int isFull(struct stack *s){
	if((s->top)==(s->size-1)){
		return 1;
	}
	return 0;
	
}
void push(struct stack *s,char data){
		s->top=s->top+1;
		s->arr[s->top]=data;
}
void pop(struct stack *s){
	s->top--;
}
int isOperator(char x){
	if(x=='+' || x=='*' || x=='-' || x=='/' || x=='%'){
		return 1;
	}
	return 0;
}
int precedence(char x){
	if(x=='/' || x=='*' || x=='%'){
		return 3;
	}
	else if(x=='+'|| x=='-'){
		return 2;
	}
}
int main(){
	struct stack *s;
	int i=0;
	s=(struct stack*) malloc (sizeof(struct stack));
	cout<<"Enter the Infix Expression"<<endl;
	string str;
	string post_exp="";
	cin>>str;
	s->top=-1;
	s->size=str.length();
	s->arr=(char*) malloc ((s->size)*sizeof(char));
	while(i<str.length()){
		
		if(!isOperator(str[i])){
			post_exp+=str[i];
			i++;
//			cout<<post_exp<<endl;
		}
		else{
			if(isEmpty(s)){
				push(s,str[i]);
				i++;
			}
			else{
				int x=precedence(str[i]);
				int y=precedence(s->arr[s->top]);
				if(x>y){
				push(s,str[i]);
				i++;
				}
				else{
				char val_pop=s->arr[s->top];
//				cout<<val_pop;
				pop(s);
				post_exp+=val_pop;
				}
			}
		}	
	}
	while(!isEmpty(s)){
		char val_pop=s->arr[s->top];
		pop(s);
		post_exp+=val_pop;
	}

	cout<<"Postfix expression is: "<<post_exp<<endl;

}
