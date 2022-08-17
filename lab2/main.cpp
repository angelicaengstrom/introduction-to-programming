#include <iostream>
#include <fstream>

int main() {
    std::ifstream file("C:\\Users\\angel\\OneDrive\\Dokument\\DT028G Introduktion till programmering\\lab2\\names.txt");
    std::ofstream new_file("C:\\Users\\angel\\OneDrive\\Dokument\\DT028G Introduktion till programmering\\lab2\\new_names.txt");
    std::string first, last, pid, address;

    while(!file.eof()){
        file >> first >> last >> pid;
        file.ignore();
        std::getline(file, address);

        new_file << last << ", " << first;
        if((int)pid[8] % 2 == 0){
            new_file << " [K]\n";
        }else{
            new_file << " [M]\n";
        }
        new_file << address << std::endl;
    }

    return 0;
}
