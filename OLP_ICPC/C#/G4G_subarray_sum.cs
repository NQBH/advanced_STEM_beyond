using System;
using System.Collections.Generic;

class GfG {
	// function to find a continuous subarray which adds up to a given number
	static List<int> subarray_sum(int[] arr, int target) {
		List<int> res = new List<int>();
		int n = arr.Length;
		for (int s = 0; s < n; ++s) { // pick a starting point for a subarray
			int curr = 0;
			// consider all ending points for the picked starting point
			for (int e = s; e < n; ++e) {
				curr += arr[e];
				if (curr == target) {
					res.Add(s + 1);
					res.Add(e + 1);
					return res;
				}
			}
		}
		res.Add(-1); // if no satisfying subarray is found
		return res;
	}

	static void Main() {
		int[] arr = {15, 2, 4, 8, 9, 5, 10, 23};
        int target = 23;
        List<int> res = subarray_sum(arr, target);
        foreach (var ele in res)
        	Console.Write(ele + " ");
	}
}