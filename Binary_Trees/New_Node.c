BTREE *new_node(int data){
	BTREE *p;
	p = (BTREE *)malloc(sizeof(BTREE));
	p->data = data;
	p->left = NULL;
	p->right = NULL;
	return p;
}
