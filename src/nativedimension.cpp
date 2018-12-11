#include "nativedimension.h"
#include "nativedimension_p.h"

#include <QScreen>
#include <QQmlEngine>
#include <QGuiApplication>
#include <QQmlApplicationEngine>

NativeDimention* NativeDimention::instance_ = nullptr;

NativeDimention::NativeDimention()
	: d_ptr(new NativeDimentionPrivate(this))
{

}

NativeDimention* NativeDimention::instance()
{
	if (instance_ == nullptr)
		qFatal("%s", QObject::tr("Class did not initialized. Use init() function.").toUtf8().data());

	return instance_;
}

#include <QWindow>

void NativeDimention::init(QQmlApplicationEngine* engine)
{
	if (instance_ != nullptr)
		qFatal("%s", QObject::tr("Initialization failed.").toUtf8().data());

	instance_ = new NativeDimention();

	const auto screens = QGuiApplication::screens();

	foreach (QScreen* screen,  screens)
		screen->setOrientationUpdateMask(Qt::LandscapeOrientation | Qt::PortraitOrientation | Qt::InvertedLandscapeOrientation | Qt::InvertedPortraitOrientation);

	qmlRegisterSingletonType<NativeDimention>("com.yas.NativeDimention", 1, 0, "NativeDimention", [](QQmlEngine *engine, QJSEngine *scriptEngine) -> QObject*
	{
		Q_UNUSED(engine)
		Q_UNUSED(scriptEngine)

		return instance_;
	});

	QObject::connect(engine, &QQmlApplicationEngine::objectCreated, [](QObject* object, const QUrl& url)
	{
		Q_UNUSED(url)

#ifdef Q_OS_IOS
		qobject_cast<QWindow*>(object)->setFlag(Qt::MaximizeUsingFullscreenGeometryHint);
#else
		Q_UNUSED(object)
#endif
		instance_->loaded();
	});
}

NativeDimention::~NativeDimention()
{

}

double NativeDimention::statusBarHeight() const
{
	Q_D(const NativeDimention);

	return d->statusBarHeight_;
}

void NativeDimention::setStatusBarHeight(double statusBarHeight)
{
	Q_D(NativeDimention);

	if (qFuzzyCompare(d->statusBarHeight_, statusBarHeight))
		return;

	d->statusBarHeight_ = statusBarHeight;
	emit statusBarHeightChanged(statusBarHeight);
}

double NativeDimention::insetBottom() const
{
	Q_D(const NativeDimention);
	return d->insetBottom_;
}

void NativeDimention::setInsetBottom(double insetBottom)
{
	Q_D(NativeDimention);

	if (qFuzzyCompare(d->insetBottom_, insetBottom))
		return;

	d->insetBottom_ = insetBottom;
	emit insetBottomChanged(insetBottom);
}

double NativeDimention::insetLeft() const
{
	Q_D(const NativeDimention);

	return d->insetLeft_;
}

void NativeDimention::setInsetLeft(double insetLeft)
{
	Q_D(NativeDimention);

	if (qFuzzyCompare(d->insetLeft_, insetLeft))
		return;

	d->insetLeft_ = insetLeft;
	emit insetLeftChanged(insetLeft);
}

double NativeDimention::insetRight() const
{
	Q_D(const NativeDimention);

	return d->insetRight_;
}

void NativeDimention::setInsetRight(double insetRight)
{
	Q_D(NativeDimention);

	if (qFuzzyCompare(d->insetRight_, insetRight))
		return;

	d->insetRight_ = insetRight;
	emit insetRightChanged(insetRight);
}

double NativeDimention::insetTop() const
{
	Q_D(const NativeDimention);

	return d->insetTop_;
}

void NativeDimention::setInsetTop(double insetTop)
{
	Q_D(NativeDimention);

	if (qFuzzyCompare(d->insetTop_, insetTop))
		return;

	d->insetTop_ = insetTop;
	emit insetTopChanged(insetTop);
}

void NativeDimention::loaded()
{
	Q_D(NativeDimention);
	d->loaded();
}
