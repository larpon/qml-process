TEMPLATE = lib
TARGET = qmlprocess

contains(QT_VERSION, ^5\\..\\..*) {
    DEFINES += QT5_BUILD
    QT += qml
} else {
    QT += declarative
}
CONFIG += qt plugin

TARGET = $$qtLibraryTarget($$TARGET)
uri = QmlProcess

# Input
SOURCES += \
    qml_process_plugin.cpp \
    qml_process.cpp

HEADERS += \
    qml_process_plugin.h \
    qml_process.h

OTHER_FILES = qmldir

!equals(_PRO_FILE_PWD_, $$OUT_PWD) {
    copy_qmldir.target = $$OUT_PWD/qmldir
    copy_qmldir.depends = $$_PRO_FILE_PWD_/qmldir
    copy_qmldir.commands = $(COPY_FILE) \"$$replace(copy_qmldir.depends, /, $$QMAKE_DIR_SEP)\" \"$$replace(copy_qmldir.target, /, $$QMAKE_DIR_SEP)\"
    QMAKE_EXTRA_TARGETS += copy_qmldir
    PRE_TARGETDEPS += $$copy_qmldir.target
}

qmldir.files = qmldir
# symbian {
#     TARGET.EPOCALLOWDLLDATA = 1
# } else:unix {
#     maemo5 | !isEmpty(MEEGO_VERSION_MAJOR) {
#         installPath = /usr/lib/qt4/imports/$$replace(uri, \\., /)
#     } else contains(QT_VERSION, ^5\\..\\..*) {
#         installPath = $$[QT_INSTALL_QML]/$$replace(uri, \\., /)
#     } else {
#         installPath = $$[QT_INSTALL_IMPORTS]/$$replace(uri, \\., /)
#     }
#     qmldir.path = $$installPath
#     target.path = $$installPath
#     INSTALLS += target qmldir
# }
unix {
    installPath = $$[QT_INSTALL_QML]/$$replace(uri, \\., /)
    qmldir.path = $$installPath
    target.path = $$installPath
    INSTALLS += target qmldir
}
