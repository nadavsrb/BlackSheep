#include "GameBoard.hpp"

using namespace game;

GameBoard::GameBoard(const Board& gb){
    m_gb.size = gb.size;
    m_gb.board = gb.board;
}

GameBoard::GameBoard(std::string filePath) {
    //intalize
    m_gb.size = 0;

    //opening the file
        std::ifstream boardFile(filePath);

        //helping varibles
        std::string line;

    //gets the size   
        while (getline(boardFile, line)) {
            ++m_gb.size;
        }

        if(m_gb.size != 5) {
            throw std::runtime_error("the size expected is 5");
        }
        //setting the file
        boardFile.clear();
        boardFile.seekg(0);

        //Intlizing the board
        std::uint32_t numValExpected = 3;
        while (getline(boardFile, line)) {
            //removing spaces
            line.erase(remove_if(line.begin(), line.end(), isspace), line.end());
            
            line = line + ",";

            std::uint32_t numVal = 0;
            std::size_t found = line.find_first_of(",");
            while(found != std::string::npos) {
                    //gets the value string.
                    int val = 0;
                    std::string valStr = line.substr(0, found);
                    line = line.erase(0, found + 1);
                    val = std::stoi(valStr);

                    if(val != 1 && val != 0 && val != -1) {
                        throw std::runtime_error("unknown val in the board");
                    }

                    ++numVal;
                    if(numVal > numValExpected){
                        throw std::runtime_error("there is line with more val than expected");
                    }

                    m_gb.board.push_back(val);

                    found = line.find_first_of(",");
            }

            if(numVal != numValExpected) {
                throw std::runtime_error("there is line that the num of val isn't right");
            }

            if (numValExpected == 3) {
                numValExpected = 2;
            }else{
                numValExpected = 3;
            }
        }

        int numOfBlackSheep = 0;
        for(int i: m_gb.board) {
            if(i == 1) {
                ++numOfBlackSheep;
            }
        }

        if(numOfBlackSheep != 1) {
            throw std::runtime_error("expected only 1 black sheep");
        }
}

