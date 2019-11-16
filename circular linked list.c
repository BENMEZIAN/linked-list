/* circular linked list implementation */
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct node{
	int data;
	struct node* next;
}node;
   // les variables globales
   node* head=NULL,*p;       int len,pos,n;   
   // prototypes de fonctions
void append();
void Display();
int length();
void insertAtBeginning();
void insert_end();
void insertpos();
void Delete_beg();
void Delete_end();
void Delete_pos();
int searchpos(int pos);
int occurence(int x);

int main(int argc, char *argv[]){
	
	int choix;

      do{
      	printf("---------Circular Linked List Operations----------\n");
	    printf("1-append.\n");
	    printf("2-display.\n");
	    printf("3-length.\n");
	    printf("4-insert node.\n");
	    printf("5-insert_end node.\n");
	    printf("6-delete node.\n");
	    printf("7-delete_end node.\n");
	    printf("8-search node.\n");
	    printf("9-occurence.\n");
	    printf("10-quitter.\n");
	    printf("\n---------------------------------\n");
	    printf("donner votre choix:");
	   	scanf("%d",&choix);
	   	switch(choix){
	   		case 1:append();
	   		break;
	   		case 2:Display();
	   		break;
	   		case 3:len=length();
	   		       printf("length is:%d\n",len);
	   		break;
	   		case 4:insertpos();
			break;
			case 5:insert_end();
			break;
		    case 6:Delete_pos();
			break;
			case 7:Delete_end();
			break;
			case 8:printf("donner la position ou vous voulez chercher:");
	   		       scanf("%d",&pos);    
			       searchpos(pos);
			break;
			break;
	   		case 9:printf("donner l'entier a rechercher:");
	   		       scanf("%d",&n);    
			       occurence(n);
	   		break;
	   		case 10:exit(1);
	   		break;		   
		   }

	  }while(choix!=10);
	   
	getch();

	return 0;
}

void append(){
	
	node* temp;
	temp=(struct node*)malloc(sizeof(struct node));
	printf("enter node data:");
	scanf("%d",&temp->data);
	temp->next=NULL;
	if(head == NULL){
	 head=temp; 
	 p=temp;                             
	}else{
		p->next=temp;
		p=temp;
		p->next=head;
    } 
}

void Display(){
	
      node *p;
    if(head == NULL)
    {
        printf("List is empty.\n");
    }
    else{
        p = head;
        do{
         printf("%d-->",p->data);
         p = p->next;
        }while(p != head);
        printf("\n");
    }
}

int length(){
	
	node* p;
	 int count=0;
	 p=head;
	 while(p->next!=head){
	 	count++;
	 	p=p->next;
	 }
	 count++;
  return count;
}

void insertAtBeginning(){
	
	node* temp;
	temp=(struct node*)malloc(sizeof(struct node));
	printf("enter node data:");
	scanf("%d",&temp->data);
	temp->next=head;
	p->next=temp;
	head=temp;	
}

void insert_end(){  // insertion à la fin

	node* temp;
	temp=(struct node*)malloc(sizeof(struct node));
	printf("enter node data:");
	scanf("%d",&temp->data);
	p->next=temp;
	temp->next=head;
	p=temp;
}

void insertpos(){
	
	node* temp; 	node* q=head;      int loc;  
	 
	 temp=(struct node*)malloc(sizeof(struct node));
	 printf("enter node data:");
	 scanf("%d",&temp->data);
	 temp->next=NULL;     

	printf("Give me the location:");
	scanf("%d",&loc);
     
	if(loc==1){  // insertion au début 
		insertAtBeginning();
	}else{ // insertion au milieu
		int i=1;
	  while(q!=NULL  &&  i<loc-1){   
	  	q=q->next;
	  	i++;
	  }
	  temp->next=q->next;
	  q->next=temp;
	}	 
}

void Delete_beg(){
	
	node*p=head;
	head=head->next;
	p->next=head;
	free(p);
}

void Delete_end(){
	
	node*p=head; node*q=p->next;
	while(p->next!=head){
		q=p;
		p=p->next;
	}
	p->next=NULL;
	q->next=head;
	free(p);
}

void Delete_pos(){

	int loc;      

	printf("Give me the location:");
	scanf("%d",&loc);

	if(loc==1){
		Delete_beg();
	}else{
		node* q;     int i=1;
		p=head;
		while(i<loc-1){
			p=p->next;
			i++;
		}
		q=p->next;
		p->next=q->next;
		free(q);
	}
}

int searchpos(int pos){
	
	node* p=head; int i=1;
	while(p->next!=head && i<pos){
	  p=p->next;
	  i++;
	}
	printf("la valeur chreche vaut:%d\n",p->data);
}

int occurence(int x){
	
	  node* p=head;    int n=0;
	  while(p->next!=head){
	  	if(p->data==x){
	  		n=n+1;
		  }
		 p=p->next;
	  }
	  if(p->next==head){
	  	if(p->data==x){
	  		n=n+1;
		  }
	  }
	printf("le nombre d'occurence vaut:%d\n",n);
}
