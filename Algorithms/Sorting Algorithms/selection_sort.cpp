void selectionSort(int arr[], int len) { 
    int idx; 
    for(int i = 0; i < n-1; i++) { 
        idx = i; 
        for (j = i+1; j < n; j++) {
          if (arr[j] < arr[min_idx]) 
            min_idx = j; 
       	}
  
  		if(idx != j) {
	        int temp = arr[idx];
	        arr[idx] = arr[j];
	        arr[j] = temp;
        } 
    } 
} 