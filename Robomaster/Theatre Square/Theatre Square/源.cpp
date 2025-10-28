#include <iostream>
using namespace std;
int main()
{
	int m, n, a;
	cin >> m >> n >> a;
	int l, w;
	if (m % a == 0)
	{
		l = m / a;
	}
	else
	{
		l = m / a + 1;
	}
	if (n % a == 0)
	{
		w = n / a;
	}
	else
	{
		w = n / a + 1;
	}
	cout << l * w;
	return 0;
}