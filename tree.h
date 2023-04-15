#pragma once
#include "bigbranch.h"

class Tree {
    int countBigBranch;
    BigBranch** pBigBranch = nullptr;
public:
    Tree() {
        std::srand(std::time(nullptr));
        countBigBranch = (std::rand() % 3) + 3;
        pBigBranch = new BigBranch*[countBigBranch];
        for (int i = 0; i < countBigBranch; ++i) {
            pBigBranch[i] = new BigBranch(this, "none");
        }
    }
    BigBranch* GetBigBranchPtr(int index) {
        if (index >= 0 && index < countBigBranch) {
            return pBigBranch[index];
        }
        return nullptr;
    }

    int GetBigBranchCount() {
        return countBigBranch;
    }
};

