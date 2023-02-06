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

    void test_correctness();

    void print_graph();

    void manual_testing(int path);

    void time_test_permutation();

    void time_test_dynamic();

    void test_dynamic();

    void test_permutation();

};



