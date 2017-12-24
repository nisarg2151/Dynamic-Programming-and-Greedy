#include <iostream>
using namespace std;

int makeChange(int N, int denominations[] ,int denominationCount)
{
	int C[denominationCount][N+1],selectedCoins[50];
	
	for(int i = 0; i < denominationCount; i++) {
	
		for(int j = 0; j <= N; j++) {
	
			selectedCoins[j] = 0;
			
			//Initialize the table
			if(j == 0)
				C[i][j] = 0;
	
			if(i == 0)
				C[i][j] = j;
	
			//select the min number of coins required to make change for current j
			else if(j < denominations[i]) 
				C[i][j] = C[i-1][j];
			
			else 
				C[i][j] = min(C[i-1][j], C[i][j- denominations[i]] + 1);
			
			cout << C[i][j] << "\t" ;
		}
		cout << endl;
	}

	//Backtracking to get the selected coins
	int i = denominationCount - 1;
	int j = N;
	int item = 0;
	while (i >= 0 && j >= 0) {
		if (C[i][j] != C[i - 1][j]) {
			item = i;

			if(denominations[i] <= j )
				selectedCoins[item] = j/denominations[i];

			else
				selectedCoins[item] = 0;

			j = j%denominations[i];
			i--;
		}
		else 
			i--;
	}
	
	//Print the selected coins
	cout << endl <<  "Distribution of Coins : \n";
	cout << "---------------------------------------------------\n";
	for (int m = 0; m < denominationCount; m++) {
		cout << denominations[m] << " x " << selectedCoins[m]  << " = " << denominations[m]*selectedCoins[m] << "\n";
	}
	cout << "---------------------------------------------------\n";



	return C[denominationCount-1][N];
}


int main()
{
	int N,denominationCount;
	int numCoins = 0,totalCoins = 0;

	cout << "---------------------------------------------------\n";

	cout << "Enter the value N to make change for : ";
	cin >> N;

	cout << "Enter the number of different denominations to be used : ";
	cin >> denominationCount;

	int denominations[denominationCount];
	cout << "Enter denomination values in ascending order : ";

	for (int i = 0; i < denominationCount; i++) {
		cin >> denominations[i];
	}

	cout << "---------------------------------------------------\n";

	totalCoins = makeChange(N, denominations, denominationCount);
	cout << "Total number of coins used = " << totalCoins << "\n";
	cout << "---------------------------------------------------\n";

	return 0;
}


