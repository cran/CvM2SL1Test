/**
     Class CXCVMTailProb_EQ: Compute the tail probability for
	                       given (L1-version) Cramer-von Mises 
                           test score for the case m = n.

     Author: Yuanhui Xiao
     Revised date: 09/05/2008

     Copyright (c) 2008 Yuanhui Xiao
*/

#include "XCVML1TailProb.h"
#include "XFreqFunct.h"

#ifndef CXCVMTailProb_EQ_H
#define CXCVMTailProb_EQ_H

class CXCVMTailProb_EQ : public CXCVMTailProb
{
public:

  CXCVMTailProb_EQ(int nA); // constructor
  
  virtual const double operator()(const double cvm) const;
     // compute the tail probability for given cvm

  virtual const double operator()(const int64_t Q) const;
     // compute the tail frequence for given Q

protected:

  void TabulateFreqFuncts();   // tabulates the tables at middle stage
};
#endif
