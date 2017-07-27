//main icerisinde ilk once find_min sonra add fonksiyonunu cagiriyoruz

int find_min(BTREE *root){
	while(root->left != NULL)
		root = root->left;
	return root->data;
}

BTREE *add(BTREE *root, int min){
	if(root != NULL){
		root->data += min;
		add(root->left, min);
		add(root->right, min);
	}
	return root;
}
