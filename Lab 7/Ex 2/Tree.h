#include <cstddef> //for size_t
#include <stdexcept> //for runtime_error
#include <vector> //for vector
#include <algorithm> //for sort
template <typename T> //template class with type parameter T
class TreeNode
{
private:
    T value; //node's value
    TreeNode<T>* parent; //pointer to parent node
    TreeNode<T>* first_child; //pointer to first child node
    TreeNode<T>* next_sibling; //pointer to next sibling node
public:
    //constructors
    TreeNode(T val) : value(val), parent(nullptr), first_child(nullptr), next_sibling(nullptr) {}
    TreeNode(T val, TreeNode<T>* par) : value(val), parent(par), first_child(nullptr), next_sibling(nullptr) {}

    //adds a child node to the current node
    void add_node(TreeNode<T>* node)
    {
        if (node)
        {
            node->parent = this; //set the parent of the child node to the current node
            if (!first_child) //if the current node has no children
            {
                first_child=node; //set the first child node to the new node
            }
            else //if the current node already has children
            {
                TreeNode<T>* sibling = first_child;
                while (sibling->next_sibling) //traverse the siblings until the last one is reached
                {
                    sibling=sibling->next_sibling;
                }
                sibling->next_sibling=node; //add the new node as a sibling to the last child node
            }
        }
    }

    //gets a node given its parent node
    TreeNode<T>& get_node(TreeNode<T>* parent)
    {
        if (!parent) //if parent node is null, return the current node
        {
            return *this;
        }
        else //if parent node is not null
        {
            TreeNode<T>* sibling = parent->first_child;
            while (sibling) //traverse the siblings of the parent node
            {
                if (sibling == this) //if the sibling is the current node
                {
                    return *this; //return the current node
                }
                sibling = sibling->next_sibling;
            }
            throw std::runtime_error("Node not found."); //if the current node is not found in the siblings of the parent node, throw an error
        }
    }

    //deletes the current node
    void delete_node()
    {
        if (parent) //if the current node has a parent
        {
            if (parent->first_child == this) //if the current node is the first child of the parent
            {
                parent->first_child = next_sibling; //set the first child of the parent to the next sibling of the current node
            }
            else //if the current node is not the first child of the parent
            {
                TreeNode<T>* sibling = parent->first_child;
                while (sibling->next_sibling != this) //traverse the siblings until the current node is reached
                {
                    sibling = sibling->next_sibling;
                }
                sibling->next_sibling = next_sibling; //set the next sibling of the previous node to the next sibling of the current node
            }
            parent = nullptr; //set the parent of the current node to null
        }
        delete_subtree(); //delete the subtree rooted at the current node
    }
    //deletes the current node and all of its children recursively
    void delete_subtree()
    {
        //start with the first child of this node
        TreeNode<T>* child = first_child;
        //iterate over all of the node's children
        while (child)
        {
            //save the next sibling node before deleting the child
            TreeNode<T>* next = child->next_sibling;
            //recursively delete the child node and its subtree
            child->delete_subtree();
            //move on to the next child
            child = next;
        }
        //delete the current node after all of its children have been deleted
        delete this;
    }


    //searches the subtree rooted at this node for a node containing the specified value
    //returns a pointer to the first matching node, or nullptr if no match is found
    TreeNode<T>* find(bool (*comp)(const T&, const T&), const T& val)
    {
        //if this node's value matches the search value, return a pointer to this node
        if (comp(value, val))
        {
            return this;
        }
        //otherwise, search this node's children recursively
        TreeNode<T>* child = first_child;
        while (child)
        {
            //recursively search the child node and its subtree for the search value
            TreeNode<T>* result = child->find(comp, val);
            //if a matching node is found, return a pointer to it
            if (result)
            {
                return result;
            }
            //otherwise, move on to the next child
            child = child->next_sibling;
        }
        //if no matching node is found, return nullptr
        return nullptr;
    }

    //inserts a node as a child of this node at the specified position
    void insert(TreeNode<T>* node, size_t index)
    {
        //if the new node pointer is null, do nothing
        if (!node)
        {
            return;
        }
        //if the index is zero, insert the new node at the beginning of the child list
        if (index == 0)
        {
            node->next_sibling = first_child;
            first_child = node;
            node->parent = this;
        }
        else
        {
            //otherwise, find the node currently at the specified index
            TreeNode<T>* child = first_child;
            for (size_t i = 0; i < index - 1 && child; ++i)
            {
                child = child->next_sibling;
            }
            //if no node is found, add the new node to the end of the child list
            if (!child)
            {
                add_node(node);
            }
            else
            {
                //otherwise, insert the new node after the node currently at the specified index
                node->next_sibling = child->next_sibling;
                child->next_sibling = node;
                node->parent = this;
            }
        }
    }
    //sorts the child nodes of this node in ascending order based on their values
    //if a comparison function is provided, it is used instead of the default less-than operator
    void sort(bool (*comp)(const T&, const T&) = nullptr)
    {
        //if the node doesn't have any children, there's nothing to sort
        if (!first_child)
        {
            return;
        }

        //create a vector to hold the children nodes
        std::vector<TreeNode<T>*> children;

        //iterate over the children nodes and add them to the vector
        TreeNode<T>* child = first_child;
        while (child)
        {
            children.push_back(child);
            child = child->next_sibling;
        }

        //sort the children nodes using the given comparison function, if one was provided
        if (comp)
        {
            std::sort(children.begin(), children.end(), [comp](TreeNode<T>* a, TreeNode<T>* b)
            {
                return comp(a->value, b->value);
            });
        }
        //if no comparison function was provided, sort the nodes in ascending order by their value
        else
        {
            std::sort(children.begin(), children.end(), [](TreeNode<T>* a, TreeNode<T>* b)
            {
                return a->value < b->value;
            });
        }

        //set the first child node to be the first element of the sorted vector
        first_child = children[0];

        //link the children nodes together in sorted order
        for(size_t i = 0; i < children.size() - 1; ++i)
        {
            children[i]->next_sibling = children[i + 1];
        }

        //the last child node in the vector has no next sibling
        children.back()->next_sibling = nullptr;
    }

    //returns the number of nodes in the subtree rooted at this node
    size_t count() const
    {
        size_t result = 0;
        //iterate over the children nodes and add their counts to the result
        TreeNode<T>* child = first_child;
        while(child)
        {
            result+=child->count();
            child=child->next_sibling;
        }

        //add 1 to the result for the current node
        return result + 1;
    }
};
