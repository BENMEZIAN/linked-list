#include <stdio.h>
#include <stdlib.h>

typedef struct node{
	int data;
	struct node *next;
}node;


  node *New,*front=NULL,*rear=NULL,*temp;


void enqueue();
void dequeue();
int display();

int main(int argc, char *argv[]) {
	
		int choix;              

      do{
      	printf("---------Single Linked List Operations----------\n");
	    printf("1-enqueue.\n");
	    printf("2-dequeue\n");
	    printf("3-display.\n");
	    printf("4-quitter\n");
	    printf("---------------------------------\n");
	    printf("donner votre choix:");
	   	scanf("%d",&choix);
	   	switch(choix){
	   		case 1:enqueue();
	   		break;
	   		case 2:dequeue();
	   		break;
	   		case 3:display();
	   		break;
	   		case 4: exit(1);
	   		break;
	     }
	}while(choix!=4);
	
	system("pause");
	
	return 0;
}

void enqueue(){
	
	New=(struct node*)malloc(sizeof(struct node));
	scanf("%d",&New->data);
	New->next=NULL;
	
	if(rear==NULL){
		front=New;
		rear=New;	
	} else{
		 rear->next=New;
		 rear=New;	
	}	
	
}

void dequeue(){
	
	if(rear==NULL){
	   printf("queue is empty");
	} else{
		temp=front;
		front=front->next;
		free(temp);
	}	
}

int display(){
	   
	    temp=front;
	  if(front==NULL){
	     printf("queue is empty");
	  } else{
	  	  while(temp!=NULL){
	  	  	 printf("%d-->",temp->data);
	  	  	 temp=temp->next;
			}
	  }
	return temp->data;
}
