#include <iostream>
using namespace std;

int main()
{
	int N,denominationCount;
	int numCoins = 0,totalCoins = 0;
	cout << "---------------------------------------------------\n";
	cout << "Enter the value N(cents) to make change for : ";
	cin >> N;

	cout << "Enter the number of different denominations : ";
	cin >> denominationCount;

	int denominations[denominationCount];
	cout << "Enter denomination values in descending order ( 1 Must be Included ) : ";
	
	for (int i = 0; i < denominationCount; i++) {
		cin >> denominations[i];
	}


	cout << "---------------------------------------------------\n";
	//Repeteadly make a greedy choice by selecting highest coin we can
	
	for (int coin=0;coin < denominationCount;coin++) {
		numCoins = N / denominations[coin];
		N = N %  denominations[coin];
		if (numCoins > 0)
			totalCoins = totalCoins + numCoins;
		cout << denominations[coin] << " x " << numCoins << " = " << (numCoins * denominations[coin]) << '\n';
	}

	cout << "---------------------------------------------------\n";
	cout << "Total Coins Used to Make Change = " << totalCoins << endl;
	cout << "---------------------------------------------------\n";

	return 0;
}
