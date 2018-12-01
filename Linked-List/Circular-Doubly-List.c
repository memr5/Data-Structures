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
	if(head==NULL){
		new->llink=new;
		head=new;
		new->rlink=head;
	}
	else{
		struct node* temp = head->llink;
        head->llink=new;
        new->llink=temp;
        new->rlink=head;
        temp->rlink=new;
	}
	printf("\nAdded!\n");
}

void InsertAtBeginning(int value){
	struct node* new = (struct node*)malloc(sizeof(struct node));
	new->data = value;

    if(!head){
        head=new;
        new->rlink=head;
        new->llink=head;
        printf("\nAdded!\n");
        return;
	}
	struct node* temp=head->llink;
	new->rlink=head;
	head->llink=new;
	head=new;
	temp->rlink=new;
	new->llink=temp;
	printf("\nAdded!\n");
}

void Display(){
	if(head==NULL){
		printf("\nList is Empty!\n");
		return;
	}
	else{
		struct node* temp=head->rlink;
		printf("\nHead-> %d->",head->data);
		while(temp!=head){
			printf("%d->",temp->data);
			temp=temp->rlink;
		}
		printf(" Head\n");
	}
}

void InsertAfter(int value){
	if(head==NULL){
		printf("\nList is Empty!\n");
		return;
	}
	else{
		struct node* temp=head->rlink;
		if(head->data==value){
            struct node* nw = (struct node*)malloc(sizeof(struct node));
            printf("Enter the value you want to insert: ");
			scanf("%d",&nw->data);
			nw->rlink=head->rlink;
			head->rlink=nw;
			nw->llink=head;
			nw->rlink->llink=nw;
			printf("\nAdded!\n");
			return;
		}
		while(temp!=head && temp->data!=value){
			temp=temp->rlink;
		}
		if(temp==head){
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
		if(head->data==value){
            if(head->rlink==head){
                head=NULL;
            }
            else{
                struct node* temp = head->llink;
                head=head->rlink;
                head->llink=temp;
                temp->rlink=head;
            }
            printf("Deleted!\n");
            return;
		}
        struct node* temp=head->rlink;
        while(temp!=head && temp->data!=value){
            temp=temp->rlink;
        }
        if(temp==head){
            printf("Value not in the list\n");
        }
        else{
            temp->llink->rlink=temp->rlink;
            temp->rlink->llink=temp->llink;
            printf("Deleted!\n");
        }
	}
}

int main(){
	int choice;
	int x;
	printf("\n******Circular-Doubly-Linked-List******\n");
Start:	printf("\nEnter 1: Insert at end\nEnter 2: Insert at Beginning\nEnter 3: Display\nEnter 4: Insert after Value\nEnter 5: Delete\nEnter 6: Exit\nEnter here: ");
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
		exit(0);
	}
	goto Start;
return 0;
}

/*
******Circular-Doubly-Linked-List******

Enter 1: Insert at end
Enter 2: Insert at Beginning
Enter 3: Display
Enter 4: Insert after Value
Enter 5: Delete
Enter 6: Exit
Enter here: 1
Enter Value you want to insert: 1

Added!

Enter 1: Insert at end
Enter 2: Insert at Beginning
Enter 3: Display
Enter 4: Insert after Value
Enter 5: Delete
Enter 6: Exit
Enter here: 1
Enter Value you want to insert: 2

Added!

Enter 1: Insert at end
Enter 2: Insert at Beginning
Enter 3: Display
Enter 4: Insert after Value
Enter 5: Delete
Enter 6: Exit
Enter here: 1
Enter Value you want to insert: 3

Added!

Enter 1: Insert at end
Enter 2: Insert at Beginning
Enter 3: Display
Enter 4: Insert after Value
Enter 5: Delete
Enter 6: Exit
Enter here: 2
Enter Value you want to add: 0

Added!

Enter 1: Insert at end
Enter 2: Insert at Beginning
Enter 3: Display
Enter 4: Insert after Value
Enter 5: Delete
Enter 6: Exit
Enter here: 3

Head-> 0->1->2->3-> Head

Enter 1: Insert at end
Enter 2: Insert at Beginning
Enter 3: Display
Enter 4: Insert after Value
Enter 5: Delete
Enter 6: Exit
Enter here: 4
Enter the value of the node after which you want to insert new node: 3
Enter the value you want to insert: 4

Added!

Enter 1: Insert at end
Enter 2: Insert at Beginning
Enter 3: Display
Enter 4: Insert after Value
Enter 5: Delete
Enter 6: Exit
Enter here: 3

Head-> 0->1->2->3->4-> Head

Enter 1: Insert at end
Enter 2: Insert at Beginning
Enter 3: Display
Enter 4: Insert after Value
Enter 5: Delete
Enter 6: Exit
Enter here: 5
Enter the value you want to delete: 2
Deleted!

Head-> 0->1->3->4-> Head
*/
