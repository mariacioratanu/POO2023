#include "Tree.h"
#include <iostream>

int main()
{
    //create some TreeNode objects
    TreeNode<int> node1(1);
    TreeNode<int> node2(2);
    TreeNode<int> node3(3);
    TreeNode<int> node4(4);
    TreeNode<int> node5(5);

    //add nodes to the tree
    node1.add_node(&node2);
    node1.add_node(&node3);
    node2.add_node(&node4);
    node2.add_node(&node5);

    //print the number of nodes in the tree
    std::cout<<"Number of nodes: "<<node1.count()<<std::endl;

    //sort the nodes in the tree
    node1.sort();

    // find a node with value 4
    TreeNode<int>* found_node = node1.find([](const int& a, const int& b) { return a == b; }, 4);
    if (found_node)
    {
        std::cout << "Found node with value 4" << std::endl;
    }
    else
    {
        std::cout << "Node with value 4 not found" << std::endl;
    }

    //insert a new node at index 1
    TreeNode<int> new_node(6);
    node1.insert(&new_node, 1);

    //delete a node and its subtree
    node2.delete_node();

    //print the number of nodes in the tree again
    std::cout<<"Number of nodes: "<<node1.count() << std::endl;

    return 0;
}

