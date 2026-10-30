
#include <iostream>
#include <string>
#include <limits>
using namespace std;

// Each node represents one song in the playlist.
class Node
{
public:
    string title;
    string artist;
    Node *prev;
    Node *next;

    Node(string songTitle, string artistName)
    {
        title = songTitle;
        artist = artistName;
        prev = nullptr;
        next = nullptr;
    }
};

class MusicPlaylist
{
private:
    Node *head;
    Node *current;

    // Find a song by title.
    Node *findSong(const string &title) const
    {
        Node *q = head;

        while (q != nullptr)
        {
            if (q->title == title)
                return q;

            q = q->next;
        }

        return nullptr;
    }

public:
    MusicPlaylist()
    {
        head = nullptr;
        current = nullptr;
    }

    // Free allocated memory.
    ~MusicPlaylist()
    {
        Node *q = head;

        while (q != nullptr)
        {
            Node *p = q;
            q = q->next;
            delete p;
        }

        head = nullptr;
        current = nullptr;
    }

    bool isEmpty() const
    {
        return head == nullptr;
    }

    // Add a new song.
    void addSong(const string &title, const string &artist)
    {
        if (title.empty())
        {
            cout << "Song title cannot be empty.\n";
            return;
        }

        if (findSong(title) != nullptr)
        {
            cout << "A song with this title already exists.\n";
            return;
        }

        Node *p = new Node(title, artist);

        if (head == nullptr)
        {
            head = p;
            current = p;
        }
        else
        {
            Node *q = head;

            while (q->next != nullptr)
                q = q->next;

            q->next = p;
            p->prev = q;
        }

        cout << "Song added successfully.\n";
    }

    // Delete a song.
    void deleteSong(const string &title)
    {
        Node *p = findSong(title);

        if (p == nullptr)
        {
            cout << "Song not found.\n";
            return;
        }

        if (p->prev != nullptr)
            p->prev->next = p->next;
        else
            head = p->next;

        if (p->next != nullptr)
            p->next->prev = p->prev;

        if (current == p)
        {
            if (p->next != nullptr)
                current = p->next;
            else
                current = p->prev;
        }

        delete p;

        cout << "Song deleted successfully.\n";
    }

    // Display songs in forward order.
    void displayForward() const
    {
        if (head == nullptr)
        {
            cout << "Playlist is empty.\n";
            return;
        }

        Node *q = head;

        cout << "\nPlaylist (forward):\n";

        while (q != nullptr)
        {
            cout << q->title << " - " << q->artist << "\n";
            q = q->next;
        }
    }

    // Display songs in reverse order.
    void displayReverse() const
    {
        if (head == nullptr)
        {
            cout << "Playlist is empty.\n";
            return;
        }

        Node *q = head;

        while (q->next != nullptr)
            q = q->next;

        cout << "\nPlaylist (reverse):\n";

        while (q != nullptr)
        {
            cout << q->title << " - " << q->artist << "\n";
            q = q->prev;
        }
    }

    // Play the current song.
    void playCurrent() const
    {
        if (current == nullptr)
        {
            cout << "No song selected. Playlist is empty.\n";
        }
        else
        {
            cout << "Now playing: " << current->title
                 << " - " << current->artist << "\n";
        }
    }

    // Play the next song.
    void playNext()
    {
        if (current == nullptr)
        {
            cout << "Playlist is empty.\n";
        }
        else if (current->next == nullptr)
        {
            cout << "Already at the last song.\n";
        }
        else
        {
            current = current->next;
            playCurrent();
        }
    }

    // Play the previous song.
    void playPrevious()
    {
        if (current == nullptr)
        {
            cout << "Playlist is empty.\n";
        }
        else if (current->prev == nullptr)
        {
            cout << "Already at the first song.\n";
        }
        else
        {
            current = current->prev;
            playCurrent();
        }
    }

    // Play the complete playlist.
    void playCompletePlaylist() const
    {
        if (head == nullptr)
        {
            cout << "Playlist is empty.\n";
            return;
        }

        Node *q = head;

        cout << "\nPlaying complete playlist:\n";

        while (q != nullptr)
        {
            cout << "Playing: " << q->title
                 << " - " << q->artist << "\n";

            q = q->next;
        }
    }

