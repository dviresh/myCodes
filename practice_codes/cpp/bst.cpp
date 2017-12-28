#include<iostream>
#include<string>
#include<bits/stdc++.h>

using namespace std;

struct Node
{
  int data;
  struct Node *right;
  struct Node *left;
  struct Node *prev;
};

struct Node *root;
struct Node *pivot1;
struct Node *pivot2;

struct Node *
createNode (int n)
{
  struct Node *leaf = new struct Node ();
  leaf->data = n;
  leaf->left = NULL;
  leaf->right = NULL;
  leaf->prev = NULL;

  return leaf;
}

void
createTree (int n, int index)
{
  if (index == 0)
    {
      struct Node *node = createNode (n);
      root = node;
      pivot1 = node;
    }
  else
    {
      struct Node *node = createNode (n);
      pivot2 = node;
      while (1)
	{
	  if (pivot1->data > pivot2->data)
	    {
	      if (pivot1->left != NULL)
		{
		  pivot1 = pivot1->left;
		}
	      else
		{
		  pivot1->left = pivot2;
		  pivot2->prev = pivot1;
		  break;
		}
	    }
	  else
	    {
	      if (pivot1->right != NULL)
		{
		  pivot1 = pivot1->right;
		}
	      else
		{
		  pivot1->right = pivot2;
		  pivot2->prev = pivot1;
		  break;
		}
	    }
	}
      pivot1 = root;
    }

}

void
printTree ()
{
  struct Node *prevNode;
  struct Node *currNode;
  pivot1 = root;
  cout << "printing the tree - left - right - root" << endl;
  int flag;
  flag = 1;
  while (flag == 1)
    {
      if (root->left != NULL || root->right != NULL)
	{
	  if (pivot1->left != NULL)
	    {
	      pivot1 = pivot1->left;
	    }
	  else
	    {
	      if (pivot1->right == NULL)
		{
		  cout << pivot1->data << endl;
		  currNode = pivot1;
		  prevNode = pivot1->prev;
		  pivot1->prev = NULL;
		  pivot1 = prevNode;
		  if (pivot1->left == currNode)
		    {
		      pivot1->left = NULL;
		    }
		  else
		    {
		      pivot1->right = NULL;
		    }
		}
	      else
		{
		  pivot1 = pivot1->right;
		}

	    }
	}
      else
	{
	  cout << root->data << endl;
	  flag = 0;
	}
    }
}

void
searchTree (int element)
{
  pivot1 = root;
  int flag = 1;
  while (flag == 1)
    {
      if (pivot1->left == NULL && pivot1->right == NULL
	  && pivot1->data != element)
	{
	  cout << "Sorry - Element not found;" << endl;
	  flag = 0;
	}
      else if (element == pivot1->data)
	{
	  cout << "element found!" << endl;
	  flag = 0;
	}
      else
	{
	  if (element > pivot1->data)
	    {

	      pivot1 = pivot1->right;
	    }
	  else
	    {
	      pivot1 = pivot1->left;
	    }
	}

    }

}




int
main ()
{
  string s, out;
  int x, i = 0, arrlen = 0;
  stringstream ss;
  cout << "Enter the elements for the tree " << endl;

// Dynamic array creation && exit the cin loop on enter key

  string line;
  int *arr = new int (sizeof (int));

  getline (cin, s);
  ss << s;
  while (ss >> out)
    {
      stringstream convert (out);
      convert >> x;
      arr[i] = x;
      i++;
      arrlen++;
    }
  int element;
  cout << "enter the element to search" << endl;
  cin >> element;
// tree creation
  //int j = 0;
  for (int j = 0; j < arrlen; j++)
    {
      createTree (arr[j], j);
    }
  printTree ();
  for (int j = 0; j < arrlen; j++)
    {
      createTree (arr[j], j);
    }
  searchTree (element);
  return 0;

}
