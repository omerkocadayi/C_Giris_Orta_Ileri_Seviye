BTREE *delete_node(BTREE *root,int data){
	BTREE *p, *q;
	if(root == NULL)
		return NULL;
	if(root->data == data){						//	CASE 1
		if(root->left == root->right){			//	CASE 1
			free(root);							//	CASE 1
			return NULL;						//	CASE 1
		}
		
		else{
			if(root->left == NULL){				//	CASE 2
				p = root->right;				//	CASE 2
				free(root);						//	CASE 2
				return p;						//	CASE 2
			}
			else if(root->right == NULL){		//	CASE 2
				p = root->left;					//	CASE 2
				free(root);						//	CASE 2
				return p;						//	CASE 2
			}
			else{
				p = q = root->right;
				while(p->left != NULL)
					p = p->left;
				p->left = root->left;
				free(root);
				return q;
			}
		}
	}
	if(root->data < data)
		root->right = delete_node(root->right,data);
	else
		root->left = delete_node(root->left,data);
	
	return root;
}
