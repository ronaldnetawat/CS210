#ifndef TREE_H
#define TREE_H

#include "treenode.h"
#include <iostream>
#include <vector>

using namespace std;

// Definition of a Binary Search Tree class
template <typename T>
class Tree{
public:
    // default constructor, sets the root to NULL
    Tree();
    // copy constructor, deep copies the other tree
    Tree(const Tree& other);

    // destructor, recursively destroys all nodes
    ~Tree();

    // Insert item x into the correct position in the tree
    void Insert(const T& x);

    // deletes (a copy of) item x from the tree.  Returns true if it's found,
    // False otherwise
    bool Delete(const T& x);

    // Determines whether item x is in the tree.  Returns true if found, false
    // otherwise
    bool Find(const T& x) const;

    // Outputs the nodes of the tree in order (Left subtree, then the node, then
    // the right subtree)
    void Print_Inorder() const;

    //Outputs the nodes of the tree in Preorder (Node, Left Subtree, and Right Subtree)
    void Print_Preorder() const;

    //Outputs the nodes of the tree in Postorder (Left Subtree, Right Subtree, Node)
    void Print_Postorder() const;

    // sets the tree up with a predefined set of nodes
    void Setup();

    // Returns the height of the tree (the number of nodes along the
    // longest path from root to a leaf). The height of an empty tree is
    // 0, the height of a one-element tree is 1. O(N)
    int Height() const;

    // Sends the elements of the tree, in search tree order, into v.
    // We have no assumptions about v’s initial size.
    // When this function completes, v will hold all of the elements of
    // the tree, in sorted order. O(N)
    void Dump_To_Vector(vector<T>& v) const;

    // Prints all of the nodes at depth d (the root is depth 1)
    // Nodes are printed left to right
    // If d is <= 0 or > the tree’s height, prints nothing.
    // O(N) (really, O(# of nodes at depth d or less))
    void Print_Nodes_At_Depth(int d) const;

    // Prints all nodes at depth 1, then all nodes at depth 2, and so on
    // O(N2)
    void Print_Nodes_By_Depth() const;

    // Returns a path of ‘L’ and ‘R’ characters to reach item “x” in the
    // tree. If “x” doesn’t exist, returns the empty string. O(H)
    string Path_To_Item(const T& x) const;

    // Returns the item at the end of a path of ‘L’ or ‘R’ characters in
    // the reference parameter “x”.
    // If there is a node at the end of that path, returns true.
    // If there isn’t, returns false.
    // O(H) (really O(path.size())
    bool Follow_Path(const string& path) const;



private:
    TreeNode<T>* root;

    // here is where we'll put the private helper functions for all of the
    // elements of the tree

    // Creates a new set of nodes that is a deep copy of the tree rooted at
    // "source".  Returns a pointer to the root of the copy
    TreeNode<T>* Copy_Tree(TreeNode<T>* source);

    // recursively deletes all nodes in the subtree pointed at by "source"
    // This includes the source node itself.
    void Delete_Tree(TreeNode<T>* source);

    // Prints the nodes of the tree in LNR order starting wth "source"
    void Print_Inorder_Helper(TreeNode<T>* source) const;

    // Prints the nodes of the tree in LNR order starting wth "source"
    void Print_Preorder_Helper(TreeNode<T>* source) const;

    // Prints the nodes of the tree in LNR order starting wth "source"
    void Print_Postorder_Helper(TreeNode<T>* source) const;


    // Recursively finds x in the subtree rooted at "source".  Returns true if it's there,
    // false otherwise
    bool Find_Helper(TreeNode<T>* source, const T& x) const;

    // Deletes node "kill" with parent "parent" from the tree
    void Delete_Node(TreeNode<T>* parent, TreeNode<T>* kill);

    // Returns the parent of the position we'll delete x.  Returns NULL if no node with x exists
    TreeNode<T>* Find_Delete_Position(TreeNode<T>* cur, const T& x) const;

    // Finds the position x will be inserted into the search tree.  Returns the parent of that position
    TreeNode<T>* Find_Insert_Position(TreeNode<T>* p, const T& x) const;

    TreeNode<T>* Find_Successor_Parent(TreeNode<T>* source) const;

