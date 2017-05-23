#include <stdio.h>
#include <stdlib.h>
struct node{
	int value;
	struct node *right;
	struct node *left;
}*head;
int height = 0;
int search = 0;
void add_node(int);
void delete_node(int);
void print_tree(struct node *);
void search_node(int, struct node *);
void height_of_tree(int, struct node *);
int main(){
	int item,choice;
	while(1){
		printf("1 - Addition\n");
		printf("2 - Deletion\n");
		printf("3 - Printing\n");
		printf("4 - Searching\n");
		printf("5 - Height of the tree\n");
		printf("6 - Exit\n");
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
			break;
		case 3:
			printf("Printing all element \n");
			print_tree(head);
			printf("\n");
			break;
		case 4:
			search = 0;
			printf("Enter the item you wanna search : ");
			scanf("%d",&item);
			search_node(item, head);
			if(search)
				printf("Found !\n");
			else
				printf("Not Found !\n");
			break;
		case 5:
			height = 0;
			printf("Height of the Tree : ");
			height_of_tree(1, head);
			printf("%d .\n", height);
			break;
		case 6:
			return 0;
			break;
		default:
			printf("Wrong Choice ! \n");
		}
	}
	return 0;
}
void add_node(int item){
	struct node *newptr,*ptr,*pre;
	newptr=(struct node *)malloc(sizeof(struct node));
	newptr->value = item;
	newptr->left = NULL;
	newptr->right = NULL;
	if(head == NULL){
		head = newptr;
		printf("Done Entering at head %d .\n",item);
	} else {
		pre = head;
		ptr = head;
		while( ptr != NULL ){
			pre = ptr;
			if( ptr->value < item )
				ptr = ptr->right;
			else if( ptr->value >= item )
				ptr = ptr->left;
		}
		if(pre->value < item)
			pre->right = newptr;
		else
			pre->left = newptr;
		printf("Done Entering after %d . \n", pre->value);
	}
}
void print_tree(struct node *ptr){
	if(ptr->left != NULL)
		print_tree(ptr->left);
	printf(" %d ", ptr->value);
	if(ptr->right != NULL)
		print_tree(ptr->right);
}
void search_node(int item, struct node *ptr){
	if(item == ptr->value){
		search = 1;
		return;
	}
	if(ptr->left != NULL && search == 0)
		search_node(item, ptr->left);
	if(ptr->right != NULL && search == 0)
		search_node(item, ptr->right);
}
void height_of_tree(int count, struct node *ptr){
	if(height < count)
		height = count;
	if(ptr->left != NULL)
		height_of_tree(count+1, ptr->left);

	if(ptr->right != NULL)
		height_of_tree(count+1, ptr->right);
}
