/**
 * \file
 *
 * \brief Instance description for PTC
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

#ifndef _SAML10_PTC_INSTANCE_
#define _SAML10_PTC_INSTANCE_

/* ========== Instance parameters for PTC peripheral ========== */
#define PTC_DMAC_ID_EOC             21       // Index of DMA EOC trigger
#define PTC_DMAC_ID_SEQ             22       // Index of DMA SEQ trigger
#define PTC_DMAC_ID_WCOMP           23       // Index of DMA WCOMP trigger
#define PTC_GCLK_ID                 19       // Index of Generic Clock
#define PTC_LINES_MSB               19      
#define PTC_LINES_NUM               20       // Number of PTC lines

#endif /* _SAML10_PTC_INSTANCE_ */
