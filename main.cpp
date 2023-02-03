#include <iostream>
#include "TSPTest.h"

int main() {
    std::ifstream input_file("input_file.txt");

    int tmp = 1;
    while (tmp < 12) {
        TSPTest t1(tmp);
        t1.min_path_test();
        tmp++;
    }

//    int N;
//    input_file >> N;
//    int **a = new int *[N];
//    for (int i = 0; i < N; i++) {
//        a[i] = new int[N];
//    }
//    for (int i = 0; i < N; i++) {
//        for (int j = 0; j < N; j++) {
//            input_file >> a[i][j];
//        }
//    }
//
//    TSPTest t2(a, N);
//    t2.manual_testing(33);
//    t2.print_graph();
    return 0;
}