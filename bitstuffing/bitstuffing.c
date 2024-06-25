#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

// Function to perform bit stuffing
void bitStuffing(char* data, int* size) 
{
    int count = 0;
    int newSize = *size;

    for (int i = 0; i < *size; i++) 
    {
        if (data[i] == '1') 
        {
            count++;
        } 
        else 
        {
            count = 0;
        }

        if (count == 5) 
        {
            // Shift all elements to the right by one
            for (int j = newSize; j > i + 1; j--) 
            {
                data[j] = data[j - 1];
            }

            // Insert '0' after the fifth consecutive '1'
            data[i + 1] = '0';
            newSize++;
            count = 0;
        }
    }

    *size = newSize;
}
// Function to perform bit destuffing
void bitDestuffing(char* data, int* size) 
{
    int count = 0;
    int newSize = *size;

    for (int i = 0; i < *size; i++) 
    {
        if (data[i] == '1') 
        {
            count++;
        } 
        else 
        {
         count = 0;
        }

        if (count == 5 && i < newSize - 1 && data[i + 1] == '0')
         {
    // Shift all elements to the left by one
              for (int j = i + 1; j < newSize ; j++) 
                {
                        data[j] = data[j + 1];
                }

               count = 0;
                }

        if (count == 5 && i < newSize - 1 && data[i + 1] == '0')
         {
    // Shift all elements to the left by one
              for (int j = i + 1; j < newSize ; j++) 
                {
                        data[j] = data[j + 1];
                }

               count = 0;
               newSize--; // Adjust newSize after shifting
         }             

    }

    *size = newSize;
}
int main()
{
    char data[MAX_SIZE];
    int size;

    // Input data
    printf("Enter the data in Binary ");
    scanf("%s", data);

    // Calculate the size of the data
    for (size = 0; data[size] != '\0'; size++);

    // Perform bit stuffing
    bitStuffing(data, &size);
    printf("Stuffed data: %s\n", data);

    // Perform bit destuffing
    bitDestuffing(data, &size);
    printf("Destuffed data: %s\n", data);

    return 0;
}