    //Helper functions for the new members added:
    int Height_Helper(TreeNode<T>* node) const;
    void Dump_To_Vector_Helper(TreeNode<T>* node, vector<T>& v) const;
    void Print_Nodes_At_Depth_Helper(TreeNode<T>* node, int d) const;
    string Path_To_Item_Helper(TreeNode<T>* node, const T& x, string path) const;
    bool Follow_Path_Helper(TreeNode<T>* node, string path) const;
};


// default constructor, sets the root to NULL.
// Note that "root== NULL" will be frequently be used to see if a tree is empty
// So we should make sure our other functions (especially Delete) maintain
// this propoerty
template <typename T>
Tree<T>::Tree(){
    root = NULL;
}

// copy constructor, calls a deep copy helper function
template <typename T>
Tree<T>::Tree(const Tree<T>& other){
    if(other.root == NULL) // are they empty?
        root = NULL;
    else{
        root = new TreeNode<T>;
        root->set_item(other.root->get_item());
        root->set_left(Copy_Tree(other.root->get_left()));
        root->set_right(Copy_Tree(other.root->get_right()));
    }
}

// Destructor, recursively destroys nodes in both subtrees
template <typename T>
Tree<T>::~Tree(){
    if(root != NULL){ // don't delete an empty tree
        Delete_Tree(root->get_left());
        root->set_left(NULL);
        Delete_Tree(root->get_right());
        root->set_right(NULL);
        delete root;
        root = NULL;
    }
}


// Inerrt: Inserts x into the tree at the position requested.  Keeps the nodes
// in a tree with the binary search tree property
template <typename T>
void Tree<T>::Insert(const T& x){
    if(root == NULL){ // create a new root
        root = new TreeNode<T>;
        root->set_item(x);
        root->set_left(NULL);
        root->set_right(NULL);
    }
    else{
        TreeNode<T>* parent = Find_Insert_Position(root, x);
        TreeNode<T>* new_guy = new TreeNode<T>;

        // set new_guy's item
        // attach new_guy to the tree
    }
}


// Deletes a node from the tree with value x.  Returns true if successful.
// If no item was found, returns false.
template <typename T>
bool Tree<T>::Delete(const T& x){
    // case 1: Deleting from an empty tree
    if(root == NULL)
        return false;

    // case 2: Deleting the root
    if(root->get_item() == x){
        // Case 2a: Deleting the root when it's the only node in the tree
        if(root->get_left() == NULL && root->get_right() == NULL){
            delete root;
            root = NULL;
            return true;
        }
            // case 2b: Deleting the root when it has one child
        else{
            if(root->get_left() == NULL || root->get_right() == NULL){
                if(root->get_left() != NULL){
                    TreeNode<T>* kill = root;
                    root=root->get_left();
                    kill->set_left(NULL);
                    delete kill;
                }
                else{
                    TreeNode<T>* kill = root;
                    root = root->get_right();
                    kill->set_right(NULL);
                    delete kill;
                }
            }
            else{
                // case 2c, where the root will have 2 children, can be handled like any other "the node we're deleting has 2 children" case

                // task 1: setup a pointer to the parent of the successor node (leftmost
                // node in right subtree
                TreeNode<T>* rkp = Find_Successor_Parent(root);
                TreeNode<T>* real_kill = rkp->get_left();

                // Task 1a: Worry about the case where the right subtree has no left node
                if(rkp == root){
                    real_kill = root->get_right();
                    rkp = root;
                }
                // task 2: swap the values in kill and the successor node.

                root->set_item(real_kill->get_item());

                // task 3: kill the successor node
                Delete_Node(rkp, real_kill);
            } // end case 2c
        } // end "not case 2a" else
    } // end case 2

    // just in case..
    if(!Find(x))
        return false;

    // Next, find the node to delete (actually, it's parent)
    TreeNode<T>* parent = Find_Delete_Position(root, x);
    // get a pointer to the node we're actually deleting
    TreeNode<T>* kill;

    if(parent->get_item() >= x){
        kill = parent->get_left();

    }
    else{
        kill = parent->get_right();

    }

    Delete_Node(parent, kill);
    return true;
}

//Height()
template <typename T>
int Tree<T>::Height() const {
    return Height_Helper(root);
    cout << endl;
}
//Height's helper function to apply recursion
template <typename T>
int Tree<T>::Height_Helper(TreeNode<T>* node) const {
    if (node == NULL) //if tree is empty, the height is 0
        return 0;
    else
    {
        //Recursively find the height of the left and right subtrees
        int left_height = Height_Helper(node->get_left());
        int right_height = Height_Helper(node->get_right());
        //If the right subtree's height is greater than the left, return its height.
        //Otherwise, return left's height.
        if(right_height > left_height)
            return right_height;
        else
        {
            return left_height;
        }
    }
}

