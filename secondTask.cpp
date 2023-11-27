#include "tree.hpp"

int main()
{
    tree::node * root = NULL;
    tree::node ** t = &root;
    std::vector<int> vals = {5, 3, 7, 2, 4, 6, 8};
    tree::insert(t, vals);
    std::cout << "tree: ";
    tree::print(t);
    std::cout << "\nroot: " << (*t)->data << "\n\n";
    for (int i = 0; i < 4; ++i) {
        tree::erase(t, (*t)->data);
        std::cout << "tree (root deleted): ";
        tree::print(t);
        std::cout << "\nnew root: " << (*t)->data << "\n\n";
    }
    return 0;
}