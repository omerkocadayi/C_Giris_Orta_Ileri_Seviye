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
