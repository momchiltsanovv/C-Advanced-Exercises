#include "StacksAndQueues/Stack&Queues.h"
#include "MapAndSet/Maps&Sets.h"

int* findFirstNegativePtr(int numbers[], int length) {
    for (int i = 0; i < length; i++) {
        if (numbers[i] < 0) {
            return &numbers[i];
        }
    }
    return nullptr;
}

int main() {


    int numbers[] {2, 4, -1, 2,5, 1,2, 6, 12};
    int* negativePtr = findFirstNegativePtr(numbers, 4);
    if (negativePtr != nullptr) {
        cout << *negativePtr;
    }
    else cout << "no negative numbers" << endl;

}