#ifndef TREE_HPP
#define TREE_HPP
#include <iostream>
#include <vector>

namespace tree {
    struct node {
        node * left;
        node * right;
        int data;
    };

    void insert(node ** tree, int val);

    void insert(node ** tree, const std::vector<int>& vals);

    node * getMax(node ** tree);

    void erase(node ** tree, int val);

    void print(node ** tree, std::ostream& out = std::cout);
}

#endif