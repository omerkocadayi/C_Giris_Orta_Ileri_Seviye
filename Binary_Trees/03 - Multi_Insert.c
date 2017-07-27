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
}
