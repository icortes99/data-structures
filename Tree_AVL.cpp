#include "Tree_AVL.h"
#include <iostream>
using namespace std;

void Tree_AVL::makeEmpty(NodeTAVL* t)
{
    if (t == NULL)
        return;
    makeEmpty(t->left);
    makeEmpty(t->right);
    delete t;
}

NodeTAVL* Tree_AVL::insert(Canton* x, NodeTAVL* t)
{
    if (t == NULL)
    {
        t = new NodeTAVL;
        t->canton = x;
        t->height = 0;
        t->left = t->right = NULL;
    }
    else if (x->get_id_canton() < t->canton->get_id_canton())
    {
        t->left = insert(x, t->left);
        if (height(t->left) - height(t->right) == 2)
        {
            if (x->get_id_canton() < t->canton->get_id_canton())
                t = singleRightRotate(t);
            else
                t = doubleRightRotate(t);
        }
    }
    else if (x->get_id_canton() > t->canton->get_id_canton())
    {
        t->right = insert(x, t->right);
        if (height(t->right) - height(t->left) == 2)
        {
            if (x->get_id_canton() > t->right->canton->get_id_canton())
                t = singleLeftRotate(t);
            else
                t = doubleLeftRotate(t);
        }
    }

    t->height = max(height(t->left), height(t->right)) + 1;
    return t;
}

NodeTAVL* Tree_AVL::singleRightRotate(NodeTAVL*& t)
{
    NodeTAVL* u = t->left;
    t->left = u->right;
    u->right = t;
    t->height = max(height(t->left), height(t->right)) + 1;
    u->height = max(height(u->left), t->height) + 1;
    return u;
}

NodeTAVL* Tree_AVL::singleLeftRotate(NodeTAVL*& t)
{
    NodeTAVL* u = t->right;
    t->right = u->left;
    u->left = t;
    t->height = max(height(t->left), height(t->right)) + 1;
    u->height = max(height(t->right), t->height) + 1;
    return u;
}

NodeTAVL* Tree_AVL::doubleLeftRotate(NodeTAVL*& t)
{
    t->right = singleRightRotate(t->right);
    return singleLeftRotate(t);
}

NodeTAVL* Tree_AVL::doubleRightRotate(NodeTAVL*& t)
{
    t->left = singleLeftRotate(t->left);
    return singleRightRotate(t);
}

NodeTAVL* Tree_AVL::findMin(NodeTAVL* t)
{
    if (t == NULL)
        return NULL;
    else if (t->left == NULL)
        return t;
    else
        return findMin(t->left);
}

NodeTAVL* Tree_AVL::findMax(NodeTAVL* t)
{
    if (t == NULL)
        return NULL;
    else if (t->right == NULL)
        return t;
    else
        return findMax(t->right);
}

int Tree_AVL::height(NodeTAVL* t)
{
    return (t == NULL ? -1 : t->height);
}

int Tree_AVL::getBalance(NodeTAVL* t)
{
    if (t == NULL)
        return 0;
    else
        return height(t->left) - height(t->right);
}

void Tree_AVL::inorder(NodeTAVL* t)
{
    if (t == NULL)
        return;
    inorder(t->left);
    cout << t->canton->get_nombre() << " ";
    inorder(t->right);
}

Tree_AVL::Tree_AVL()
{
    root = NULL;
}

void Tree_AVL::agregar(Canton* canton)
{
    root = insert(canton, root);
}

void Tree_AVL::display()
{
    inorder(root);
    cout << endl;
}