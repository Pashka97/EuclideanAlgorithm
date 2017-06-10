// --------------------------complex.h----------------------------------------
// Pavel Samsonov CSS 342
// 16 April 2017
// ---------------------------------------------------------------------------
// Purpose - A representation of the Euclidean Algorithm, can be modified to
//			 display runtime, and amount of operations per N value
// --------------------------------------------------------------------------- 
// Notes on specifications, special algorithms, and assumptions.
// Euclidean Algorithm
// ---------------------------------------------------------------------------


#include<iostream>
#include <sys/time.h>
using namespace std;

//pass ints as references if we want to display in main
//however decided against that in the end
void euc(int n, int &m_int1, int &m_int2, int &m_maxCost) {
	//keep program invariants
	if (n <= 8) {
		cout << "INPUT LESSTHAN 8, DELETING SYSTEM 32";
		return;
	}
	int cost = 0;
	int gcd = 1;

	double mill1; // Will represent millisecond of current clock time
	double mill2;
	struct timeval tv { 0 };

	gettimeofday(&tv, NULL);
	mill1 = 1000000 * tv.tv_sec + (tv.tv_usec);
	
	for (int i = 8; i <= n; i++) {
		for (int j = 1; j <= i; j++) {
			
			cost = 0;
			int num1 = j;
			int num2 = i;
			int temp = 0;
			while (num1 % num2 != 0) {
				temp = num1;
				num1 = num2;
				num2 = temp % num1;
				cost++;
			}
			if (cost > m_maxCost) {
				gcd = num2;
				m_maxCost = cost;
				m_int1 = j;
				m_int2 = i;
			}
		}
		gettimeofday(&tv, NULL);
		mill2 = 1000000* tv.tv_sec + (tv.tv_usec);
		//cout << "At i = " << i << "; gcd (" << m_int1 << "," << m_int2 << ") = ";
		//cout << gcd << " took " << m_maxCost << " operations" << endl;
		//cout << i << " " << m_maxCost << endl;
		cout << i << " " << (mill2-mill1)/1000 << endl;
		//= i value; runtime =
	}
	
}

int main()
{
	int m_maxCost = 0, m_int1 = 0, m_int2 = 0;

	euc(3000, m_int1, m_int2, m_maxCost);

    return 0;
}

