
#include "XCVML1TailProb_EQ.h"
#include "XCVML1TailProb_NE1.h"
#include "XCVML1TailProb_NE2.h"

#include "XCvML1Test.h"

extern "C" {

	void CvMTestStat(double *x, int *nx, double *y, int *ny, double *testscore)
	{
		CXCvMTest Test(*nx, *ny);		

		double *pooled = new double[*nx+*ny];
		for(int i=0; i<*nx; i++)
			pooled[i] = x[i];

		for(int i=0; i<*ny; i++)
			pooled[i+*nx] = y[i];

		pooled--;
		*testscore = Test(pooled);
		pooled++;

		delete pooled;
	}

	void CvMTestPVal(int *n, int *m, double *x, int *nx, double *p)
	{
		if( *n == *m){

			CXCVMTailProb_EQ TailProb(*n);
			for(int i=0; i<*nx; i++)
				p[i] = TailProb(x[i]);

		}else if((*n+*m) % 2 == 0){

			CXCVMTailProb_NE1 TailProb(*n, *m);
			for(int i=0; i<*nx; i++)
				p[i] = TailProb(x[i]);

		}else{

			CXCVMTailProb_NE2 TailProb(*n, *m);
			for(int i=0; i<*nx; i++)
				p[i] = TailProb(x[i]);
		}
	}
}