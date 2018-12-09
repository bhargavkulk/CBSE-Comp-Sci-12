void binary_search(int arr[], int len, int num) {
	int low = 0;
	int high = len - 1;
	int flag = 1;

	while(low <= high) {
		int mid = (low + high) / 2;
		if(arr[mid] < num)
			low = mid + 1;
		else if(arr[mid] > num)
			high = mid - 1;
		else {
			cout << "Found " << num << " at index " << mid << endl;
			flag = 0;
			break;
		}
	}

	if(flag) cout << num << " not found." << endl;
}