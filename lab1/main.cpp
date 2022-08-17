#include <iostream>
#include <fstream>

int main() {
    std::ifstream file("C:\\Users\\angel\\OneDrive\\Dokument\\DT028G Introduktion till programmering\\lab1\\values.txt");
    int max, x, min, sum, i = 1;
    file >> x;

    max = min = sum = x;
    while(file >> x){
        if(x > max){
            max = x;
        }
        if(x < min){
            min = x;
        }
        sum += x;
        i++;
    }
    double mean = sum / i;

    std::cout << "Minsta värdet: " << min << "\nStörsta värdet: " << max << "\nMedelvärdet: " << mean << std::endl;

    return 0;
}
