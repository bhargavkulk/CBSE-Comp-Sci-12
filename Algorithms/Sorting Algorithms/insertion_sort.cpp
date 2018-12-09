void insertion_sort(int arr[], int len) {
	for(int i = 1; i < len; i++) {
		int j = i;

		while(j > 0 && arr[j-1] > arr[j]) {
			int temp = arr[j];
			arr[j] = arr[j-1];
			arr[j-1] = temp;

			j++;
		}
	}
}