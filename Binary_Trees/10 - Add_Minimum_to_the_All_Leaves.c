//main icerisinde ilk once find_min sonra add fonksiyonunu cagiriyoruz

int find_min(BTREE *root){
	if(root != NULL){
		int min = root->data;
		while(root != NULL){
			if(root->data < min)
				min = root->data;
			root = root->left;
		}
		return min;
	}
	else
		return -1000;
}

BTREE *add(BTREE *root, int min){
	if(root != NULL){
		root->data += min;
		add(root->left, min);
		add(root->right, min);
	}
	return root;
}
