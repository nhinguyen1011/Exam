#include <iostream>
#include <ctime>
using namespace std;
//1. Swap 2 given integers
void swap(int* a, int* b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}

//2. Calculate the total value of 2 integers
int* sum(int* a, int* b)
{
	int* s = new int;
	*s = *a + *b;
	return s;
}

//3. Input an array with unknown size
void inputArray(int* a, int& n)
{
	cout << "Input Array: " << endl;
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
	}
}

//4. Print a given array
void printArray(int* a, int n)
{
	cout << "Array: ";
	for (int i = 0; i < n; i++)
	{
		cout << a[i] << " ";
	}
	cout << endl;
}

//5. Find the largest value from a given array
int* findMax(int* arr, int n)
{
	int* max = new int;
	*max = arr[0];
	for (int i = 1; i < n; i++)
	{
		if (*max < arr[i])
			*max = arr[i];
	}
	return max;
}

//6. Find the longest ascending subarray from a given array
int* findLongestAscendingSubarray(int* a, int n, int& length)
{
	if (!a)
		return nullptr;
	int new_length = length = 0;
	int* start_p = a;
	int* cur_p = start_p;

	for (int i = 0; i < n; i++) {
		if (a[i] > a[i + 1]) 
		{				//*(a+i) - (a)
			new_length = &a[i] - cur_p; //trừ địa chỉ
			if (new_length > length) {
				start_p = cur_p;
				length = new_length;
				cur_p = &a[i + 1];
			}
			else
				cur_p = &a[i + 1];
		}
	}
	if (length > 0)
		length += 1;
	return start_p;
}

//7. Swap 2 given arrays
void swapArrays(int* a, int* b, int& na, int& nb)
{
	//int* temp_a = new int[nb]; //mảng temp_a giữ phần tử của mảng b
	//int temp_n = nb;
	//for (int i = 0; i < nb; i++)
	//{
	//	temp_a[i] = b[i];
	//}
	//b = new int[na];
	//for (int i = 0; i < na; i++) //mảng b giữ phần tử mảng a
	//{
	//	b[i] = a[i];
	//}
	//nb = na;
	//a = new int[temp_n];
	//for (int i = 0; i < temp_n; i++)
	//{
	//	a[i] = temp_a[i];
	//}
	//na = temp_n;

	//swap head pointer
	//int len = na > nb ? na : nb;
	int len;
	if (na > nb)
		len = na;
	else
		len = nb;

	for (int i = 0; i < len; i++) {
		/*int temp = *(a + i);
		*(a + i) = *(b + i);
		*(b + i) = temp;*/
		int temp = a[i];
		a[i] = b[i];
		b[i] = temp;
	}
	//swap length
	int t = na;
	na = nb;
	nb = t;
}

//8. Concatenate 2 given array
int* concatenate2Arrays(int* a, int* b, int na, int nb)
{
	int* c = new int[na + nb]; //khi cấp phát mảng động mới có kích thước ổn định nhất có thể
	for (int i = 0; i < na; i++)
	{
		c[i] = a[i];
	}
	for (int i = na; i < na + nb; i++)
	{
		c[i] = b[i - na];
	}
	return c;
}

//9. Given 2 ascending array with distinguish elements. Generate a new ascending array with all elements from the given array
int* merge2Arrays(int* a, int* b, int na, int nb, int& nc)
{
	nc = na + nb;
	int* c = new int[nc];
	int i = 0, j = 0, k = 0;
	while (i < na && j < nb)
	{
		if (a[i] < b[j])
		{
			c[k++] = a[i++];
		}
		else
		{
			c[k++] = b[j++];
		}
	}
	//lưu những ptu còn lại của a[] vào c[]
	while (i < na)
	{
		c[k++] = a[i++];
	}
	//lưu những ptu còn lại của b[] vào c[]
	while (j < nb)
	{
		c[k++] = b[j++];
	}
	return c;
}

//10. Generate a random matrix with keyboard input size
void generateMatrix1(int** a, int& length, int& width)
{
	if (length == 0 || width == 0)
		return;
	srand(time(0));
	int data;
	for (int i = 0; i < width; i++)
	{
		for (int j = 0; j < length; j++)
		{
			data = rand() % 100;
			a[i][j] = data;
		}
	}
	cout << width << " " << length << endl;
}

void outputMatrix(int** a, int length, int width)
{
	if (!a || length == 0 || width == 0)
		return;
	for (int i = 0; i < width; i++)
	{
		for (int j = 0; j < length; j++)
		{
			cout << a[i][j] << "\t";
		}
		cout << endl;
	}

}

