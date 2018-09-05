#include<stdio.h>
int top=-1;
int MAXSIZE=100;
char s[100];

int isOperand(char x){
	if((x>='a'&& x<='z')||(x>='A' && x<='Z')){
		return 1;	
	}
	else
		return 0;
}

void push(char x){

	s[++top]=x;

}

char pop(){

	return s[top--];

}

int priority(char x){
	if(x=='('){
		return 0;
	}
	else if(x=='+' || x=='-'){
		return 1;	
	}
	else if(x=='*' || x=='/'){
		return 2;
	}
}

int main(){

	char exp[MAXSIZE],*e;
	printf("Enter your infix Expression: ");
	scanf("%s",exp);
	e=exp;
	while(*e!='\0'){
		
		if(isOperand(*e)){
			printf("%c",*e);		
		}

		else if(*e=='('){
			push(*e);
		}
		
		else if(*e==')'){
			while(s[top]!='('){
				printf("%c",pop());
			}
			top--;		
		}		
	
		else{			
			while(priority(s[top])>=priority(*e)){
					printf("%c",pop());
			}
			push(*e);
		}
	e++;
	}
	
while(top!=-1){
	printf("%c",pop());
}
printf("\n");
}
