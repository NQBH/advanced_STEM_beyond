using System;

class G4G {
	// function to check whether any pair exists whose sum is equal to the given target value
	static bool two_sum_naive(int[] arr, int target) {
		int n = arr.Length;
		for (int i = 0; i < n; ++i) // iterate through each element in the array
			for (int j = i + 1; j < n; ++j) // for each element arr[i], check every other element arr[j] that comes after it
				if (arr[i] + arr[j] == target) return true; // check if the sum of the current pair equals the target
		return false; // if no pair is found after checking all possibilities
	}

	static void Main() {
		int[] arr = { 0, -1, 2, -3, 1 };
        int target = -2;

        // call the two_sum_naive & print the result
        if (two_sum_naive(arr, target)) Console.WriteLine("true");
        else Console.WriteLine("false");
	}
}