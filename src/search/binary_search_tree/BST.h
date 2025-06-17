
#include <stdio.h>
#include <stdlib.h>


struct BSTNode{
  int val;
  struct BSTNode *l;
  struct BSTNode *r;
};

typedef struct BSTNode BSTNode_t ;



BSTNode_t* newNodeCreate(int value);
BSTNode_t* findMIN(BSTNode_t* root);
BSTNode_t* insertNode(BSTNode_t* node, int value);
BSTNode_t* searchNode(BSTNode_t* root, int target);
BSTNode_t* deleteNode(BSTNode_t* root, int target);

void inOrder(BSTNode_t* root);
void preOrder(BSTNode_t* root);
void postOreder(BSTNode_t* root);
void freeNode(BSTNode_t* root);



inline BSTNode_t* newNodeCreate(int value) 
{
  printf("new node created\n");
  BSTNode_t* temp = 
    (BSTNode_t*)malloc(sizeof(BSTNode_t));
  temp->val = value;
  temp->l = NULL;
  temp->r = NULL;
  return temp;
}

inline BSTNode_t* insertNode(BSTNode_t* node, int value)
{
  if (NULL == node)
  {
    return newNodeCreate(value);
  }
  if (value < node->val) 
  {
    node->l = insertNode(node->l, value);
  }
  else if (value > node->val) 
  {
    node->r = insertNode(node->r, value);
  }
  return node;
}

inline BSTNode_t* searchNode(BSTNode_t* root, int target)
{
  if (NULL == root || root->val == target) 
  {
    return root;
  }

  if (root->val < target)
  {
    return searchNode(root->r, target);
  }
  return searchNode(root->l, target);

}


inline void postOreder(BSTNode_t* root)
{
  if (NULL != root)
  {
    postOreder(root->l);
    postOreder(root->r);
    printf(" %d ", root->val );
  }
}


inline void inOrder(BSTNode_t* root) 
{
  if (NULL != root)
  {
    inOrder(root->l);
    printf(" %d ", root->val);
    inOrder(root->r);
  }
  
}


inline void preOrder(BSTNode_t* root)
{
  if (NULL != root)
  {
    printf(" %d ", root->val);
    preOrder(root->l);
    preOrder(root->r);
  }
}

inline BSTNode_t* findMIN(BSTNode_t* root) 
{
  if (NULL == root) 
  {
    return root;
  }
  else if (NULL != root->l)
  {
    return findMIN(root->l);
  }
  return root;
}



inline BSTNode_t* deleteNode(BSTNode_t* root, int target)
{
  
  if (NULL == root)
  {
    return NULL;
  }
  // if our taget is on the right side of the tree
  if (target > root->val)
  {
    root->r = deleteNode(root->r, target);
  }
  // if our taget is on the left side of the tree
  else if (target < root->val)
  {
    root->l = deleteNode(root->l, target);
  } 
  // we found our target
  else {
    // if our target is in the bottom of the tree
    if (NULL == root->l && NULL  == root->r)
    {
      free(root);
      return NULL;
    } 
    // if our target has another node linked
    else if (NULL == root->l || NULL == root->r)
    {
      BSTNode_t* tempo;
      // our target has a node in the right side
      if (NULL == root->l)
      {
        tempo = root->r;
      }
      // our target has a node in the left side
      else {
        tempo = root->l;
      }
      free(root);
      return tempo;

    }
    // our target has both node linked
    else {
      BSTNode_t* tempo = findMIN(root->r);
      root->val = tempo->val;
      root->r = deleteNode(root->r, tempo->val);
    }
  }
  return root;
}

inline void freeNode(BSTNode_t* root) 
{
  if (NULL == root) {
    return ;
  };

  if (NULL!= root->l)
  {
    freeNode(root->l);
  };

  if (NULL != root->r) 
  {
    freeNode(root->r);
  };

  printf("node->%d free\n", root->val);
  free(root);

}
