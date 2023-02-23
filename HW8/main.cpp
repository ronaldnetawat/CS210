

}

void Player::Insert_Node(const int **first, string name, int pos) {
    Node* newPlayer = new Node();
    newPlayer->my_name = name;
    newPlayer->my_pos = pos;
    newPlayer->next = *first;
    *first = newPlayer;
}

// accessor functions
// you should write them
string Player::Get_Name() const {
    return my_name;
}

int Player::Get_Pos() const {
    return my_pos;
}

// mutator functions
// you should write them
void Player::Set_Name(const string &s) {
    my_name = s;
}

void Player::Set_Pos(int new_pos) {
    my_pos = new_pos;
}


// comparison operators- equality means the same name
bool Player::operator==(const Player& other) const{
    if(my_name == other.Get_Name())
        return true;
    else
        return false;
}

bool Player::operator!=(const Player& other) const{
    if(my_name != other.Get_Name())
        return true;
    else
        return false;
}


// < and <= means an earlier position
bool Player::operator<(const Player& other) const{
    if(my_pos < other.Get_Pos())
        return true;
    else
        return false;
}

bool Player::operator<=(const Player& other) const {
    if (my_pos <= other.Get_Pos())
        return true;
    else
        return false;
}

bool Player::operator>(const Player& other) const{
    if(my_pos > other.Get_Pos())
        return true;
    else
        return false;
}


int main()
{
    Node* first = new Node();
    cout << "THE GAME" << endl << "----------------" << endl << endl;
    int no_of_players;
    cout << "Enter the number of players: ";
    cin >> no_of_players;


    list<string> Players;
    for(int i = 0; i < no_of_players; i++)
    {
        string pName;
        int position;
        Insert_Node(&first, pName, position);
        Players.push_back(name);
    }

    Node *item = Find_Item_At_Index(0);
    deleteNode(first, item);

    string nextPlayer = first->next.Get_Name();
    cout << "Next player is: " << nextPlayer;
    int nextPos;
    cout << "Enter a new position: ";
    cin >> nextPos;

    while(nextPos > first->next.Get_Pos())
    {
        Insert_Node(first, nextPlayer, nextPos);
    }


}
