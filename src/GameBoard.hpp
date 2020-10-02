#pragma once

#include <cstdint>
#include <vector>
#include <ostream>
#include <memory>
#include <string>
#include <fstream>
#include <algorithm>

#include <iostream>///

namespace game{class GameBoard;}

std::ostream& operator<<(std::ostream& stream, const game::GameBoard& gb);

namespace game{
    struct Board {
        std::uint32_t size;

        /**
         * @brief 
         * 0 = white sheep
         * 1 = black sheep
         * -1 = no sheep;
         */
        std::vector<int> board;
    };

    class GameBoard{
        Board m_gb;
    
    public:
        GameBoard(std::string filePath);
        GameBoard(const Board& gb);

        std::vector<std::shared_ptr<GameBoard>> moveOptions(std::uint32_t loc) const;

        bool isSolution() const;

        friend std::ostream& ::operator<<(std::ostream& stream, const GameBoard& gb);
    };
}