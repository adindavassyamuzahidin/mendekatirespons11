#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <ctime>
#include <chrono>
#include <numeric>
#include <functional>
using namespace std;
using namespace std::chrono;

// --- Sorting algorithms ---
void bubbleSort(vector<int>& a) {
    int n = a.size();
    for (int i = 0; i < n - 1; ++i) {
        bool swapped = false;
        for (int j = 0; j < n - i - 1; ++j) {
            if (a[j] > a[j + 1]) {
                swap(a[j], a[j + 1]);
                swapped = true;
            }
        }
        if (!swapped) break;
    }
}

void selectionSort(vector<int>& a) {
    int n = a.size();
    for (int i = 0; i < n - 1; ++i) {
        int minIdx = i;
        for (int j = i + 1; j < n; ++j)
            if (a[j] < a[minIdx]) minIdx = j;
        swap(a[i], a[minIdx]);
    }
}

void insertionSort(vector<int>& a) {
    int n = a.size();
    for (int i = 1; i < n; ++i) {
        int key = a[i];
        int j = i - 1;
        while (j >= 0 && a[j] > key) {
            a[j + 1] = a[j];
            --j;
        }
        a[j + 1] = key;
    }
}

void mergeMerge(vector<int>& a, int l, int m, int r) {
    int n1 = m - l + 1, n2 = r - m;
    vector<int> L(n1), R(n2);
    for (int i = 0; i < n1; ++i) L[i] = a[l + i];
    for (int j = 0; j < n2; ++j) R[j] = a[m + 1 + j];
    int i = 0, j = 0, k = l;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) a[k++] = L[i++];
        else a[k++] = R[j++];
    }
    while (i < n1) a[k++] = L[i++];
    while (j < n2) a[k++] = R[j++];
}

void mergeSortRec(vector<int>& a, int l, int r) {
    if (l >= r) return;
    int m = l + (r - l) / 2;
    mergeSortRec(a, l, m);
    mergeSortRec(a, m + 1, r);
    mergeMerge(a, l, m, r);
}

void mergeSort(vector<int>& a) { mergeSortRec(a, 0, a.size() - 1); }

int partitionQS(vector<int>& a, int low, int high) {
    int pivot = a[low + (high - low) / 2];
    int i = low, j = high;
    while (i <= j) {
        while (a[i] < pivot) ++i;
        while (a[j] > pivot) --j;
        if (i <= j) {
            swap(a[i], a[j]);
            ++i; --j;
        }
    }
    return i;
}

void quickSortRec(vector<int>& a, int low, int high) {
    if (low >= high) return;
    int idx = partitionQS(a, low, high);
    if (low < idx - 1) quickSortRec(a, low, idx - 1);
    if (idx < high) quickSortRec(a, idx, high);
}

void quickSort(vector<int>& a) { quickSortRec(a, 0, a.size() - 1); }

// --- Timing utility ---
template <typename F>
long long time_function_microsec(F sort_fn, vector<int> arr) {
    auto start = high_resolution_clock::now();
    sort_fn(arr);
    auto stop = high_resolution_clock::now();
    return duration_cast<microseconds>(stop - start).count();
}

// --- Main experiment ---
int main() {
    srand((unsigned)time(0));
    vector<int> sizes = {1000, 5000, 20000};
    int trials = 5;

    vector<pair<string, function<void(vector<int>&)>>> algos = {
        {"Bubble Sort", bubbleSort},
        {"Selection Sort", selectionSort},
        {"Insertion Sort", insertionSort},
        {"Merge Sort", mergeSort},
        {"Quick Sort", quickSort}
    };

    cout << "Eksperimen waktu pengurutan (mikrosekon)\n";
    for (int n : sizes) {
        cout << "\n=== n = " << n << " ===\n";
        vector<vector<int>> datasets(trials, vector<int>(n));
        for (int t = 0; t < trials; ++t)
            for (int i = 0; i < n; ++i)
                datasets[t][i] = rand() % 1000000;

        for (auto &algo : algos) {
            const string &name = algo.first;
            auto &fn = algo.second;
            if ((name == "Bubble Sort" || name == "Selection Sort" || name == "Insertion Sort") && n > 50000) {
                cout << name << ": SKIPPED\n"; continue;
            }
            vector<long long> times;
            for (int t = 0; t < trials; ++t)
                times.push_back(time_function_microsec(fn, datasets[t]));
            double avg = accumulate(times.begin(), times.end(), 0.0) / times.size();
            cout << name << " -> rata-rata: " << (long long)avg << " us\n";
        }
    }
    cout << "\nSelesai.\n";
    system ("pause");
}
