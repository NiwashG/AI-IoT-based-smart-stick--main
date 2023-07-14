#include <stdio.h>

int main()
{
    int numMarkers;
    printf("Enter the number of markers: ");
    scanf("%d", &numMarkers);

    int markers[numMarkers];
    printf("Enter the values of the markers:\n");
    for (int i = 0; i < numMarkers; i++)
    {
        scanf("%d", &markers[i]);
    }

    int jamesPoints = 0;
    int bobPoints = 0;

    // James shoots first
    for (int i = 0; i < numMarkers; i++)
    {
        if (i % 2 == 0)
        {
            // James' turn
            if (markers[0] > markers[numMarkers - 1])
            {
                jamesPoints += markers[0];
                // Remove the first marker from the array
                for (int j = 0; j < numMarkers - 1; j++)
                {
                    markers[j] = markers[j + 1];
                }
            }
            else
            {
                jamesPoints += markers[numMarkers - 1];
                // Remove the last marker from the array
                numMarkers--;
            }
        }
        else
        {
            // Bob's turn
            if (markers[0] > markers[numMarkers - 1])
            {
                bobPoints += markers[0];
                // Remove the first marker from the array
                for (int j = 0; j < numMarkers - 1; j++)
                {
                    markers[j] = markers[j + 1];
                }
            }
            else
            {
                bobPoints += markers[numMarkers - 1];
                // Remove the last marker from the array
                numMarkers--;
            }
        }
    }

    printf("James' total points: %d\n", jamesPoints);
    printf("Bob's total points: %d\n", bobPoints);

    if (jamesPoints > bobPoints)
    {
        printf("James wins the shooting competition!\n");
    }
    else if (jamesPoints < bobPoints)
    {
        printf("Bob wins the shooting competition!\n");
    }
    else
    {
        printf("It's a tie!\n");
    }

    return 0;
}