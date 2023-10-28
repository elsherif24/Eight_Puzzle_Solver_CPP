# Eight Puzzle Solver Using C++, SFML

## Introduction:

Given an initial state of the board, the problem is to find a sequence of moves that transitions this state to the goal
state;
that is, the configuration with all tiles arranged in ascending order
$0, 1, 2, 3, 4, 5, 6, 7, 8$ using search algorithms BFS, DFS, and A-Star with Manhattan and Euclidean as heuristic
functions.

|   | 1 | 2 |
|---|---|---|
| 3 | 4 | 5 |
| 6 | 7 | 8 |

## Demo:

https://github.com/el-sharif-mohamed22/Eight_Puzzle_Solver_C/assets/95565086/9d424c75-5bcb-4349-8cf3-44c89b551126

### How to run:

1. Enter the state from the keyboard as one string without spaces, and append it with a letter from:
    1. d, for DFS.
    2. b for BFS.
    3. e for A* using euclidean heuristic.
    4. m, for A* using manhattan heuristic
2. Click the button `Start Search`.
3. Use arrows `left` & `right` arrow for navigation between states.
4. Use `backspace` to remove the current state and put another one.

## State representation:

To maximize utilization of performance, the state of the board ($3 * 3$ grid) is represented using an 32-bit integer.
The 32-bit integer is divided into eight 4-bit sections, each section represents where the number is in the board.

```mermaid
timeline
    title 32-bit integer representation of the board
    Position of 7 in board: 4-bit section 7
    Position of 6 in board: 4-bit section 6
    Position of 5 in board: 4-bit section 5
    Position of 4 in board: 4-bit section 4
    Position of 3 in board: 4-bit section 3
    Position of 2 in board: 4-bit section 2
    Position of 1 in board: 4-bit section 1
    Position of 0 in board: 4-bit section 0
```

> Note: The number 8 wasn't stored in the 32-bit integer because it is not needed to represent the state of the board.

### State Calculations:

* To get the position of zero in the board, the 32-bit integer is masked with `0xF`.
* Then the neighboring positions are calculated and become targets.
* The target is then swapped with the position of zero in the board.
* This operation takes at most $4$ operations for searching where is the targets in the integer.
* Time complexity is $O(1)$.

## Used Date Structures:

Table of data structures used in the project.

| Data Structure        | Description                                                                                                  |
|-----------------------|--------------------------------------------------------------------------------------------------------------|
| `std::vector`         | It was mainly used in the implementation. It was used to store state grid, neighbors data, and path to goal. |
| `std::unordered_set`  | Used to store the nodes in the explored set.                                                                 |
| `std::unordered_map`  | Used to store the parent of the node.                                                                        |
| `std::queue`          | Used as the frontier in BFS.                                                                                 |
| `std::stack`          | Used as the frontier in DFS.                                                                                 |
| `std::priority_queue` | Used to store the nodes in the frontier for A* algorithm.                                                    |

## Used Algorithms:

| Algorithm | Description                                                                                                                                                                                                                                                                                        |
|-----------|----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|
| BFS       | It explores the states by visiting the shallowest nodes in the graph. It depends on FIFO for expanding the nodes and uses a queue for its implementation.                                                                                                                                          |
| DFS       | It explores the states by visiting the deepest nodes in the graph. It depends on LIFO for expanding and uses stack for its implementation.                                                                                                                                                         |
| A*        | It explores the states by visiting the lowest cost nodes in the graph and gets the shortest path to the goal using a heuristic function to get an estimation to the goal. It uses priority queue for its implementations. And for the heuristics it uses Manhattan and Euclidean for calculations. |

## Heuristic Functions:

### Theoretically:

| Manhattan Distance                                                                                                                        | Euclidean Distance                                                                                                                                |
|-------------------------------------------------------------------------------------------------------------------------------------------|---------------------------------------------------------------------------------------------------------------------------------------------------|
| It is the sum of absolute values of differences in the goal’s x and y coordinates and the current cell’s x and y coordinates respectively | It is the distance between the current cell and the goal cell using the distance formula.$h = \sqrt{(cell.x - goal.x)^2 + (cell.y - goal:y)^2 }$. |
| Simple to calculate and efficient for grid-based environments.                                                                            | More computationally expensive than Manhattan distance.                                                                                           |
| Admissible for grid-based environments( never overestimates true cost but it may do in non-grid-based environments).                      | Admissible as it gets a more accurate estimation of true cost in open spaces.                                                                     |

