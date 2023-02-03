#include <iostream>
#include <vector>
#include <algorithm>
#include <ctime>
#include <fstream>


class Dynamic {
private:
    int **graph;
    int N;
    int steps = 0;
    unsigned int start_time = 0;
    unsigned int end_time = 0;
public:
    int path;
    Dynamic(int V);

    Dynamic(int **arr, int V);

    void print_graph();

    void dynamic();

    void time_divide_to_steps();

};