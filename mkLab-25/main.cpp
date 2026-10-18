#include <iostream>
#include <chrono>
using namespace std;
#include <string>
#include <vector>
#include <list>
#include <set>
#include <chrono>
#include <algorithm>
#include <iomanip>

int main() {
    vector<string> v;
    list<string> l;
    set<string> s;

    long long read_v = 0, read_l = 0, read_s = 0;
    long long sort_v = 0, sort_l = 0, sort_s = -1; // set is already sorted
    long long insert_v = 0, insert_l = 0, insert_s = 0;
    long long delete_v = 0, delete_l = 0, delete_s = 0;

    string line;
    //Race 1
    ifstream file1("codes.txt");
    auto start = high_resolution_clock::now();
    while (getline(file1, line)) {
        v.push_back(line);
    }
    auto end = high_resolution_clock::now();
    read_v = duration_cast<nanoseconds>(end - start).count();
    file1.close();

    ifstream file2("codes.txt");
    start = high_resolution_clock::now();
    while (getline(file2, line)) {
        l.push_back(line);
    }
    end = high_resolution_clock::now();
    read_l = duration_cast<nanoseconds>(end - start).count();
    file2.close();

    ifstream file3("codes.txt");
    start = high_resolution_clock::now();
    while (getline(file3, line)) {
        s.insert(line);
    }
    end = high_resolution_clock::now();
    read_s = duration_cast<nanoseconds>(end - start).count();
    file3.close();

    //Race 2
    start = high_resolution_clock::now();
    sort(v.begin(), v.end());
    end = high_resolution_clock::now();
    sort_v = duration_cast<nanoseconds>(end - start).count();

    start = high_resolution_clock::now();
    l.sort();
    end = high_resolution_clock::now();
    sort_l = duration_cast<nanoseconds>(end - start).count();


    return 0;
}

/* syntax examples:
auto start = high_resolution_clock::now()
auto end = high_resolution_clock::now()
auto duration = duration_cast<milliseconds>(end - start)
duration.count() references elapsed milliseconds
*/