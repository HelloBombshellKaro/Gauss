#include <iostream>
#define NN 20

void elim();
void rozwiaz();
void wpisz();
void wypisz();

int n;
double A[NN][NN];
double b[NN],x[NN];

int main() {
	wpisz();
	elim();
	rozwiaz();
	wypisz();

	system("PAUSE");
	return 0;
}

void elim() {
	for (int i = 0; i < n-1; i++) {
		for (int j = i + 1; j < n; j++) {
			double d = A[j][i] / A[i][i];
			for (int k = i; k < n; k++) {
				A[j][k] -= d * A[i][k];
			}
			b[j] -= d * b[i];
		}
	}
}

void rozwiaz() {
	x[n-1] = b[n-1] / A[n-1][n-1];
	for (int i = n - 2; i >= 0; i--) {
		double suma = 0;
		for (int j = i + 1; j < n; j++) {
			suma += x[j] * A[i][j];
		}
		x[i] = (b[i] - suma) / A[i][i];
	}
}

void wpisz() {
	using namespace std;
	printf_s("Wpisz n: ");
	cin >> n;
	printf_s("Wpisz macierz A:\n");
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++)
		{
			cin >> A[i][j];
		}
	}
	printf_s("Wpisz wektor b:\n");
	for (int i = 0; i < n; i++) {
		cin >> b[i];
	}
	wypisz();
}

void wypisz() {
	using namespace std;
	cout << "A:" << endl;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++)
		{
			cout << A[i][j] << " ";
		}
		cout << endl;
	}
	cout << "x:" << endl;
	for (int i = 0; i < n; i++) {
		cout << x[i] << endl;
	}
}