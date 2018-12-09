void linear_search(int arr[], int len, int num) {
	int flag = 1;

	for(int i = 0; i < len; i++) {
		if(arr[i] == num) {
			cout << "Found " << num << " at index " << i << endl;
			flag = 0;
			break;
		}
	}

	if(flag) cout << num << " not found." << endl;
}