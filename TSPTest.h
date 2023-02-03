#include "Dynamic.h"
#include "Permutation.h"

class TSPTest {
private:
    int **arr;
    int N;
public:

    TSPTest(int V);

    TSPTest(int **graph, int V);

    void time_test();

    void min_path_test();

    void print_graph();

    // test with static // test correct
    void manual_testing(int path);
};



