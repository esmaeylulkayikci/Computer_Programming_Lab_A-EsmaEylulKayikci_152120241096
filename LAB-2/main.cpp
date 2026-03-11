#include <iostream>

using namespace std;

struct Node
{
    string data;
    Node* next;
};

void addword(Node*& head, string word)
{
    Node* new_node = new Node();
    new_node -> data = word;
    new_node -> next = nullptr;

    if (head == nullptr)
    {
        head = new_node;
    }
    else
    {
        Node* temp = head;
        while (temp -> next != nullptr)
        {
            temp = temp -> next;
        }
        temp -> next = new_node;
    }
}

void undo(Node*& head)
{
    if (head == nullptr)
    {
        return;
    }

    if (head -> next == nullptr)
    {
        delete head;
        head = nullptr;
        return;
    }

    Node* temp = head;
    while (temp -> next -> next != nullptr)
    {
        temp = temp -> next;
    }
    delete temp -> next;
    temp -> next = nullptr;
}

void display(Node* head)
{
    Node* temp = head;
    while (temp != nullptr)
    {
        cout << "[" << temp -> data << "] -> ";
        temp = temp -> next;
    }
    cout << "\nNULL\n" << endl;
}

int main()
{
    Node* head = nullptr;
    string input;

    cout << "\nBasic Text Reviser\n" << endl;
    cout << "Enter a word, type erasing for 'UNDO', exit to 'EXIT'\n" << endl;

    while (true)
    {
        cout << "> ";
        cin >> input;

        if(input == "EXIT")
        {
            break;
        }
        else if (input == "UNDO")
        {
            undo(head);
        }
        else
        {
            addword(head, input);
        }
        display (head);
    }

    return 0;
}
