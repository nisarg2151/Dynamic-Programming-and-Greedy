#include<iostream>
using namespace std;
#include<stdio.h>
int knapSack(int W, int weight[50], int value[50], int n);

int n, W;
//int i;
int weight[50], value[50];

int C[50][50];

int main() {
	int i;
	cout << "Enter Total Number Of Items : ";
	cin >> n;

	cout << "Enter Capacity of Knapsack : ";
	cin >> W;

	cout << "Enter Weight of Each Item : ";
	for (i = 0; i < n; i++) {
		cin >> weight[i];
	}

	cout << "Enter Value of Each Item : ";
	for (i = 0; i < n; i++) {
		cin >> value[i];
	}

	cout << endl;

	int total = knapSack(W, weight, value, n);
	cout << endl << "Total Value in Knapsack  = " << total << endl;
}

int max(int a, int b) {
	return (a > b) ? a : b;
}

int knapSack(int W, int weight[], int value[], int n) {
	int i, j;
	int K[n][W + 1];

	//fill the table K[][] 
	for (j = 0; j <= W; j++) {
		for (i = 0; i < n; i++) {

			if (j == 0)
				K[i][j] = 0;			//Initialize the table

			else if (i == 0) {
				if (weight[i] <= j)
					K[i][j] = value[i];
				else
					K[i][j] = 0;
			} 
			else {					// Choose the item that maximizes the weight in knapsack without exceeding W //
				if (weight[i] <= j)
					K[i][j] = max(value[i] + K[i - 1][j - weight[i]],
							K[i - 1][j]);
				else
					K[i][j] = K[i - 1][j];
			}
		}
	}


	//Print the filled table K[][]
	for (i = 0; i < n; i++) {
		for (j = 0; j <= W; j++) {
			cout << K[i][j] << " ";
		}
		cout << endl;
	}


	//Store the selected items in seperate array by backtracking in table K[][]
	int selectedItems[25];
	int ii = n - 1;
	int jj = W;
	int item = 0;
	while (ii >= 0 && jj >= 0) {
		if(ii==0) {
			if(jj>=weight[ii]){
				selectedItems[item] = 1;
				item++;
				ii--;
			}
			else
				ii--;
		}
		else{
			if (K[ii][jj] != K[ii-1][jj]) {
				selectedItems[item] = ii + 1;
				item++;
				jj = jj - weight[ii];
				ii--;

			} else 
				ii--;
			
		}
	}

	//Print the selected items
	cout << endl << "Items that will make it to the knapsack are : ";
	for (int m = item-1; m >= 0; m--) {
		cout << selectedItems[m]  << "  ";
	}

	cout << "\n";

	return K[n - 1][W];
}


