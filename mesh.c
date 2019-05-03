#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <malloc.h>


struct Node 
{ 
	//char data[10]; 
	int data;
	struct Node *next; 
	struct Node *prev;
	struct Node *up;
	struct Node *down;
	 
}; 

struct Node * first=NULL,*last=NULL,*cur=NULL;

struct Node * new_node()
{
	//char elem[10];
	int elem;
	struct Node *p;
	p=malloc(sizeof(struct Node));
	printf("enter element\n");
	scanf("%d",&elem);
  //strcpy(p->data,elem);
        p->data=elem;
	p->next=NULL;
	p->prev=NULL;
	p->up=NULL;
	p->down=NULL;
	return p;
}


void insert_front() 
{ 
	struct Node *p; 

	p=new_node();
	
	if(first==NULL)
	{
		first=p;
		last=p;
		cur=p;
	}
	else if(first->next==NULL)
    {
		p->next=first;
		first->prev=p;
		last=p->next;
		first=p;
		cur=p;
	}
	else
	{
		p->next=first;
		first->prev=p;
		first=p;
		cur=p;
	
	}
}

void insert_rear() 
{ 
	struct Node *p; 
    
	p=new_node();
	
	if(first==NULL)
	{
		first=p;
		last=p;
		cur=p;
	}
	else
	{
		last->next=p;
		p->prev=last;
		last=last->next;
		cur=p;
	}
}

void insert_above() 
{
	struct Node *p; 
    
	p=new_node();
	
	if(first==NULL)
	{
		first=p;
		last=p;
		cur=p;
	}
	else
	{
		if(cur->up!=NULL)
		   printf("insert is not possible node is already exist in above\n");
		else
		   p->down=cur;
		   cur->up=p;
		   cur=p;
	} 
	
}
void insert_below() 
{
	struct Node *p; 
    
	p=new_node();
	
	if(first==NULL)
	{
		first=p;
		last=p;
		cur=p;
	}
	else
	{
		if(cur->down!=NULL)
		 printf("insert is not possible node is already exist in below\n");
		else
		p->up=cur;
		cur->down=p;
		cur=p;
	}
	
}

void move_front()
{
	if(cur->next!=NULL)
	{
		cur=cur->next;
		printf("current moved to %d element\t",cur->data);
	}
	else
	printf("move not possible next node not exits\n");
	
}

void move_back()
{
	if(cur->prev!=NULL)
	{
		cur=cur->prev;
		printf("current moved to %d element\t",cur->data);
	}
	else
	printf("move not possible previous node not exits\n");
	
}

void move_up()
{
	if(cur->up!=NULL)
	{
		cur=cur->up;
		printf("current moved to %d element\t",cur->data);
	}
	else
	printf("move not possible  node  does not exits in the above\n");
	
}
void move_down()
{
	if(cur->down!=NULL)
	{
		cur=cur->down;
		printf("current moved to %d element\t",cur->data);
	}
	else
	printf("move not possible  node  does not exits in the below\n");
	
}

void set_value()
{
	int elem;
	printf("enter element\n");
	scanf("%d",&elem);
	cur->data=elem;
	printf("value set successfully\n");
}

void get_value()
{	
	printf("value of current node is %d\t",cur->data);
}


void flattenList() 
{ 
	
	if (first== NULL) 
	printf("list is emplty\n");

	struct Node *tmp; 
	struct Node *tail = first; 
	while (tail->next!= NULL) 
		tail = tail->next; 

	
	struct Node *current = first; 
	while (current != tail) 
	{ 
		if (current->down) 
		{ 
			tail->next = current->down; 
			current->down->prev=tail;
			tmp = current->down; 
			while (tmp->next) 
				tmp = tmp->next; 
			tail = tmp; 
		} 

		current = current->next; 
	} 
} 

void display()
{ 
	struct Node *temp=first;
	while (temp != NULL) { 
		
		printf("%d\t", temp->data); 
		temp= temp->next; 
	} 
	printf("\n"); 
} 

 void inorder(struct Node *temp)
{
	
	if(temp!=NULL)
	{
		printf("%d\t",temp->data);
		inorder(temp->next);
		inorder(temp->down);
		//inorder(temp->up);
	}
		
}
/*void remove_node()
{
	struct Node *temp=first,*t;
	int elem;
	printf("enter element to be remove\n");
	scanf("%d",&elem);
	while (temp != NULL) { 
		if(temp->data==elem)
		{
			t=temp->prev;
			t->next=temp->next;
			free(temp);
		
		}
		else
		temp=temp->next;
	}
	//if(temp==NULL)
	//printf("element is not exist\n");
		
} */

