//
// Created by patha on 13-01-2021.
//

#include "iostream"

using namespace std;

int count = 1;
void towers(int num, char frompeg, char topeg, char auxpeg)
{
    if (num == 1)
    {
        printf("\n %d. Move disk 1 from peg %c to peg %c", count++, frompeg, topeg);
        return;
    }
    towers(num - 1, frompeg, auxpeg, topeg);
    printf("\n %d. Move disk %d from peg %c to peg %c", count++, num, frompeg, topeg);
    towers(num - 1, auxpeg, topeg, frompeg);
}

int main()
{
    int num;
    printf("Enter the number of disks : ");
    scanf("%d", &num);
    printf("The sequence of moves involved in the Tower of Hanoi are :\n");
    towers(num, 'A', 'C', 'B');
    printf("\n Total moves required are : %d", count-1);
    return 0;
}
