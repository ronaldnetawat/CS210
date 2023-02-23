#ifndef PLAYER_H
#define PLAYER_H

#include <string>
#include <list>

using namespace std;

class Player{
public:
    // accessors
    string Get_Name() const;
    int Get_Pos() const;

    //mutators
    void Set_Name(const string& s);
    void Set_Pos(int new_pos);

    // comparison operators- equality means the same name
    bool operator==(const Player& other) const;
    bool operator!=(const Player& other) const;
    // < means at an earlier position
    bool operator<(const Player& other) const;
    bool operator<=(const Player& other) const;
    // > means at a later position
    bool operator>(const Player& other) const;

    //Insert a new node (player) in the linked list
    void Insert_Node(const Node** first, string name, int pos);

    //Find the item at a particular index
    void Find_Item_At_Index(const int pos);

    //Delete a particular item
    void deleteNode(Node* first, Node* item);

private:
    string my_name;
    int my_pos;
    Node* next;
};


#endif
