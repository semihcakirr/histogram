#include <stdio.h>

#define MAX_SIZE 1000 /* Input array's size. (UPDATE IT DEPENDING ON YOUR ARRAY SIZE.) */

/* Function to find the size of the array. */
int find_size_of_array(int A[])
{
    int size = 0;
    while (A[size] != -1 && size < MAX_SIZE)
    {
        size++;
    }
    return size;
}

/* Function to print the histogram. */
void print_histogram(int A[], int size, int lower, int upper)
{
    int counts[upper - lower + 1];
    int i;
    int row, col;

    /* Initializing counts arrays elements to zero. */
    for (i = 0; i < upper - lower + 1; i++)
    {
        counts[i] = 0;
    }

    /* Counting the occurrences of each number within the given range. */
    for (i = 0; i < size; i++)
    {
        if (A[i] >= lower && A[i] <= upper)
        {
            counts[A[i] - lower]++;
        }
    }

    /* Finding the maximum count. */
    int max_count = 0;
    for (i = 0; i < upper - lower + 1; i++)
    {
        if (counts[i] > max_count)
        {
            max_count = counts[i];
        }
    }

    /* Printing the histogram. */
    for (row = max_count; row > 0; row--)
    {
        for (col = 0; col < upper - lower + 1; col++)
        {
            if (counts[col] >= row)
            {
                printf("*");
            }
            else
            {
                printf(" ");
            }
        }
        printf("\n");
    }
}

/* Function to calculate the average. */
void calculate_average(int A[], int size)
{
    double sum = 0;
    double average;
    int i;
    for (i = 0; i < size; i++)
    {
        sum += A[i];
    }
    average = sum / (double)size;
    printf("Average: %.2lf\n", average);
}

/* Function to calculate the mode. */
void calculate_mode(int A[], int size)
{
    int counts[MAX_SIZE] = {0};
    int max_count = 0;
    int i;

    for (i = 0; i < size; i++)
    {
        counts[A[i]]++;
        if (counts[A[i]] > max_count)
        {
            max_count = counts[A[i]];
        }
    }

    printf("Mode: ");
    for (i = 0; i < MAX_SIZE; i++)
    {
        if (counts[i] == max_count)
        {
            printf("%d ", i);
        }
    }
    printf("\n");
}

/* Function to calculate the median */
double calculate_median(int A[], int size)
{
    int sorted_array[size];
    int i, j;
    int temp;
    for (i = 0; i < size; i++)
    {
        sorted_array[i] = A[i];
    }

    for (i = 0; i < size - 1; i++)
    {
        for (j = 0; j < size - i - 1; j++)
        {
            if (sorted_array[j] > sorted_array[j + 1])
            {
                temp = sorted_array[j];
                sorted_array[j] = sorted_array[j + 1];
                sorted_array[j + 1] = temp;
            }
        }
    }

    if (size % 2 == 0)
    {
        return (sorted_array[size / 2 - 1] + sorted_array[size / 2]) / 2.0;
    }
    else
    {
        return sorted_array[size / 2];
    }
}

int main()
{
    int counter = 0;

    /* The input array definiton. */
    int number_array[MAX_SIZE] = {113, 166, 97, 182, 57, 198, 162, 93, 115, 155,
                                  109, 155, 174, 88, 154, 185, 88, 96, 169, 107,
                                  112, 92, 88, 126, 190, 77, 161, 54, 81, 149,
                                  118, 78, 120, 169, 79, 176, 89, 125, 150, 108,
                                  180, 95, 121, 172, 107, 158, 196, 82, 87, 106,
                                  179, 72, 152, 101, 116, 53, 85, 69, 167, 67,
                                  156, 90, 168, 185, 89, 168, 85, 127, 80, 72,
                                  144, 89, 59, 104, 163, 142, 147, 140, 112, 160,
                                  111, 169, 58, 66, 167, 189, 144, 197, 81, 161,
                                  180, 196, 93, 93, 126, 173, 76, 60, 122, 105, -1};

    /* Getting user input for the interval. */
    int lower, upper;
    printf("Enter A and B values: ");
    scanf("%d %d", &lower, &upper);
    while (lower < 50 || upper > 200) /* Loop for invalid intervals. */
    {
        printf("Please enter a valid interval! The A value must be minimum 50 and B value must not exceed 200!\n"); /* Printing error message. */
        printf("Enter A and B values: ");
        scanf("%d %d", &lower, &upper);
    }

    /* Printing the histogram. */
    int size = find_size_of_array(number_array);
    print_histogram(number_array, size, lower, upper);

    /* Additional numbers input loop. */
    int add_more = 1;
    printf("Would you like to add new numbers? (Press 1 for yes, Press 0 for no): ");
    scanf("%d", &add_more); /* Scanning the input. */
    if (add_more == 1)
    {
        printf("Enter the numbers (up to five, end with -1):\n");
        int new_number, index = size;
        while (counter < 5)
        {
            scanf("%d", &new_number);
            if (new_number == -1 || index >= MAX_SIZE - 1)
                break;
            number_array[index++] = new_number;
            counter++;
        }
        number_array[index] = -1; /* Adding the terminator. */
        size = index;
        /* Printing updated histogram.*/
        print_histogram(number_array, size, lower, upper);
    }
    else if (add_more != 1 && add_more != 0) /* Printing an error message for wrong choice. */
    {
        printf("You did not enter a valid choice.\n");
    }

    /* Calculating and printing average. */
    calculate_average(number_array, size);

    /* Calculating and printing mode. */
    calculate_mode(number_array, size);

    /* Calculating and printing median. */
    double median = calculate_median(number_array, size);
    printf("Median: %.2f\n", median);

    return 0;
}