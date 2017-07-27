#include <stdio.h>
#include <stdlib.h>

struct node{
	int data;
	struct node *left;
	struct node *right;
};

typedef struct node BTREE;

BTREE *new_node(int data){
	BTREE *p;
	p = (BTREE *)malloc(sizeof(BTREE));
	p->data = data;
	p->left = NULL;
	p->right = NULL;
	return p;
}

BTREE *insert(BTREE *root, int data){
	if(root != NULL){
		if(data < root->data)
			root->left = insert(root->left,data);
		else
			root->right = insert(root->right,data);
	}
	else
		root = new_node(data);
	return root;
}

BTREE *multi_insert(BTREE *myroot){
	int i;
	printf("Insert a node until you input'-*1'\n");
	printf("\nEnter data : "); scanf("%d",&i);
	while(i != -1){
		myroot = insert(myroot,i);
		printf("\nEnter data : "); scanf("%d",&i);
	}
	inorder(myroot);
	return myroot;
};

int count_leaves(BTREE *root){
	if(root == NULL)
		return 0;
	return 1 + count_leaves(root->left) + count_leaves(root->right);
}

int height(BTREE *root){
	if(root == NULL)
		return -1;
	int l_height, r_height;
	l_height = height(root->left);
	r_height = height(root->right);
	
	if(l_height > r_height)
		return l_height+1;
	else
		return r_height+1;
}

int depth(BTREE *root){
	if(root == NULL)
		return 0;
	int l_depth, r_depth;
	l_depth = depth(root->left);
	r_depth = depth(root->right);
	
	if(l_depth > r_depth)
		return l_depth+1;
	else
		return r_depth+1;	
}

int search(BTREE *root,int key){
	if(root == NULL)
		return -1;
	if(key < root->data)
		return search(root->left,key);
	else if(key > root->data)
		return search(root->right,key);
	else{
		return 1;
	}
	return -1;			
}

BTREE *delete_node(BTREE *root,int data){
	BTREE *p, *q;
	if(root == NULL)
		return NULL;
	if(root->data == data){						//	CASE 1
		if(root->left == root->right){			//	CASE 1
			free(root);							//	CASE 1
			return NULL;						//	CASE 1
		}
		
		else{
			if(root->left == NULL){				//	CASE 2
				p = root->right;				//	CASE 2
				free(root);						//	CASE 2
				return p;						//	CASE 2
			}
			else if(root->right == NULL){		//	CASE 2
				p = root->left;					//	CASE 2
				free(root);						//	CASE 2
				return p;						//	CASE 2
			}
			else{
				p = q = root->right;
				while(p->left != NULL)
					p = p->left;
				p->left = root->left;
				free(root);
				return q;
			}
		}
	}
	if(root->data < data)
		root->right = delete_node(root->right,data);
	else
		root->left = delete_node(root->left,data);
	
	return root;
}

void print_tree(BTREE *head){
	int x;
	printf("1 ==> Preorder print\n");
	printf("2 ==> Inorder print\n");
	printf("3 ==> Postorder print\n");
	printf("\nMake your choice : "); scanf("%d",&x);
	switch(x){
		case 1:
			preorder(head);
			break;
		case 2:
			inorder(head);
			break;
		case 3:
			postorder(head);
			break;
		default:
			printf("Uncorrect entry !");
			break;
	}
}

void preorder(BTREE *head){
	if(head == NULL)
		return;
	printf("\n%d",head->data);
	preorder(head->left);
	preorder(head->right);
}

void inorder(BTREE *head){
	if(head == NULL)
		return;
	inorder(head->left);
	printf("\n%d",head->data);
	inorder(head->right);
}

void postorder(BTREE *head){
	if(head == NULL)
		return;
	postorder(head->left);
	postorder(head->right);
	printf("\n%d",head->data);
}

int main(){
	BTREE *root = NULL;
	int secim, data, key, x;
	
	while(1){
		printf("Press Any Key For Continue !!"); getch();
		system("CLS");
		printf("1 ==> New leaf\n");
		printf("2 ==> Insert leaf\n3 ==> Insert multi leaves (while you enter '-1')\n");
		printf("4 ==> Count leaves\n5 ==> Height of tree\n");
		printf("6 ==> Depth of tree\n7 ==> Traverse\n8 ==> Search leaf in the tree\n");
		printf("9 ==> Delete a leaf\n10==> Exit\n");
		printf("\n\nMake your choice : "); scanf("%d",&secim);
		system("CLS");
		
		switch(secim){
			case 1:
				printf("Enter a data for new node : "); scanf("%d",&data);
				root = new_node(data);
				break;
			case 2:
				printf("Enter a data for insert : "); scanf("%d",&data);
				root = insert(root,data);
				break;
			case 3:
				root = multi_insert(root);
				break;
			case 4:
				printf("There is/are %d nodes in a tree", count_leaves(root));
				break;
			case 5:
				printf("Tree's height : %d", height(root));
				break;
			case 6:
				printf("Tree's depth : %d",depth(root));
				break;
			case 7:
				print_tree(root);
				break;
			case 8:
				printf("Enter a data for search : "); scanf("%d",&key);
				x = search(root,key);
				if(x == 1)
					printf("\nLeaf is found !!\nLeaf's data : %d",root->data);
				else
					printf("\nLeaf is not found !!\n",root->data);					
				break;
			case 9:
				printf("Enter a data for delete : "); scanf("%d",&data);
				root = delete_node(root,data);
				break;		
			case 10:
				printf("EXIT !!");
				return 0;
			default:
				printf("Uncorrect entry !! Try Again !!");
				break;		
		}
	}
}
