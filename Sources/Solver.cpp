//
// Created by Al-Sh on 10/25/2023.
//



#include "../Headers/Solver.h"

bool verifyInput(std::string& input) {
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
    if (basicString.back() == 'd') {
        DFS dfs = DFS(grid);
        try {
            dfs.search();
        } catch (std::exception& e) {
            info.setString(e.what());
            return;
        }
        vector1 = dfs.path;
        std::stringstream report;
        report << "DFS\n";
        report << "Cost of Path: " << dfs.costOfPath << "\n";
        report << "Nodes Expanded: " << dfs.nodesExpanded << "\n";
        report << "Max Depth Search: " << dfs.maxDepthSearch << "\n";
        report << "Running Time: " << dfs.runningTime << " ms\n";
        info.setString(report.str());
    } else if (basicString.back() == 'b') {
        BFS bfs = BFS(grid);
        try {
            bfs.search();
        } catch (std::exception& e) {
            info.setString(e.what());
            return;
        }
        vector1 = bfs.path;
        std::stringstream report;
        report << "BFS\n";
        report << "Cost of Path: " << bfs.costOfPath << "\n";
        report << "Nodes Expanded: " << bfs.nodesExpanded << "\n";
        report << "Max Depth Search: " << bfs.maxDepthSearch << "\n";
        report << "Running Time: " << bfs.runningTime << " ms\n";
        info.setString(report.str());
    } else if (basicString.back() == 'm') {
        AStarMan aStarMan = AStarMan(grid);
        try {
            aStarMan.search();
        } catch (std::exception& e) {
            info.setString(e.what());
            return;
        }
        vector1 = aStarMan.path;
        std::stringstream report;
        report << "A* with Manhattan Distance\n";
        report << "Cost of Path: " << aStarMan.costOfPath << "\n";
        report << "Nodes Expanded: " << aStarMan.nodesExpanded << "\n";
        report << "Max Depth Search: " << aStarMan.maxDepthSearch << "\n";
        report << "Running Time: " << aStarMan.runningTime << " ms\n";
        info.setString(report.str());
    } else if (basicString.back() == 'e') {
        AStarEuc aStarEuc = AStarEuc(grid);
        try {
            aStarEuc.search();
        } catch (std::exception& e) {
            info.setString(e.what());
            return;
        }
        vector1 = aStarEuc.path;
        std::stringstream report;
        report << "A* with Euclidean Distance\n";
        report << "Cost of Path: " << aStarEuc.costOfPath << "\n";
        report << "Nodes Expanded: " << aStarEuc.nodesExpanded << "\n";
        report << "Max Depth Search: " << aStarEuc.maxDepthSearch << "\n";
        report << "Running Time: " << aStarEuc.runningTime << " ms\n";
        info.setString(report.str());
    }
    
}
