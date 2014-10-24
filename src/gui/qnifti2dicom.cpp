//  This file is part of Nifti2Dicom, is an open source converter from
//  3D NIfTI images to 2D DICOM series.
//
//  Copyright (C) 2010,2012 Gabriele Arnulfo <gabriele.arnulfo@dist.unige.it>
//
//  Nifti2Dicom is free software: you can redistribute it and/or modify
//  it under the terms of the GNU General Public License as published by
//  the Free Software Foundation, either version 3 of the License, or
//  (at your option) any later version.
//
//  Nifti2Dicom is distributed in the hope that it will be useful,
//  but WITHOUT ANY WARRANTY; without even the implied warranty of
//  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
//  GNU General Public License for more details.
//
//  You should have received a copy of the GNU General Public License
//  along with Nifti2Dicom.  If not, see <http://www.gnu.org/licenses/>.


#include <iostream>

#include <QtCore/qglobal.h>

#if (QT_VERSION < QT_VERSION_CHECK(5, 0, 0))
#include <QtGui/QApplication>
#include <QtGui/QWizard>
#include <QtGui/QMainWindow>
#else
#include <QtWidgets/QApplication>
#include <QtWidgets/QWizard>
#include <QtWidgets/QMainWindow>
#endif

#include "init.h"
#include "customize.h"
#include "finalize.h"
#include "wizard.h"
#include "Nifti2DicomConfig.h"

void print_version()
{
    std::cout << "qnifti2dicom " << Nifti2Dicom_VERSION << std::endl;
}

void print_usage()
{
    std::cout << "USAGE" << std::endl;
    std::cout << std::endl;
    std::cout << "   qnifti2dicom  [-h] [--help] [--version]" << std::endl;
    std::cout << std::endl;
    std::cout << std::endl;
    std::cout << "Where:" << std::endl;
    std::cout << std::endl;
    std::cout << "--version" << std::endl;
    std::cout << "     Displays version information and exits." << std::endl;
    std::cout << std::endl;
    std::cout << "-h,  --help" << std::endl;
    std::cout << "     Displays usage information and exits." << std::endl;
}


int main(int argc, char* argv[])
{
#ifdef Q_WS_X11
    bool useGUI = getenv("DISPLAY") != 0;
#else
    bool useGUI = true;
#endif

    QApplication app(argc, argv, useGUI);

    Q_FOREACH (const QString &arg, app.arguments()) {
        if (arg == QLatin1String("--version")) {
            print_version();
            exit(0);
        }
        if (arg == QLatin1String("--help") || arg == QLatin1String("-h")) {
            print_usage();
            exit(0);
        }
    }

    if (!useGUI) {
        std::cerr << "Cannot run qnifti2dicom without DISPLAY." << std::endl;
        std::cerr << "Please set the DISPLAY environment variable or use nifti2dicom instead." << std::endl;;
        exit(1);
    }

    n2d::gui::Wizard*       wiz     = new n2d::gui::Wizard(0);
    n2d::gui::init*         page1   = new n2d::gui::init(wiz);
    n2d::gui::customize*    page2   = new n2d::gui::customize(wiz);
    n2d::gui::finalize*     page3   = new n2d::gui::finalize(wiz);

    wiz->addPage(page1);
    wiz->addPage(page2);
    wiz->addPage(page3);

    wiz->show();

    int ret = app.exec();

    delete wiz;

     return ret;
}