### Practically: on average run of 500 permutations.

|                | Manhattan Distance | Euclidean Distance |
|----------------|--------------------|--------------------|
| Nodes Expanded | 1391.3             | 2079.17            |
| Cost of path   | 21.6957            | 21.6957            |
| Search depth   | 21.6957            | 21.6957            |
| Running time   | 2.88933            | 5.41897 ms         |

> Note that Manhattan Distance is more admissible.

## Tie breaking policy:

* Tie breaking policy, neighbors investigating order when a tie:
    * Up.
    * Down.
    * Left.
    * Right.
* For DFS the neighbors are reversed because stack is LIFO.
* For the A* algorithm when nodes have equal cost then it depends on the `priority queue` how it does sort the states.

## Class Diagrams:

```mermaid
---
title: Eight Puzzle Solver
---
classDiagram
    Algorithm <|-- DFS
    Algorithm <|-- BFS
    Algorithm <|-- AStarMan
    Algorithm <|-- AStarEuc
    class DFS {
        -HashSet explored
        -Hashmap parentMap
        -Stack frontier
        -Bool dfs()
    }
    class BFS {
        -HashSet explored
        -Hashmap parentMap
        -Queue frontier
        -Bool bfs()
    }
    class AStarMan {
        -HashSet explored
        -Hashmap parentMap
        -Queue frontier
        -Bool AStarMan()
        -int manhattanDistance()
    }
    class AStarEuc {
        -HashSet explored
        -Hashmap parentMap
        -Queue frontier
        -Bool AStarMan()
        -int euclideanDistance()
    }
    class Algorithm {
        +Path
        +costOfPath
        +nodesExpanded
        +searchDepth
        +runningTime
        +search()*
    }
```

## Optimizations:

* Used 32-bit integer for state representation, and bitwise operations.
* Neighbors are precomputed for every zero position, leads to $O(1)$.
* Used the `parent-map` (search tree) to find out if the state is in the `frontier` in $O(1)$.
* `Maximum Depth Search` is calculated within the frontier instead of iterating the whole search tree.
* The omission of storing the eight position in the state, this led to a problem of calculating it.
    * But the usage of the addition to find its position while calculating the differences in the other positions. Led
      to the same complexity as if we stored it.
* Used unit testing to test optimized manhattan distance functions.

## Sample Runs:

