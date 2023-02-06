#include "Permutation.h"

Permutation::Permutation(int **arr, int V) {
    graph = arr;
    N = V;
}


/*
void Permutation::print_graph() {
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            std::cout << graph[i][j] << " ";
        }
        std::cout << "\n";
    }
}
*/

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

/*
        for (int i = 0; i < vertex.size(); i++) {
            current_path_weight += graph[k][vertex[i]];
            k = vertex[i];
            tmp.push_back(k);
            steps += 1;
        }
*/

        for (int i: vertex) {
            current_path_weight += graph[k][i];
            k = i;
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

#include <fstream>

using namespace std;

void Permutation::time_divide_to_steps() {
    std::ofstream output_file_p;
    output_file_p.open("file_1.csv", ios::app);
    output_file_p << (double) end_time / CLOCKS_PER_SEC << ",";
    output_file_p << steps << ",";
    output_file_p << ((double) end_time / CLOCKS_PER_SEC) / double(steps) << "\n";
}