#pragma once

#include <vector>
#include <cmath>  // for std::sqrt and std::ceil
#include <functional>  // for std::greater
#include <algorithm> // for std::sort

namespace dsac::priority {

std::vector<int> top_sqrtN_sorted(const std::vector<int>& v) {
    const int n = static_cast<int>(v.size());
    if (n == 0) {
       return {}; // edge case checking if vector is empty 
    }

    const int k = static_cast<int>(std::ceil(std::sqrt(n))); // calculate largest k
    std::priority_queue<int, std::vector<int>, std::greater<int>> hq; // initialize min-heap

    for (int height : v) {
        if (hq.size() < k) { // fill the heap with up to k elements
            hq.push(height);
        }
        // if larger height is found, replace the smallest height in the heap
        else if (height > hq.top()) {
            hq.pop();
            hq.push(height);
        }
        // if heap is full up to k elements and curr height is not large enough, ignore
    }
    // Put heap values into a vector to be sorted in descending order
    std::vector<int> output;
    output.reserve(k); // set min vector capacity to k values, which optimizes performance by reducing # of reallocations

    while (!hq.empty()) {
        output.push_back(hq.top());
        hq.pop();
    }
    std::sort(output.begin(), output.end(), std::greater<int>()); // sorting
    return output;
}

}