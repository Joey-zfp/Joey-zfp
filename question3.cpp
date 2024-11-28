#include <iostream>
#include <vector>
#include <queue>
#include <tuple>
#include <string>
#include <sstream>

using namespace std;

struct Element {
    int value;
    int arrayIndex;
    int elementIndex;

    bool operator>(const Element& other) const {
        return value > other.value;
    }
};

vector<int> mergeKSortedArrays(vector<vector<int>>& arrays) {
    priority_queue<Element, vector<Element>, greater<Element>> minHeap;
    vector<int> mergedArray;

    for (int i = 0; i < arrays.size(); ++i) {
        if (!arrays[i].empty()) {
            minHeap.push({ arrays[i][0], i, 0 });
        }
    }

    while (!minHeap.empty()) {
        Element current = minHeap.top();
        minHeap.pop();

        mergedArray.push_back(current.value);

        int nextIndex = current.elementIndex + 1;
        if (nextIndex < arrays[current.arrayIndex].size()) {
            minHeap.push({ arrays[current.arrayIndex][nextIndex], current.arrayIndex, nextIndex });
        }
    }

    return mergedArray;
}

int main() {
    int k;
    cout << "Enter the number of sorted arrays (K): ";
    cin >> k;

    vector<vector<int>> arrays(k);
    cout << "Enter each sorted array on a new line:" << endl;
    cin.ignore();

    for (int i = 0; i < k; ++i) {
        string line;
        getline(cin, line);
        stringstream ss(line);
        int num;
        while (ss >> num) {
            arrays[i].push_back(num);
        }
    }

    vector<int> mergedArray = mergeKSortedArrays(arrays);

    cout << "Merged Array: [";
    for (size_t i = 0; i < mergedArray.size(); ++i) {
        cout << mergedArray[i];
        if (i < mergedArray.size() - 1) cout << ", ";
    }
    cout << "]" << endl;

    return 0;
}
