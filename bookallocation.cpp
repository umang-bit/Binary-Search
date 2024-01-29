#include <iostream>
using namespace std;

bool ispossible(int arr[], int size, int m, int mid) {
    int pagesum = 0;
    int studentcount = 1;
    for (int i = 0; i < size; i++) {
        if (pagesum + arr[i] <= mid) {
            pagesum += arr[i];
        } else {
            studentcount++;
            if (studentcount > m) {
                return false;
            }
            pagesum = arr[i];
        }
    }
    return true;
}

int main() {
    int arr[7] = {10, 20, 30,40, 50,60,70};
    int m;
    cout << "Enter the number of students: ";
    cin >> m;
    int s = 0;
    int e = 0;
    for (int i = 0; i < 4; i++) {
        e += arr[i];
    }
    
    int ans = -1; // Initialize ans with a default value
    while (s <= e) {
        int mid = s + (e - s) / 2;
        if (ispossible(arr, 4, m, mid)) {
            ans = mid;
            e = mid - 1;
        } else {
            s = mid + 1;
        }
    }
    
    cout << "The minimum maximum pages a student can read is: " << ans << endl;
    return 0;
}
