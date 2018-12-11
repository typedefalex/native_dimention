# native_dimention

Introduction
------------

Simple api to getting insets for ios(notch) and for android(cutout).

Usage
---------------

- git clone https://github.com/typedefalex/native_dimention.git

- add to main .pro file 
  `include(../../src/nativedimension.pri)`
- Use `NativeDimention::init(&engine)` after `QGuiApplication()` instance and before `QQmlApplicationEngine::load()` function.
  
  `QGuiApplication app(argc, argv);
	QQmlApplicationEngine engine;
  ...
  NativeDimention::init(&engine);
  ...
	engine.load(QUrl(QStringLiteral("qrc:/main.qml")));`

Screenshots
-----------

![iPhoneXR](screenshots/iPhoneXR.png)
![iPhone5s](screenshots/iPhone5s.png)
![androidP](screenshots/androidP.png)
![androidO](screenshots/androidO.png)
![androidO_tablet](screenshots/androidO_tablet.png)


