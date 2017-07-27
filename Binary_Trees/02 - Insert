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
