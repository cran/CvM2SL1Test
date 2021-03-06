/**
    Class CXCVM: a base class for L1-version of
                 Cramer-von Mises Test

    Author: Yuanhui Xiao
    Revised date:  09/05/2008

    Copyright (c) 2008 Yuanhui Xiao
*/

#ifndef CXCVM_H
#define CXCVM_H

#include <cmath>

#include <stdint.h>

class CXCVM{

public:

  CXCVM(int nA=1, int nB=1); // nA and nB are sample sizes
  virtual ~CXCVM();
  
protected:

  const int64_t   ToInt(const double dStat) const; // convert T2 to zeta
  const double ToDouble(const int64_t iStat) const; // convert zeta to T2

  const int GCD(); // return the great common divisor using Euclidean algorithm

protected:

  int m_nA, m_nB; // sample sizes
  int64_t m_nL;       // least common multiple of m_nA and m_nB
  int64_t m_nP, m_nQ; // m_nP = m_nL/m_nA, m_nQ = m_nL/m_nB
  
  double m_dCoe;  // coefficient 
};
#endif



