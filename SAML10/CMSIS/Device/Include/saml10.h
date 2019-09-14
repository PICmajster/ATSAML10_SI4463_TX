/**
 * \file
 *
 * \brief Top header file for SAML10
 *
 * Copyright (c) 2018 Microchip Technology Inc.
 *
 * \asf_license_start
 *
 * \page License
 *
 * SPDX-License-Identifier: Apache-2.0
 *
 * Licensed under the Apache License, Version 2.0 (the "License"); you may
 * not use this file except in compliance with the License.
 * You may obtain a copy of the Licence at
 * 
 * http://www.apache.org/licenses/LICENSE-2.0
 * 
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an AS IS BASIS, WITHOUT
 * WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 *
 * \asf_license_stop
 *
 */

#ifndef _SAML10_
#define _SAML10_

/**
 * \defgroup SAML10_definitions SAML10 Device Definitions
 * \brief SAML10 CMSIS Definitions.
 */

#if   defined(__SAML10D14A__) || defined(__ATSAML10D14A__)
  #include "saml10d14a.h"
#elif defined(__SAML10D15A__) || defined(__ATSAML10D15A__)
  #include "saml10d15a.h"
#elif defined(__SAML10D16A__) || defined(__ATSAML10D16A__)
  #include "saml10d16a.h"
#elif defined(__SAML10E14A__) || defined(__ATSAML10E14A__)
  #include "saml10e14a.h"
#elif defined(__SAML10E15A__) || defined(__ATSAML10E15A__)
  #include "saml10e15a.h"
#elif defined(__SAML10E16A__) || defined(__ATSAML10E16A__)
  #include "saml10e16a.h"
#else
  #error Library does not support the specified device.
#endif

#endif /* _SAML10_ */
