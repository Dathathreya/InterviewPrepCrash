#include <bits/stdc++.h>

using namespace std;
typedef long long int lli;
lli nC2(lli v){
	return 1ll*v*(v-1)/2;
}

typedef long long int lli;
// Question_2
void maxSubsequenceSum(vector<int> nums){
	int target = nums[0];
	int n = nums.size() - 1,i=0,j=0,cnt =0;
	int lefthalf = (n/2)+(n&1);
	int righthalf = (n/2);
	vector<pair< int,int>> left;
	vector<pair< int, int>> right;
	for(i=0;i<(1<<lefthalf);i++){
		lli ls = 0 , rs = 0;
		bool once = false;
		for(int bit=0;bit<lefthalf;bit++){
			if((1<<bit)&i){
				ls += nums[bit+1];
				if(i<(1<<righthalf)){
					rs += nums[bit+1+lefthalf];
				}
				once = true;
			}
		}
		if(once)
			{ left.push_back({ls,i}); }
		if(once && (i<(1<<righthalf)))	
			{ right.push_back({rs,i}); }
	}

	sort(right.begin(),right.end());
	sort(left.begin(),left.end());
	 std::pair<int, int> value1 ={nums[0],-1};
	auto itrA1 = lower_bound(right.begin(),right.end(),value1); 
	auto itrA2 = lower_bound(left.begin(),left.end(),value1); 
	// direct search
	while((itrA1!=right.end())&&(itrA1->first==nums[0])){
		cnt = max(cnt,itrA1->second);
		itrA1++;
	}
	
	// direct search
	while((itrA2!=left.end())&&(itrA2->first==nums[0])){
		cnt = max(cnt,itrA2->second);
		itrA2++;
	}

	for(i=0;i<left.size();i++){
		 std::pair<int, int> value ={nums[0]-left[i].first,-1};
		auto itrA = lower_bound(right.begin(),right.end(),value); 
		if((itrA!=right.end())&&(itrA->first==value.first))
		{	
					lli bpcl=__builtin_popcount(left[i].first);
					lli bpcr=__builtin_popcount(itrA->second);
					if(cnt<(bpcl+bpcr)){
						cnt = bpcl+bpcr;
					}
				
		}
	}
	printf("%d ",cnt);
	return;
}

// Question_3
void MaxElementsCount(int k,vector<int> arr){
	sort(arr.begin(),arr.end());
	// for(auto itr: arr){
	// 	cout<<itr<<" ";
	// }
	// cout<<endl;
	int n = arr.size();
	int i=0,j=0,cnt=0;
	for(i=0;i<n;){
		while((j<n)&&((arr[j]-arr[i])<=k)){
			j++;
		}
		if(cnt<(j-i)){
			cnt = j-i;
		}
		i++;
	}
	printf("%d ",cnt);
	return;
}

int main(){
	int k,n,i,x;
	vector<int> arr;
	/*
		cin>>k>>n;
		// Question_3
		// sliding window for count of maximum Elements which forms a subset in an array of size 
		// with min,max difference between them as k;
		for(i=0;i<n;i++){
			cin>>x;
			arr.push_back(x);
		}
		MaxElementsCount(k,arr); 
	*/
	///*
		cin>>n;
		//Question_3
		//sliding window for count of maximum Elements which forms a subset in an array of size 
		//with min,max difference between them
		//as k;
		for(i=0;i<n;i++){
			cin>>x;
			arr.push_back(x);
		}
		maxSubsequenceSum(arr); 
	//*/
}

// 2
// 8
// 4
// 2
// 6
// 100
// 101
// 102
// 110
// 101
// answer: 4  {100 101 101 102}

// 1
// 5
// 1
// 2
// 3
// 2
// 4
// answer: 3 {1 2 2}
