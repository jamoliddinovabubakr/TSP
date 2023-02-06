#include "TSPTest.h"


TSPTest::TSPTest(int V) {
    N = V;
    arr = new int *[N];
    for (int i = 0; i < N; i++) {
        arr[i] = new int[N];
    }
    int n = 0;
    for (int k = 0; k < N; k++) {
        for (; n < N; n++) {
            if (k == n) {
                arr[k][n] = 0;
                continue;
            }
            arr[k][n] = rand() % 10 + 5;
            arr[n][k] = arr[k][n];
        }
        n = k;
    }
}

TSPTest::TSPTest(int **graph, int V) {
    arr = graph;
    N = V;
}

void TSPTest::time_test_permutation() {
    Permutation p(arr, N);
    p.permutation();
    p.time_divide_to_steps();
}


void TSPTest::time_test_dynamic() {
    Dynamic d(arr, N);
    d.dynamic();
    d.time_divide_to_steps();
}


void TSPTest::time_test() {
    Permutation p(arr, N);
    Dynamic d(arr, N);
    p.permutation();
    d.dynamic();
    p.time_divide_to_steps();
    d.time_divide_to_steps();
}

void TSPTest::print_graph() {
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            std::cout << arr[i][j] << " ";
        }
        std::cout << "\n";
    }
}

void TSPTest::test_dynamic() {
    Dynamic d_test(arr, N);
    d_test.dynamic();
}

void TSPTest::test_permutation() {
    Dynamic d_test(arr, N);
    d_test.dynamic();
}

void TSPTest::test_correctness() {
    Permutation p_test(arr, N);
    Dynamic d_test(arr, N);
    p_test.permutation();
    d_test.dynamic();

    if (p_test.traversed.size() == N) {
        // to do make it linear status: done
        std::vector<bool> visited(N); // to do init with false
        for (int i = 0; i < N; ++i) {
            visited[i] = false;
        }
        for (int i: p_test.traversed) {
            if (visited[i]) {
                std::cout << "error";
                break;
            }
            visited[i] = true;
        }
    }

/*
            for (int i = 0; i < N; ++i) {
                for (int j = i + 1; j < N; ++j) {
                    if (p_test.traversed[i] == p_test.traversed[j]) {
                        std::cout << "Error";
                    }
                }
            }
        std::cout << p_test.path << '\n';
*/

    if (p_test.path != d_test.path) {
        std::cout << "Error" << std::endl;
    }
}


void TSPTest::manual_testing(int path) {
    Permutation p_test(arr, N);
    Dynamic d_test(arr, N);
    p_test.permutation();
    d_test.dynamic();
    if (!(p_test.path == d_test.path && path == d_test.path)) {
        std::cout << "Error in manual testing function!" << std::endl;
        std::cout << p_test.path << " != " << path << std::endl;
    }
}