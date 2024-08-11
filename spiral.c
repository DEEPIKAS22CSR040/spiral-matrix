int* spiralOrder(int** matrix, int matrixSize, int* matrixColSize, int* returnSize) {
    int m = matrixSize, n = *matrixColSize;
    int left = 0, right = n - 1, top = 0, bottom = m - 1;
    int* ans = (int*)malloc(m * n * sizeof(int));
    int i, k = 0;

    while (top <= bottom && left <= right) {
        // Traverse from left to right
        for (i = left; i <= right; i++)
            ans[k++] = matrix[top][i];
        top++;

       
        for (i = top; i <= bottom; i++)
            ans[k++] = matrix[i][right];
        right--;

        
        if (top <= bottom) {
            for (i = right; i >= left; i--)
                ans[k++] = matrix[bottom][i];
            bottom--;
        }

        
        if (left <= right) {
            for (i = bottom; i >= top; i--)
                ans[k++] = matrix[i][left];
            left++;
        }
    }

    *returnSize = k;
    return ans;
}
