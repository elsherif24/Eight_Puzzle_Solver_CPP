//
// Created by Al-Sh on 10/25/2023.
//



#include <memory>
#include "../Headers/Solver.h"

bool verifyInput(std::string &input) {
    if (input.size() != 10) {
        return false;
    }
    char alg = input.back();
    if (alg != 'd' && alg != 'b' && alg != 'm' && alg != 'e') {
        return false;
    }
    std::set<char> s;
    for (int i = 0; i < 9; ++i) {
        if (input[i] < '0' || input[i] > '8') {
            return false;
        }
        s.insert(input[i]);
    }
    if (s.size() != 9)
        return false;
    return true;
}

std::unique_ptr<Algorithm> createAlgorithm(char algType, const std::vector<int> &grid, std::string &algorithmName) {
    switch (algType) {
        case 'd':
            algorithmName = "DFS";
            return std::make_unique<DFS>(grid);
        case 'b':
            algorithmName = "BFS";
            return std::make_unique<BFS>(grid);
        case 'm':
            algorithmName = "A* Manhattan";
            return std::make_unique<AStarMan>(grid);
        case 'e':
            algorithmName = "A* Euclidean";
            return std::make_unique<AStarEuc>(grid);
        default:
            throw std::invalid_argument("Invalid algorithm type");
    }
}

std::string generateReport(const Algorithm &algorithm, const std::string &algorithmName) {
    std::stringstream report;
    report << algorithmName << "\n";
    report << "Cost of Path: " << algorithm.costOfPath << "\n";
    report << "Nodes Expanded: " << algorithm.nodesExpanded << "\n";
    report << "Max Depth Search: " << algorithm.maxDepthSearch << "\n";
    report << "Running Time: " << algorithm.runningTime << " ms\n";
    return report.str();
}

void run(std::vector<std::vector<int>> &vector1, std::string basicString, sf::Text &info) {
    if (!verifyInput(basicString)) {
        info.setString("Invalid Input");
        return;
    }
    std::vector<int> grid(9);
    for (int i = 0; i < 9; ++i) {
        grid[i] = basicString[i] - '0';
    }
    // run the algorithm
    std::unique_ptr<Algorithm> algorithm;
    std::string algorithmName;
    try {
        algorithm = createAlgorithm(basicString.back(), grid, algorithmName);
        algorithm->search();
    } catch (std::exception &e) {
        std::stringstream report;
        report << algorithmName << "\n";
        report << e.what() << "\n";
        report << "Nodes Expanded: " << algorithm->nodesExpanded << "\n";
        report << "Max Depth Search: " << algorithm->maxDepthSearch << "\n";
        report << "Running Time: " << algorithm->runningTime << " ms\n";
        info.setString(report.str());
        return;
    }
    vector1 = algorithm->path;

    info.setString(generateReport(*algorithm, algorithmName));
}