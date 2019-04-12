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

#ifndef NATIVEDIMENSION_P_H
#define NATIVEDIMENSION_P_H

#include <QObject>

class NativeDimention;

class NativeDimentionPrivate
{
	Q_DISABLE_COPY(NativeDimentionPrivate)
	Q_DECLARE_PUBLIC(NativeDimention)

	NativeDimentionPrivate(NativeDimention* native);

	NativeDimention * const q_ptr;

	double statusBarHeight_;

	double insetBottom_;
	double insetLeft_;
	double insetRight_;
	double insetTop_;

	void loaded();
};

#endif // NATIVE_P_H
