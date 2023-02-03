#include <iostream>
#include <vector>
#include "TSPTest.h"

int main() {
    std::ifstream input_file("input_file.txt");

    int N;
//    input_file >> N;
    std::cin >> N;
    int **a = new int *[N];
    for (int i = 0; i < N; i++) {
        a[i] = new int[N];
    }

//    for (int i = 0; i < N; i++) {
//        for (int j = 0; j < N; j++) {
//            input_file >> a[i][j];
//        }
//    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            std::cin >> a[i][j];
        }
    }


    int tmp = 1;
    while (tmp < 12) {
        TSPTest t1(tmp);
        t1.min_path_test();
        tmp++;
    }


    return 0;
}