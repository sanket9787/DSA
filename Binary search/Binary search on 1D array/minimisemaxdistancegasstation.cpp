#include <bits/stdc++.h>
double minimiseMaxDistance(vector<int> &arr, int k){
	// Write your code here.
	int n = arr.size();
	// vector<int> a(n-1, 0);
	
	// int ind = 0;
	// for(int i = 0; i<k ; i++){
	// 	long double maxlen = -1;
	// 	for(int j = 0; j< n - 1; j++){
	// 		long double diff = arr[j+1] - arr[j];
	// 		long double length = diff / (double)(a[j]+1);
			
	// 		if(length > maxlen) {
	// 			maxlen = length;
				
	// 			ind = j;
				
	// 		}
	// 	}
		
	// 	a[ind]++;
	// }
	// long double maxi = -1;
	// for(int i = 0; i<n-1; i++){
	// 	long double diff = arr[i+1] - arr[i];
	// 	long double length = diff/(double)(a[i]+1);
	// 	if(length > maxi){
	// 		maxi = length;
	// 	}
		
	// }

	priority_queue<pair<long double, int>> q;
	vector<int> howMany(n-1,0);

	for(int i = 0; i < arr.size() - 1; i++){
		long double diff = arr[i+1] - arr[i];
		q.push({diff,i});
	}

	for(int i= 0; i< k; i++){
		auto top = q.top();
		q.pop();
		
		int secInd = top.second;
		howMany[secInd]++;

		long double diff = arr[secInd+1] - arr[secInd];
		long double Newlength = diff/ (double) (howMany[secInd]+1);
		q.push({Newlength, secInd});

	}

	auto top = q.top();
	return top.first;
}
