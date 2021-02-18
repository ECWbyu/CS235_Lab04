#include "QS.h"
using namespace std;

QS::QS() {
    createArray(0);
}

QS::~QS() {
    delete [] p;
}

bool QS::createArray(int capacity) {
    if (capacity <= 0) {
        return false;
    }
    delete [] p;
    p = new int [capacity];
    maxSize = capacity;
    currSize = 0;
    return true;
}

bool QS::addToArray(int value) {
    if (currSize >= maxSize) {
        return false;
    }
    p[currSize] = value;
    ++currSize;
    return true;
}

int QS::at(int index) {
    // Assumes the index is valid.
    return *(p + index);
}

void QS::swap(int indexA, int indexB) {
    // Assumes the indexes are valid.
    int tmp = at(indexA);
    *(p + indexA) = *(p + indexB);
    *(p + indexB) = tmp;
}

void QS::clear() {
    createArray(0);    
}

void QS::sortAll() {
    if (currSize == 0) {
        return;
    }
    int middle = partition(0, currSize - 1, medianOfThree(0, currSize - 1));
    sortStep(0, middle - 1);
    sortStep(middle + 1, currSize - 1);
}

void QS::sortStep(int left, int right) {
    int pivot = medianOfThree(left, right);
    if (pivot == -1) {
        return;
    }
    pivot = partition(left, right, pivot);
    if (pivot == -1) {
        return;
    }
    sortStep(left, pivot - 1);
    sortStep(pivot + 1, right);
}

int QS::medianOfThree(int left, int right) {
    if (currSize == 0) {
        return -1;
    }
    if (left < 0 or right < 0 or left >= currSize or right >= currSize) {
        return -1;
    }
    if (left >= right) {
        return -1;
    }
    int middle = (left + right) / 2;
    if (at(left) > at(middle)) {
        swap(left, middle);
    }
    if (at(middle) > at(right)) {
        swap(middle, right);
    }
    if (at(left) > at(middle)) {
        swap(left, middle);
    }
    return middle;
}

int QS::partition(int left, int right, int pivot) {
    if (currSize == 0) {
        return -1;
    }
    if (left < 0 or right < 0 or left >= currSize or right >= currSize) {
        return -1;
    }
    if (left >= right) {
        return -1;
    }
    if (not (pivot > left and pivot < right)) {
        return -1;
    }
    swap(left, pivot);
    int up = left + 1;
    int down = right;
    do {
        while (at(up) <= at(pivot) or up == right) {
            ++up;
        }
        while (at(down) > at(pivot) or down == left) {
            --down;
        }
        if (up < down) {
            swap(up, down);
        }
    } while (up < down);
    swap(left, down);
    return down;
}

string QS::getArray() {
    if (currSize <= 0) {
        return "";
    }
    stringstream ss;
    ss << p[0];
    for (int i = 1; i < currSize; i++) {
        ss << ", " << p[i];
    }
    return ss.str();
}

int QS::getSize() {
    return currSize;
}