import java.util.ArrayList;
import java.util.List;

class GfG {
	// function to find a continuous subarray whose sum = a given number
	static ArrayList<Integer> subarray_sum(int[] arr, int target) {
		ArrayList<Integer> res = new ArrayList<>();
		int n = arr.length;
		for (int s = 0; s < n; ++s) { // pick a starting point for a subarray
			int curr = 0;
			// consider all ending points for the picked starting point
			for (int e = s; e < n; ++e) {
				curr += arr[e];
				if (curr == target) {
					res.add(s + 1);
					res.add(e + 1);
					return res;
				}
			}
		}
		res.add(-1); // if no satisfying subarray is found
        return res;
	}

	public static void main(String[] args) {
		int[] arr = {15, 2, 4, 8, 9, 5, 10, 23};
        int target = 23;
        ArrayList<Integer> res = subarray_sum(arr, target);
        for (int ele : res)
        	System.out.print(ele + " ");
	}
}