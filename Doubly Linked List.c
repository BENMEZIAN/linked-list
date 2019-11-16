/* Doubly Linked List implementation */
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

typedef struct node{
	int data;
	struct node* next;
	struct node* prev;
}node;

// global variables
  node* head=NULL;   int len,pos,n;
  node* tail=NULL;
// prototypes des fonctions
void append();
int length();
void Display();
void insertAtBeginning();
void insertAtEnd();
void insertpos();
void Delete_beg();
void Delete_end();
void Delete_pos();
bool isPalindrome();
int searchpos(int pos);
int occurence(int x);
void reverseList();

int main(int argc, char *argv[]) {
	
	int choix;  

      do{
      	printf("---------doubly Linked List Operations----------\n");
	    printf("1-append.\n");
	    printf("2-length.\n");
	    printf("3-display.\n");
	    printf("4-palindrome.\n");
	    printf("5-insert node.\n");
	    printf("6-insert_end.\n");
	    printf("7-delete node.\n");
	    printf("8-delete_end.\n");
	    printf("9-search node.\n");
	    printf("10-occurence node.\n");
	    printf("11-reverse list.\n");
	    printf("12-quitter.\n");
	    printf("---------------------------------\n");
	    printf("donner votre choix:");
	   	scanf("%d",&choix);
	   	switch(choix){
	   		case 1:append();
	   		break;
	   		case 2:len=length();
	   		 printf("length is:%d\n",len);
	   		break;
	   		case 3:Display();   //                        
	   		break;
	   		case 4:isPalindrome();
	   		break;
	   		case 5:insertpos();
	   		break;
	   		case 6:insertAtEnd();
	   		break;
	   		case 7:Delete_pos();
	   		break;
	   		case 8:Delete_end();
	   		break;
	   		case 9:printf("donner la position pos:");
	   		       scanf("%d",&pos); 
			       searchpos(pos);
			case 10:printf("donner l'entier a rechercher:");
	   		       scanf("%d",&n);    
			       occurence(n);
			break;       
			case 11:reverseList();
	   		break;
	   		case 12:exit(1);
	   		break;	          
		   }

	   	}while(choix!=12);
	   	
	   	getch();
	
	return 0;
}

void append()
{
    node* newnode; 
    newnode =(struct node*)malloc(sizeof(struct node));
    printf("enter node data:");
    scanf("%d",&newnode->data);
	newnode->prev = NULL;
    newnode->next = NULL;
    
    if(head == NULL){
	 	head=newnode;
	 	tail=newnode;
	 }else{
	 	tail->next=newnode;
	 	newnode->prev=tail;
	 	tail=newnode;
	 }
}

int length(){

	 node* p;
	 int count=0;
	 p=head;
	 while(p!=NULL){
	 	count++;
	 	p=p->next;
	 }
	return count;
}

void Display(){

	 node*p;
	 if(p==NULL){
	 	printf("list is empty.\n");
	 }else{
	 	 p=head;
	 	while(p!=NULL){
	 		printf("%d-->",p->data);
	 		p=p->next;
		 }
		 printf("\n");
	 }
}

bool isPalindrome(){
	
    node *p=head,*q=tail;  bool pal=true;
       
    if (tail == NULL){
    	pal=true;
	}
     
    while (p != q) 
    { 
        if (p->data != q->data){
        	pal=false;
		}
         p = p->next; 
         q = q->prev; 
    } 
    
    if(pal==true){
    	printf("the list is palindrome.\n");
	}else{
		printf("the list is not palindrome.\n");
	}
  
}

int searchpos(int pos){
	
	  node* p=head; int i=1;
	  while(p!=NULL && i<pos){
	  	p=p->next;
	  	i++;
	  }
	printf("la valeur chreche vaut:%d\n",p->data);
}

int occurence(int x){
	
	  node* p=head;    int n=0;
	  while(p!=NULL){
	  	if(p->data==x){
	  		n=n+1;
		  }
		 p=p->next;
	  }
	printf("le nombre d'occurence vaut:%d\n",n);
}

void insertAtBeginning(){
         
		node * newnode;
		newnode = (struct node *)malloc(sizeof(struct node));
        printf("enter node data:");
        scanf("%d",&newnode->data);
        newnode->next = head; 
        newnode->prev = NULL; 

        head->prev = newnode;
        head = newnode;
}

void insertAtEnd(){
	
	    node* newnode; node* temp;
     
	    newnode = (struct node *)malloc(sizeof(struct node));
        printf("enter node data:");
        scanf("%d",&newnode->data);
		
		temp=head;
		
		while(temp->next!=NULL){
			temp=temp->next;
		}
		 
        newnode->next = NULL;
        newnode->prev = temp;

        temp->next = newnode;
        tail = newnode;
}

void insertpos(){
	
	node * newnode, *temp;    int loc;
	
	 newnode=(struct node*)malloc(sizeof(struct node));
	 printf("enter node data:");
	 scanf("%d",&newnode->data);
	 newnode->next=NULL;
	 newnode->prev=NULL;     

	printf("Give me the location:");
	scanf("%d",&loc);
	
	if(loc==1){  // insertion au début 
		insertAtBeginning();
	}else{   // insertion au milieu
		temp = head;  int i=1;

        while(i<loc-1 && temp!=NULL){
            temp = temp->next;
            i++;
        }
        
        newnode->next = temp->next;
        newnode->prev = temp;           
        temp->next->prev = newnode;
        temp->next = newnode;
    }
    
}

void Delete_beg(){
	
	node*p=head;
	 
	if(p==tail){
		tail=NULL;
		head=NULL;
		free(p);
	}else{
		head=head->next;
		head->prev=NULL;
		free(p);
	}
	
}

void Delete_end(){
	
	node*p=tail;
	
	if(head==tail){
		tail=NULL;
		head=NULL;
	}else{
		tail->prev->next=NULL;
		tail=tail->prev;
	}
	 free(p);
}

void Delete_pos(){
	
	node* p;   int loc;    

	printf("Give me the location:");
	scanf("%d",&loc);
	
	if(loc>length()){
		printf("Invalid location.\n");
	}else if(loc==1){
		Delete_beg();
	}else{
		p=head;  int i=1; // pourquoi comme ca
		while(i<loc  && p!=NULL){
			p=p->next;
			i++;
		}
	 p->prev->next=p->next;
	 p->next->prev=p->prev;
	 free(p);
	}
	
}

void reverseList(){
	
	node*p=head,*temp;
	
    while(p != NULL){
        temp = p->next;
        p->next = p->prev;
        p->prev = temp;
        p = temp;
    } 
	
	temp = head;
    head = tail;
    tail = temp;
}
