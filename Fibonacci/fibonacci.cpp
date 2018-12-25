#include <math.h>
#include <algorithm>
#include <chrono>
#include <cstdlib>
#include <deque>
#include <functional>
#include <iostream>
#include <iterator>
#include <list>
#include <map>
#include <numeric>
#include <set>
#include <string>
#include <vector>

long long f1(long long n) {
    if (n <= 1) return n;
    return f1(n - 1) + f1(n - 2);
}

long long f2(long long n) {
    if (n <= 1) return n;
    std::vector<long long> vec(n + 1, 0);
    vec[0] = 0;
    vec[1] = 1;
    for (long long i = 2; i < n + 1; ++i) vec[i] = vec[i - 1] + vec[i - 2];

    return vec.back();
}

long long f3(long long n) {
    double sqrt5 = std::sqrt(5);

    return std::llroundl(1 / sqrt5 * std::pow((1 + sqrt5) / 2.0, n));
}

int main() {
    using namespace std::chrono;
    int a = 10;
    auto start = high_resolution_clock::now();
    std::cout << "Brute force: \n";
    std::cout << f1(a) << std::endl;
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);
    std::cout << "Running time: " << duration.count() << std::endl;
    start = high_resolution_clock::now();
    std::cout << "Dynamic programing: \n";
    std::cout << f2(a) << std::endl;
    stop = high_resolution_clock::now();
    duration = duration_cast<microseconds>(stop - start);
    std::cout << "Running time: " << duration.count() << std::endl;
    start = high_resolution_clock::now();
    std::cout << "Analytical: \n";
    std::cout << f3(a) << std::endl;
    stop = high_resolution_clock::now();
    duration = duration_cast<microseconds>(stop - start);
    std::cout << "Running time: " << duration.count() << std::endl;

    return 0;
}
