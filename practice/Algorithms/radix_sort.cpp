element     sort(1)    sort(2)      sort(3)

804         001         001         001
026         052         804         005
005         804         005         026
064         064         026         052
052         005         052         064
001         026         064         804

sort(x) => stable sort xth digit (counting sort)
after xth digit sorting element having <= x digit are in correct order

Radix_sort(A, d) {
    //each key in A[1...n] is a d-digit integer
    // digits are numbered 1 to d from right to left
    for(i=1 to d) {
        use a stable sort like counting sort algorithm to sort A on digit i
    }
}