#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

struct node{
	int data;
	struct node* next;
};

struct node* addEdge(struct node* head,int value){

	struct node* nw = (struct node*)malloc(sizeof(struct node));
	nw->data=value;
	nw->next=NULL;

	if(!head){
		head=nw;
		return head;
	}
	struct node* temp = head;
	while(temp->next!=NULL){
		temp=temp->next;
	}
	temp->next=nw;

return head;
}

int main(){
	printf("\nEnter number of Vertices: ");
	int n;
	scanf("%d",&n);
	struct node* head[n+1];
	for(int i=1;i<=n;i++){
		head[i]=NULL;
	}
	printf("\nEnter number of Edges: ");
	int e;
	scanf("%d",&e);
	printf("\nEnter Edges(ex: v1 v2):\n");
	for(int i=0;i<e;i++){
		int x,y;
		scanf("%d %d",&x,&y);
		head[x]=addEdge(head[x],y);
		head[y]=addEdge(head[y],x);
	}
	bool visited[n+1];
	for(int i=1;i<=n;i++){
		visited[i]=false;
	}	
	
	int Q[n+1];
	int f=0,r=0;
	Q[0]=1;
	visited[1]=true;
	r++;
	while(f!=r){
		printf("%d ",Q[f]);
		int v=Q[f];
		++f;
		for(struct node* i=head[v];i!=NULL;i=i->next){
			if(!visited[i->data]){
				visited[i->data]=true;
				Q[r]=i->data;
				++r;
			}
		}	
	}	
	printf("\n");
return 0;
}
