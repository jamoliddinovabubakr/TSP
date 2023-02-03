#include <iostream>
#include <vector>
#include <algorithm>
#include <ctime>
#include <fstream>

class Permutation {
private:
    int **graph;
    int N;
    int steps = 0;
    unsigned int start_time = 0;
    unsigned int end_time = 0;
public:
    int path;
    std::vector<int> traversed;
    Permutation(int V);

    Permutation(int **arr, int V);

    void print_graph();

    void permutation();

    void time_divide_to_steps();
};