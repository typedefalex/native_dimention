#include "nativedimension_p.h"

#include "nativedimension.h"

#import <UIKit/UIKit.h>

#include <QScreen>
#include <QGuiApplication>

NativeDimentionPrivate::NativeDimentionPrivate(NativeDimention* native)
	: q_ptr(native),
	  statusBarHeight_(0),
	  insetBottom_(0), insetLeft_(0), insetRight_(0), insetTop_(0)
{

}

void NativeDimentionPrivate::loaded()
{
	auto func = [this]()
	{
		Q_Q(NativeDimention);

		q->setStatusBarHeight(static_cast<double>([UIApplication sharedApplication].statusBarFrame.size.height));

		if (@available(iOS 11.0, *))
		{
			UIWindow *window = UIApplication.sharedApplication.keyWindow;

			q->setInsetBottom(static_cast<double>(window.safeAreaInsets.bottom));
			q->setInsetLeft(static_cast<double>(window.safeAreaInsets.left));
			q->setInsetRight(static_cast<double>(window.safeAreaInsets.right));
			q->setInsetTop(static_cast<double>(window.safeAreaInsets.top));
		}
		else
		{
			q->setInsetBottom(0);
			q->setInsetLeft(0);
			q->setInsetRight(0);
			q->setInsetTop(0);
		}
	};

	QObject::connect(QGuiApplication::primaryScreen(), &QScreen::geometryChanged, func);

	func();
}
