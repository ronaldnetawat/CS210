#include "tree.h"

using namespace std;

int main(){
    Tree<int> my_tree;
    // use this before you've written insert
    my_tree.Setup();

    // use this when you've written insert
    //cout << "Enter 10 numbers: ";
    // for(int i = 0; i < 10; i++){
    //   int x;
    //   cin >> x;
    //   my_tree.Insert(x);
    // }
    //cout << "inorder traversal: ";
    //my_tree.Print_Inorder();
    //cout << endl;
    // cout << "preorder traversal: ";
    // my_tree.Print_Preorder();
    // cout << endl;
    // cout << "postorder traversal: ";
    // my_tree.Print_Postorder();
    // cout<< endl;

    //Tree<int> copy(my_tree);
    //copy.Insert(-1);
    //cout << "Copy test- original tree: ";
    // my_tree.Print_Inorder();
    // cout << endl;
    //cout << "Copy test- copy tree: ";
    // copy.Print_Inorder();
    //cout << endl;

    // cout << "Enter an item to find: ";
    // int x;
    // cin >> x;
    //if(my_tree.Find(x))
    //  cout << "It's there " << endl;
    // else
    //   cout << "It's not there " << endl;

    // for(int i = 0; i < 10; i++){
    //  cout << "Enter an item to delete: ";
    //  int del_item;
    // cin >> del_item;
    //  my_tree.Delete(del_item);
    // cout << "Current tree: ";
    //  my_tree.Print_Inorder();
    // }

    //Height
    int height = my_tree.Height();
    cout << "Height = " << height;

    //Dump_To_Vector()
    vector<int> v;
    my_tree.Dump_To_Vector(v);
    for(int i = 0; i < v.size(); i++)
    {
        cout << v[i] << endl;
    }

    //Print_Nodes_At_Depth()
    int depth;
    cout << "Enter depth: ";
    cin >> depth;
    cout << "Nodes at depth " << depth << ": ";
    my_tree.Print_Nodes_At_Depth(depth);


    //Print_Nodes_By_Depth()
    my_tree.Print_Nodes_By_Depth();

    //Path_To_Item();
    int item;
    cout << "Enter item: ";
    cin >> item;
    cout << "Path to " << item << ": ";
    cout << my_tree.Path_To_Item(item);

    //Follow_Path()
    string path;
    cout << "Enter path: ";
    cin >> path;
    cout << my_tree.Follow_Path(path);

    return 0;
}
