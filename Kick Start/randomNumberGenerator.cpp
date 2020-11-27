#include <iostream>
#include <fstream>

using namespace std;

int main(int argc, char const *argv[])
{
    ofstream outputFile;
    outputFile.open("input.txt");

    int n = 0;

    cout << "How many numbers shoudl be generated? ";
    cin >> n;

	int l, r;
	cout << "range : left right (included)\n";
	cin >> l >> r;

    for(int i = 0; i < n; i++) {
        int j = rand() % (l-r+1);
        outputFile << l + j;
        outputFile << " ";
    }

    outputFile.close();

    return 0;
}

