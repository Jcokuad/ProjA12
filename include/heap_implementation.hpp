#pragma once
#include <functional>    // defines std::less
#include <vector>
#include <utility>  // for std::swap

namespace dsac::priority {
// min-heap by default given by the Compare = std::less<Entry>
template <typename Entry, typename Compare=std::less<Entry>>

class HeapPriorityQueue {
    protected:
        std::vector<Entry> data;

        Compare less_than;

        int parent(int j) const {
            return (j-1) / 2;
        }

        int left(int j) const {
            return 2 * j + 1;
        }

        int right(int j) const {
            return 2 * j + 2;
        }

        bool has_left(int j) const {
            return left(j) < data.size();
        }

        bool has_right(int j) const {
            return right(j) < data.size();
        }

        void upheap(int j) {
            // continue to root (or break statement)
            while (j > 0) {
                int p{parent(j)};

                // if j's entry is less than its parent
                if (less_than(data[j], data[p])) {
                    std::swap(data[j], data[p]);

                    // continue from new location after the swap
                    j = p;
                } else 
                    break;
            }
        }

        void downheap(int j) {
            // continue to bottom (or break statement)
            while (has_left(j)) {

                // although right may be smaller
                int small_child{left(j)};
                if (has_right(j)) {
                    if (less_than(data[right(j)], data[left(j)])) {
                        small_child = right(j);
                    }
                }

                // if small child's entry is less than j's
                if (less_than(data[small_child], data[j])) {
                    std::swap(data[j], data[small_child]);

                    // continue from the new location after the swap
                    j = small_child;
                } else
                    break;
            }
        }

        void heapify() {
            if(data.empty()) {
                return;
            }

            // start at PARENT of last entry
            int start{parent(data.size()-1)};

            // loop until processing the root
            for (int j = start; j >= 0; j--) {
                downheap(j);
            }
        }

    public:
        HeapPriorityQueue() = default;

        // Creates a priority queue populated with the given entries
        HeapPriorityQueue(const std::vector<Entry>& contents) {
            data = contents;
            heapify();
        }

        int size() const {
            return static_cast<int>(data.size());
        }

        bool empty() const {
            return data.empty();
        }

        const Entry& min() const {
            return data.front();
        }

        void insert(const Entry& e) {
            // add to the end of the vector
            data.push_back(e);

            // upheap newly added entry
            upheap(static_cast<int>(data.size()) - 1);
        }

        void remove_min() {
            std::swap(data[0], data[data.size() - 1]);
            data.pop_back();
            if (!data.empty()) {
                downheap(0);
            }
        }
};

}