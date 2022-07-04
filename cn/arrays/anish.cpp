int tripletSum(int *arr, int n, int sum)
{
    // Write your code here
    int count = 0;
    sort(arr, arr + n);
    for (int k = 0; k < n; k++)
    {
        int i = k + 1;
        int j = n - 1;
        int num = sum - arr[k];
        while (i < j)
        {

            if (arr[i] + arr[j] > num)
            {
                j--;
            }
            else if (arr[i] + arr[j] < num)
            {
                i++;
            }
            else
            {
                int elementAtStart = arr[i];
                int elementAtEnd = arr[j];

                if (elementAtStart == elementAtEnd)
                {
                    int totalElementsFromStartToEnd = (j - i) + 1;
                    count += (totalElementsFromStartToEnd * (totalElementsFromStartToEnd - 1) / 2);
                    break;
                }

                int tempStartIndex = i + 1;
                int tempEndIndex = j - 1;

                while (tempStartIndex <= tempEndIndex && arr[tempStartIndex] == elementAtStart)
                {
                    tempStartIndex += 1;
                }

                while (tempEndIndex >= tempStartIndex && arr[tempEndIndex] == elementAtEnd)
                {
                    tempEndIndex -= 1;
                }

                int totalElementsFromStart = (tempStartIndex - i);
                int totalElementsFromEnd = (j - tempEndIndex);

                count += (totalElementsFromStart * totalElementsFromEnd);

                i = tempStartIndex;
                j = tempEndIndex;
            }
        }
    }
    return count;
}