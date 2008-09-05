/**
     Class CXCVMTailProb_EQ:  Compute the tail probability for
	                       given (L1-version) Cramer-von Mises 
                           test score for the case m+n is even 
                           but m != n.

     Author: Yuanhui Xiao
     Revised date: 09/05/2008

     Copyright (c) 2008 Yuanhui Xiao
*/

#include "XCVML1TailProb.h"
#include "XFreqFunct.h"

#ifndef CXCVMTailProb_NE1_H
#define CXCVMTailProb_NE1_H

class CXCVMTailProb_NE1 : public CXCVMTailProb
{
public:

  CXCVMTailProb_NE1(int nA, int nB); // constructor
    
  virtual const double operator()(const double cvm) const;
     // compute the tail probability for given cvm

  virtual const double operator()(const long Q) const;
     // compute the tail frequence for given Q
};
#endif
