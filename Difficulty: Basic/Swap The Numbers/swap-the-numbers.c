void swap(int *a, int *b) {
    // code here
    *a^=*b;
    *b^=*a;
    *a^=*b;
}
