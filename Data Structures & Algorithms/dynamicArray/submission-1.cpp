class DynamicArray {
public:

    int *arr;
    int size;
    int currCapacity;

    DynamicArray(int capacity) {
        size = 0;
        currCapacity = capacity;
        arr = new int[currCapacity];
    }

    int get(int i) {
        return arr[i];
    }

    void set(int i, int n) {
        arr[i]=n;
    }

    void pushback(int n) {
        if(size==currCapacity) resize();
        arr[size] = n;
        size++;
    }

    int popback() {
        size--;
        return arr[size];
    }

    void resize() {
        currCapacity *= 2;
        int *newArr = new int[currCapacity];
        for(int i = 0; i < size; i++) {
            newArr[i] = arr[i];
        }
        arr = newArr;
    }

    int getSize() {
        return size;
    }

    int getCapacity() {
        return currCapacity;
    }   
};
