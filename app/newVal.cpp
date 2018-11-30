/**
  * BSD 3-Clause License
  * Copyright (c) 2018, KrishnaBhatu
  * All rights reserved.
  * Redistribution and use in source and binary forms, with or without
  * modification, are permitted provided that the following conditions are met:
  *
  * Redistributions of source code must retain the above copyright notice, this
  * list of conditions and the following disclaimer.
  * Redistributions in binary form must reproduce the above copyright notice,
  * this list of conditions and the following disclaimer in the documentation
  * and/or other materials provided with the distribution.
  * Neither the name of the copyright holder nor the names of its
  * contributors may be used to endorse or promote products derived from
  * this software without specific prior written permission.
  * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
  * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
  * DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE
  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
  * SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
  * CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,
  * OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
  * OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
  *  @copyright (c) BSD
  *  @file    newVal.cpp
  *  @author  Krishna Bhatu
  *
  *  @brief This is the service class madeup for demonstration purpose.
  *
  *  @section DESCRIPTION
  *
  *  Source code for definition of the service class, it defines the check
  *  method which will be implemented by the clients. 
  */
#include "../include/newVal.h"
#include <math.h>
#include <iostream>

NewVal::NewVal() {
}
NewVal::~NewVal() {
}
/*
 * @brief This method check if the desired result is achieved or not.
 *
 * @param claVel This is the calculated value
 * @param desVel This is the desired value
 * @return Returns boolean flag to indicate if the calculated result matches the
 *         desired result.           
 */
bool NewVal::checkResult(double calVel, double desVel) {
  bool flag;
  if (fabs(calVel - desVel) < 1) {
    flag = true;
  } else {
      flag = false;
  }
  return flag;
}
