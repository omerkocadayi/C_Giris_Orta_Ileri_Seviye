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
