#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Song {
public:
    string title;
    string artist;

    Song(string t, string a) : title(t), artist(a) {}
};

class Playlist {
private:
    string name;
    vector<Song> songs;

public:
    Playlist(const string& playlistName) : name(playlistName) {}

    void setName(const string& newName) {
        name = newName;
    }

    string getName() const {
        return name;
    }

    void addSong(const Song& song) {
        songs.push_back(song);
    }

    void viewSongs() const {
        if (songs.empty()) {
            cout << "Playlist is empty." << endl;
            return;
        }
        cout << "Songs in Playlist:\n";
        for (size_t i = 0; i < songs.size(); ++i) {
            cout << i << ": Title: " << songs[i].title << ", Artist: " << songs[i].artist << endl;
        }
    }

    void updateSong(int index, const Song& song) {
        if (index >= 0 && index < songs.size()) {
            songs[index] = song;
        } else {
            cout << "Invalid index." << endl;
        }
    }

    void deleteSong(int index) {
        if (index >= 0 && index < songs.size()) {
            songs.erase(songs.begin() + index);
        } else {
            cout << "Invalid index." << endl;
        }
    }
};

class User {
public:
    string username;

    User(const string& user) : username(user) {}
};

int main() {
    string username, password;

    cout << "Create an account\n";
    cout << "Enter username: ";
    cin >> username;


    User user(username);

    string playlistName;
    cout << "Enter the name of the playlist: ";
    cin.ignore();
    getline(cin, playlistName); 

    Playlist playlist(playlistName);  
    int choice;
    do {
        cout << "\nUser: " << user.username << "\nPlaylist: " << playlist.getName() << "\n";
        cout << "1. Change Playlist Name\n2. Add Song\n3. View Songs\n4. Update Song\n5. Delete Song\n6. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        if (choice == 1) {
            string newName;
            cout << "Enter new playlist name (can include numbers and text): ";
            cin.ignore();  
            getline(cin, newName); 
            playlist.setName(newName);
        } else if (choice == 2) {
            string title, artist;
            cout << "Enter song title: ";
            cin.ignore();  
            getline(cin, title); 
            cout << "Enter song artist: ";
            getline(cin, artist); 
            playlist.addSong(Song(title, artist));
        } else if (choice == 3) {
            playlist.viewSongs(); 
        } else if (choice == 4) {
            int index;
            string title, artist;
            cout << "Enter song index to update: ";
            cin >> index;
            cout << "Enter new song title: ";
            cin.ignore();  
            getline(cin, title);
            cout << "Enter new song artist: ";
            getline(cin, artist);
            playlist.updateSong(index, Song(title, artist));
        } else if (choice == 5) {
            int index;
            cout << "Enter song index to delete: ";
            cin >> index;
            playlist.deleteSong(index);
        }
    } while (choice != 6);

    return 0;
}