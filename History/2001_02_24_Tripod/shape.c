void CalcMoments(void) 
{
	int i,j;
	
	float aPls,aMin;
	
	a00 = 0.0;
	a10 = a01 = 0.0;
	a20 = a11 = a02 = 0.0;
	
	imMin = 10.0;
	imMax = 0.0;
	
	for (i = 0; i < 320; i++) {
		for (j = 0; j < 320; j++) {
		
			image[i][j] = 1-image[i][j];
			a00 = a00 + image[i][j];
			
			
			if (image[i][j] < imMin) imMin = image[i][j];
			if (image[i][j] > imMax) imMax = image[i][j];
		}
	}

	for (i = 0; i < 320; i++) {
		for (j = 0; j < 320; j++) {
		
			a10 = a10 + i*image[i][j]/a00;
			a01 = a01 + j*image[i][j]/a00;
		}
	}


	for (i = 0; i < 320; i++) {
		for (j = 0; j < 320; j++) {
		
			a20 = a20 + (i-a10)*(i-a10)*image[i][j]/a00;
			a11 = a11 + (i-a10)*(j-a01)*image[i][j]/a00;			
			a02 = a02 + (j-a01)*(j-a01)*image[i][j]/a00;
		}
	}
	
	
	aPls = (a20 + a02)/2.0;
	aMin = (a20 - a02)/2.0;
	
	
	lambda1 = sqrt(aPls + sqrt(aMin*aMin + a11*a11));
	lambda2 = sqrt(aPls - sqrt(aMin*aMin + a11*a11));
	
	
	alpha = atan2(a11,aMin)*90.0/PI;
	
	
	if (lambda1 > estimateA) estimateA = lambda1;
	if (lambda1 < estimateBmax) estimateBmax = lambda1;
	
	if (lambda2 > estimateBmin) estimateBmin = lambda2;
	if (lambda2 < estimateC) estimateC = lambda2;
	

	estimateBmean = (estimateBmin + estimateBmax)/2.0;

	slant = acos(sqrt((lambda1-estimateBmean)*(lambda1+estimateBmean)/
			(estimateA*estimateA - estimateBmean*estimateBmean)))*180/PI;
	
}
