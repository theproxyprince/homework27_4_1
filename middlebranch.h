#pragma once

#include <cassert>
#include <utility>
#include <ctime>

class MiddleBranch {
    class BigBranch* bigBranch = nullptr;
    std::string elfName;
public:
    MiddleBranch (class BigBranch* inBigBranch, std::string inName) : bigBranch(inBigBranch), elfName(std::move(inName)){
        assert(inBigBranch != nullptr);
    }

    std::string GetElfName() {
        return this->elfName;
    }

    void SetElfName(std::string& name) {
        this->elfName = name;
    }
};

