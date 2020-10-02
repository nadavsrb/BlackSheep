#pragma once

#include "Solution.hpp"
#include "file_reading.hpp"

#include <string>
#include <fstream>
#include <iostream>///

namespace game{
class RecSolution : public Solution {
    std::string m_filePath;
    public:
        RecSolution(std::string filePath);
        virtual void solve(std::shared_ptr<GameBoard> gb) override;
};
}