//Dump_To_Vector
template <typename T>
void Tree<T>::Dump_To_Vector(vector<T> &v) const {
    Dump_To_Vector_Helper(root, v);
}
//Dump_To_Vector's helper function
//Extracts and stores the items in a vector
template <typename T>
void Tree<T>::Dump_To_Vector_Helper(TreeNode<T> *node, vector<T> &v) const {
    //Base case to check if the node (root) is NULL
    if(node == NULL)
        cout << "The tree is empty!";
    else if(node != NULL)
    {
        //this step recursively stores values in the vector
        //First the left subtree
        Dump_To_Vector_Helper(node->get_left(), v);
        //Then the middle
        v.push_back(node->get_item());
        //Then the right subtree
        Dump_To_Vector_Helper(node->get_right());
    }
}

//Print_Nodes_By_Depth
template <typename T>
void Tree<T>::Print_Nodes_By_Depth() const {
    int h, d;
    h = Height();
    d = 1;
    if(root == NULL)
        cout << "Empty Tree!";
    else
        for(int i = h; i > 0; i--)
        {
            cout << "Depth: " << d << ", Elements: " << Print_Nodes_At_Depth(d);
            d++;
        }
}


//Print_Nodes_At_Depth
template <typename T>
void Tree<T>::Print_Nodes_At_Depth(int d) const {
    Print_Nodes_At_Depth_Helper(root, d-1);
    cout << endl;
}

template <typename T>
void Tree<T>::Print_Nodes_At_Depth_Helper(TreeNode<T> *node, int d) const {
    if (node == NULL) //base case when tree is empty
        cout << "Empty Tree!";
    else if(d != 0) //not reached the depth, first go down the left and then right subtrees
    {
        //Call the helper function recursively for both sides
        //depth is two less than d to go down and reach the correct depth
        Print_Nodes_At_Depth_Helper(node->get_left(), d-1);
        Print_Nodes_At_Depth_Helper(node->get_right(), d-1);
    }
    else // d = 0, it's the correct depth
    {
        cout << node->get_item() << " ";
    }
}


//Path_To_Item
template <typename T>
string Tree<T>::Path_To_Item(const T &x) const {
    string path;
    Path_To_Item_Helper(root, x, path);
    return path;
}

template <typename T>
string Tree<T>::Path_To_Item_Helper(TreeNode<T> *node, const T &x, string path) const {
    string left = "L";
    string right = "R";
    if(node == NULL)
    {
        path = "No path, sorry.";
        return path;
    }
    else if(node->get_item()==x)
    {
        path = "The item is at the root.";
        return path;
    }
    else if(node->get_item() > x) //if root is bigger than x, go left
    {
        path = path + left;
        return Path_To_Item_Helper(node->get_left(), x, path);
    }
    else //if root is smaller, go right, and follow recursion as:
    {
        path = path + right;
        return Path_To_Item_Helper(node->get_right(), x, path);
    }

}

//Follow_Path
template <typename T>
bool Tree<T>::Follow_Path(const string &path) const {
    return Follow_Path_Helper(root, path);
}

template <typename T>
bool Tree<T>::Follow_Path_Helper(TreeNode<T> *node, string path) const {
    if(node == NULL)
        return false;
    else
    {
        for(int i = 0; i < path.length(); i++)
        {
            if(path[i] == 'L')
            {
                node = node->get_left();
                i++;
            }
            else if(path[i] == 'R')
            {
                node = node->get_right();
                i++;
            }
        }
        if(node == NULL)
        {
            return false;
        }
        else
            return true;
    }
}



// Find: finds a node with item x in the tree.  returns true if it exists,
// returns false otherwise
template <typename T>
bool Tree<T>::Find(const T& x) const{
    return Find_Helper(root, x);
}


// Print-Inorder: Prints the items in the search tree in search tree order
template <typename T>
void Tree<T>::Print_Inorder() const{
    return Print_Inorder_Helper(root);
    cout << endl;
}



// Print_Inorder_Helper: Prints an LNR traversal starting at "source"
template <typename T>
void Tree<T>::Print_Inorder_Helper(TreeNode<T>* source) const{
    if(source != NULL){
        Print_Inorder_Helper(source->get_left());
        cout << source->get_item() << " ";
        Print_Inorder_Helper(source->get_right());
    }
}

