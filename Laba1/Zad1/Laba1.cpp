#include <iostream>
#include <random>
#include <time.h>

using namespace std;

int main() {
    setlocale(0, "");
    srand(time(NULL));
    int n;
    int flag = 1; 
    cout << "Elements: ";
    if (scanf("%d", &n) == 1) { 
        flag = 0; 
    }
    if (flag) {
        cout << "Incorrect input\n";
        return 0;
    }

    
    if (n <= 0) {
        cout << "Elems.\n";
        return 1;
    }

    
    int* arr = new int[n];

   
    for (int i = 0; i < n; i++) {
        cout << "Elem " << i + 1 << ": ";
        arr[i]=rand()%1000;

    }

    
    cout << "Elems:\n";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    
    cout << "Address: " << static_cast<void*>(arr) << "\n";

    
    cout << "Rast:\n";
    for (int i = 0; i < n; i++) {
        
        size_t byte_diff = i * sizeof(int);
        cout<<&arr[i]<<endl;
        int element_diff = i;
        cout << "Elem " << i + 1 << ": " << arr[i] 
             << " Rast: " << byte_diff << " byte or " 
             << element_diff << " elems\n";
    }

    
    delete[] arr;

    return 0;
}
