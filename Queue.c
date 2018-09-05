#include<stdio.h>
#include<stdlib.h>

int f=0,r=0;

int enqueue(int q[],int x,int SizeOfQueue){
    if(r==SizeOfQueue){
        printf("Overflow!\n");
        return 0;
    }
    else{
        q[r++]=x;
        return 1;
    }
}

int dequeue(int q[]){
    int temp;
    if(f==r){
        printf("Underflow!!\n");
        return 0;
    }
    else{
        temp=q[f];
        q[f++]=0;
        return temp;
    }
}

int size(){
    return (r-f);
}

int main(){
    int n,x,v,O;
    printf("Enter size of the Queue: ");
    scanf("%d",&n);
    int q[n];
    pick : printf("\n\nQQQQQQQQQQ--Queue--QQQQQQQQQQ\n");
           printf("-----------CHOICES-----------\n");
           printf("1.ENQUEUE\n2.DEQUEUE\n3.DISPLAY QUEUE\n4.SIZE OF QUEUE\n5.EXIT!!\n");
           printf("------------------------------\n\n");
           printf("ENTER YOUR CHOICE: ");
           scanf("%d",&O);

    switch(O){
        case 1:
            printf("Enter Element you want to Add: ");
            scanf("%d",&x);
            v=enqueue(q,x,n);
            if(v){
                printf("\nADDED!!\n");
            }
            else{
                printf("Try Different Choice!!\n");
            }
            break;

        case 2:
            v=dequeue(q);
            if(v){
                printf("\nElement DEQUEUED: %d\n",v);
            }
            else{
                printf("Try Different Choice!!\n");
            }
            break;

        case 3:
        if(size()){
            printf("QUEUE: ");
            for(int i=f;i<r;i++){
                printf("%d ",q[i]);
            }
            printf("\n");
        }
        else{
            printf("\nQueue is Empty!!\n");
        }
            break;

        case 4:
            v=size();
            printf("Size: %d\n",v);
            break;

        case 5:
            exit(0);
    }
    goto pick;
return 0;
}
