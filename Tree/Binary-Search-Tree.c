#include<stdio.h>
#include<stdlib.h>

struct node{
	int data;
	struct node* left;
	struct node* right;
};

struct node* Create_New(int value){
	struct node* new = (struct node*)malloc(sizeof(struct node));
	new->data=value;
	new->left=NULL;
	new->right=NULL;
return new;
}

struct node* Insert(struct node* root,int value){
	if(!root){
		root=Create_New(value);
		printf("\nAdded!\n");
		return root;
	}

	if(root->data > value){
		root->left=Insert(root->left,value);
	}
	else if(root->data < value){
		root->right=Insert(root->right,value);
	}
	else{
		printf("\nDuplicate Values Not Allowed!\n");
	}
return root;
}

void Inorder(struct node* root){
	if(root){
		Inorder(root->left);
		printf("%d ",root->data);
		Inorder(root->right);
	}
}

void Pre_Order(struct node* root){
	if(root){
		printf("%d ",root->data);
		Pre_Order(root->left);
		Pre_Order(root->right);
	}
}

void Post_Order(struct node* root){
	if(root){
		Post_Order(root->left);
		Post_Order(root->right);
		printf("%d ",root->data);
	}
}

struct node* Delete(struct node* root,int value){
	if(!root){
		printf("\nValue Not in the Tree\n");
		// return root;
	}
	if(root->data > value){
		root->left = Delete(root->left,value);
	}
	else if(root->data < value){
		root->right = Delete(root->right,value);
	}
	else{
        printf("\nDeleted!\n");
		if(root->left==NULL && root->right==NULL){
			free(root);
			return NULL;
		}
		else if(root->right==NULL){
			struct node* temp = root->left;
			free(root);
			return root->left;
		}
		else if(root->left==NULL){
			struct node* temp = root->right;
			free(root);
			return root->right;
		}
		else{
			struct node* temp = root->right;
			while(temp->left!=NULL){
				temp=temp->left;
			}
			root->data = temp->data;
			root->right=Delete(root->right,temp->data);
		}
	}
return root;
}

int main(){

	int choice,x;
	struct node* root = NULL;

START : printf("\n<<<<Binary-Search-Tree>>>>\n");
	printf("Enter 1: Insert\nEnter 2: Inorder\nEnter 3: Pre-Order\nEnter 4: Post-Order\nEnter 5: Delete\nEnter 6: Exit\n");
	printf("Enter choice: ");
	scanf("%d",&choice);

	switch(choice){
		case 1:
		printf("\nEnter Value to Add: ");
		scanf("%d",&x);
		root=Insert(root,x);
		break;

		case 2:
		printf("\nInorder : ");
		Inorder(root);
		printf("\n");
		break;

		case 3:
		printf("\nPre-Order : ");
		Pre_Order(root);
		printf("\n");
		break;

		case 4:
		printf("\nPost-Order : ");
		Post_Order(root);
		printf("\n");
		break;

		case 5:
		if(!root){
			printf("\nTree is Empty!\n");
			break;
		}
		printf("\nEnter Value to Delete : ");
		scanf("%d",&x);
		root=Delete(root,x);
		break;

		case 6:
		exit(0);
	}
	goto START;
return 0;
}