| State            | DFS                                                                                                                                 | BFS                                                                                                                                 | A* Euclidean                                                                                                                        | A* Manhattan                                                                                                                        |
|------------------|-------------------------------------------------------------------------------------------------------------------------------------|-------------------------------------------------------------------------------------------------------------------------------------|-------------------------------------------------------------------------------------------------------------------------------------|-------------------------------------------------------------------------------------------------------------------------------------|
| No Solution      | ![no_sol (1)](https://github.com/el-sharif-mohamed22/Eight_Puzzle_Solver_C/assets/95565086/5721df8b-4cdf-41a8-b2a4-c163eac0d870)    | ![no_sol (2)](https://github.com/el-sharif-mohamed22/Eight_Puzzle_Solver_C/assets/95565086/789af347-82c1-4017-a042-eb8ba5144eb0)    | ![no_sol (3)](https://github.com/el-sharif-mohamed22/Eight_Puzzle_Solver_C/assets/95565086/18721a9e-efdb-44bd-a77b-ee89e6d7c6d1)    | ![no_sol (4)](https://github.com/el-sharif-mohamed22/Eight_Puzzle_Solver_C/assets/95565086/6e2769d9-7348-40d0-a989-cf7e9d16367b)    |
| DFS inefficiency | ![dfs_ineff (1)](https://github.com/el-sharif-mohamed22/Eight_Puzzle_Solver_C/assets/95565086/d54308d7-4a54-40f8-9792-0a11dd8d3b21) | ![dfs_ineff (2)](https://github.com/el-sharif-mohamed22/Eight_Puzzle_Solver_C/assets/95565086/c1ee071a-83d3-48ab-8213-53b92af5b0e9) | ![dfs_ineff (3)](https://github.com/el-sharif-mohamed22/Eight_Puzzle_Solver_C/assets/95565086/a7fa50ac-333a-4182-bb9b-47429ce6eb34) | ![dfs_ineff (4)](https://github.com/el-sharif-mohamed22/Eight_Puzzle_Solver_C/assets/95565086/c421a4f1-1b98-4c5c-a57d-e571d8d599ec) |
| Start            | ![start (1)](https://github.com/el-sharif-mohamed22/Eight_Puzzle_Solver_C/assets/95565086/4f7fa296-35d4-4b93-9e76-9cd6a1bf4d3c)     | ![start (2)](https://github.com/el-sharif-mohamed22/Eight_Puzzle_Solver_C/assets/95565086/dfbe824b-bde9-4454-9555-aa4e3fa6467f)     | ![start (3)](https://github.com/el-sharif-mohamed22/Eight_Puzzle_Solver_C/assets/95565086/0fc5f890-e353-4860-9254-b805e1b08278)     | ![start (4)](https://github.com/el-sharif-mohamed22/Eight_Puzzle_Solver_C/assets/95565086/543f5452-d424-4d32-87bb-c76f98cc252d)     |
| DFS Best         | ![dfs_best (1)](https://github.com/el-sharif-mohamed22/Eight_Puzzle_Solver_C/assets/95565086/868c049e-2238-4b44-9db3-73bad9169cbf)  | ![dfs_best (2)](https://github.com/el-sharif-mohamed22/Eight_Puzzle_Solver_C/assets/95565086/99b004a4-33ec-47f5-9981-61e61de38e85)  | ![dfs_best (3)](https://github.com/el-sharif-mohamed22/Eight_Puzzle_Solver_C/assets/95565086/831bf181-142c-46f1-9e10-ec8496908d33)  | ![dfs_best (4)](https://github.com/el-sharif-mohamed22/Eight_Puzzle_Solver_C/assets/95565086/9001e635-8702-4b7b-ac42-3c75966fef50)  |
| Cost 28          | ![cost_28_1 (1)](https://github.com/el-sharif-mohamed22/Eight_Puzzle_Solver_C/assets/95565086/7993e3fb-ed2b-4b99-a7e3-cede622ead84) | ![cost_28_1 (2)](https://github.com/el-sharif-mohamed22/Eight_Puzzle_Solver_C/assets/95565086/ba3d2d2a-86a7-4a9d-ab12-ccc9a27805b1) | ![cost_28_1 (3)](https://github.com/el-sharif-mohamed22/Eight_Puzzle_Solver_C/assets/95565086/049bafb6-3868-4e2a-acfa-64da028673f2) | ![cost_28_1 (4)](https://github.com/el-sharif-mohamed22/Eight_Puzzle_Solver_C/assets/95565086/88528646-a93c-412a-953a-92700d6c1f61) |
| Cost 28          | ![cost_28_2 (1)](https://github.com/el-sharif-mohamed22/Eight_Puzzle_Solver_C/assets/95565086/c5933b5f-7220-4b4f-805e-846f51b78db6) | ![cost_28_2 (2)](https://github.com/el-sharif-mohamed22/Eight_Puzzle_Solver_C/assets/95565086/2e1319d7-143a-41bf-be76-6818f9666a84) | ![cost_28_2 (3)](https://github.com/el-sharif-mohamed22/Eight_Puzzle_Solver_C/assets/95565086/46a66c76-2140-414f-a89b-799b32aa77eb) | ![cost_28_2 (4)](https://github.com/el-sharif-mohamed22/Eight_Puzzle_Solver_C/assets/95565086/872a2c00-45c9-4c3a-817b-30909faa1087) |
| invalid          |             ![invalid (1)](https://github.com/el-sharif-mohamed22/Eight_Puzzle_Solver_C/assets/95565086/c15d8bf1-605f-4221-9291-8d9793a4bf5c)
                                                                                                                        |                                                                                                                                     |                     ![invalid (2)](https://github.com/el-sharif-mohamed22/Eight_Puzzle_Solver_C/assets/95565086/282bdf9d-a285-4a92-a1fb-e7f905cb169c)
                                                                                                                |                                                                                                                                     |
