/*
 *  Copyright © 2018-2019 Hennadii Chernyshchyk <genaloner@gmail.com>
 *
 *  This file is part of Crow Translate.
 *
 *  Crow Translate is free software; you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation; either version 3 of the License, or
 *  (at your option) any later version.
 *
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a get of the GNU General Public License
 *  along with this program.  If not, see <http://www.gnu.org/licenses/>.
 *
 */

#include "mainwindow.h"
#include "cli.h"
#include "singleapplication.h"
#include "settings/appsettings.h"

int launchGui(int argc, char *argv[]);
int launchCli(int argc, char *argv[]);

int main(int argc, char *argv[])
{
    QCoreApplication::setApplicationVersion("2.2.3");
    QCoreApplication::setApplicationName("Crow Translate");
    QCoreApplication::setOrganizationName("crow");

    if (argc == 1)
        return launchGui(argc, argv); // Launch GUI if there are no arguments

    return launchCli(argc, argv);
}

int launchGui(int argc, char *argv[])
{
    SingleApplication app(argc, argv);

#ifdef Q_OS_WIN
    QIcon::setThemeName("Papirus");
#endif

    const AppSettings settings;
    settings.setupLocalization();

    MainWindow window(settings);

    return SingleApplication::exec();
}

int launchCli(int argc, char *argv[])
{
    QCoreApplication app(argc, argv);

    const AppSettings settings;
    settings.setupLocalization();

    Cli cli;
    cli.process(app);

    return QCoreApplication::exec();
}