std::vector<std::shared_ptr<GameBoard>> GameBoard::moveOptions(std::uint32_t loc) const {
    std::vector<std::shared_ptr<GameBoard>> options = {};
    if(loc > 12) {
        throw std::runtime_error("not valid location");
    }
    if(m_gb.board.at(loc) == -1) {
        return options;
    }

    std::shared_ptr<GameBoard> copy;
    if(loc == 0) {
        if(m_gb.board.at(1) == 0 && m_gb.board.at(2) == -1) {
            copy = std::make_shared<GameBoard>(m_gb);
            copy->m_gb.board.at(loc) = -1;
            copy->m_gb.board.at(1) = -1;
            copy->m_gb.board.at(2) = m_gb.board.at(loc);
            options.push_back(copy);
        }

        if(m_gb.board.at(3) == 0 && m_gb.board.at(6) == -1) {
            copy = std::make_shared<GameBoard>(m_gb);
            copy->m_gb.board.at(loc) = -1;
            copy->m_gb.board.at(3) = -1;
            copy->m_gb.board.at(6) = m_gb.board.at(loc);
            options.push_back(copy);   
        }

        if(m_gb.board.at(5) == 0 && m_gb.board.at(10) == -1) {
            copy = std::make_shared<GameBoard>(m_gb);
            copy->m_gb.board.at(loc) = -1;
            copy->m_gb.board.at(5) = -1;
            copy->m_gb.board.at(10) = m_gb.board.at(loc);
            options.push_back(copy);
        }
    }else if(loc == 1) {
        if(m_gb.board.at(3) == 0 && m_gb.board.at(5) == -1) {
            copy = std::make_shared<GameBoard>(m_gb);
            copy->m_gb.board.at(loc) = -1;
            copy->m_gb.board.at(3) = -1;
            copy->m_gb.board.at(5) = m_gb.board.at(loc);
            options.push_back(copy);
        }

        if(m_gb.board.at(4) == 0 && m_gb.board.at(7) == -1) {
            copy = std::make_shared<GameBoard>(m_gb);
            copy->m_gb.board.at(loc) = -1;
            copy->m_gb.board.at(4) = -1;
            copy->m_gb.board.at(7) = m_gb.board.at(loc);
            options.push_back(copy);   
        }

        if(m_gb.board.at(6) == 0 && m_gb.board.at(11) == -1) {
            copy = std::make_shared<GameBoard>(m_gb);
            copy->m_gb.board.at(loc) = -1;
            copy->m_gb.board.at(6) = -1;
            copy->m_gb.board.at(11) = m_gb.board.at(loc);
            options.push_back(copy);   
        }
    }else if(loc == 2) {
        if(m_gb.board.at(1) == 0 && m_gb.board.at(0) == -1) {
            copy = std::make_shared<GameBoard>(m_gb);
            copy->m_gb.board.at(loc) = -1;
            copy->m_gb.board.at(1) = -1;
            copy->m_gb.board.at(0) = m_gb.board.at(loc);
            options.push_back(copy);
        }

        if(m_gb.board.at(4) == 0 && m_gb.board.at(6) == -1) {
            copy = std::make_shared<GameBoard>(m_gb);
            copy->m_gb.board.at(loc) = -1;
            copy->m_gb.board.at(4) = -1;
            copy->m_gb.board.at(6) = m_gb.board.at(loc);
            options.push_back(copy);   
        }

        if(m_gb.board.at(7) == 0 && m_gb.board.at(12) == -1) {
            copy = std::make_shared<GameBoard>(m_gb);
            copy->m_gb.board.at(loc) = -1;
            copy->m_gb.board.at(7) = -1;
            copy->m_gb.board.at(12) = m_gb.board.at(loc);
            options.push_back(copy);
        }
    }else if(loc == 3) {
        if(m_gb.board.at(6) == 0 && m_gb.board.at(9) == -1) {
            copy = std::make_shared<GameBoard>(m_gb);
            copy->m_gb.board.at(loc) = -1;
            copy->m_gb.board.at(6) = -1;
            copy->m_gb.board.at(9) = m_gb.board.at(loc);
            options.push_back(copy);
        }
    }else if(loc == 4) {
        if(m_gb.board.at(6) == 0 && m_gb.board.at(8) == -1) {
            copy = std::make_shared<GameBoard>(m_gb);
            copy->m_gb.board.at(loc) = -1;
            copy->m_gb.board.at(6) = -1;
            copy->m_gb.board.at(8) = m_gb.board.at(loc);
            options.push_back(copy);
        }
    }else if(loc == 5) {
        if(m_gb.board.at(3) == 0 && m_gb.board.at(1) == -1) {
            copy = std::make_shared<GameBoard>(m_gb);
            copy->m_gb.board.at(loc) = -1;
            copy->m_gb.board.at(3) = -1;
            copy->m_gb.board.at(1) = m_gb.board.at(loc);
            options.push_back(copy);
        }

        if(m_gb.board.at(6) == 0 && m_gb.board.at(7) == -1) {
            copy = std::make_shared<GameBoard>(m_gb);
            copy->m_gb.board.at(loc) = -1;
            copy->m_gb.board.at(6) = -1;
            copy->m_gb.board.at(7) = m_gb.board.at(loc);
            options.push_back(copy);   
        }

        if(m_gb.board.at(8) == 0 && m_gb.board.at(11) == -1) {
            copy = std::make_shared<GameBoard>(m_gb);
            copy->m_gb.board.at(loc) = -1;
            copy->m_gb.board.at(8) = -1;
            copy->m_gb.board.at(11) = m_gb.board.at(loc);
            options.push_back(copy);   
        }
    }else if(loc == 6) {
        if(m_gb.board.at(3) == 0 && m_gb.board.at(0) == -1) {
            copy = std::make_shared<GameBoard>(m_gb);
            copy->m_gb.board.at(loc) = -1;
            copy->m_gb.board.at(3) = -1;
            copy->m_gb.board.at(0) = m_gb.board.at(loc);
            options.push_back(copy);
        }

        if(m_gb.board.at(4) == 0 && m_gb.board.at(2) == -1) {
            copy = std::make_shared<GameBoard>(m_gb);
            copy->m_gb.board.at(loc) = -1;
            copy->m_gb.board.at(4) = -1;
            copy->m_gb.board.at(2) = m_gb.board.at(loc);
            options.push_back(copy);
        }

        if(m_gb.board.at(8) == 0 && m_gb.board.at(10) == -1) {
            copy = std::make_shared<GameBoard>(m_gb);
            copy->m_gb.board.at(loc) = -1;
            copy->m_gb.board.at(8) = -1;
            copy->m_gb.board.at(10) = m_gb.board.at(loc);
            options.push_back(copy);   
        }

        if(m_gb.board.at(9) == 0 && m_gb.board.at(12) == -1) {
            copy = std::make_shared<GameBoard>(m_gb);
            copy->m_gb.board.at(loc) = -1;
            copy->m_gb.board.at(9) = -1;
            copy->m_gb.board.at(12) = m_gb.board.at(loc);
            options.push_back(copy);   
        }
    }else if(loc == 7) {
        if(m_gb.board.at(4) == 0 && m_gb.board.at(1) == -1) {
            copy = std::make_shared<GameBoard>(m_gb);
            copy->m_gb.board.at(loc) = -1;
            copy->m_gb.board.at(4) = -1;
            copy->m_gb.board.at(1) = m_gb.board.at(loc);
            options.push_back(copy);
        }

        if(m_gb.board.at(6) == 0 && m_gb.board.at(5) == -1) {
            copy = std::make_shared<GameBoard>(m_gb);
            copy->m_gb.board.at(loc) = -1;
            copy->m_gb.board.at(6) = -1;
            copy->m_gb.board.at(5) = m_gb.board.at(loc);
            options.push_back(copy);   
        }

        if(m_gb.board.at(9) == 0 && m_gb.board.at(11) == -1) {
            copy = std::make_shared<GameBoard>(m_gb);
            copy->m_gb.board.at(loc) = -1;
            copy->m_gb.board.at(9) = -1;
            copy->m_gb.board.at(11) = m_gb.board.at(loc);
            options.push_back(copy);   
        }
    } else { //8<=loc<=12
        copy = std::make_shared<GameBoard>(m_gb);
        std::reverse(copy->m_gb.board.begin(), copy->m_gb.board.end());

        options = copy->moveOptions(12 - loc);

        for(auto option: options) {
            std::reverse(option->m_gb.board.begin(), option->m_gb.board.end());
        }
    }

    return options;
}

bool GameBoard::isSolution() const {
    for (int i: m_gb.board) {
        if(i == 0) {
            return false;
        }
    }
    
    return true;
}


std::ostream& operator<<(std::ostream& stream, const game::GameBoard& gb) {
    std::uint32_t numValExpected = 3;
    std::uint32_t valIndex = 0;
    for(uint32_t i = 0; i < gb.m_gb.size; ++i) {
        if (numValExpected == 2) {
            stream<<" ";
        }
        stream<<"|";
        for(uint32_t j = 0; j < numValExpected; ++j) {
            int val = gb.m_gb.board.at(valIndex);
            if(val == -1) {
               stream<<"*"<<"|"; 
            } else {
                stream<<val<<"|";
            }
            
            ++valIndex;
        }
        stream<<std::endl;

        if (numValExpected == 3) {
            numValExpected = 2;
        }else{
            numValExpected = 3;
        } 
    }

    return stream;
}