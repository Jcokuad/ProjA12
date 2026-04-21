#pragma once

#include <vector>
#include <queue>
#include <functional> // for std::greater

namespace dsac::priority {

int min_merge_cost(const std::vector<int>& files) {
    // Check if there are 1 or less files
    if (files.size() <= 1) {
        return 0;
    }

    // Initialize a min-heap
    std::priority_queue<int, std::vector<int>, std::greater<int>> hq;

    // add all files to the heap
    for (int file_sz : files) {
        hq.push(file_sz);
    }

    int total = 0;
    while (hq.size() > 1) {
        int first{hq.top()}; // assign the first smallest to first, then remove from heap
        hq.pop();

        int second{hq.top()}; // assign the next smallest to second, then remove from heap
        hq.pop();

        int merge = first + second; // cost of the merge is a + b
        total += merge;
        hq.push(merge); // put the merged file back in the heap
    }

    return total;
}

}

