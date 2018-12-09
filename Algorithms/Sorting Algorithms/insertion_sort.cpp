void insertion_sort(int arr[], int len) {
	for(int i = 1; i < len; i++) {
		int x = a[i];

		int j = i - 1;
		while(x < a[j] && j >= 0) {
			a[j+1] = a[j];
			j--;
		}

		a[j+1] = temp;
	}
}