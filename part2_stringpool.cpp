#include <iostream>
#include <string>
using namespace std;

class StringPool {
public:
    string* stringPool;
    int currentSize;
    int maxSize;

    // Constructor - runs automatically when we create a StringPool object
    StringPool() {
        maxSize = 5;
        currentSize = 0;
        stringPool = new string[maxSize];
    }

    void addString(string s) {
        if (currentSize < maxSize) {
            stringPool[currentSize] = s;
            currentSize = currentSize + 1;
            cout << "Added: " << s << endl;
        } else {
            cout << "Pool is full!" << endl;
        }
    }
 // Removes a string but does NOT free memory (this is the "leak")
    void removeString(int index) {
        cout << "Removing: " << stringPool[index] << endl;
        for (int i = index; i < currentSize - 1; i++) {
            stringPool[i] = stringPool[i + 1];
        }
        currentSize = currentSize - 1;
    }

    void displayPool() {
        cout << "Pool has " << currentSize << " strings: ";
        for (int i = 0; i < currentSize; i++) {
            cout << stringPool[i] << " ";
        }
        cout << endl;
    }
};

int main() {
    StringPool pool;
    pool.addString("Apple");
    pool.addString("Banana");
    pool.addString("Cherry");
    pool.addString("Date");

    pool.displayPool();

    pool.removeString(0);
    pool.removeString(0);

    pool.displayPool();

    // Fix the memory leak - free the memory manually
    delete[] pool.stringPool;
    cout << "Memory freed!" << endl;

    return 0;
}
