#pragma once

#include "GameBoard.hpp"
#include <memory>

namespace game{
class Solution {
    public:
        virtual void solve(std::shared_ptr<GameBoard> gb) = 0;

        virtual ~Solution() = default;
};
}