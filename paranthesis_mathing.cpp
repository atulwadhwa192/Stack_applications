#include<stdlib.h>
#include<iostream>
#include<string>
// pos i.e. position starts from 1 i.e. index +1
// opening paranthesis - {,[,(
// closing paranthesis - },],)
using namespace std;
struct stack{
	int size;
	int top;
	char *arr;
};
int isEmpty(struct stack *s){
	if(s->top==-1){
		return 1;
	}
	return 0;
	
}
int isFull(struct stack *s){
	if((s->top)==((s->size)-1)){
		return 1;
	}
	return 0;	
}
void push(struct stack *s,char data){
	if(isFull(s)){
		cout<<"Stack Overflow"<<endl;
	}
	else{
		s->top++;
		s->arr[s->top]=data;
	}
	
}
void pop(struct stack *s){
	if(isEmpty(s)){
		cout<<"Stack Underflow"<<endl;
	}
	else{
		s->top--;
	}
}
void peek(struct stack *s,int i){
	int pos=(s->top)-i+1;
	cout<<"Element at pos "<<i<<" is "<< s->arr[pos]<<endl;
}
int main(){
	int flag=0;
	string str;
	cout<<"Enter the string";
	cin>>str;
	int size=str.length();
	struct stack *s;
	s=(struct stack*) malloc (sizeof(struct stack));
	s->size=size;
	s->top=-1;
	s->arr= (char*) malloc(size*sizeof(char));
	for(int i=0;i<size;i++){
		if(str[i]=='{'|| str[i]=='(' || str[i]=='['){
			push(s,str[i]);
		}
		else if(str[i]=='}'){
			if(isEmpty(s)){
				flag=1;
				cout<<"INVALID EXPRESSION"<<endl;
				break;
				}
			else if(s->arr[s->top]!='{'){
				break;
			}
			else{
//				cout<<s->top<<endl;
				pop(s);
				}
			}
		else if(str[i]==')'){
				if(isEmpty(s)){
				flag=1;
				cout<<"INVALID EXPRESSION"<<endl;
				break;
				}
			else if(s->arr[s->top]!='('){
				break;
			}
			else{
//				cout<<s->top<<endl;
				pop(s);
				}
		}
		else if(str[i]==']'){
				if(isEmpty(s)){
				flag=1;
				cout<<"INVALID EXPRESSION"<<endl;
				break;
				}
			else if(s->arr[s->top]!='['){
				break;
			}
			else{
//				cout<<s->top<<endl;
				pop(s);
				}
		}
		else{
			continue;
		}
	}
//	cout<<s->top;
	// for viewing stack before poping
//	for(int i=1;i<=(s->top)+1;i++){
//		peek(s,i);
//	}
if(flag==0 && s->top==-1){
	cout<<"Balanced Expression"<<endl;
}
else if(s->top!=-1 && flag==0){
	cout<<"INVALID EXPRESSION"<<endl;
}
}
