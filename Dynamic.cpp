#include "Dynamic.h"

Dynamic::Dynamic(int **arr, int V) {
    graph = arr;
    N = V;
}

/*
void Dynamic::print_graph() {
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            std::cout << graph[i][j] << " ";
        }
        std::cout << std::endl;
    }
}
*/

void Dynamic::dynamic() {
    start_time = clock();
    std::vector<std::vector<int>> d((1 << N), std::vector<int>(N, INT_MAX));
    d[0][0] = 0;
    for (int mask = 0; mask < (1 << N); mask++) {
        for (int i = 0; i < N; i++) {
            if (d[mask][i] == INT_MAX)
                continue;
            for (int j = 0; j < N; j++) {
                steps += 1;
                if (!(mask & (1 << j)))
                    d[mask ^ (1 << j)][j] = std::min(d[mask ^ (1 << j)][j], d[mask][i] + graph[i][j]);
            }
        }
    }
    end_time = clock() - start_time;
    path = d[(1 << N) - 1][0];
}


void Dynamic::time_divide_to_steps() {
    std::cout << ((double) end_time / CLOCKS_PER_SEC) / double(steps) << std::endl;
}