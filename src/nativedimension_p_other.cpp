/*
 *  Copyright © 2018-2019 Alex Yakubinskiy. All rights reserved. Contacts: <prktown.work@gmail.com>
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#include "nativedimension_p.h"

#include "nativedimension.h"

NativeDimentionPrivate::NativeDimentionPrivate(NativeDimention* native)
	: q_ptr(native),
	  statusBarHeight_(0),
	  insetBottom_(0), insetLeft_(0), insetRight_(0), insetTop_(0)
{

}

void NativeDimentionPrivate::loaded()
{

}
