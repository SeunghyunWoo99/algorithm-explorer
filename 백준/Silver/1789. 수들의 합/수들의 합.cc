#include <iostream>

using namespace std;

int main() {

	long long S;
	cin >> S;
    
    long long acc = 0;
    for (int i=1; i<92685; i++) {
        acc += i;
        if (S-acc <= i) {
            cout << i;
            return 0;
        }
    }
    
	return 0;
}