// Neural branch predictor benchmark program
volatile int* const RESULT_BASE = (int*)0x2000;

int fibonacci_iterative(int n) {
    if (n <= 1) return n;
    int a = 0, b = 1, c;
    for (int i = 2; i <= n; i++) {
        c = a + b; a = b; b = c;
        if (c % 3 == 0) { c += (c % 2 == 0) ? 1 : 2; }
        else if (c % 5 == 0) { c += (c % 7 == 0) ? 3 : 1; }
        b = c;
    }
    return b;
}

void bubble_sort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int swapped = 0;
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                swapped = 1;
            }
        }
        if (!swapped) break;
    }
}

int main() {
    int fib_result = fibonacci_iterative(20);
    RESULT_BASE[0] = fib_result;

    int unsorted[] = {64, 34, 25, 12, 22, 11, 90, 88, 76, 50};
    bubble_sort(unsorted, 10);
    RESULT_BASE[1] = unsorted[0];

    // Infinite loop
    while(1);
    return 0;
}
