#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

int highestFrequency(int arr[], int n) {
    // Write your code here
    unordered_map<int, int> mp;
    int ans = 0;
    for(int i=0; i<n; i++)
	{
		mp[arr[i]]++;
		if(mp[arr[i]]>ans)
			ans = mp[arr[i]];
	}
    return ans;
}

int main()
{
	int n;
	cin >> n;
	int* arr = new int[n];
	unordered_map<int, int> mp;
	vector<int> ans;
	for(int i=0; i<n; i++)
	{
		cin >> arr[i];
		mp[arr[i]]++;
		if(mp[arr[i]] == 1)
			ans.push_back(arr[i]);
	}

	for(int i=0; i<ans.size(); i++)
		cout << ans[i] << " ";

	return 0;
}