template <typename T>
void Tree<T>::Print_Preorder() const {
    return Print_Preorder_Helper();
    cout << endl;
}

template <typename T>
void Tree<T>::Print_Preorder_Helper(TreeNode<T>* source) const{
    if(source != NULL){
        cout << source->get_item() << " ";
        Print_Preorder_Helper(source->get_left());
        Print_Preorder_Helper(source->get_right());
    }
}

template <typename T>
void Tree<T>::Print_Postorder() const {
    return Print_Postorder_Helper();
    cout << endl;
}

template <typename T>
void Tree<T>::Print_Postorder_Helper(TreeNode<T> *source) const{
    if(source != NULL){
        Print_Postorder_Helper(source->get_left());
        Print_Postorder_Helper(source->get_right());
        cout << source->get_item();
    }
}





// Find_Helper: The pointer version of "find", passing the current node
// as a parameter
template <typename T>
bool Tree<T>::Find_Helper(TreeNode<T>* source, const T& x) const{
    if(source == NULL) //empty tree
     return false;
    else if (source->get_item() == x)
        return true;
    else if (source->get_item() > x)
        return Find_Helper(source->get_left(), x); //recursively called until found at left
    else
        return Find_Helper(source->get_right(), x); //recursively called until found at right
}


// deletes the node "kill" with parent "parent".
// I made it its own function to isolate the 3 cases
template <typename T>
void Tree<T>::Delete_Node(TreeNode<T>* parent, TreeNode<T>* kill){

    // is the node we're trying to kill a left or right child?
    bool is_left;
    if(parent->get_left() == kill)
        is_left = true;
    else
        is_left = false;

    // case 1: kill is a leaf.
    if(kill->get_left() == NULL && kill->get_right() == NULL){
        if(is_left)
            parent->set_left(NULL);
        else
            parent->set_right(NULL);
        delete kill;
    }
        // case 2:  kill has one child.
    else if(kill->get_left() == NULL || kill->get_right() == NULL){
        // lots of cases here.
        if(is_left){
            // kill is a left child
            if(kill->get_left() != NULL){
                // and has a left child
                cout << "This case is not complete yet" << endl;
            }
            else{ // kill is a left child but its child is a right child
                cout << "This case is not complete yet" << endl;

            }
        }
        else{
            // kill is a right child
            if(kill->get_left() != NULL){
                // kill's one child is a left child
                cout << "This case is not complete yet" << endl;

            }
            else{ // kill is a right child that has a right child
                cout << "This case is not complete yet" << endl;

            }
        }
    }
        // case 3: Kill has two children
    else{
        // task 1: setup a pointer to the parent of the successor node (leftmost
        // node in right subtree
        TreeNode<T>* rkp = Find_Successor_Parent(kill);
        TreeNode<T>* real_kill = rkp->get_left();
        // task 1a: worry about the case where the right child does not have a left subtree
        if(rkp==kill)
            real_kill = rkp->get_right();

        // task 2: swap the values in kill and the successor node.
        // (or really, just copy the sucessor value into the kill node)


        // task 3: kill the successor node

    }
}

// Find_Insert_Position: Called by Insert to recursively find
// the place the item should be inserted.
//  Returns the _parent_ of the position in the
// tree x's node should be (because the child on that side will be NULL)


template <typename T>
TreeNode<T>* Tree<T>::Find_Insert_Position(TreeNode<T>* p, const T& x) const{
    if(p == NULL) // shouldn't happen
        return NULL;
    if(p->get_item() >= x){ // look left
        if(p->get_left() == NULL) // then the left child is where the new
            // node should be
            return p;
        else
            return Find_Insert_Position(p->get_left(), x);
    }
    else{ // look right
        if(p->get_right() == NULL) // then the right child is where the new node
            // should be
            return p;
        else
            return Find_Insert_Position(p->get_right(), x);
    }
}



