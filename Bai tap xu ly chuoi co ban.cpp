// Bai tap xu ly chuoi co ban.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
/*
Bài tập 1: Đếm ký tựtrong chuỗi
Đề bài :
Viết chương trình nhậpvào một chuỗi ký tự và một ký tự cần đếm, 
sau đó trả vềsốlần xuất hiện của ký tự đó trong chuỗi(phân biệt chữ hoa / thường).
Ví dụ minh họa :
Input: s = "Hello World", char = 'l'
Output : 3
Input : s = "Programming", char = 'g'
Output : 2
Input : s = "Python", char = 'x'
Output : 0
Input : s = "HELLO", char = 'h'
Output : 0 (vì phân biệt chữ hoa / thường)
*/

int countstring(char a[], char x, int n)
{
	int count = 0;
	for (int i = 0; i < n; i++)
	{
		if (a[i] == x)
		{
			count++;
		}
	}
	return count;
}
/*
Bài tập 2: Kiểm tra chuỗipalindrome
Đề bài:
Viết chương trình kiểm tra xem một chuỗi có phải là palindrome hay không.
Palindrome là chuỗi đọc từ trái sang phải và từ phải sang trái đều giống nhau. 
Bỏ qua khoảng trắng và không phân biệt chữ hoa/thường.
*/
// Ham kiem tra ky tu dac biet
int isLetterOrDigit(char a)
{
	if ((a >= '0' && a <= '9') || (a >= 'a' && a <= 'z') || (a >= 'A' && a <= 'Z'))
		return 1;
	return 0;
}
// Ham palindrome
bool palindrome(char a[])
{
	int j = 0;
	_strlwr(a);  // string lower: chuyen string ve chu thuong
	for (int i = 0; i < strlen(a); i++) // xoa bo chu viet hoa khoang trang
	{
		if(isLetterOrDigit(a[i]) == 1)
		a[j++] = a[i];
	}
	a[j] = '\0';
	// Cach 1 : So sanh chuoi voi chuoi dao nguoc
	char acpy[30];
	strcpy(acpy, a);
	if (strcmp(_strrev(acpy),a)!=0) // ( can tao ban sao )
	{
		return false;
	}
	
	// Cach 2: Su dung 2 con tro ( dau va cuoi ) di chuyen ve giua
	int left = 0, right = strlen(a) - 1;
	while (left < right) {
		if (a[left] != a[right])
			return false;
		left++;
		right--;
	}
	return true;
}
int main()
{
	char s[30];
	printf("Nhap s: ");
	fgets(s, strlen(s), stdin);
	printf("%d",palindrome(s));
	return 0;

}