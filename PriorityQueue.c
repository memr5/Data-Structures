#include<stdio.h>
#include<stdlib.h>

int f=0,r=0;

struct queue{
    int q[10];
    int f;
    int r;
    int count;
}q1,q2,q3;


int enqueue(struct queue *p,int x,int qsize){
    if((p->count)==qsize){
        printf("Queue is Full!\n");
        return 0;
    }
    else{
        p->q[p->r]=x;
        p->r=((p->r)+1)%qsize;
        (p->count)++;
        return 1;
    }
}

void dequeue(struct queue *p,int qsize,int i){
    /*if((p->count)==0){
        printf("Queue is Empty!\n");
    }*/
        printf("Dequeued element: %d\nFrom: %d queue",p->q[p->f],i);
        p->q[p->f]=0;
        p->f=((p->f)+1)%qsize;
        (p->count)--;

}

int main(){

    q1.f=0;q1.r=0;q1.count=0;q2.f=0;q2.r=0;q2.count=0;q3.f=0;q3.r=0;q3.count=0;

    int c,p;
   pick: printf("\n\nChoices:\n-----------------------\n1.Priority(0-2) of Member you want add to Queue\n2.Delete element\n3.Display Queues\n4.Exit\n-----------------------\nENTER CHOICE: ");
    scanf("%d",&c);
    if(c==1){
        printf("Enter priority: ");
        scanf("%d",&p);

        switch(p){
            case 0:
                printf("Enter value: ");
                scanf("%d",&c);
                c=enqueue(&q1,c,10);
                break;

            case 1:
                printf("Enter value: ");
                scanf("%d",&c);
                c=enqueue(&q2,c,10);
                break;

            case 2:
                printf("Enter value: ");
                scanf("%d",&c);
                c=enqueue(&q3,c,10);
                break;
        }
        if(c){
                    printf("Added!!\n");
                }
                else{
                    printf("Try different Choice!\n");
                }
    }
    else if(c==2){
        if(q1.count!=0){
            dequeue(&q1,10,1);
        }
        else if(q2.count!=0){
            dequeue(&q2,10,2);
        }
        else if(q3.count!=0){
            dequeue(&q3,10,3);
        }
        else{
            printf("All Queues are Empty!\n");
        }
    }
    else if(c==3){
        if(q1.count!=0){
            printf("\nQueue 1: ");
            if(q1.f>=q1.r){
                for(int i=q1.f;i<10;i++){
                    printf("%d ",q1.q[i]);
                }
                for(int i=0;i<q1.r;i++){
                    printf("%d ",q1.q[i]);
                }
            }
            else{
                for(int i=q1.f;i<q1.r;i++){
                    printf("%d ",q1.q[i]);
                }
            }
            '\n';
        }
        if(q2.count!=0){
            printf("\nQueue 2: ");
            if(q2.f>=q2.r){
                for(int i=q2.f;i<10;i++){
                    printf("%d ",q2.q[i]);
                }
                for(int i=0;i<q2.r;i++){
                    printf("%d ",q2.q[i]);
                }
            }
            else{
                for(int i=q2.f;i<q2.r;i++){
                    printf("%d ",q2.q[i]);
                }
            }
        }
        if(q3.count!=0){
            printf("\nQueue 3: ");
            if(q3.f>=q3.r){
                for(int i=q3.f;i<10;i++){
                    printf("%d ",q3.q[i]);
                }
                for(int i=0;i<q3.r;i++){
                    printf("%d ",q3.q[i]);
                }
            }
            else{
                for(int i=q3.f;i<q3.r;i++){
                    printf("%d ",q3.q[i]);
                }
            }
            '\n';
        }
        else{
            printf("All Queues are Empty!\n");
        }
    }
    else{
        exit(0);
    }
    goto pick;
    return 0;
}
