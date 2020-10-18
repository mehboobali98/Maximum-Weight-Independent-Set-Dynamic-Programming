#include <iostream>
#include <vector>

using namespace std;

int bottomUp(vector<int> max_set);

int topDown(vector<int> max_set, int size);

int main() {

    vector<int> max_set;
    max_set.push_back(2);
    max_set.push_back(3);
    max_set.push_back(2);
    max_set.push_back(3);

    cout << bottomUp(max_set) << endl;
    cout << topDown(max_set, max_set.size());


    return 0;
}

int bottomUp(vector<int> max_set) {
    vector<int> temp;
    temp.push_back(0);
    temp.push_back(max_set.at(1));

    for (int i = 2; i < max_set.size(); i++) {
        temp.push_back(max(temp.at(i - 1), temp.at(i - 2) + max_set.at(i)));
    }

    return temp.back();
}

int topDown(vector<int> max_set, int size) {
    if (size == 0)
        return 0;

    if (size == 1)
        return max_set.at(1);

    int val1 = topDown(max_set, size - 1);
    int val2 = topDown(max_set, size - 2);

    return max(val1, val2 + max_set.back());
}
