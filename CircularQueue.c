#include<stdio.h>
#include<stdlib.h>
//global variables
int f=0,r=0,count=0;

int enqueue(int cq[],int x,int n){
    if(count==n){
        printf("OVERFLOW!!\n");
        return 0;
    }
    else{
        cq[r]=x;
        r=(r+1)%n;
        count++;
        return 1;
    }
}

void dequeue(int cq[],int n){
    if(count==0){
        printf("Underflow!!\n");
    }
    else{
        printf("Element Dequeued: %d",cq[f]);
        cq[f]=0;
        f=(f+1)%n;
        count--;
    }
}

int main(){
    int n,x,v,O;
    printf("Enter size of the Queue: ");
    scanf("%d",&n);
    int cq[n];
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
            v=enqueue(cq,x,n);
            if(v){
                printf("\nADDED!!\n");
            }
            else{
                printf("Try Different Choice!!\n");
            }
            break;

        case 2:
            dequeue(cq,n);
            break;

        case 3:
        if(count>0){
            if(f>=r){
                for(int i=f;i<n;i++){
                    printf("%d ",cq[i]);
                }
                for(int i=0;i<r;i++){
                    printf("%d ",cq[i]);
                }
            }
            else{
                for(int i=f;i<r;i++){
                    printf("%d ",cq[i]);
                }
            }
        }
        else{
            printf("Queue is Empty!\n");
        }
        //'\n';
        break;

        case 4:
            v=count;
            printf("Size: %d\n",v);
            break;

        case 5:
            exit(0);
    }
    goto pick;
return 0;

}
