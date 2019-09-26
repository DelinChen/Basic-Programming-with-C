int scrambled( unsigned int arr1[], unsigned int arr2[], unsigned int len ){
	if (len == 0){
		return 1;
	}
	for(int i=0;i<len;i++){
		for(int j=0;j<len;j++){
			if (arr1[i] == arr2[j]){
				arr2[j]=100;
				break;
			}
		}
	}
	for (int i = 0; i < len; i++){
	if (arr2[i]!=100)
		return 0;
	}
		return 1;
}