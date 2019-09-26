void reverse( int arr[], unsigned int len ){
	for(int i=0;i<len/(float)2;i++){
		int a = arr[i];
		int b = arr[len-1-i];
		arr[i] = b;
		arr[len-1-i] = a;
	}
}