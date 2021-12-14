 #include <bits/stdc++.h>

using namespace std;
class SGTree{
	vector<int> seg;

public:
	SGTree(int n){
		seg.resize(4*n+1);
	}

	void build(int ind, int low, int high, int arr[] ){
		if(low==high){
			seg[ind]=arr[low];
			return;
		}
		int mid=(low+high)/2;
		build(2*ind+1, low , mid, arr);
		build(2*ind+2, mid+1, high, arr);
		seg[ind]=min(seg[2*ind+1],seg[2*ind+2]);
	}
	void update(int seg_ind, int arr_ind,int value, int low, int high){
		if(low==high){
			seg[seg_ind]=value;
			return;
		}
		int mid = (low+high)/2;
		if(mid>=arr_ind){
			update(2*seg_ind+1,arr_ind,value,low, mid);
		}
		else {
			update(2*seg_ind+2,arr_ind, value,mid+1,high);
		}
		seg[seg_ind]=min(seg[2*seg_ind+2],seg[2*seg_ind+1]);
	}
	int query(int ind, int low, int high, int l, int r){
		//no overlap
		//l r low high or low high l r
		if (l>high||low>r)return INT_MAX;

		//complete overlap
		//[l low  high r]
		if(l<=low&&r>=high)return seg[ind];

		//othrwise partial overlap
		int mid= (low+high)/2;
		int left=query(2*ind+1,low, mid,l,r);
		int right=query(2*ind+2, mid+1, high, l,r);
		return min(left, right);
	}

};

void solve(){
	int n;
	cin>>n;
	int arr[n];
	for (int i = 0; i < n; ++i)
	{
		cin>>arr[i];

	}
	SGTree sgTree= SGTree(n);
	sgTree.build(0, 0,n-1, arr);
	int q;
	cin >>q;
	while(q--){
		int type;
		cin>>type;
		if(type==1){
			int l,r;
			cin>>l>>r;
			
			cout<<sgTree.query(0, 0,n-1, l,r)<<endl;
			}
		else{
			int ind, value;
			cin>>ind>>value;
			sgTree.update(0,ind, value, 0, n-1);
		    }
		}
	}
void solve2(){
	int n1;
	cin>>n1;
	int arr1[n1];
	for (int i=0;i<n1;i++){
		cin>>arr1[i];
	}
	SGTree sg1= SGTree(n1);
	sg1.build(0,0, n1-1, arr1);

	int n2;
	cin>>n2;
	int arr2[n2];
	for (int i=0;i<n2;i++){
		cin>>arr2[i];
	}
	SGTree sg2= SGTree(n2);
	sg2.build(0,0, n2-1, arr2);

	int q;
	cin>>q;
	while(q--){
		int type;
		cin>>type;
		if(type==1){
			int l1,l2,r1,r2;
			cin>>l1>>r1>>l2>>r2;
			int min1=sg1.query(0,0,n1-1,l1,r1);
			int min2=sg2.query(0,0,n2-1,l2,r2);
			cout<<min(min1,min2)<<endl;
		}
		else{
			int arrNo, ind, value;
			cin>>arrNo>>ind>>value;
			if(arrNo==1){
				sg1.update(0,ind, value,0,n1-1);
			}
			else{
				sg2.update(0,ind, value,0,n2-1);
			}
		}

	}
}
int main(){
	solve2();
}