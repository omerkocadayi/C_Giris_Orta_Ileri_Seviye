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
