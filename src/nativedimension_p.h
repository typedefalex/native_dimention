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
