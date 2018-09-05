#include<stdio.h>
#include<stdlib.h>
int top=-1;

int push(int s[],int x,int n){

	if(top==n-1){
		printf("\nStack if Full!!\n\n");
		return 0;
	}
	else if(top<n-1){
		s[++top]=x;
		return 1;
	}
}

int pop(int s[]){
	if(top==-1){
		printf("\nNothing to pop!!\n\n");
		return 0;
	}

	else
		return s[top--];
}

int isEmpty(){
	if(top==-1){return 0;}
	else return 1;
}


int main(){
	
	int n,choice,x;
	printf("Enter size of the Stack:");
	scanf("%d",&n);
	int s[n];

	pick : printf("\n\n------------------------------------\n");
	printf("Choose one Option from the following\n");
	printf("1.Push one element\n2.Pop out top element\n3.Check if Stack is empty\n4.Exit\n");
	printf("------------------------------------\n");
	printf("Enter your Choice:");
	scanf("%d",&choice);

	switch(choice){
	
		case 1:
		printf("Enter value of element you want to push:");
		scanf("%d",&x);
		
		if(push(s,x,n)==0){ printf("\nTry different choice!!\n"); }

		else{
			printf("\nAdded!!\n");		
		}
		break;

		case 2:
		x=pop(s);
		if(x==0){
				printf("\nTry different choice!!\n");	
			}
		else{
				printf("\nPopped element:%d\n",x);
			}
		break;

		case 3:
		x=isEmpty();
		if(x==0){
				printf("\nStack is Empty!!\n");			
			}
		else{
				printf("\nStack is not empty!!\n");			
			}
		break;

		case 4:
		exit(0);
	}
	goto pick;

return 0;
}
