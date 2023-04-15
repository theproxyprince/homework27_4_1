#include <iostream>
#include "tree.h"
#include <array>

std::array<Tree*, 2> VillageInit() {
    std::array<Tree*, 2> village {nullptr};
    std::string tmpElfName;
    int n = 1;
    for (auto &k : village) {
        k = new Tree;
        std::cout << "Tree #" << n++ << ": " <<std::endl;
        for(int i = 0; i < k->GetBigBranchCount(); ++i){
            std::string elfName;
            std::cout << "Enter elf's name at the house in the big branch #" << i+1 << " : ";
            std::cin >> elfName;
            k->GetBigBranchPtr(i)->SetElfName(elfName);
            for(int j = 0; j < k->GetBigBranchPtr(i)->GetMiddleBranchCount(); ++j){
                std::cout << "Enter elf's name at the house in the middle branch #" << j+1 << " : ";
                std::cin >> elfName;
                k->GetBigBranchPtr(i)->GetMiddleBranchPtr(j)->SetElfName(elfName);
            }
        }
    }
    return village;
}



int main() {
    std::array<Tree*, 2> village = VillageInit();
    std::string inString;
    do {
        std::cout << "Enter elf name to search: " << std::endl;
        std::cin >> inString;
        if (inString != "exit") {
            int neighbors = 0;
            for (auto& k : village) {
                for (int i = 0; i < k->GetBigBranchCount(); ++i) {
                    neighbors=k->GetBigBranchPtr(i)->GetElfNeighbors(inString);
                    if (neighbors != -1) {
                        std::cout << "Elf " << inString << " has " << neighbors << " neighbors." << std::endl;
                        break;
                    }
                }
                if (neighbors != -1) {
                    break;
                }
            }

            if (neighbors == -1) {
                std::cout << "Elf " << inString << " not find." << std::endl;
            }
        }
    } while (inString != "exit");

    return 0;
}