struct Node * findnode()
{
	 char path[10];
	 char* p;
	 struct Node *temp=first;
	 printf("enter path \n");
	 scanf("%s",path);
	 p = strtok (path,",");
     while (p!= NULL)
    {
       printf ("%s\n",p);
       if(*p=='R')
       {
		   if(temp->next)
		   temp=temp->next; 
		   else
		   printf("node not exits in right of %d\t",temp->data);
	   }
      else if(*p=='L')
       {
		   if(temp->prev)
		   temp=temp->prev; 
		   else
		   printf("node not exits in lift of %d\t",temp->data);
	   }
       else if(*p=='U')
       {
		   if(temp->up)
		   temp=temp->up; 
		   else
		   printf("node not exits above the %d\t",temp->data);
	   }
       else if(*p=='D')
       {
		   if(temp->down)
		   temp=temp->down;
		   else
		   printf("node not exits in below the %d\t",temp->data); 
	   }
       
       p = strtok (NULL, ",");
    }
    printf("node value is %d\n",temp->data);
    return temp;
}


void remove_node()
{
	struct Node* temp=NULL;
	temp=findnode();
	
    if(temp->next)
	{
	  temp->next->prev=NULL;
	  temp->next=NULL;
     }
    if(temp->prev)
	{
	  temp->prev->next=NULL;
	  temp->prev=NULL;
    }
    if(temp->up)
	{
	  temp->up->down=NULL;
	  temp->up=NULL;
    }
    if(temp->down)
	{
	  temp->down->up=NULL;
	  temp->down=NULL;
    }
    printf("%d element is removed from the list\n",temp->data);
}
void connect_nodes(struct Node *node1,struct Node *node2)
{
	
	 char ch[10];
	 printf("which link to be connect to the node2 from node1\n");
	 scanf("%s",ch);
	
	 if (strcmp("R",ch) == 0)
	 {
		 node1->next=node2;
		 node2->prev=node1;
	 }
	// else if(ch=='U')
	else if (strcmp("U",ch) == 0)
	 {
		 node1->up=node2;
		 node2->down=node1;
	 }
	// else if(ch=='L')
	else if (strcmp("L",ch) == 0)
	 {
		 node1->prev=node2;
		 node2->next=node1;
	 }
	// else if(ch=='D')
	 else if (strcmp("D",ch) == 0)
	 {
		 node1->down=node2;
		 node2->up=node1;
	 }
	 else
	 printf("invalid link\n");
	 
	 printf("two nodes connected successfully\n");
}


void link()
{
	 struct Node *node1=NULL,*node2=NULL;
	 node1=findnode();
	 node2=findnode();
	 connect_nodes(node1,node2); 
}




int main()
{
	int choice;
	char ans = 'Y';
    struct Node *temp;  
    while (ans == 'Y'||ans == 'y')
	{
		printf("1:insert-front\n2:insert_rear\n3:insert_above\n4:insert_below\n5:move_front\n6:move_back\n7:move_up\n8:move_down\n9:set value to current node\n10:fetch value from current node\n11:flattenList\n12:display list\n13:remove_node\n14:connect two nodes\n15:search node\n");
		printf("enter choice\n");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1:insert_front();
			        break; 
			        
			case 2:insert_rear();
			        break;
			        
			case 3:insert_above();
			       break;
			       
			case 4:insert_below();
			       break;
			       
		        case 5:move_front();
			       break;
			       
			case 6:move_back();
			       break;
			       
			case 7:move_up();
			        break;  
			        
			case 8:move_down();
			        break;  
			        
			case 9:set_value();
			        break;  
			        
		        case 10:get_value();
			        break;  
			        
			case 11:flattenList(); 
			         break;
			case 12://display();
			        temp=first;
			        inorder(temp);
			         break;
			//case 13: display();
		          	//break;
		        case 13:remove_node();
		                 break;
		        case 14:link();
		                break;
		        case 15:findnode();
		                break;
			default:exit(0);
			         break;
		}
		 printf("\nYOU WANT TO CONTINUE (Y/N)\n");
         scanf(" %c", &ans);
	}
}
	


