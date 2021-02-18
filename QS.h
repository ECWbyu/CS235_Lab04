#include <iostream>
#include <string>
#include <sstream>
using namespace std;

class QS {
public:
    QS();
    ~QS();
    bool createArray(int capacity);
    bool addToArray(int value);
    int at(int index);
    void swap(int indexA, int indexB);
    void clear();
    void sortAll();
    void sortStep(int left, int right);
    int medianOfThree(int left, int right);
    int partition(int left, int right, int pivot);
    string getArray();
    int getSize();
private:
    int *p;
    int maxSize = 0;
    int currSize = 0;
};