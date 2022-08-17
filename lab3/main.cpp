#include <iostream>
#include <fstream>
#include <vector>

bool is_sorted(std::ifstream file){
    int a, b;
    file >> a;
    while(file >> b){
        if(a > b) {
            return false;
        }
        a = b;
    }
    return true;
}

template<typename T>
std::vector<T> merge_sort(std::ifstream A, std::ifstream B){
    std::vector<T> C;
    T a, b;
    A >> a;
    B >> b;
    while(!A.eof() && !B.eof()){
        if(a < b){
            C.push_back(a);
            A >> a;
        }else{
            C.push_back(b);
            B >> b;
        }
    }

    return C;
}

int main() {
    if(is_sorted(std::ifstream("C:\\Users\\angel\\OneDrive\\Dokument\\DT028G Introduktion till programmering\\lab3\\A1"))){
        std::cout << "Sorterad" << std::endl;
    }else{
        std::cout << "Inte sorterad" << std::endl;
    }

    if(is_sorted(std::ifstream("C:\\Users\\angel\\OneDrive\\Dokument\\DT028G Introduktion till programmering\\lab3\\A")) &&
    is_sorted(std::ifstream("C:\\Users\\angel\\OneDrive\\Dokument\\DT028G Introduktion till programmering\\lab3\\B"))){
        auto C = merge_sort<int>(std::ifstream("C:\\Users\\angel\\OneDrive\\Dokument\\DT028G Introduktion till programmering\\lab3\\A"),
                        std::ifstream("C:\\Users\\angel\\OneDrive\\Dokument\\DT028G Introduktion till programmering\\lab3\\B"));
        std::ofstream file("C:\\Users\\angel\\OneDrive\\Dokument\\DT028G Introduktion till programmering\\lab3\\C");
        for(auto i : C){
            file << i << " ";
        }
    }
    return 0;
}
