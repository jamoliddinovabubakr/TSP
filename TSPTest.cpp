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


void TSPTest::time_test() {
    Permutation p(arr, N);
    Dynamic d(arr, N);
    p.permutation();
    d.dynamic();
    p.time_divide_to_steps();
    d.time_divide_to_steps();
}


void TSPTest::min_path_test() {
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

/*            for (int i = 0; i < N; ++i) {
                for (int j = i + 1; j < N; ++j) {
                    if (p_test.traversed[i] == p_test.traversed[j]) {
                        std::cout << "Error";
                    }
                }
            }
        std::cout << p_test.path << '\n';*/
    if (p_test.path != d_test.path) {
        std::cout << "Error" << std::endl;
    }
}
