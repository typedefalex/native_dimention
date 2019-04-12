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

#ifndef NATIVEDIMENSION_H
#define NATIVEDIMENSION_H

#include <QObject>

class NativeDimentionPrivate;
class QQmlApplicationEngine;

class NativeDimention : public QObject
{
	Q_OBJECT
	Q_DECLARE_PRIVATE(NativeDimention)

	Q_PROPERTY(double statusBarHeight READ statusBarHeight WRITE setStatusBarHeight NOTIFY statusBarHeightChanged)

	Q_PROPERTY(double insetBottom READ insetBottom WRITE setInsetBottom NOTIFY insetBottomChanged)
	Q_PROPERTY(double insetLeft READ insetLeft WRITE setInsetLeft NOTIFY insetLeftChanged)
	Q_PROPERTY(double insetRight READ insetRight WRITE setInsetRight NOTIFY insetRightChanged)
	Q_PROPERTY(double insetTop READ insetTop WRITE setInsetTop NOTIFY insetTopChanged)

public:
	static NativeDimention* instance();
	static void init(QQmlApplicationEngine* engine);
	explicit NativeDimention();
	~NativeDimention();

	Q_INVOKABLE double statusBarHeight() const;
	Q_INVOKABLE void setStatusBarHeight(double statusBarHeight);

	Q_INVOKABLE double insetBottom() const;
	Q_INVOKABLE void setInsetBottom(double insetBottom);

	Q_INVOKABLE double insetLeft() const;
	Q_INVOKABLE void setInsetLeft(double insetLeft);

	Q_INVOKABLE double insetRight() const;
	Q_INVOKABLE void setInsetRight(double insetRight);

	Q_INVOKABLE double insetTop() const;
	Q_INVOKABLE void setInsetTop(double insetTop);

signals:
	void statusBarHeightChanged(double statusBarHeight);

	void insetBottomChanged(double insetBottom);
	void insetLeftChanged(double insetLeft);
	void insetRightChanged(double insetRight);
	void insetTopChanged(double insetTop);

private:
	static NativeDimention* instance_;
	QScopedPointer<NativeDimentionPrivate> const d_ptr;

	void loaded();
};

#endif // NATIVEDIMENSION_H
