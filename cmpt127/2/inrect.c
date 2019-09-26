#include<stdio.h>

int InRectangle( float pt[2], float rect[4] ){
	if (rect[2]<rect[0]){
		float a = rect[0];
		float b = rect[2];
		rect[0]=b;
		rect[2]=a;
	}
	if (rect[3]<rect[1]){
		float a = rect[1];
		float b = rect[3];
		rect[1]=b;
		rect[3]=a;
	}
if (rect[0]<=pt[0] & pt[0]<=rect[2] & rect[1]<=pt[1] & pt[1]<=rect[3]){
	return 1;
	}
	else{
		return 0;
	}
}