//11. Given 2 1D arrays a and b.Generate the matrix c that c[i][j] = a[i] * b[j]
int** generateMatrix2(int* a, int* b, int na, int nb)
{
	int** c;
	c = new int* [na];
	for (int i = 0; i < na; i++) {
		c[i] = new int[nb];
	}
	for (int i = 0; i < na; i++)
		for (int j = 0; j < nb; j++) {
			c[i][j] = a[i] * b[j];
		}
	return c;
}

//12. Swap 2 columns / rows of a given matrix
void swapRows(int** a, int length, int width, int row1, int row2)
{
	if (row1 < 0 || row2 < 0 || row1 > length || row2 > length)
		return;
	for (int i = 0; i <= width; i++)
		swap(a[row1-1][i], a[row2-1][i]);
}
void swapColumns(int** a, int length, int width, int col1, int col2) 
{
	if (col1 < 0 || col2 < 0 || col1 > width || col2 > width)
		cout << "clgt" << endl;
		//return;
	for (int i = 0; i <= length; i++)
		swap(a[i][col1-1], a[i][col2-1]);
}

//13. Generate the transpose matrix of a given matrix
int** transposeMatrix(int** a, int length, int width)
{
	/*int** a_t = new int* [width];
	for (int i = 0; i < width; i++)
	{
		a_t[i] = new int[length];
	}

	for (int i = 0; i < length; i++)
	{
		for (int j = 0; j < width; j++)
		{
			a_t[j][i] = a[i][j];
		}
	}
	outputMatrix(a_t, length, width);

	return a_t;

	for (int i = 0; i < width; i++)
	{
		delete[]a_t[i];
	}
	delete[]a_t;*/

	int** a_t = new int* [width], i, j;
	for (i = 0; i < width; i++) {
		a_t[i] = new int[length];
		for (j = 0; j < length; j++) 
		{
			a_t[i][j] = a[j][i];
		}
	}
	return a_t;
	for (int i = 0; i < width; i++)
	{
		delete[]a_t[i];
	}
	delete[]a_t;
}

//14. Concatenate 2 given size-equal matrices, horizontally / vertically
int** concatenate2MatricesH(int** a, int** b, int length, int width)
{
	if (!a || !b)
		return nullptr;
	int width_c = 2 * width;

	// concatenate horizontally
	int** c = new int* [length];
	for (int i = 0; i < length; i++) {
		c[i] = new int[2 * width];
	}
	for (int i = 0; i < length; i++)
	{
		for (int j = 0; j < width; j++)
		{
			c[i][j] = a[i][j];
		}
	}
	for (int i = 0; i < length; i++)
	{
		for (int j = 0; j < width; j++)
		{
			c[i][width + j] = b[i][j];
		}
	}
	return c;
}
int** concatenate2MatricesV(int** a, int** b, int length, int width)
{
	if (!a || !b)
		return nullptr;
	int length_c = 2 * length;

	// concatenate vertically
	int** c = new int* [length_c];
	for (int i = 0; i < length_c; i++) {
		c[i] = new int[width];
	}
	for (int i = 0; i < length; i++)
	{
		for (int j = 0; j < width; j++)
		{
			c[i][j] = a[i][j];
		}
	}
	for (int i = 0; i < length; i++)
	{
		for (int j = 0; j < width; j++)
		{
			c[length + i][j] = b[i][j];
		}
	}
	return c;
}

//15. Multiple 2 given matrices
bool multiple2Matrices(int** a, int** b, int lengtha, int widtha, int lengthb, int widthb)
{
	if (!a || !b || widtha != lengthb)
		return false;

	int** c = new int* [lengtha];
	for (int i = 0; i < lengtha; i++)
	{
		c[i] = new int[widthb];
	}
	// initialize c[i][j]
	for (int i = 0; i < lengtha; i++)
	{
		for (int j = 0; j < widthb; j++)
		{
			c[i][j] = 0;
		}
	}

	for (int i = 0; i < lengtha; i++)
	{
		for (int j = 0; j < widthb; j++)
		{
			for (int u = 0; u < widtha; u++)
			{
				c[i][j] += (a[i][u] * b[u][j]);
			}
			cout << " " << c[i][j];
		}
		cout << endl;
	}
	return true;
}

