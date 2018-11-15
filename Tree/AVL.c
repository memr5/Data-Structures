#include<stdio.h>
#include<stdlib.h>
#include<math.h>

struct node{
	int data;
	int height;
	struct node* left;
	struct node* right;
};

int MAX(int l,int r){
    return (l>=r ? l : r);
}

struct node* New_Node(int value){
        struct node* nw = (struct node*)malloc(sizeof(struct node));
        nw->data = value;
        nw->left=NULL;
        nw->right=NULL;
        nw->height=0;
return nw;
}

int Height(struct node* root){
    if(root==NULL){
        return -1;
    }
return root->height;
}

int BalanceF(struct node* root){
    return (Height(root->left)-Height(root->right));
}

struct node* rotate_Right(struct node* root){
    struct node* temp = root->left;
    root->left=temp->right;
    temp->right=root;
    root->height=1+MAX(Height(root->left),Height(root->right));
    temp->height=1+MAX(Height(temp->left),Height(temp->right));
return temp;
}

struct node* rotate_Left(struct node* root){
    struct node* temp = root->right;
    root->right=temp->left;
    temp->left=root;
    root->height=1+MAX(Height(root->left),Height(root->right));
    temp->height=1+MAX(Height(temp->left),Height(temp->right));
return temp;
}

struct node* Left_Left(struct node* root){
    root=rotate_Right(root);
return root;
}

struct node* Left_Right(struct node* root){
    root->left=rotate_Left(root->left);
    root=rotate_Right(root);
return root;
}

struct node* Right_Right(struct node* root){
    root=rotate_Left(root);
return root;
}

struct node* Right_Left(struct node* root){
    root->right=rotate_Right(root->right);
    root=rotate_Left(root);
return root;
}

struct node* Insert(struct node* root,int value){

    if(root==NULL){
        root=New_Node(value);
        return root;
    }
    else if(root->data > value){
        root->left=Insert(root->left,value);
        if(BalanceF(root)==2){
            if(root->left->data > value){
                //Left-Left
                root=Left_Left(root);
            }
            else{
                //Left-Right
                root=Left_Right(root);
            }
        }
    }
    else if(root->data < value){
        root->right=Insert(root->right,value);
        if(BalanceF(root)==-2){
            if(root->right->data < value){
                //Right-Right
                root=Right_Right(root);
            }
            else{
                root=Right_Left(root);
            }
        }
    }
    else{
        printf("\nDuplicate Keys Not-Allowed!\n");
    }

    root->height = 1 + MAX(Height(root->left),Height(root->right));

return root;
}

struct node* Delete(struct node* root,int value){
    if(!root){
        printf("\nValue Not in Tree!\n");
        return root;
    }

    if(root->data > value){
        root->left=Delete(root->left,value);
        if(BalanceF(root)==-2){
            if(BalanceF(root->right)<=0){
                //Right-Right
                root=Right_Right(root);
            }
            else{
                root=Right_Left(root);
            }
        }
    }
    else if(root->data < value){
        root->right=Delete(root->right,value);
        if(BalanceF(root)==2){
            if(BalanceF(root->left)>=0){
                //Left-Left
                root=Left_Left(root);
            }
            else{
                //Left-Right
                root=Left_Right(root);
            }
        }
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

    root->height=1+MAX(Height(root->left),Height(root->right));

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

int main(){

	int choice,x;
	struct node* root = NULL;

START : printf("\n<<<<AVL-Tree>>>>\n");
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

