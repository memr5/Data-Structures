//Using Rear Pointer//
#include<stdio.h>
#include<stdlib.h>

struct node{
	int data;
	struct node* next;
};

struct node* head=NULL,*rear=NULL;

void InsertAtEnd(int value){

	struct node* new=(struct node*)malloc(sizeof(struct node));
	new->data=value;
	//new->next=NULL;
	if(head==NULL){
		head=new;
		new->next=head;
		rear=new;
	}
	else{
		rear->next=new;
		new->next=head;
		rear=new;
	}
printf("Added!\n");
}

void InsertAtBeginning(int value){
	struct node* new=(struct node*)malloc(sizeof(struct node));
	new->data=value;
	if(head){
		new->next=head;
		rear->next=new;
	}
	else{
		new->next=new;
		rear=new;
	}
	head=new;
	printf("Added!\n");
}

void Display(){
	if(head==NULL){
		printf("List is Empty\n");
	}
	else{
		struct node* temp=head;
		printf("List: HEAD->%d ->",head->data);
		temp=temp->next;
		while(temp!=head){
			printf("%d -> ",temp->data);
			temp=temp->next;
		}
		printf("HEAD\n");
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
		if(current->data==value){
			head=head->next;
			rear->next=head;
			return;
		}
		current=current->next;
		prev=head;
		while(current!=head && current->data != value){
			temp=current;
			current=current->next;
			prev=temp;
		}
		if(current!=head && current->next!=head){
			prev->next=current->next;
			free(current);
			printf("Deleted!\n");
		}
		else if(current!=head){
			rear=prev;
			prev->next=head;
			free(current);
			printf("Deleted!\n");
		}
		else if(current==head){
			printf("Value not in the list!\n");
		}
	}
}

void PrintInReverse(struct node* Head){
	if(Head!=head){
		PrintInReverse(Head->next);
		printf("%d-> ",Head->data);
	}
}

void Reverse_List(){
	if(head==NULL){
		printf("List is Empty!\n");
		return;
	}
	else{
		struct node* current=head,*prev=NULL,*temp;
		while(current->next!=head){
			temp=current;
			current=current->next;
			temp->next=prev;
			prev=temp;
		}
		if(prev!=NULL){
			current->next=prev;
			rear=head;
			head->next=current;
			head=current;
			printf("Reversed!!\n");
		}
	}
}


int main(){
	int choice;
	int x;
Start:	printf("Enter 1: Insert at end\nEnter 2: Insert at Beginning\nEnter 3: Display\nEnter 4: Insert after Value\nEnter 5: Delete\nEnter 6: Print in reverse order\nEnter 7: Reverse-List\nEnter 8: Exit\nEnter here: ");
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
			PrintInReverse(head->next);
			printf("%d->HEAD\n",head->data);
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
List: HEAD->0 ->1 -> 2 -> 3 -> HEAD
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
Enter data value of new node: 5
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
List: HEAD->0 ->1 -> 2 -> 5 -> 3 -> HEAD
Enter 1: Insert at end
Enter 2: Insert at Beginning
Enter 3: Display
Enter 4: Insert after Value
Enter 5: Delete
Enter 6: Print in reverse order
Enter 7: Reverse-List
Enter 8: Exit
Enter here: 5
Enter value to delete: 5
Deleted!
List: HEAD->0 ->1 -> 2 -> 3 -> HEAD
Enter 1: Insert at end
Enter 2: Insert at Beginning
Enter 3: Display
Enter 4: Insert after Value
Enter 5: Delete
Enter 6: Print in reverse order
Enter 7: Reverse-List
Enter 8: Exit
Enter here: 6
Reverse-Order : TAIL-> 3-> 2-> 1-> 0->HEAD
Enter 1: Insert at end
Enter 2: Insert at Beginning
Enter 3: Display
Enter 4: Insert after Value
Enter 5: Delete
Enter 6: Print in reverse order
Enter 7: Reverse-List
Enter 8: Exit
Enter here: 7
Reversed!!
List: HEAD->3 ->2 -> 1 -> 0 -> HEAD
*/
