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

    //Race 3
    start = high_resolution_clock::now();
    v.insert(v.begin() + (v.size() / 2), "TESTCODE");
    end = high_resolution_clock::now();
    insert_v = duration_cast<nanoseconds>(end - start).count();

    auto lit = l.begin();
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

    auto sit = s.begin();
    advance(sit, s.size() / 2);
    start = high_resolution_clock::now();
    s.erase(sit);
    end = high_resolution_clock::now();
    delete_s = duration_cast<nanoseconds>(end - start).count();

    cout << "Operation\tVector\t\tList\t\tSet\n";
    cout << "Read\t\t" << read_v << "\t" << read_l << "\t" << read_s << "\n";
    cout << "Sort\t\t" << sort_v << "\t" << sort_l << "\t" << sort_s << "\n";
    cout << "Insert\t\t" << insert_v << "\t" << insert_l << "\t" << insert_s << "\n";
    cout << "Delete\t\t" << delete_v << "\t" << delete_l << "\t" << delete_s << "\n";

    return 0;
}

/* syntax examples:
auto start = high_resolution_clock::now()
auto end = high_resolution_clock::now()
auto duration = duration_cast<milliseconds>(end - start)
duration.count() references elapsed milliseconds
*/