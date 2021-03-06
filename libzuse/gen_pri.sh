#!/bin/bash

#
# This scirpt helps library callers that is a Qt project
#
# Run this script in the library caller's source directory
# to generate a libzuse.pri corresponds to that PWD
#

LIB_ROOT=$(dirname $0)
qmake -project \
	-o libzuse.pri \
	-t lib \
	-nopwd \
	$LIB_ROOT
sed -i '/TEMPLATE =/d' libzuse.pri
sed -i '/TARGET =/d' libzuse.pri
sed -i '/main.cpp/d' libzuse.pri
sed -i '/# Auto*/c\# Generated by libzuse/gen_pri.sh, do NOT modify' libzuse.pri

