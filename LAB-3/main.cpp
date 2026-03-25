#include <iostream>

using namespace std;

struct Song
{
    string title;
    string artist;
    int ratings[3];
    Song* next;
    Song* prev;
    Song(string T, string A, int r1, r2, r3)
    {
        title = T;
        artist = A;
        ratings[0] = r1;
        ratings[1] = r2;
        ratings[2] = r3;
        next = nullptr;
        prev = nullptr;
    }
};

struct playlist_manager
{
    void add_song(string T, string A, int r1, r2, r3)
    {
        Song* new_song = new Song(T, A, r1, r2, r3);

        if (head == nullptr)
        {
            head = line = current = new_song;
        }
        else
        {
            line -> next = new_song;
            new_song -> prev = line;
            line = new_song;
        }
    }
    void next_song()
    {
        if (current != nullptr && current -> next != nullptr)
        {
            current = current -> next;
        }
    }
    void prev_song()
    {
        if (current != nullptr && current -> prev != nullptr)
        {
            current = current -> prev;
        }
    }
    void display()
    {
        if (head == nullptr)
        {
            return;
        }
        cout << "\nPLAYLIST\n";
        for (Song* temp = head; temp != nullptr; temp = temp -> next)
        {
            if (temp == current)
            {
                cout << "->";
            }

        }
    }

};

int main()
{
    playlist_manager my_playlist;
    my_playlist.add_song("Dracula", "Tame Impala and Jennie");
    my_playlist.add_song("Papparazi", "Lady Gaga");
    my_playlist.display();

    return 0;
}
