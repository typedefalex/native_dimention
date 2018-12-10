QT += quick

CONFIG += c++11

HEADERS += \
    $$PWD/nativedimension.h \
    $$PWD/nativedimension_p.h

SOURCES += \
    $$PWD/nativedimension.cpp \

android {
    QT += androidextras
    SOURCES += $$PWD/nativedimension_p_android.cpp
}
else:ios {
    OBJECTIVE_SOURCES += $$PWD/nativedimension_p_ios.mm
    SOURCES += $$OBJECTIVE_SOURCES
}
else: {
    SOURCES += $$PWD/nativedimension_p_other.cpp
}

INCLUDEPATH += "$$PWD/"
