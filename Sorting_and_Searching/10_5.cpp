//Algorithm : 	SparseSearch : Do Binary Search but if you encounter space,
//				keep searching till you find the closest non-empty string
//Time Complexity : O(logN)
//Space Complexity : O(1)
//Assumption : Input array of strings will be sorted

#include <iostream>
#include <string>
using namespace std;
#include <string>

int SparseSearch(string* arr, int start, int end, string val) {
	if (start>end)
		return -1;
	if (val == "") {
		cout << "ERROR: val is empty!!" << endl;
		return -1;
	}
	cout << "SparseSearch with start=" << arr[start] << " and end=" << arr[end] << endl;
	int mid = (start+end)/2;
	if (arr[mid] == "") { //Find the closest non-empty mid
		cout << mid << " location has empty string!" << endl;
		int left = mid - 1;
		int right = mid + 1;
		while(left >= start && right<=end) {
			if ((arr[left] != "") || (arr[right] != "")) {
				mid = (arr[left] != "") ? left : right;
				cout << "Found new mid string " << arr[mid] << " with mid " << mid << endl;
				break;
			}
			left--;
			right++;
		}
		if (arr[mid] == "") {
			if (left<start && right>end)  //Exhausted both ends
					return -1;
			else if (left<start) {
				while(right<=end) {
					if (arr[right] != "") {
						mid = right;
						cout << "Found new mid string " << arr[mid] << " with mid " << mid << endl;
						break;
					}
					right++;
				}
			} else {
				while(left>=start) {
					if (arr[left] != "") {
						mid = left;
						cout << "Found new mid string " << arr[mid] << " with mid " << mid << endl;
						break;
					}
					left--;
				}
			}
		}
		if (arr[mid] == "")
			return -1;
	}
	if (arr[mid] == val)
		return mid;
	if (val.compare(arr[mid]) < 0)
		return(SparseSearch(arr, start, mid-1, val));
	else
		return(SparseSearch(arr, mid+1, end, val));
}

int main() {

	//string arr[] = {"at", "", "", "", "ball", "", "", "car", "", "", "dad", "", ""};
	string arr[] = {"", "", "", "", "", "", "", "", "", "", "", "k"};
 	string val = "ball";
	int res = SparseSearch(arr, 0, 11, val);
	if (res==-1)
		cout << val << " not found!" << endl;
	else
		cout << val << " found at " << res << endl;

	return 0;
}
