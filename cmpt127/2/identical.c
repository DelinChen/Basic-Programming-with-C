int identical( int arr1[], int arr2[], unsigned int len ){
	int a = 1;
	for (int i=0;i<len;i++){
		if(arr1[i]!=arr2[i]){
			a = 0;
		}
	}
	return a;
}