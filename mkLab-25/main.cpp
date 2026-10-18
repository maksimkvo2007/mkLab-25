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

int main() {
    vector<string> v;
    list<string> l;
    set<string> s;

    long long read_v = 0, read_l = 0, read_s = 0;
    long long sort_v = 0, sort_l = 0, sort_s = -1; // set is already sorted
    long long insert_v = 0, insert_l = 0, insert_s = 0;
    long long delete_v = 0, delete_l = 0, delete_s = 0;

    string line;
    high_resolution_clock::time_point start, end;

    //Race 1
    ifstream file1("mkLab-25/codes.txt");
    start = high_resolution_clock::now();
    while (getline(file1, line)) {
        v.push_back(line);
    }
    end = high_resolution_clock::now();
    read_v = duration_cast<nanoseconds>(end - start).count();
    file1.close();

    ifstream file2("mkLab-25/codes.txt");
    start = high_resolution_clock::now();
    while (getline(file2, line)) {
        l.push_back(line);
    }
    end = high_resolution_clock::now();
    read_l = duration_cast<nanoseconds>(end - start).count();
    file2.close();

    ifstream file3("mkLab-25/codes.txt");
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

    //Race 3
    start = high_resolution_clock::now();
    v.insert(v.begin() + (v.size() / 2), "TESTCODE");
    end = high_resolution_clock::now();
    insert_v = duration_cast<nanoseconds>(end - start).count();

    list<string>::iterator lit = l.begin();
    advance(lit, l.size() / 2);
    start = high_resolution_clock::now();
    l.insert(lit, "TESTCODE");
    end = high_resolution_clock::now();
    insert_l = duration_cast<nanoseconds>(end - start).count();

    start = high_resolution_clock::now();
    s.insert("TESTCODE");
    end = high_resolution_clock::now();
    insert_s = duration_cast<nanoseconds>(end - start).count();

    //Race 4
    start = high_resolution_clock::now();
    v.erase(v.begin() + (v.size() / 2));
    end = high_resolution_clock::now();
    delete_v = duration_cast<nanoseconds>(end - start).count();

    lit = l.begin();
    advance(lit, l.size() / 2);
    start = high_resolution_clock::now();
    l.erase(lit);
    end = high_resolution_clock::now();
    delete_l = duration_cast<nanoseconds>(end - start).count();

    set<string>::iterator sit = s.begin();
    advance(sit, s.size() / 2);
    start = high_resolution_clock::now();
    s.erase(sit);
    end = high_resolution_clock::now();
    delete_s = duration_cast<nanoseconds>(end - start).count();

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

