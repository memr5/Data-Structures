#include<stdio.h>
#include<stdlib.h>

struct node{
	int data;
	struct node* llink;
	struct node* rlink;
};

struct node* head=NULL;

void InsertAtEnd(int value){
	struct node* new = (struct node*)malloc(sizeof(struct node));
	new->data = value;
	new->rlink=NULL;
	if(head==NULL){
		new->llink=NULL;
		head=new;
	}
	else{
		struct node* temp = head;
		while(temp->rlink!=NULL){
			temp=temp->rlink;
		}
		new->llink=temp;
		temp->rlink=new;
	}
	printf("\nAdded!\n");
}

void InsertAtBeginning(int value){
	struct node* new = (struct node*)malloc(sizeof(struct node));
	new->data = value;
	new->llink=NULL;
	if(!head){
        head=new;
        new->rlink=NULL;
        printf("\nAdded!\n");
        return;
	}
	new->rlink=head;
	head->llink=new;
	head=new;
	printf("\nAdded!\n");
}

void Display(){
	if(head==NULL){
		printf("\nList is Empty!\n");
		return;
	}
	else{
		struct node* temp=head;
		printf("\nHead-> ");
		while(temp){
			printf("%d->",temp->data);
			temp=temp->rlink;
		}
		printf(" NULL\n");
	}
}

void InsertAfter(int value){
	if(head==NULL){
		printf("\nList is Empty!\n");
		return;
	}
	else{
		struct node* temp=head;
		while(temp && temp->data!=value){
			temp=temp->rlink;
		}
		if(temp==NULL){
			printf("\nValue not in the List!\n");
		}
		else{
			printf("Enter the value you want to insert: ");
			int newdata;
			scanf("%d",&newdata);
			struct node* new=(struct node*)malloc(sizeof(struct node));
			new->data=newdata;
			new->rlink=temp->rlink;
			temp->rlink=new;
			new->llink=temp;
			new->rlink->llink=new;
			printf("\nAdded!\n");
		}
	}
}

void DeleteValue(){
	if(head==NULL){
		printf("\nList is Empty!\n");
		return;
	}
	else{
		printf("Enter the value you want to delete: ");
		int value;
		scanf("%d",&value);
		struct node* temp=head;
		while(temp && temp->data!=value){
			temp=temp->rlink;
		}
		if(temp){
			printf("\nDeleted!\n");
			if(temp==head){
				head=temp->rlink;
				if(temp->rlink){
					temp->rlink->llink=NULL;
				}
				return;
			}
			temp->llink->rlink=temp->rlink;
			temp->rlink->llink=temp->llink;
			free(temp);
		}
		else{
			printf("\nValue not in the List!\n");
		}
	}
}

void PrintInReverse(){
	struct node* tail=head;
	while(tail->rlink!=NULL){
		tail=tail->rlink;
	}
	while(tail){
		printf("%d->",tail->data);
		tail=tail->llink;
	}
}

void Reverse_List(){
	if(head==NULL){
		printf("\nList is Empty!\n");
		return;
	}
	else if(head->rlink){
		struct node* temp=head,*temp2;
		while(temp->rlink!=NULL){
			temp2=temp->llink;
			temp->llink=temp->rlink;
			temp->rlink=temp2;
			temp=temp->llink;
		}
		temp2=temp->llink;
		temp->llink=temp->rlink;
		temp->rlink=temp2;
		head=temp;
		printf("\nReversed!\n");
	}
}

int main(){
	int choice;
	int x;
	printf("\n******Doubly-Linked-List******\n");
Start:	printf("\nEnter 1: Insert at end\nEnter 2: Insert at Beginning\nEnter 3: Display\nEnter 4: Insert after Value\nEnter 5: Delete\nEnter 6: Print in reverse order\nEnter 7: Reverse-List\nEnter 8: Exit\nEnter here: ");
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
			PrintInReverse();
			printf(" HEAD\n");
		}
		break;

		case 7:
		Reverse_List();
		Display();
		break;

		case 8:
		exit(0);
	}
	goto Start;
return 0;
}

/*
******Doubly-Linked-List******

Enter 1: Insert at end
Enter 2: Insert at Beginning
Enter 3: Display
Enter 4: Insert after Value
Enter 5: Delete
Enter 6: Print in reverse order
Enter 7: Reverse-List
Enter 8: Exit
Enter here: 1
Enter Value you want to insert: 1

Added!

Enter 1: Insert at end
Enter 2: Insert at Beginning
Enter 3: Display
Enter 4: Insert after Value
Enter 5: Delete
Enter 6: Print in reverse order
Enter 7: Reverse-List
Enter 8: Exit
Enter here: 1
Enter Value you want to insert: 2

Added!

Enter 1: Insert at end
Enter 2: Insert at Beginning
Enter 3: Display
Enter 4: Insert after Value
Enter 5: Delete
Enter 6: Print in reverse order
Enter 7: Reverse-List
Enter 8: Exit
Enter here: 1
Enter Value you want to insert: 3

Added!

Enter 1: Insert at end
Enter 2: Insert at Beginning
Enter 3: Display
Enter 4: Insert after Value
Enter 5: Delete
Enter 6: Print in reverse order
Enter 7: Reverse-List
Enter 8: Exit
Enter here: 1
Enter Value you want to insert: 4

Added!

Enter 1: Insert at end
Enter 2: Insert at Beginning
Enter 3: Display
Enter 4: Insert after Value
Enter 5: Delete
Enter 6: Print in reverse order
Enter 7: Reverse-List
Enter 8: Exit
Enter here: 2
Enter Value you want to add: 0

Added!

Enter 1: Insert at end
Enter 2: Insert at Beginning
Enter 3: Display
Enter 4: Insert after Value
Enter 5: Delete
Enter 6: Print in reverse order
Enter 7: Reverse-List
Enter 8: Exit
Enter here: 3

Head-> 0->1->2->3->4-> NULL

Enter 1: Insert at end
Enter 2: Insert at Beginning
Enter 3: Display
Enter 4: Insert after Value
Enter 5: Delete
Enter 6: Print in reverse order
Enter 7: Reverse-List
Enter 8: Exit
Enter here: 4
Enter the value of the node after which you want to insert new node: 2
Enter the value you want to insert: 5

Added!

Enter 1: Insert at end
Enter 2: Insert at Beginning
Enter 3: Display
Enter 4: Insert after Value
Enter 5: Delete
Enter 6: Print in reverse order
Enter 7: Reverse-List
Enter 8: Exit
Enter here: 3

Head-> 0->1->2->5->3->4-> NULL

Enter 1: Insert at end
Enter 2: Insert at Beginning
Enter 3: Display
Enter 4: Insert after Value
Enter 5: Delete
Enter 6: Print in reverse order
Enter 7: Reverse-List
Enter 8: Exit
Enter here: 5
Enter the value you want to delete: 5

Deleted!

Head-> 0->1->2->3->4-> NULL

Enter 1: Insert at end
Enter 2: Insert at Beginning
Enter 3: Display
Enter 4: Insert after Value
Enter 5: Delete
Enter 6: Print in reverse order
Enter 7: Reverse-List
Enter 8: Exit
Enter here: 6
Reverse-Order : TAIL-> 4->3->2->1->0-> HEAD

Enter 1: Insert at end
Enter 2: Insert at Beginning
Enter 3: Display
Enter 4: Insert after Value
Enter 5: Delete
Enter 6: Print in reverse order
Enter 7: Reverse-List
Enter 8: Exit
Enter here: 7

Reversed!

Head-> 4->3->2->1->0-> NULL
*/
