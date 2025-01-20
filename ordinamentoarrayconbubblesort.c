#define N 10  // Definisci la dimensione dell'array (esempio, 10)

void bubblesort(int* array) {
    for (int outer = 0; outer < N; outer++) {
        for (int inner = outer + 1; inner < N; inner++) {
            if (array[outer] > array[inner]) {
                int temp = array[outer];
                array[outer] = array[inner];
                array[inner] = temp;
            }
        }
    }
}