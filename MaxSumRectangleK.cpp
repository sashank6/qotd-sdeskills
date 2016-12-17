class Solution {
public:
	int maxSumSubmatrix(vector<vector<int>>& mat, int k) {
		int n = mat.size();
		int m = mat[0].size();
		for (int i = 1; i < m; i++) {
			for (int j = 0; j < n; j++) {
				mat[j][i] += mat[j][i - 1];
			}
		}
		int maxsum = INT_MIN;
		for (int start = 0; start < m; start++) {
			for (int end = start; end < m; end++) {
				int arr[n + 1] = { 0 };
				for (int row = 0; row < n; row++)
					arr[row + 1] = mat[row][end]
							- ((start == 0) ? 0 : mat[row][start - 1]);
				int gsum = INT_MIN;

				for (int i = 1; i < n + 1; i++)
					arr[i] += arr[i - 1];
				for (int i = 0; i < n + 1; i++) {
					for (int j = 0; j < i; j++) {
						if ((arr[i] - arr[j]) <= k) {
							gsum = max(gsum, arr[i] - arr[j]);
						}

					}
				}
				if (gsum > maxsum) {
					maxsum = gsum;
				}
			}
		}
		return maxsum;

	}
};

