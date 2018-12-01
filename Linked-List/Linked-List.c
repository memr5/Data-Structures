#include<stdio.h>
#include<stdlib.h>

struct node{
	int data;
	struct node* next;
};

struct node* head=NULL;

void InsertAtEnd(int value){

	struct node* new=(struct node*)malloc(sizeof(struct node));
	new->data=value;
	new->next=NULL;
	if(head==NULL){
		head=new;
	}
	else{
		struct node* temp=head;
		while(temp->next!=NULL){
			temp=temp->next;
		}
		temp->next=new;
	}
printf("Added!\n");
}

void InsertAtBeginning(int value){
	struct node* new=(struct node*)malloc(sizeof(struct node));
	new->data=value;
	new->next=head;
	head=new;
	printf("Added!\n");
}

void Display(){
	if(head==NULL){
		printf("List is Empty\n");
	}
	else{
		struct node* temp=head;
		printf("List: HEAD->");
		while(temp!=NULL){
			printf("%d -> ",temp->data);
			temp=temp->next;
		}
		printf("NULL\n");
	}
}

void InsertAfter(int value){

	if(head==NULL){
		printf("List is Empty!\n");
		return;
	}
	struct node* temp=head;
	while(temp!=NULL && temp->data!=value){
		temp=temp->next;
	}
	if(temp==NULL){
		printf("Value not in the List\n");
	}
	else{
		int newdata;
		printf("Enter data value of new node: ");
		scanf("%d",&newdata);
		struct node* new=(struct node*)malloc(sizeof(struct node));
		new->data=newdata;

		new->next=temp->next;
		temp->next=new;
		printf("Added!\n");
	}
}

void DeleteValue(){
	if(head==NULL){
		printf("List is Empty!\n");
		return;
	}
	else{
		int value;
		printf("Enter value to delete: ");
		scanf("%d",&value);
		struct node* current=head,*prev=NULL,*temp;
		while(current!=NULL && current->data != value){
			temp=current;
			current=current->next;
			prev=temp;
		}
		if(prev==NULL){
			head=head->next;
			printf("Deleted!\n");
		}
		else if(current!=NULL && prev!=NULL){
			prev->next=current->next;
			free(current);
			printf("Deleted!\n");
		}
		else if(current==NULL){
			printf("Value not in the list!\n");
		}
	}
}

void PrintInReverse(struct node* head){
	if(head!=NULL){
		PrintInReverse(head->next);
		printf("%d-> ",head->data);
	}
}

void Reverse_List(){
	if(head==NULL){
		printf("List is Empty!\n");
		return;
	}
	else{
		struct node* current=head,*prev=NULL,*temp;
		while(current->next!=NULL){
			temp=current;
			current=current->next;
			temp->next=prev;
			prev=temp;
		}
		if(prev!=NULL){
			current->next=prev;
			head=current;
			printf("Reversed!!\n");
		}
	}
}

void Swap_Pairs(){
    if(head==NULL){
        printf("List is Empty!\n");
        return;
    }
    else if(head->next!=NULL){
        struct node* temp=head->next;
        head->next=head->next->next;
        temp->next=head;
        head=temp;

        struct node* current=head->next->next, *prev=head->next;
        while(current && current->next!=NULL){
            temp=current->next;
            current->next=current->next->next;
            temp->next=current;
            prev->next=temp;
            current=current->next;
            prev=prev->next->next;
        }
        printf("Swapped!\n");
    }
}

int main(){
	int choice;
	int x;
Start:	printf("Enter 1: Insert at end\nEnter 2: Insert at Beginning\nEnter 3: Display\nEnter 4: Insert after Value\nEnter 5: Delete\nEnter 6: Print in reverse order\nEnter 7: Reverse-List\nEnter 8: Swap-Pairs\nEnter 9: Exit\nEnter here: ");
	scanf("%d",&choice);
	switch(choice){
		case 1:

		printf("Enter Value you want to insert: ");
		scanf("%d",&x);
		InsertAtEnd(x);
		break;

		case 2:
		printf("Enter Value you want to add: ");
		scanf("%d",&x);
		InsertAtBeginning(x);
		break;

		case 3:
		Display();
		break;

		case 4:
		printf("Enter the value of the node after which you want to insert new node: ");
		scanf("%d",&x);
		InsertAfter(x);
		break;

		case 5:
		DeleteValue();
		Display();
		break;

		case 6:
		if(head==NULL){
			printf("List is Empty!\n");
		}
		else{
			printf("Reverse-Order : TAIL-> ");
			PrintInReverse(head);
			printf(" HEAD\n");
		}
		break;

		case 7:
		Reverse_List();
		Display();
		break;

		case 8:
		Swap_Pairs();
		break;

		case 9:
		exit(0);
	}
	goto Start;
return 0;
}