// Find_Delete_Position- finds the parent of the node we want to delete in
// the tree and returns a pointer to it.  Returns NULL if no node matching
// the item exists
template <typename T>
TreeNode<T>* Tree<T>::Find_Delete_Position(TreeNode<T>* cur, const T& x) const{
    //base case when the given node is NULL
    if(cur == NULL)
        return NULL;
    //Checking left children
    if(cur->get_item() >=x)
    {
        if(cur->get_left()==NULL) //base case 1
            return NULL;
        else if(cur->get_left()->get_item() == x) //if found at left children
            return cur;
        else
            return Find_Delete_Position(cur->get_left(), x); //recursively check again
    }
    //Checking the right children, similarly:
    else
    {
        if (cur->get_right() == NULL)
            return NULL;
        else if (cur->get_right()->get_item() == x)
            return cur;
        else
            return Find_Delete_Position(cur->get_right(), x);
    }
}


// Delete_Tree: Recursively deletes all subtrees of "source", then deletes "source"
template <typename T>
void Tree<T>::Delete_Tree(TreeNode<T>* source){
    //base case when the tree is empty
    if(source == NULL)
        cout << "Empty tree!";
    else
    {
        //Recursively delete left and right subtrees
        Delete_Tree(source->get_left());
        Delete_Tree(source->get_right());
        //Delete the node at the end
        Delete(source->get_item());
    }
}

// deep copies a tree rooted at "source".  Returns a pointer to the root of the copy
template <typename T>
TreeNode<T>* Tree<T>::Copy_Tree(TreeNode<T>* source){
    // here's the beginning of Copy_Tree
    if(source == NULL)
        return NULL;
    else{
        // create a new node for the root of the new tree
        TreeNode<T>* new_root = new TreeNode<T>;
        // Set new_root's item to source's item
        new_root->set_item(source->get_item());
        // call Copy_Tree recursively on source->get_left().  it'll return a pointer.
        // set the left child of new_root to be that pointer.  DO NOT SAY NEW AGAIN
        Copy_Tree(source->get_left());
        new_root->set_left(source->get_left());
        // call Copy_Tree recursively on source->get_right().  It'll return a pointer.
        // Set the right child of new_root to be that pointer.  DO NOT SAY NEW AGAIN
        Copy_Tree(source->get_right());
        new_root->set_right(source->get_right());
        return new_root;
    }
}

// assumes source has a right child
template <typename T>
TreeNode<T>* Tree<T>::Find_Successor_Parent(TreeNode<T>* source) const{


    TreeNode<T>* cur = source;
    TreeNode<T>* parent = cur;
    cur = cur->get_right();
    if(cur->get_left() == NULL)
        //then cur is the successor, and source is the parent
        return source;
    else{
        // loop through the left children until you can't any more.  cur is the last left
        // child, parent is its parent.
    }
    return parent;
}


// sets up the tree with a pre-defined structure.
// Only should be used to give you something to work with before Insert is written
// ONLY WORKS ON TREES OF INTS

template <typename T>
void Tree<T>::Setup(){
    // get rid of anything already there
    Delete_Tree(root);

    // I'm creating these nodes in the order they'll show up in the
    // tree, row by row, starting from the root
    root = new TreeNode<T>;
    root->set_item(10);

    TreeNode<T>* six = new TreeNode<T>;
    six->set_item(6);

    TreeNode<T>* fifteen = new TreeNode<T>;
    fifteen->set_item(15);

    TreeNode<T>* four = new TreeNode<T>;
    four->set_item(4);

    TreeNode<T>* eight = new TreeNode<T>;
    eight->set_item(8);

    TreeNode<T>* thirteen = new TreeNode<T>;
    thirteen->set_item(13);

    TreeNode<T>* seventeen = new TreeNode<T>;
    seventeen->set_item(17);

    TreeNode<T>* two = new TreeNode<T>;
    two->set_item(2);

    TreeNode<T>* fourteen = new TreeNode<T>;
    fourteen->set_item(14);

    TreeNode<T>* one = new TreeNode<T>;
    one->set_item(1);

    // now to hook them up
    root->set_left(six);
    root->set_right(fifteen);

    six->set_left(four);
    six->set_right(eight);

    fifteen->set_left(thirteen);
    fifteen->set_right(seventeen);

    four->set_left(two);
    four->set_right(NULL);

    eight->set_left(NULL);
    eight->set_right(NULL);

    thirteen->set_left(NULL);
    thirteen->set_right(fourteen);

    seventeen->set_left(NULL);
    seventeen->set_right(NULL);

    two->set_left(one);
    two->set_right(NULL);

    fourteen->set_left(NULL);
    fourteen->set_right(NULL);

    one->set_left(NULL);
    one->set_right(NULL);
}


#endif
