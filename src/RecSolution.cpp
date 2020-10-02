#include "RecSolution.hpp"

using namespace game;

RecSolution::RecSolution(std::string filePath) {
    m_filePath = filePath;
    files::writeFileContent(filePath, "");
}

bool getSol(std::shared_ptr<GameBoard> gb, std::vector<std::shared_ptr<GameBoard>>& sol) {
    if(gb->isSolution()){
        sol.push_back(gb);
        return true;
    }

    for(int i = 0; i <= 12; i++) {
        auto options = gb->moveOptions(i);
        for(auto option: options) {
            if(getSol(option, sol)) {
                sol.push_back(gb);
                return true;
            }
        }
    }

    return false;
}

void RecSolution::solve(std::shared_ptr<GameBoard> gb) {
    std::ofstream out(m_filePath, std::ios::app);

    std::vector<std::shared_ptr<GameBoard>> sol;
    if(getSol(gb, sol)) {
        std::reverse(sol.begin(), sol.end());

        for(auto i: sol) {
            out << *i << std::endl;
        }
    } else{
        out << "no solution found" << std::endl;
    }

    out << "done!" << std::endl;
}