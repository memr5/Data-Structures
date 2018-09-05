#include<stdio.h>

int top=-1,maintop=-1;;
char temp[100];


int IsNum(char x){
    if(x>='0'&&x<='9'){
        return 1;
    }
    else return 0;
}

void push(char x){
    temp[++top]=x;
}

int IsOperator(char x){
    if(x=='+'||x=='-'||x=='*'||x=='/'||x=='%'){
        return 1;
    }
    else return 0;
}

int pop(int m[]){
	return m[maintop--];
}

int main(){

	char s[100],*exp;
	int count=0;
	int main[100];
	printf("Enter Postfix exp: ");
	scanf("%[^\n]%*c",s);
	printf("%s\n",s);
	exp=s;
	while(*exp!='\0'){

        if(IsNum(*exp)){
            push(*exp);
            count++;
        }

        else if(*exp==' ' && IsNum(temp[top])){
            if(count==2){
                main[++maintop]=(temp[top-1]-'0')*10 + temp[top]-'0';
                count=0;
            }
            else if(count==1){
                main[++maintop]=temp[top]-'0';
                count=0;
                }
            }
        else if(IsOperator(*exp)){
        push(*exp);
	int n=pop(main);
	int m=pop(main);
                switch(*exp){
                    case '+':
			m+=n;
                        break;
                    case '-':
			m-=n;
                        break;
                    case '*':
			m*=n;
                        break;
                    case '/':
                        m/=n;
                        break;
                    case '%':
                        m%=n;
                        break;
                }
		main[++maintop]=m;
            }
		
            exp++;
        }
        printf("Answer: %d\n",main[maintop]);
    return 0;
	}

