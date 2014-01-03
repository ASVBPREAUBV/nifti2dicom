Nifti2Dicom
===========

Convert 3D medical images to DICOM 2D series

Nifti2Dicom is a convertion tool that converts 3D NIfTI files (and other
formats supported by ITK, including Analyze, MetaImage Nrrd and VTK)
to DICOM.
Unlike other conversion tools, it can import a DICOM file that is used
to import the patient and study DICOM tags, and allows you to edit the
accession number and other DICOM tags, in order to create a valid DICOM
that can be imported in a PACS.


Source code is in directory is split into 2 parts:
 - src/core (command line tool)
 - src/gui (GUI)


To build Nifti2Dicom you need:

 * Command line tools:
   - Insight Toolkit (ITK) 3.17 or later using GDCM 2.xx
   - Templatized command-line argument parser for C++ (TCLAP) 1.2 or later

 * GUI
   - Qt4 (4.4 or later)
   - Visualization toolkit (VTK) 5.xx with Qt4 support enabled

 * Documentation
   - Doxygen
   - Graphwiz


[![Build Status](https://travis-ci.org/biolab-unige/nifti2dicom.png?branch=master)](https://travis-ci.org/biolab-unige/nifti2dicom)
