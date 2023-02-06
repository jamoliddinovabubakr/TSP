#include <iostream>
#include "TSPTest.h"

using namespace std;

int main() {
    std::ofstream output_file_p;
    std::ofstream output_file_d;

    remove("file_1.csv");
    remove("file_2.csv");

    int tmp = 7;
    while (tmp < 12) {
        TSPTest t1(tmp);
//        t1.test_correctness();
        t1.test_permutation();
        t1.time_test_permutation();
        tmp++;
    }

    tmp = 10;
    while (tmp < 18) {
        TSPTest t1(tmp);
//        t1.test_correctness();
        t1.test_dynamic();
        t1.time_test_dynamic();
        tmp++;
    }




/*    int N;
    input_file >> N;
    int **a = new int *[N];
    for (int i = 0; i < N; i++) {
        a[i] = new int[N];
    }
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            input_file >> a[i][j];
        }
    }

    TSPTest t2(a, N);
    t2.manual_testing(33);
    t2.print_graph();*/
    return 0;
}