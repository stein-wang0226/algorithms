class Solution {
public:

	bool isSametree(struct TreeNode* s, struct TreeNode* t)
	{
		if (s == NULL && t == NULL) return true;
		return  s && t 
		&& s->val == t->val 
		&& isSametree(s->left, t->left) 
		&& isSametree(s->right, t->right);
	}

	bool isSubtree(struct TreeNode* s, struct TreeNode* t) {
		if (s == NULL && t == NULL) return true;
		if (s == NULL && t != NULL) return false;
		return isSametree(s, t)
		|| isSubtree(s->left, t)
		|| isSubtree(s->right, t);
	}
};