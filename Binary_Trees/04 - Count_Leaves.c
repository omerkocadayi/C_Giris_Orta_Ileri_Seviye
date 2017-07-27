int count_leaves(BTREE *root){
	if(root == NULL)
		return 0;
	return 1 + count_leaves(root->left) + count_leaves(root->right);
}
