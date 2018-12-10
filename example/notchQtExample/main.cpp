#include <QIcon>
#include <QGuiApplication>
#include <QQmlApplicationEngine>

#include <nativedimension.h>

int main(int argc, char *argv[])
{
	QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);

	QGuiApplication app(argc, argv);

	QIcon::setThemeName(QStringLiteral("gallery"));

	QQmlApplicationEngine engine;

	NativeDimention::init(&engine);

	engine.load(QUrl(QStringLiteral("qrc:/main.qml")));
	if (engine.rootObjects().isEmpty())
		return -1;

	return app.exec();
}
