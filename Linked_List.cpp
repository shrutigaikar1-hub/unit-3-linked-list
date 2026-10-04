#include <iostream>
#include <string>
using namespace std;

struct Node {
    string song;
    Node* next;
};

void insertSong(Node*& head, string song) {
    Node* newNode = new Node();
    newNode->song = song;
    newNode->next = head;
    head = newNode;
}

void deleteSong(Node*& head) {
    if (head == NULL) {
        cout << "Playlist is empty." << endl;
        return;
    }

    Node* temp = head;
    head = head->next;
    delete temp;

    cout << "Song deleted successfully." << endl;
}

void searchSong(Node* head, string song) {
    Node* temp = head;

    while (temp != NULL) {
        if (temp->song == song) {
            cout << "Song found in playlist." << endl;
            return;
        }
        temp = temp->next;
    }

    cout << "Song not found." << endl;
}

void display(Node* head) {
    if (head == NULL) {
        cout << "Playlist is empty." << endl;
        return;
    }

    Node* temp = head;

    cout << "Playlist:" << endl;
    while (temp != NULL) {
        cout << temp->song << endl;
        temp = temp->next;
    }
}

int main() {
    Node* head = NULL;
    int choice;
    string song;

    do {
        cout << "\n--- Playlist Menu ---" << endl;
        cout << "1. Insert Song" << endl;
        cout << "2. Delete Song" << endl;
        cout << "3. Search Song" << endl;
        cout << "4. Display Playlist" << endl;
        cout << "5. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter song name: ";
                cin.ignore();
                getline(cin, song);
                insertSong(head, song);
                cout << "Song inserted successfully." << endl;
                break;

            case 2:
                deleteSong(head);
                break;

            case 3:
                cout << "Enter song name to search: ";
                cin.ignore();
                getline(cin, song);
                searchSong(head, song);
                break;

            case 4:
                display(head);
                break;

            case 5:
                cout << "Exiting..." << endl;
                break;

            default:
                cout << "Invalid choice." << endl;
        }

    } while (choice != 5);

    return 0;
}
