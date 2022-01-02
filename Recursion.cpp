#include <iostream>
#include <math.h>
using namespace std;


////1. Calculate the sum of S = 1 + 2 + 3 + ... + n
//int calculateSum(int n)
//{
//	if (n == 1)
//		return 1;
//	return calculateSum(n - 1) + n;
//}
//
////2. Calculate the factorial n! = 1 ∗ 2 ∗ 3 ∗ ... ∗ n
//double factorial(int n)
//{
//	if (n == 1)
//		return 1;
//	return factorial(n - 1) * n;
//}
//
////3. Calculate x^n
//float mux(int x, int n)
//{
//	if (n == 0)
//		return 1;
//	if (n > 0)
//	{
//		if (n == 1)
//			return x;
//		return mux(x, n - 1) * x;
//	}
//	if (n < 0)
//	{
//		if (n == -1)
//			return 1.0 / x;
//		return mux(x, n + 1) * (1.0 / x);
//	}
//}
//
////4. Count the number of digits of a given integer
//int countDigits(int n)
//{
//	if (n / 10 == 0)
//		return 1;
//	return countDigits(n / 10) + 1;
//}
//
////5. Verify if every digits of given integer are even
//bool checkAllEven(int n)
//{
//	if (n == 0)
//		return true;
//	if ((n % 10) % 2 != 0)
//		return false; //sai do phát hiện 1 chữ số lẻ
//	return checkAllEven(n / 10); //bỏ đi 1 chữ số
//}
//
////6. Count the number of common divisor of 2 given integers
//int countCommonDiv(int a, int b) //CHƯA CÓ ĐỆ QUY
//{
//	int p = UCLN(a, b);
//	int count = 0;
//	for (int i = 1; i <= int(sqrt(p)); i++)
//	{
//		if (p % i == 0) 
//		{
//			if (p / i == i)
//			{
//				count++;
//			}
//			else
//			{
//				count += 2;
//			}
//		}
//	}
//	return count;
//}
//
////7. Calculate the Greatest common divisor and Least common multiple of 2 given integers
//int UCLN(int a, int b)
//{
//	if (b == 0)
//		return a;
//	return UCLN(b, a % b);
//}
//int BCNN(int a, int b) //COI LẠI
//{
//	if (a % b == 0) 
//		return a;
//	return a * BCNN(b, a % b) / (a % b);
//}
//
////8. Calculate the reverse value of a given integer
//int reverse(int n)
//{
//	int rev_n = 0;
//	int base_pos = 1;
//	while (n > 0)
//	{
//		reverse(n / 10);
//		rev_n += (n % 10) * base_pos;
//		base_pos *= 10;
//	}
//	return rev_n;
//}
//
////9. Calculate the ith Fibonacci number
//int fibo(int n)
//{
//	if (n == 0)
//		return 0;
//	if (n == 1)
//		return 1;
//	return fibo(n - 1) + fibo(n - 2);
//}
//
////10. * Given 4 single distinguish characters. Print out all possible permutation
////Example: ABCD, ABDC, ACBD


#include <math.h>
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

long sum(int n)
{
	if (n == 1)
		return 1;
	else
		return sum(n - 1) + n;
}
long factorial(int n)
{
	if (n == 1)
		return 1;
	return n * factorial(n - 1);
}
long xn(int x, int n)
{
	if (n == 1)
		return x;
	return x * xn(x, n - 1);
}
int count_number(int n)
{
	if (n == 0)
		return 0;
	return 1 + count_number(n / 10);
}
bool is_even(int n)
{
	if (n == 0)
		return true;
	if (n % 2 != 0)
		return false;
	return is_even(n / 10);
}
int count_divisor(int a, int b, int i)
{
	if (i > min(a, b))
		return 0;
	else
	{
		if (a % i == 0 && b % i == 0)
		{
			return count_divisor(a, b, i + 1) + 1;
		}
		else
			return count_divisor(a, b, i + 1);
	}
}
int gcd(int a, int b) {
	if (b == 0) return a;
	if (a % b == 0) return b;
	return gcd(b, a % b);
}
int lcm(int a, int b)
{
	static int temp = 1;
	if (temp % a == 0 && temp % b == 0)
	{
		return temp;
	}
	else
	{
		temp++;
		lcm(a, b);
		return temp;
	}

}

int reverse(int n)
{
	int digit = (int)log10(n);

	// Base condition
	if (n == 0)
		return 0;
	else
		return ((n % 10 * pow(10, digit)) + reverse(n / 10));
}
int fibonacci(int n)
{
	if (n == 1 || n == 2)
		return 1;
	return fibonacci(n - 1) + fibonacci(n - 2);
}
bool* b = new bool[5];
char a[5];

void permutation(string s)
{
	sort(s.begin(), s.end());
	do {
		cout << s << " ";
	} while (next_permutation(s.begin(), s.end())); // std::next_permutation

	cout << endl;
}
void Try(string a, int l, int r)
{
	// Base case  
	if (l == r)
		cout << a << endl;
	else
	{
		// Permutations made  
		for (int i = l; i <= r; i++)
		{

			// Swapping done  
			swap(a[l], a[i]);

			// Recursion called  
			Try(a, l + 1, r);

			//backtrack  
			swap(a[l], a[i]);
		}
	}
}

