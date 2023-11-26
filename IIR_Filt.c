float infiniteIR(float inSample) {
    int i;
    float aSum = 0, bSum = 0;

    // Shift x array
    for(i = 0; i < N - 1; i++) {
        x[i] = x[i + 1];
    }
    x[N - 1] = inSample;

    // Compute bSum
    for(i = 0; i < N; i++) {
        bSum += x[N - 1 - i] * b[i];
    }

    // Compute aSum
    for(i = 1; i < N; i++) {
        aSum += y[i - 1] * a[i];
    }

    // Shift y array
    for(i = N - 1; i > 0; i--) {
        y[i] = y[i - 1];
    }

    // Calculate and return output
    y[0] = bSum - aSum;
    return y[0];
}
