#include <iostream>
#include "Playlist.h"
using namespace std;
Playlist::Playlist()
{
    head=nullptr;
    tail=nullptr;
    currentSong=nullptr;
}
Playlist::~Playlist()
{
Node* currentSong = head;
    while (currentSong != nullptr)
    {
        Node* nextNode = currentSong->next;
        delete currentSong;
        currentSong = nextNode;
    }
}
void Playlist::addSong(string song)
{
Node* newNode = new Node(song);
    if (head == nullptr)
    {
        head = newNode;

        tail = newNode;
        currentSong = newNode;
    }
    else
    {
        tail->next = newNode;
        tail = newNode;
    }
}
bool Playlist::removeSong(string title)
{

        if (head == nullptr) {
            return false;
        }

        if (head->data.name == title) {
            Node* toDelete = head;
            head = head->next;

            if (head == nullptr) {
                tail = nullptr;
            }

            if (currentSong == toDelete) {
                currentSong = head;
            }

            delete toDelete;
            return true;
        }

        Node* current = head;

        while (current->next != nullptr && current->next->data.name != title) {
            current = current->next;
        }

        if (current->next == nullptr) {
            return false;
        }

        Node* toDelete = current->next;

        current->next = toDelete->next;

        if (toDelete == tail) {
            tail = current;
        }

        if (currentSong == toDelete) {
            currentSong = nullptr;
        }

        delete toDelete;
        return true;
    }

void Playlist::playCurrent()
{
    if (currentSong == nullptr)
    {
        cout<<"Sarki Bulunamadi";
    }
    else
    {
        cout << "Su an caliyor: " << currentSong->data.name << " - "    << currentSong->data.artist << "\n";
    }
}
void Playlist::nextSong()
{
    if (currentSong == nullptr)
    {
        cout<<"Sarki Bulunamadi";
    }
    else if (currentSong->next != nullptr)
    {
        cout << currentSong->data.name << " - " <<currentSong->data.artist << "\n";
    }
    else
    {
        cout << "Listenin sonuna ulasildi. En basa donuluyor...\n";
        currentSong = head;
    }
    cout << "Sarki degistirildi. Su an caliyor: "<< currentSong->data.name << " - "<< currentSong->data.artist << "\n";


}

void Playlist::prevSong()



{
    // Durum 1: Liste boşsa veya hiç şarkı seçilmemişse
    if (head == nullptr || currentSong == nullptr) {
        std::cout << "Liste bos veya secili sarki yok.\n";
        return;
    }

    if (currentSong == head) {
        std::cout << "Zaten ilk sarkidasiniz, geriye gidilemez.\n";
        return;
    }

    Node* current = head;

    while (current->next != currentSong) {
        current = current->next;
    }

    currentSong = current;

    std::cout << "Bir onceki sarkiya donuldu. Su an caliyor: "
              << current->data.name << " - "
              << current->data.artist << "\n";
}
void Playlist::toggleRepeat() {
    isRepeat = !isRepeat;

    if (isRepeat) {
        std::cout << "Tekrar modu ACILDI.\n";
    } else {
        std::cout << "Tekrar modu KAPATILDI.\n";
    }
}
void Playlist::printPlaylist()
{
    Node* current = head;
    while (current != nullptr)
    {
        cout  << current->song << "\n";
        current=current->next;
    }
}




