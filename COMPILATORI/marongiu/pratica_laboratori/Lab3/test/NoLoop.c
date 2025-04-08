int noLoop(int a) {
    if (a > 10) return 1;
    for (int i = 0; i < 10; i++) a++;
    return 0;
}