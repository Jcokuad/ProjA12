#pragma once

#include <vector>
#include "heap_priority_queue.hpp"

namespace dsac::priority {

int min_merge_cost(const std::vector<int>& files) {
    // Check if there are 1 or less files
    if (files.size() <= 1) {
        return 0;
    }

    // Initialize a min-heap
    HeapPriorityQueue<int> hq;

    // add all files to the heap
    for (int file_sz : files) {
        hq.insert(file_sz);
    }

    int total = 0;
    while (hq.size() > 1) {
        int first{hq.min()}; // assign the first smallest to first, then remove from heap
        hq.remove_min();

        int second{hq.min()}; // assign the next smallest to second, then remove from heap
        hq.remove_min();

        int merge = first + second; // cost of the merge is a + b
        total += merge;
        hq.insert(merge); // put the merged file back in the heap
    }

    return total;
}

}

