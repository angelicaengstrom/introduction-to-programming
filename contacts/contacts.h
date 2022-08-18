//
// Created by angel on 2022-08-17.
//

#ifndef CONTACTS_CONTACTS_H
#define CONTACTS_CONTACTS_H

#include <iostream>
#include <vector>
#include <fstream>
#include <algorithm>

void add_contact();
void search_contact(const std::vector<std::vector<std::string>>& contacts);
void erase_contact(std::vector<std::vector<std::string>>& contacts);


#endif //CONTACTS_CONTACTS_H
