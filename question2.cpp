#include <iostream>
#include <queue>
#include <vector>
#include <string>
#include <sstream>
#include <algorithm>

using namespace std;

struct Task {
    string name;
    int priority;

    bool operator<(const Task& other) const {
        return priority < other.priority;
    }
};

int main() {
    int n;
    cout << "Enter the number of operations: ";
    cin >> n;
    cin.ignore();

    priority_queue<Task> maxHeap;

    vector<Task> remainingTasks;

    for (int i = 0; i < n; ++i) {
        string input;
        getline(cin, input);

        stringstream ss(input);
        string command;
        ss >> command;

        if (command == "ADD") {
            string taskName;
            int priority;
            ss >> taskName >> priority;
            maxHeap.push({ taskName, priority });
        }
        else if (command == "GET") {
            if (!maxHeap.empty()) {
                Task topTask = maxHeap.top();
                maxHeap.pop();
                cout << topTask.name << endl;
            }
            else {
                cout << "No tasks available" << endl;
            }
        }
    }

    while (!maxHeap.empty()) {
        remainingTasks.push_back(maxHeap.top());
        maxHeap.pop();
    }

    sort(remainingTasks.begin(), remainingTasks.end(), [](const Task& a, const Task& b) {
        return a.priority > b.priority;
        });

    cout << "Remaining tasks: [";
    for (size_t i = 0; i < remainingTasks.size(); ++i) {
        cout << "('" << remainingTasks[i].name << "', " << remainingTasks[i].priority << ")";
        if (i < remainingTasks.size() - 1) cout << ", ";
    }
    cout << "]" << endl;

    return 0;
}
