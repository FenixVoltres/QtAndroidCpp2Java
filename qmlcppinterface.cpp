#include <QAndroidJniEnvironment>
#include <QAndroidJniObject>
#include <QDebug>

#include "qmlcppinterface.h"

QmlCppInterface::QmlCppInterface(QObject *parent) :
    QObject(parent)
{
}

QString QmlCppInterface::getStringFromJava(int number) const
{

    jint javaInt = (jint) number;
    QAndroidJniObject resultString =
            QAndroidJniObject::callStaticObjectMethod("qt/android/java/SmallJavaClassDemostratingCppToJavaCommunication",
                                                      "getMeSomeStringWithMyNumber",
                                                      "(I)Ljava/lang/String;",
                                                      javaInt);

    QAndroidJniEnvironment env;
    if (env->ExceptionCheck())
    {
        env->ExceptionClear();

        qCritical() << "Something went wrong!";
        // Handle the exception
    }

    return resultString.toString();
}
