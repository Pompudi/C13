#include "ft_btree.h"
#include <stdio.h>
void	btree_apply_prefix(t_btree *root,void(*applyf)(void*))
{
	if (root)
	{
		applyf(root->item);
		btree_apply_prefix(root->left, applyf);
		btree_apply_prefix(root->right, applyf);
	}
}
void sum5(void *i)
{
	printf("%d ", i);
}
int main()
{

	t_btree subsubtree = {NULL, NULL, "3"};
	t_btree subsubtree2 = {NULL, NULL, "4"};
	t_btree subsubtree3 = {NULL, NULL, "6"};
	t_btree subsubtree4 = {NULL, NULL, "7"};
	t_btree subtree = {&subsubtree, &subsubtree2, "2"};
	t_btree subtree2 = {&subsubtree3, &subsubtree4, "5"};
	t_btree tree = {&subtree, &subtree2, "1"};
	btree_apply_prefix(tree, sum5);
}
