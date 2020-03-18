int getCountOfNode(Node *root, int l, int h)
{
  // your code goes here 
  int count = 0;
  if(root==NULL) return 0;
  if(root->data>=l && root->data<=h) count++;
  count+= getCountOfNode(root->left,l,h);
  count+= getCountOfNode(root->right,l,h);
  
  return count;
}