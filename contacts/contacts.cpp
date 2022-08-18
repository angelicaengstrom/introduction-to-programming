//
// Created by angel on 2022-08-17.
//

#include "contacts.h"

bool is_alpha(const std::string& input){
    for(int i = 0; i < input.size(); i++){
        if(!std::isalpha(input[i]) && !std::isspace(input[i])){
            return false;
        }
    }
    return true;
}

void write_to_file(std::ofstream file, const std::vector<std::vector<std::string>>& contacts){
    for(auto contact : contacts){
        for(auto c : contact){
            file << c << std::endl;
        }
    }
    file.close();
}

void print_contact_at(const int& index) {
    std::ifstream file("C:\\Users\\angel\\OneDrive\\Dokument\\DT028G Introduktion till programmering\\contacts\\contacts.txt");
    std::string x;
    int i = 0;
    int j = 0;

    while(std::getline(file, x)){
        if(i % 5 == 0){
            j++;
        }
        if(j - 1 == index){
            std::cout << x << std::endl;
        }
        i++;
    }
    std::cout << "================\n";

    file.close();
}

void add_contact(){
    std::vector<std::string> contact;
    std::string input;

    std::cout << "First- & lastname: ";
    std::cin.ignore();
    std::getline(std::cin, input);
    contact.push_back(input);

    std::cout << "Address: ";
    std::getline(std::cin, input);
    contact.push_back(input);

    std::cout << "Email: ";
    std::getline(std::cin, input);
    contact.push_back(input);

    std::cout << "Phone number: ";
    std::getline(std::cin, input);
    contact.push_back(input);

    std::cout << "Birthday: ";
    std::getline(std::cin, input);
    contact.push_back(input);

    std::ofstream file("C:\\Users\\angel\\OneDrive\\Dokument\\DT028G Introduktion till programmering\\contacts\\contacts.txt", std::ios::app);
    for(auto i : contact){
        file << i << "\n";
    }
    file.close();
}

void search_contact(const std::vector<std::vector<std::string>>& contacts) {
    std::string input;
    std::cout << "Search: ";
    std::cin.ignore();
    std::getline(std::cin, input);
    std::transform(input.begin(), input.end(), input.begin(), ::tolower);

    bool match = false;

    for(int i = 0; i < contacts.size(); i++){
        auto contact = contacts[i];
        for(int j = 0; j < contact.size(); j++){
            size_t found = contact[j].find(input);
            if(found != std::string::npos){
                print_contact_at(i);
                match = true;
                break;
            }
        }
    }

    if(!match){
        std::cout << "We didn't find \"" << input << "\"" << std::endl;
    }
}

void erase_contact(std::vector<std::vector<std::string>>& contacts) {
    std::string input;
    std::cout << "Choose contact: ";
    std::cin.ignore();
    std::getline(std::cin, input);
    std::transform(input.begin(), input.end(), input.begin(), ::tolower);
    std::vector<std::string> result(contacts.size());
    result.assign(contacts.size(), "");
    bool match = false;

    for(int i = 0; i < contacts.size(); i++){
        auto contact = contacts[i];
        size_t found = contact[0].find(input);
        if(found != std::string::npos){
            std::cout << i + 1 << ". " << contact[0] << std::endl;
            result[i] = contact[0];
            match = true;
        }
    }

    if(match){
        std::cout << "Enter the number you want to delete: (or 0 to cancel)" << std::endl;
        while(std::cin >> input) {
            if(isdigit(input[0]) && stoi(input) <= result.size()) {
                if (stoi(input)) {
                    if (!result[stoi(input) - 1].empty()) {
                        std::cout << "Deleting " << input[0] << ". " << result[stoi(input) - 1] << std::endl;
                        contacts[stoi(input) - 1].clear();
                        write_to_file(std::ofstream("C:\\Users\\angel\\OneDrive\\Dokument\\DT028G Introduktion till programmering\\contacts\\contacts.txt"), contacts);
                        break;
                    } else {
                        std::cout << "Enter a valid number: " << std::endl;
                    }
                } else {
                    break;
                }
            }else {
                std::cout << "Enter a valid number: " << std::endl;
            }
        }
    }else{
        std::cout << "We didn't find \"" << input << "\"" << std::endl;

    }
}