//16. Given matrice a.Find the submatrix of a which satisfy keyboard input size and has the largest total value of its elements
int** findSubmatrix(int** a, int length, int width, int& length_, int& width_)
{
	cout << "Enter length and width of submatrix: ";
	cin >> length_ >> width_;
	if (length_ > length || width_ > width) return NULL;
	if (length_ == length && width_ == width) return a;

	int numL = length - length_ + 1, numW = width - width_ + 1;
	//numL: number of all possible locations of the first element in each submatrix when put on the length scale.
	//numW: number of all possible locations of the first element in each submatrix when put on the width scale.

	//initialize sum array
	int** sumOfSubmatrices = new int* [numL];
	for (int i = 0; i < numL; i++) {
		sumOfSubmatrices[i] = new int[numW];
		for (int j = 0; j < numW; j++) {
			sumOfSubmatrices[i][j] = 0;
		}
	}

	//calculating sum
	for (int k = 0; k < numL; k++) {
		for (int l = 0; l < numW; l++) {
			for (int i = k; i < k + length_; i++) {
				for (int j = l; j < l + width_; j++) {
					sumOfSubmatrices[k][l] += a[i][j];
				}
			}
		}
	}

	//find max sum
	int max = sumOfSubmatrices[0][0], maxL = 0, maxW = 0;
	for (int k = 0; k < numL; k++) {
		for (int l = 0; l < numW; l++) {
			if (max < sumOfSubmatrices[k][l]) {
				max = sumOfSubmatrices[k][l];
				maxL = k;
				maxW = l;
			}
		}
	}

	//just for debug
	/*
	for (int i = 0;i < numL;i++) {
		for (int j = 0;j < numW;j++) {
			cout<<sumOfSubmatrices[i][j]<<endl;
		}
	}*/

	//reallocate
	for (int i = 0; i < numL; i++) {
		delete[]sumOfSubmatrices[i];
	}
	delete[]sumOfSubmatrices;

	//initialize submatrix and add value
	int** submatrix = new int* [length_];
	for (int i = 0; i < length_; i++) {
		submatrix[i] = new int[width_];
	}

	for (int i = maxL; i < maxL + length_; i++) {
		for (int j = maxW; j < maxW + width_; j++) {
			submatrix[i - maxL][j - maxW] = a[i][j];
		}
	}
	return submatrix;
}

//17. Sequential Search
int LinearSearch(int* a, int n, int key)
{
	for (int i = 0; i < n; i++)
		if (a[i] == key)
			return i;
	return -1;
}

//18. Sequential Search
int SentinelLinearSearch(int* a, int n, int key)
{
	bool flag = false;
	for (int i = 0; i < n; i++)
		if (a[i] == key)
		{
			flag = true;
			key = i;
		}
	if (flag == true)
		return key;
	else
		return -1;
}

//19. Binary Search
int BinarySearch(int* a, int n, int key)
{
	int left, right;
	left = 0;
	right = n - 1;

	while (left <= right)
	{
		int mid = left + (right - left) / 2;
		if (a[mid] == key)
			return mid;

		if (a[mid] < key)
			left = mid + 1;
		else
			right = mid - 1;

	}
	return -1;
}

//20. Binary Search (using recursion)
int RecursiveBinarySearch(int* a, int left, int right, int key)
{
	if (left > right)
		return -1;
	int mid = left + (right - left) / 2;
	if (a[mid] == key)
		return mid;
	if (key > a[mid])
		return RecursiveBinarySearch(a, mid + 1, right, key);
	else
		return RecursiveBinarySearch(a, left, mid, key);
}

