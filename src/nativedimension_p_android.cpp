#include "nativedimension_p.h"

#include "nativedimension.h"

#include <QtAndroid>
#include <QtAndroidExtras>
#include <QAndroidJniObject>

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

		QAndroidJniObject activity = QtAndroid::androidActivity();


		QAndroidJniObject context = QtAndroid::androidContext();
		QAndroidJniObject resources = context.callObjectMethod("getResources", "()Landroid/content/res/Resources;");

		jfloat density = resources.callObjectMethod("getDisplayMetrics", "()Landroid/util/DisplayMetrics;").getField<jfloat>("density");

		jfloat statusBarHeight = 0.0;

		//QAndroidJniObject::getStaticField<jint>("android/os/Build$VERSION", "SDK_INT")
		//Build.VERSION_CODES.KITKAT
		if (QtAndroid::androidSdkVersion() >= 19)
		{
			jint resourceId = resources.callMethod<jint>("getIdentifier", "(Ljava/lang/String;Ljava/lang/String;Ljava/lang/String;)I",
														 QAndroidJniObject::fromString("status_bar_height").object<jstring>(),
														 QAndroidJniObject::fromString("dimen").object<jstring>(),
														 QAndroidJniObject::fromString("android").object<jstring>());

			if (resourceId > 0)
			{
				statusBarHeight = static_cast<jfloat>(resources.callMethod<jint>("getDimensionPixelSize", "(I)I", resourceId)) / density;
			}
		}

		q->setStatusBarHeight(static_cast<double>(statusBarHeight));

		if (QtAndroid::androidSdkVersion() >= 28)
		{
			jint content = QAndroidJniObject::getStaticField<jint>("android/R$id", "content");

			QAndroidJniObject displayCutout = QtAndroid::androidActivity().callObjectMethod("findViewById", "(I)Landroid/view/View;", content).
					callObjectMethod("getRootWindowInsets", "()Landroid/view/WindowInsets;").
					callObjectMethod("getDisplayCutout", "()Landroid/view/DisplayCutout;");


			jfloat inset = static_cast<jfloat>(displayCutout.callMethod<jint>("getSafeInsetBottom"))/density;
			q->setInsetBottom(static_cast<double>(inset));

			inset = static_cast<jfloat>(displayCutout.callMethod<jint>("getSafeInsetLeft"))/density;
			q->setInsetLeft(static_cast<double>(inset));

			inset = static_cast<jfloat>(displayCutout.callMethod<jint>("getSafeInsetRight"))/density;
			q->setInsetRight(static_cast<double>(inset));

			inset = static_cast<jfloat>(displayCutout.callMethod<jint>("getSafeInsetTop"))/density;
			q->setInsetTop(static_cast<double>(inset));
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
