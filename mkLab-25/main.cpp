#include <iostream>
#include <fstream>
#include <chrono>
using namespace std;
#include <string>
#include <vector>
#include <list>
#include <set>
#include <chrono>
#include <algorithm>
#include <iomanip>
using namespace std::chrono;

const int SIMULATIONS = 15;

int main() {
    vector<string> v;
    list<string> l;
    set<string> s;

    long long results[2][4][3] = {{{0}}};
    
    string line;
    high_resolution_clock::time_point start, end;
    for (int sim = 0; sim < SIMULATIONS; sim++) {
    v.clear(); l.clear(); s.clear();

    //Race 1
    ifstream file1("names.txt");
    start = high_resolution_clock::now();
    while (getline(file1, line)) {
        v.push_back(line);
    }
    end = high_resolution_clock::now();
    results[0][0][0] = duration_cast<nanoseconds>(end - start).count();
    file1.close();

    ifstream file2("names.txt");
    start = high_resolution_clock::now();
    while (getline(file2, line)) {
        l.push_back(line);
    }
    end = high_resolution_clock::now();
    results[0][0][1] = duration_cast<nanoseconds>(end - start).count();
    file2.close();

    ifstream file3("names.txt");
    start = high_resolution_clock::now();
    while (getline(file3, line)) {
        s.insert(line);
    }
    end = high_resolution_clock::now();
    results[0][0][2] = duration_cast<nanoseconds>(end - start).count();
    file3.close();

    //Race 2
    start = high_resolution_clock::now();
    sort(v.begin(), v.end());
    end = high_resolution_clock::now();
    results[0][1][0] = duration_cast<nanoseconds>(end - start).count();

    start = high_resolution_clock::now();
    l.sort();
    end = high_resolution_clock::now();
    results[0][1][1] = duration_cast<nanoseconds>(end - start).count();

    results[0][1][2] = -1; // Sets are sorted

    //Race 3
    start = high_resolution_clock::now();
    v.insert(v.begin() + (v.size() / 2), "TESTCODE");
    end = high_resolution_clock::now();
    results[0][2][0] = duration_cast<nanoseconds>(end - start).count();

    list<string>::iterator lit = l.begin();
    advance(lit, l.size() / 2);
    start = high_resolution_clock::now();
    l.insert(lit, "TESTCODE");
    end = high_resolution_clock::now();
    results[0][2][1] = duration_cast<nanoseconds>(end - start).count();

    start = high_resolution_clock::now();
    s.insert("TESTCODE");
    end = high_resolution_clock::now();
    results[0][2][2] = duration_cast<nanoseconds>(end - start).count();

    //Race 4
    start = high_resolution_clock::now();
    v.erase(v.begin() + (v.size() / 2));
    end = high_resolution_clock::now();
    results[0][3][0] = duration_cast<nanoseconds>(end - start).count();

    lit = l.begin();
    advance(lit, l.size() / 2);
    start = high_resolution_clock::now();
    l.erase(lit);
    end = high_resolution_clock::now();
    results[0][3][1] = duration_cast<nanoseconds>(end - start).count();

    set<string>::iterator sit = s.begin();
    advance(sit, s.size() / 2);
    start = high_resolution_clock::now();
    s.erase(sit);
    end = high_resolution_clock::now();
    results[0][3][2] = duration_cast<nanoseconds>(end - start).count();
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 3; j++) {
            results[1][i][j] += results[0][i][j];
        }
    }
} // Closes the loop from earlier

    
    cout << left << setw(12) << "Operation"
         << right << setw(14) << "Vector"
         << setw(14) << "List"
         << setw(14) << "Set" << endl;

    cout << left << setw(12) << "Read"
         << right << setw(14) << read_v
         << setw(14) << read_l
         << setw(14) << read_s << endl;

    cout << left << setw(12) << "Sort"
         << right << setw(14) << sort_v
         << setw(14) << sort_l
         << setw(14) << sort_s << endl;

    cout << left << setw(12) << "Insert"
         << right << setw(14) << insert_v
         << setw(14) << insert_l
         << setw(14) << insert_s << endl;

    cout << left << setw(12) << "Delete"
         << right << setw(14) << delete_v
         << setw(14) << delete_l
         << setw(14) << delete_s << endl;

    return 0;
}

