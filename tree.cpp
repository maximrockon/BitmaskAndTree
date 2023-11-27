#include "tree.hpp"

namespace tree {
    void insert(node ** tree, int val)
    {
        node *temp = NULL;
        if(!(*tree)) {
            temp = (node *)malloc(sizeof(node));
            temp->left = temp->right = NULL;
            temp->data = val;
            *tree = temp;
            return;
        }
        if(val < (*tree)->data) {
            insert(&(*tree)->left, val);
        } else if(val > (*tree)->data) {
            insert(&(*tree)->right, val);
        }
    }

    void insert(node ** tree, const std::vector<int>& vals) {
        for (int val : vals) {
            insert(tree, val);
        }
    }

    node * getMax(node ** tree) {
        node * max = *tree;
        while (max->right) {
            max = max->right;
        }
        return max;
    }

    void erase(node ** tree, int val) {
        if (!(*tree)) {
            return;
        }
        if (val < (*tree)->data) {
            erase(&(*tree)->left, val);
        } else if (val > (*tree)->data) {
            erase(&(*tree)->right, val);
        } else {
            if (!(*tree)->left) {
                node *temp = (*tree)->right;
                free(*tree);
                *tree = temp;
            } else if (!(*tree)->right) {
                node *temp = (*tree)->left;
                free(*tree);
                *tree = temp;
            } else {
                node *leftMAx = getMax(&(*tree)->left);
                (*tree)->data = leftMAx->data;
                erase(&(*tree)->left, leftMAx->data);
            }
        }
    }

    void print(node ** tree, std::ostream& out) {
        if (*tree) {
            print(&(*tree)->left, out);
            out << (*tree)->data << ' ';
            print(&(*tree)->right, out);
        }
    }
}