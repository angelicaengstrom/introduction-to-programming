#include <iostream>
#include <algorithm>
#include "contacts.h"

enum menu{
    add = 1, search = 2, erase = 3, cancel = 4
};

void print_menu(){
    std::cout << "1. Add contact | 2. Search contact | 3. Erase contact | 4. Exit" << std::endl;
}

std::vector<std::vector<std::string>> get_contacts(std::ifstream file){
    std::string x;
    std::vector<std::vector<std::string>> contacts;

    while(std::getline(file, x)){
        std::vector<std::string> contact;
        std::transform(x.begin(), x.end(), x.begin(), ::tolower);
        contact.push_back(x);
        for(int i = 0; i < 4; i++){
            std::getline(file,x);
            std::transform(x.begin(), x.end(), x.begin(), ::tolower);
            contact.push_back(x);
        }
        contacts.push_back(contact);
    }
    file.close();

    return contacts;
}

int main() {
    menu choice;
    int x;

    print_menu();

    std::vector<std::vector<std::string>> contacts;

    while(std::cin >> x){
        choice = (menu)x;
        contacts = get_contacts(std::ifstream("C:\\Users\\angel\\OneDrive\\Dokument\\DT028G Introduktion till programmering\\contacts\\contacts.txt"));

        switch (choice) {
            case add:
                std::cout << "Add" << std::endl;
                add_contact();
                break;
            case search:
                std::cout << "Search" << std::endl;
                search_contact(contacts);
                break;
            case erase:
                std::cout << "Erase" << std::endl;
                erase_contact(contacts);
                break;
            case cancel:
                std::cout << "Exit" << std::endl;
                return 0;
            default:
                std::cout << "Ange en siffra mellan 1-4..." << std::endl;
                break;
        }
        print_menu();
    }

    return 0;
}
