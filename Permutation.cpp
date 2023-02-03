//
// Created by user on 1/21/2023.
//

#include "Permutation.h"


Permutation::Permutation(int **arr, int V) {
    graph = arr;
    N = V;
}

Permutation::Permutation(int V) {
    N = V;
    graph = new int *[N];
    for (int i = 0; i < N; i++) {
        graph[i] = new int[N];
    }
    int n = 0;
    for (int k = 0; k < N; k++) {
        for (; n < N; n++) {
            if (k == n) {
                graph[k][n] = 0;
                continue;
            }
            graph[k][n] = rand() % 10 + 3;
            graph[n][k] = graph[k][n];
        }
        n = k;
    }
}

void Permutation::print_graph() {
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            std::cout << graph[i][j] << " ";
        }
        std::cout << "\n";
    }
}

void Permutation::permutation() {
    start_time = clock();
    int count = 0;
    int s = 0;
    std::vector<int> vertex;
    for (int i = 0; i < N; i++)
        if (i != s)
            vertex.push_back(i);
    int min_path = INT_MAX;
    do {
        std::vector<int> tmp;
        count++;
        int current_path_weight = 0;
        int k = s;
        tmp.push_back(k);
        for (int i = 0; i < vertex.size(); i++) {
            current_path_weight += graph[k][vertex[i]];
            k = vertex[i];
            tmp.push_back(k);
            steps += 1;
        }
        current_path_weight += graph[k][s];
        if (min_path > current_path_weight) {
            min_path = current_path_weight;
            traversed = tmp;
        }
    } while (next_permutation(vertex.begin(), vertex.end()));
    end_time = clock() - start_time;
    path = min_path;
}

void Permutation::time_divide_to_steps() {
    std::cout << ((double) end_time / CLOCKS_PER_SEC) / double(steps) << std::endl;
}