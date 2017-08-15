int height(BTREE *root){
	if(root == NULL)
		return -1;
	int l_height=0, r_height=0;
	l_height = height(root->left);
	r_height = height(root->right);
	
	if(l_height > r_height)
		return l_height+1;
	else
		return r_height+1;
}
