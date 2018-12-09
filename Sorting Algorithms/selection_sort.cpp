void selection_sort(int arr[], int len) {
	for(int i = 0; i < len - 1; i++) {
		int min = i;

		for(int j = i + 1; j < len; j++) {
			// to sort in descending, make '<' to '>'
			if(arr[j] < arr[min]) min = j;
		}

		if(min != j) {
			int temp = arr[min];
			arr[min] = arr[i];
			arr[i] = temp;
		}
	}
}