int main()
{
	//CAU 1
	/*int x = 10, y = 9;
	swap(x, y);
	cout << "x = " << x << endl;
	cout << "y = " << y << endl;*/

	//CAU 2
	//int* a = &x;
	//int* b = &y;
	//cout << *sum(&x, &y) << endl;

	//CAU 5
	//int length1 = 0;
	/*int n;
	cout << "Enter number of elements: ";
	cin >> n;
	int* a = new int[n];
	inputArray(a, n);
	printArray(a, n);
	cout << "Max = " << *findMax(a, n) << endl;*/

	//CAU 6
	//int n = 9, length;
	//int* a = new int[n] {20, 20, 10, 2, 3, 100, 59, -3, 5};
	//int* b = findLongestAscendingSubarray(a, n, length);
	//printArray(b, length);

	//CAU 7
	/*int na;
	cout << "Enter number of elements a: ";
	cin >> na;
	int* a = new int[na];
	inputArray(a, na);
	printArray(a, na);
	int nb;
	cout << "Enter number of elements b: ";
	cin >> nb;
	int* b = new int[nb];
	inputArray(b, nb);
	printArray(b, nb);
	swapArrays(a, b, na, nb);
	cout << "Swap 2 arrays" << endl;
	printArray(a, na);
	printArray(b, nb);*/

	//CAU 8
	/*int* arr1 = new int[5]{ 1,2,3,4,5 };
	int* arr2 = new int[5]{ 1,2,3,4,5 };
	int* arr3 = concatenate2Arrays(arr1, arr2, 5, 5);
	for (int i = 0; i < 10; i++)
	{
		cout << arr3[i] << " ";
	}
	cout << "\n";*/

	//CAU 9
	/*int na;
	cout << "Enter number of elements a: ";
	cin >> na;
	int* a = new int[na];
	inputArray(a, na);
	printArray(a, na);
	int nb;
	cout << "Enter number of elements b: ";
	cin >> nb;
	int* b = new int[nb];
	inputArray(b, nb);
	printArray(b, nb);
	int nc;
	int* c = merge2Arrays(a, b, na, nb, nc);
	printArray(c, nc);*/

	//CAU 10
	/*int length, width;
	cout << "Enter the length of the Matrix: ";
	cin >> length;
	cout << "Enter the width of the Matrix:";
	cin >> width;
	int** m = new int*[width];
	for (int i = 0; i < width; i++)
	{
		m[i] = new int[length];
	}
	generateMatrix1(m, length, width);
	cout << "Your Matrix is:" << endl;
	outputMatrix(m, length, width);
	for (int i = 0; i < width; i++)
	{
		delete[]m[i];
	}
	delete[]m;*/

	//CAU 11
	/*int na;
	cout << "Enter number of elements a: ";
	cin >> na;
	int* a = new int[na];
	inputArray(a, na);
	printArray(a, na);
	int nb;
	cout << "Enter number of elements b: ";
	cin >> nb;
	int* b = new int[nb];
	inputArray(b, nb);
	printArray(b, nb);
	int** c = generateMatrix2(a, b, na, nb);
	cout << "The new matrix after generating:" << endl;
	outputMatrix(c, na, nb);
	cout << endl;*/

	//CAU 12
	/*int length, width;
	cout << "Enter the length of the Matrix: ";
	cin >> length;
	cout << "Enter the width of the Matrix:";
	cin >> width;
	int** m = new int*[width];
	for (int i = 0; i < width; i++)
	{
		m[i] = new int[length];
	}
	generateMatrix1(m, length, width);
	cout << "Your Matrix is:" << endl;
	outputMatrix(m, length, width);
	int r1, r2;
	cout << "Enter 2 numbers standing for 2 rows that you want to swap" << endl;
	cout << "Row 1: ";
	cin >> r1;
	cout << "Row 2: ";
	cin >> r2;
	swapRows(m, length, width, r1, r2);
	cout << "After Swapping:" << endl;
	outputMatrix(m, length, width);
	int c1, c2;
	cout << "Enter 2 numbers standing for 2 rows that you want to swap" << endl;
	cout << "Col 1: ";
	cin >> c1;
	cout << "Col 2: ";
	cin >> c2;
	swapColumns(m, length, width, c1, c2);
	cout << "After Swapping:" << endl;
	outputMatrix(m, length, width);
	for (int i = 0; i < width; i++)
	{
		delete[]m[i];
	}
	delete[]m; */

	//CAU 13
	int length, width;
	cout << "Enter the length of the Matrix: ";
	cin >> length;
	cout << "Enter the width of the Matrix:";
	cin >> width;
	//int** m = new int* [width];
	int** m = nullptr;
	/*for (int i = 0; i < width; i++)
	{
		m[i] = new int[length];
	}*/
	generateMatrix1(m, length, width);
	cout << "Your Matrix is:" << endl;
	outputMatrix(m, length, width);
	int **a = transposeMatrix(m, length, width);
	cout << "After transposing: " << endl;
	outputMatrix(a, length, width);

	//CAU 17, 18
	//int na;
	//cout << "Enter number of elements a: ";
	//cin >> na;
	//int* a = new int[na];
	//inputArray(a, na);
	//printArray(a, na);
	//int key;
	//cout << "Enter an element you want to search: ";
	//cin >> key;
	//int pos = LinearSearch(a, na, key);
	////int pos = SentinelLinearSearch(a, na, key);
	//cout << "\t" << key << " locates at the position " << pos << endl;

	//CAU 19, 20
	//cout << "Binary Search" << endl;
	//int na;
	//cout << "Enter number of elements a: ";
	//cin >> na;
	//int* a = new int[na];
	//inputArray(a, na);
	//printArray(a, na);
	//int key;
	//cout << "Enter key you want to search: ";
	//cin >> key;
	////int pos = BinarySearch(a, na, key);
	//int pos = RecursiveBinarySearch(a, 0, na - 1, key);
	//if (pos == -1)
	//{
	//	cout << "\t" << key << " does not exist in the array" << endl;
	//}
	//else
	//{
	//	cout << "\t" << key << " locates at the position " << pos << endl;
	//}
	

	system("pause");

	return 0;
}
