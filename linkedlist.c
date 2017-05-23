#include <stdio.h>
#include <stdlib.h>
struct node{
	int value;
	struct node *next;
}*head;
void add_node(int);
void delete_node(int);
void print_list();
int main(){
	int item,choice;
	while(1){
		printf("1 - Addition\n");
		printf("2 - Deletion\n");
		printf("3 - Printing\n");
		printf("4 - Exit\n");
		printf("Enter your Choice : ");
		scanf("%d",&choice);
		switch(choice){
		case 1:
			printf("Enter the item you wanna add : ");
			scanf("%d",&item);
			add_node(item);
			break;
		case 2:
			printf("Enter the item you wanna delete : ");
			scanf("%d",&item);
			delete_node(item);
			break;
		case 3:
			print_list();
			break;
		case 4:
			return 0;
			break;
		default:
			printf("Wrong Choice ! \n");
		}
	}
	return 0;
}
void add_node(int item){
	struct node *newptr,*ptr,*prev;
	newptr=(struct node *)malloc(sizeof(struct node));
	newptr->value=item;
	newptr->next=NULL;
	if(head==NULL)
		head=newptr;
	else{
		if(head->value>item){
			newptr->next=head;
			head=newptr;
			printf("\n%d  - Done Entering !\n\n",head->value);
		}
		else{
			ptr=head;
			prev=head;
			while(ptr!=NULL){
				if(ptr->value<item){
					prev=ptr;
					ptr=ptr->next;
				}
				else
				break;
			}
			prev->next=newptr;
			newptr->next=ptr;
		}
	}
}
void delete_node(int item){
	struct node *ptr,*prev;
	int found=0;
	if(head==NULL)
		printf("\nList is Empty !\n\n");
	else{
		ptr=prev=head;
		if(head->value==item){
			head=head->next;
			found=1;
			printf("\nElement Deleted ! \n\n");
			return;
		} else {
		  while(ptr!=NULL){
			if(ptr->value==item){
				found=1;
				prev->next=ptr->next;
				printf("\nElement Deleted ! \n\n");
				return;
			}
			else{
				prev=ptr;
				ptr=ptr->next;
			}
		  }
		}
	}
	if(found==0)
		printf("\nItem Not Found !!\n\n");
}
void print_list(){
	int count=0;
	struct node *ptr;
	if(head==NULL)
	printf("Nothing in the List !!\n");
	else{
		ptr=head;
		printf("\nThe List contains : \n");
		while(ptr!=NULL){
			if(count==0)
			printf("%d ",ptr->value);
			else
			printf("-> %d ",ptr->value);
			count++;
			ptr=ptr->next;
		}
		printf("\n\n");
	}
}
