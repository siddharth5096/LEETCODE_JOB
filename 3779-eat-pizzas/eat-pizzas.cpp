class Solution
{
public:
    long long maxWeight(vector<int>& arr)
    {
        // Step 1: Sort the array in descending order
        sort(arr.begin(), arr.end(), greater<int>());

        // Step 2: Compute the maximum possible sum
        return computeMaxGain(arr, (arr.size() / 4 + 1) / 2);
    }

private:
    long long computeMaxGain(vector<int>& slices, int oddMeals) 
    {
        long long totalGain = 0;
        int indexA = 0;

        // Step 3: Pick the first 'oddMeals' elements
        while (indexA < oddMeals) 
        {
            totalGain += slices[indexA++];
        }

        int evenMeals = slices.size() / 4 - oddMeals, indexB = 0;

        // Step 4: Pick elements from deeper positions using a specific offset pattern
        while (indexB < evenMeals) 
        {
            totalGain += slices[oddMeals + 2 * indexB++ + 1];
        }

        return totalGain;
    }
};