#include <iostream>
using namespace std;

void linearSearch(int n, int item, int arr[]) {
    for (int i = 0; i < n; i++) {
        if (arr[i] == item) {
            cout << item << " found at position " << i + 1 << endl;
            return;
        }
    }
    cout << item << " not found" << endl;
}

int main() {
    int arr[10];
    int n, item;

    cout << "Enter the array size: ";
    cin >> n;

    if (n <= 0 || n > 10) {
        cout << "Invalid array size. Must be between 1 and 10." << endl;
        return 1;
    }

    cout << "Enter the elements: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    cout << "Enter the search item: ";
    cin >> item;

    linearSearch(n, item, arr);

    return 0;
}
