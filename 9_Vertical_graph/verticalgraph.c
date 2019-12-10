#include<stdio.h>
#include<stdlib.h>
#define MAX_ARRAY_SIZE 80

void set_start_end (int a, int b, int *min, int *max) {
    if ( a > b ) {
        *min = b;
        *max = a;
    } else {
        *min = a;
        *max = b;
    }
}

/* Draw chart accourding provided data, create multi-dimentional array
fill with space or '#' */
void paint_chart (int *arr, int size, int min_value, int max_value) {
    int chart_height = max_value - min_value;
    int i, j, start, end;

    char chart_array[chart_height][size + 1];

    // null terminator
    for ( i = 0; i < chart_height; ++i )
        chart_array[i][size] = '\0';

    for ( j = 0; j < size; ++j ) {
        set_start_end(max_value, max_value - arr[j], &start, &end);
        for ( i = 0; i < start; ++i )
            chart_array[i][j] = ' ';
        for ( ; i < end; ++i )
            chart_array[i][j] = '#';
        for ( ; i < chart_height; ++i )
            chart_array[i][j] = ' ';
    }

    for ( i = 0; i < chart_height; ++i ) {
        printf( "%s\n", chart_array[i]);
    }
}

/* Read input stream until end of file (EOF) */
int read_stdin (FILE *input_stream, int *arr, int size, int *min, int *max) {
    int count = 0;

    // Reads up to the max allowed size whichi 80
    while ( count < size  &&  fscanf(input_stream, "%d", &arr[count]) == 1 )
    { // Reading stops when the read fails or until EOF
        if ( arr[count] > *max )
            *max = arr[count];
        if ( arr[count] < *min )
            *min = arr[count];
        ++count;
    }
    return count;
}
int main(int argc, char const *argv[]) {
  int min_value = 0, max_value = 0;
  int values[MAX_ARRAY_SIZE];
  int values_num = read_stdin(stdin, values, MAX_ARRAY_SIZE, &min_value, &max_value);

  paint_chart(values, values_num, min_value, max_value);
  return 0;
}
