#include <iostream>
#include <fstream>
#include <map>
#include <vector>
#include <algorithm>

int main() {
    std::fstream file("C:\\Users\\angel\\OneDrive\\Dokument\\DT028G Introduktion till programmering\\lab4\\hitchhikersguide.txt");
    std::string x;
    std::map<std::string, int> words;

    while(file >> x){
        std::transform(x.begin(), x.end(), x.begin(), ::tolower);
        
        if(words.count(x)){
            words[x]++;
        }else{
            words[x] = 1;
        }
    }

    std::multimap<int, std::string, std::greater<>> result;
    for(auto& it : words){
        result.insert(std::make_pair(it.second, it.first));
    }

    std::cout << "Ange n: " << std::endl;
    int n;
    std::cin >> n;
    int i = 0;

    for(auto& it : result){
        std::cout << ++i << ". " << it.second << " - " << it.first << std::endl;
        if(n <= i){
            break;
        }
    }

        /*

    std::vector<std::pair<std::string, int>> result;
    result.reserve(words.size());

    for(const auto& word : words){
        result.emplace_back(word);
    }

    std::sort(result.begin(), result.end(), [](const auto& x, const auto& y){
        return x.second > y.second;
    });

    std::cout << "Ange n: " << std::endl;
    int n;
    std::cin >> n;

    for(int i = 0; i < n; i++){
        std::cout << i + 1 << ". " << result[i].first << " - " << result[i].second << std::endl;
    }*/
    return 0;
}
