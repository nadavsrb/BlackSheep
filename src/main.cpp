#include "GameBoard.hpp"
#include "RecSolution.hpp"
#include <memory>
#include <string>
#include <iostream>
#include <exception>

using namespace game;

int main() {
    try {

    std::shared_ptr<GameBoard> gb = std::make_shared<GameBoard>("problem.txt");
    std::unique_ptr<RecSolution> solution = std::make_unique<RecSolution>("solution.txt");

    solution->solve(gb);
    } catch(const std::exception& e) {
        std::cout<<e.what()<<std::endl;
    }
    return 0;
}