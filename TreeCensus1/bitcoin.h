/*******************************************************************************
  Title          : bitcoin.h
  Author         : Stewart Weiss
  Created on     : January 29, 2018
  Description    : The interface file for the Bitcoin class
  Purpose        : To provide a means of generating uniformly distributed 0's 
                   and 1's
  Usage          : Include this file with client code
  Build with     : No building 
  Modifications  : 
 
*******************************************************************************/

#ifndef __BITCOIN_H__
#define __BITCOIN_H__


/*******************************************************************************
                           Random Number Routines
    To get repeatable and hence testable behavior, use the same argument to
    create a Bitcoin object each time.  
    To get different runs each time, create the Bitcoin object with a different
    value each time, such as the return value of the time(NULL) function in Unix
    as in
         Bitcoin(time(NULL));

*******************************************************************************/

class Bitcoin 
{
public:
    // Constructor for Bitcoin
    Bitcoin( int n = 0);

    /** operator()  returns with equal probability 0 or 1
     *  @return int  
     */
    int  operator()();
};

#endif /* __BITCOIN_H__ */


