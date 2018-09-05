#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *link;
};

struct node *root=NULL;

void atEnd(){
    struct node *temp,*p;
    temp=(struct node*)malloc(sizeof(struct node));
    printf("Enter data you want to store: ");
    scanf("%d",&temp->data);
    temp->link=NULL;
    if(root==NULL){
        root=temp;
    }
    else{
        p=root;
        while(p->link!=NULL){
            p=p->link;
        }
        p->link=temp;
    }
}

void atBeginning(){

    struct node *temp;
    temp=(struct node*)malloc(sizeof(struct node));

    printf("Enter Data you want to store: ");
    scanf("%d",&temp->data);
    temp->link=NULL;

    if(root==NULL){
        root=temp;
    }
    else{
        temp->link=root;
        root=temp;
    }
}

int length(){
    struct node *p;
    int count=0;
    if(root==NULL){
        return 0;
    }
    else{
        p=root;
        while(p!=NULL){
            p=p->link;
            count++;
        }
        return count++;
    }
}

int atAfter(){
    int n,i=1;
    int len=length();
    struct node *temp,*p;
    printf("Enter index after which you want to insert element: ");
    scanf("%d",&n);

    if(n>len){
        printf("Index not Valid!\n");
        return 0;
    }
    else{
        temp=(struct node*)malloc(sizeof(struct node));
        printf("Enter data you want to store: ");
        scanf("%d",&temp->data);
        temp->link=NULL;
        p=root;
        while(i<n){
            p=p->link;
            i++;
        }
        temp->link=p->link;
        p->link=temp;
        return 1;
    }
}

void display(){
    int len=length();
    struct node *p;
    if(len==0){
        printf("\nNothing to Display!!\n");
    }
    else{
        p=root;
        for(int i=1;i<=len;i++){
            printf("%d->",p->data);
            p=p->link;
        }
    }
}

void deleteElement(){
    int n,i=1;
    int len=length();
    struct node *p=root,*temp;
    if(len==0){
        printf("Nothing to Delete!\n");
    }
    else{
        printf("Enter index(1-%d) of element you want to delete: ",len);
        scanf("%d",&n);
        while(i<n-1){
            p=p->link;
        }
        temp=p;
        p=p->link;
        p=p->link;
        temp->link=p;
        printf("DELETED!!\n");
    }
}

int main(){

    int O,v;
     pick: printf("\n\nLLL--LinkedList--LLLLLLLL\n");
           printf("-----------CHOICES-----------\n");
           printf("1.At End\n2.At Beginning\n3.At After\n4.Length of List\n5.Display\n6.Delete element\n7.EXIT!!\n");
           printf("------------------------------\n\n");
           printf("ENTER YOUR CHOICE: ");
           scanf("%d",&O);

    switch(O){
        case 1:
        atEnd();
        printf("\nAdded!\n");
        break;

        case 2:
        atBeginning();
        printf("\nAdded!\n");
        break;

        case 3:
        v=atAfter();
        if(v){
            printf("\nAdded!!\n");
        }
        else{
            printf("\nTry different Choice!\n");
        }
        break;

        case 4:
        v=length();
        printf("\nLength= %d\n",v);
        break;

        case 5:
        display();
        break;

        case 6:
        deleteElement();
        break;

        case 7:
        exit(0);
    }
    goto pick;
return 0;
}
