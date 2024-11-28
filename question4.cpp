#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Task {
    int profit;
    int deadline;
};

int scheduleTasks(vector<Task>& tasks, vector<int>& scheduledTasks) {
    sort(tasks.begin(), tasks.end(), [](const Task& a, const Task& b) {
        return a.profit > b.profit;
        });

    int maxDeadline = 0;
    for (const auto& task : tasks) {
        maxDeadline = max(maxDeadline, task.deadline);
    }

    vector<int> slots(maxDeadline, -1);
    int totalProfit = 0;

    for (const auto& task : tasks) {
        for (int j = task.deadline - 1; j >= 0; --j) {
            if (slots[j] == -1) {
                slots[j] = task.profit;
                scheduledTasks.push_back(task.profit);
                totalProfit += task.profit;
                break;
            }
        }
    }

    return totalProfit;
}

int main() {
    int n;
    cout << "Enter the number of tasks: ";
    cin >> n;

    vector<Task> tasks(n);
    cout << "Enter the profit and deadline for each task:" << endl;
    for (int i = 0; i < n; ++i) {
        cin >> tasks[i].profit >> tasks[i].deadline;
    }

    vector<int> scheduledTasks;
    int maxProfit = scheduleTasks(tasks, scheduledTasks);

    cout << "Maximum Profit: " << maxProfit << endl;
    cout << "Scheduled Tasks: [";
    for (size_t i = 0; i < scheduledTasks.size(); ++i) {
        cout << scheduledTasks[i];
        if (i < scheduledTasks.size() - 1) cout << ", ";
    }
    cout << "]" << endl;

    return 0;
}