    // Repeat the playlist a specified number of times.
    void repeatAll(int repetitions) const
    {
        if (head == nullptr)
        {
            cout << "Playlist is empty.\n";
            return;
        }

        if (repetitions <= 0)
        {
            cout << "Repetitions must be greater than zero.\n";
            return;
        }

        for (int i = 1; i <= repetitions; ++i)
        {
            Node *q = head;

            cout << "\nRepetition " << i << ":\n";

            while (q != nullptr)
            {
                cout << "Playing: " << q->title
                     << " - " << q->artist << "\n";

                q = q->next;
            }
        }
    }

    // Show the current song.
    void showCurrent() const
    {
        if (current == nullptr)
        {
            cout << "Current song: None\n";
        }
        else
        {
            cout << "Current song: " << current->title
                 << " - " << current->artist << "\n";
        }
    }
};

int main()
{
    MusicPlaylist playlist;
    int choice = 0;

    do
    {
        cout << "\n===== MUSIC PLAYLIST MANAGER =====\n"
             << "1. Add Song\n"
             << "2. Delete Song\n"
             << "3. Display Playlist\n"
             << "4. Display Playlist in Reverse\n"
             << "5. Play Current Song\n"
             << "6. Play Next Song\n"
             << "7. Play Previous Song\n"
             << "8. Play Complete Playlist\n"
             << "9. Repeat All\n"
             << "10. Show Current Song\n"
             << "11. Exit\n"
             << "Enter choice: ";

        if (!(cin >> choice))
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');

            cout << "Invalid input. Enter a number from 1 to 11.\n";
            continue;
        }

        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        string title, artist;
        int repetitions;

        switch (choice)
        {
        case 1:
            cout << "Enter song title: ";
            getline(cin, title);

            cout << "Enter artist name: ";
            getline(cin, artist);

            playlist.addSong(title, artist);
            break;

        case 2:
            cout << "Enter title to delete: ";
            getline(cin, title);

            playlist.deleteSong(title);
            break;

        case 3:
            playlist.displayForward();
            break;

        case 4:
            playlist.displayReverse();
            break;

        case 5:
            playlist.playCurrent();
            break;

        case 6:
            playlist.playNext();
            break;

        case 7:
            playlist.playPrevious();
            break;

        case 8:
            playlist.playCompletePlaylist();
            break;

        case 9:
            cout << "Enter number of repetitions: ";

            if (cin >> repetitions)
            {
                cin.ignore(
                    numeric_limits<streamsize>::max(), '\n');

                playlist.repeatAll(repetitions);
            }
            else
            {
                cin.clear();
                cin.ignore(
                    numeric_limits<streamsize>::max(), '\n');

                cout << "Invalid repetition count.\n";
            }
            break;

        case 10:
            playlist.showCurrent();
            break;

        case 11:
            cout << "Exiting Music Playlist Manager. Goodbye!\n";
            break;

        default:
            cout << "Invalid choice. Select 1 to 11.\n";
        }

    } while (choice != 11);

    return 0;
}

PS C:\Users\Student\OneDrive\Desktop\vedika111> cd  g++ playlist.cpp -o playlist
PS C:\Users\Student\OneDrive\Desktop\vedika111> cd  ./playlist

===== MUSIC PLAYLIST MANAGER =====
1. Add Song
2. Delete Song
3. Display Playlist
4. Display Playlist in Reverse
5. Play Current Song
6. Play Next Song
7. Play Previous Song
8. Play Complete Playlist
9. Repeat All
10. Show Current Song
11. Exit
Enter choice: 1
Enter song title: Meri ma
Enter artist name: Mr .khan
Song added successfully.

===== MUSIC PLAYLIST MANAGER =====
1. Add Song
2. Delete Song
3. Display Playlist
4. Display Playlist in Reverse
5. Play Current Song
6. Play Next Song
7. Play Previous Song
8. Play Complete Playlist
9. Repeat All
10. Show Current Song
11. Exit
Enter choice: 