int main(int argc, char* argv[])
{
	int n;
	int x;
	cout << "Enter x: ";
	cin >> x;
	cout << "Enter n: ";
	cin >> n;


	//Excersise 1:
	cout << "The sum of S = 1 + 2 + 3 + ... + " << n << " = " << sum(n) << endl;

	//Excersise 2:
	cout << "Thus n! = 1 * 2 * 3 * ... * " << n << " = " << factorial(n) << endl;

	//Excersise 3:
	cout << "Thus x^n = " << x << "^" << n << " = " << xn(x, n) << endl;

	//Excersise 4:
	cout << "The number of digits of " << n << " is " << count_number(n) << endl;

	//Excersise 5:
	if (is_even(n))
	{
		cout << "Number " << n << " is even!" << endl;
	}
	else
	{
		cout << "Number " << n << " is not even!" << endl;
	}

	//Excersise 6:
	int a, b;
	cout << "Enter a: ";
	cin >> a;
	cout << "Enter b: ";
	cin >> b;
	cout << "The number of common divisor of " << a << " and " << b << " is " << count_divisor(a, b, 1) << endl;

	//Excersise 7:
	//int a, b;
	int c, d;
	cout << "Enter c: ";
	cin >> c;
	cout << "Enter d: ";
	cin >> d;
	cout << "The Greatest common divisor of " << c << " and " << d << " is " << gcd(c, d) << endl;
	cout << "The Least common multiple of " << c << " and " << d << " is " << lcm(c, d) << endl;

	//Excersise 8:
	cout << "The reverse value of " << n << " is " << reverse(n) << endl;

	//Excersise 9:
	cout << "Fibonacci number of F(" << n << ") is " << fibonacci(n) << endl;

	//Excersise 10:
	string s;
	cout << "Enter 4 single distinguish characters: ";
	cin >> s;
	cout << "All possible permutation: ";
	int l = 0, r = s.length() - 1;
	Try(s, l, r);

	return 0;
}

//int main()
//{
//	//cout << "Tong: " << calculateSum(4) << endl;
//	//cout << "Giai thua: " << factorial(20) << endl;
//	//cout << "x ^ n: " << mux(2, -3) << endl;
//	//cout << "So luong chu so: " << countDigits(-100) << endl;
//
//	/*bool check = checkAllEven(200);
//	if (check)
//	{
//		cout << "La so toan chan" << endl;
//	}
//	else
//	{
//		cout << "Khong phai so toan chan" << endl;
//	}*/
//
//	//cout << "Dem so uoc chung: " << countCommonDiv(12, 10) << endl;
//	//cout << "Uoc chung lon nhat: " << UCLN(20, 6) << endl;
//	//cout << "Boi chung nho nhat: " << BCNN(5, 12) << endl;
//	cout << "Dao nguoc so: " << reverse(123) << endl;
//	//cout << fibo(10) << endl;
//
//	/*string s;
//	cout << "Nhap chu: ";
//	cin >> s;*/
//
//	return 0;
//}

int main(int argc, char* argv[])
{
	int n;
	int x;
	cout << "Enter x: ";
	cin >> x;
	cout << "Enter n: ";
	cin >> n;


	//Excersise 1:
	cout << "The sum of S = 1 + 2 + 3 + ... + " << n << " = " << sum(n) << endl;

	//Excersise 2:
	cout << "Thus n! = 1 * 2 * 3 * ... * " << n << " = " << factorial(n) << endl;

	//Excersise 3:
	cout << "Thus x^n = " << x << "^" << n << " = " << xn(x, n) << endl;

	//Excersise 4:
	cout << "The number of digits of " << n << " is " << count_number(n) << endl;

	//Excersise 5:
	if (is_even(n))
	{
		cout << "Number " << n << " is even!" << endl;
	}
	else
	{
		cout << "Number " << n << " is not even!" << endl;
	}

	//Excersise 6:
	int a, b;
	cout << "Enter a: ";
	cin >> a;
	cout << "Enter b: ";
	cin >> b;
	cout << "The number of common divisor of " << a << " and " << b << " is " << count_divisor(a, b, 1) << endl;

	//Excersise 7:
	//int a, b;
	int c, d;
	cout << "Enter c: ";
	cin >> c;
	cout << "Enter d: ";
	cin >> d;
	cout << "The Greatest common divisor of " << c << " and " << d << " is " << gcd(c, d) << endl;
	cout << "The Least common multiple of " << c << " and " << d << " is " << lcm(c, d) << endl;

	//Excersise 8:
	cout << "The reverse value of " << n << " is " << reverse(n) << endl;

	//Excersise 9:
	cout << "Fibonacci number of F(" << n << ") is " << fibonacci(n) << endl;

	//Excersise 10:
	string s;
	cout << "Enter 4 single distinguish characters: ";
	cin >> s;
	cout << "All possible permutation: ";
	int l = 0, r = s.length() - 1;
	Try(s, l, r);

	return 0;
}