// 2-D array is an array of arrays

#include <iostream>
using namespace std;

int main()
{
    int a[3][3] = {6, 2, 3, 4, 5, 8, 5, 6, 11};
    int *ptr;
    // ptr = a; -> this is not valid in 2-D array because assigning address of first element of an 2-D array is a whole array that is {6,2,4}
    ptr = &a[0][0]; // or ptr = a[0]; // but this is invalid ptr = a[0][0]; because this will store the value of a[0][0] in ptr that is not possible
    // different ways to access base address/contents of the array: p, a, &a[0][0], &a, *a, a[0]
    //a+1 = &a[1] = addressof 4;
    // *(a + 1) = a[1] = a&[1][0] = addressof 4; 
    // *(*(a+1) + 2) = a[1][2] = 8; 
    // general form = *(*(arr +i)+j) = a[i][j]

    return 0;
}