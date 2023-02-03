#include <iostream>
#include <vector>
#include <algorithm>
#include <ctime>
#include <fstream>


class Dynamic {
private:
    int **graph;  // graph
    int N; // number of vertices
    int steps = 0;
    unsigned int start_time = 0;
    unsigned int end_time = 0;
public:
    int path;// store the minimum path

    Dynamic(int **arr, int V);

    // find the minimum path
    void dynamic();

    // time divide to steps
    void time_divide_to_steps();

};