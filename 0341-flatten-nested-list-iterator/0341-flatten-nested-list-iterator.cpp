class NestedIterator {
public:
    NestedIterator(vector<NestedInteger> &nestedList) {
        flatten(nestedList);
        it = flattenedList.begin();
    }

    int next() {
        return *it++;
    }

    bool hasNext() {
        return it != flattenedList.end();
    }

private:
    vector<int> flattenedList;
    vector<int>::iterator it;

    void flatten(const vector<NestedInteger> &nestedList) {
        for (const auto &ni : nestedList) {
            if (ni.isInteger()) {
                flattenedList.push_back(ni.getInteger());
            } else {
                flatten(ni.getList());
            }
        }
    }
};


// Usage example:
// NestedIterator i = new NestedIterator(nestedList);
// while (i.hasNext()) {
//     v[f()] = i.next();
// }