#include <iostream>
#include <chrono>
#include <iomanip>
#include <random>
#include <algorithm>
#include <iterator>
#include <vector>
#include <fstream>

#include "quick_sort.h"
#include "merge_sort.h"
#include "heap_sort.h"
#include "cocktail_sort.h"
#include "counting_sort.h"

using namespace std;

int main() {
//    random_device rnd_device;
//    mt19937 mersenne_engine {rnd_device()};
//    uniform_int_distribution<int> dist {-1000000000, 1000000000};
//
//    auto gen = [&dist, &mersenne_engine](){
//        return dist(mersenne_engine);
//    };
//
//    vector<int> vec(100000);
//    generate(begin(vec), end(vec), gen);
//
//    fstream file("array.txt");
//
//    for (auto i : vec) file << i << " ";
//    file.close();

    vector<int> arr;
    fstream file("../array.txt");
    string nr;
    while (!file.eof()) {
        file >> nr;
        arr.emplace_back(std::stoi(nr));
    }
    file.close();

    vector<int>::const_iterator start = arr.begin();
    vector<int>::const_iterator end = arr.end();
    vector<int> endarr(start, end);

    auto start_timer = chrono::high_resolution_clock::now();
    ios_base::sync_with_stdio(false);

    countSort(endarr);

    auto end_timer = chrono::high_resolution_clock::now();

    double time_taken =
            chrono::duration_cast<chrono::nanoseconds>(end_timer - start_timer).count();

    time_taken *= 1e-9;
    cout << time_taken << setprecision(4) << endl;
}
