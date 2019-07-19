#include <iostream>
#include <sstream>
using namespace std;

// sorts int array in descending order
void selectionSort(int a[], int n) { 
    int i, j, min, temp;
    for (i = 0; i < n - 1; i++) {
        min = i;
        for (j = i + 1; j < n; j++) if (a[j] > a[min]) min = j;
        temp = a[i];
        a[i] = a[min];
        a[min] = temp;
    }
}

int main(int argc, char *argv[]) {

    if (argc - 1 < 2) {
        cout << "Usage: change [denominations] [amount]" << endl;
        exit(1);
    }

    int denoms[argc - 2]; // stores denominators, from argv[1] to second last argv 
    int amount; // will be the last elemnt of argv

    for (int i = 1; i < argc - 1; ++i) {
        denoms[i-1] = stoi(argv[i]);
    }

    amount = stoi(argv[argc - 1]);

    selectionSort(denoms, argc - 2);

    // for (int i = 0; i < argc - 2; i++){
    //     cout << "Denoms:" << denoms[i] << endl;
    // }
    // cout << "Amount:" << amount << endl;

    int changes[argc - 2];

    for (int i = 0; i < argc - 2; i++) {
        changes[i] = amount / denoms[i];
        amount-=changes[i]*denoms[i];
    }

    if (amount) {
        cout << "Impossible" << endl;
        return 0;
    }

    for (int i = 0; i < argc - 2; i++) {
        if (changes[i]) {
            cout << changes[i] << " x " << denoms[i] << endl;
        }
    }

    return 0;
}
