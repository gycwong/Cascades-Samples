/* Copyright (c) 2012 Research In Motion Limited.
*
* Licensed under the Apache License, Version 2.0 (the "License");
* you may not use this file except in compliance with the License.
* You may obtain a copy of the License at
*
* http://www.apache.org/licenses/LICENSE-2.0
*
* Unless required by applicable law or agreed to in writing, software
* distributed under the License is distributed on an "AS IS" BASIS,
* WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
* See the License for the specific language governing permissions and
* limitations under the License.
*/

#include "HelloBattery.hpp"

#include <bb/cascades/Application>
#include <QtCore/QLocale>
#include <QtCore/QTranslator>

using ::bb::cascades::Application;

/**
 * This sample application shows some basic
 * usage of the BatteryInfo API, such as charging level and charging state.
 */
int main(int argc, char **argv)
{
    Application app(argc, argv);

    QTranslator translator;
    QString locale_string = QLocale().name(); 
    QString filename = QString( "BatterySample_%1" ).arg( locale_string );
    if (translator.load(filename, "app/native/qm")) {
        app.installTranslator( &translator );
    }

    // Object which injects the battery info object into the qml context
    HelloBattery mainApp;

    return Application::exec();
}

