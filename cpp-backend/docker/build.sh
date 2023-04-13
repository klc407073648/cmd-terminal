#!/bin/bash
source ./common.sh

function preDeal() 
{
    logDebug "preDeal begin"

	rm -rf $work_path/build/*
	rm -rf $work_path/logs
	
	export LD_LIBRARY_PATH=$LD_LIBRARY_PATH:$work_path/lib/3partlib:$work_path/lib/comlib
    cd $work_path/docker
    chmod 777 *.sh
    dos2unix *.sh

    logDebug "preDeal end"
}

function buildMyprj() 
{
    logDebug "buildMyprj begin"

    cd $work_path

    tar zxf StiBel_V2.1.1.tar.gz

    logInfo "work_path:$work_path"

    cd $work_path/build

    rm -rf ./*

    cmake -DCMAKE_BUILD_TYPE=Release -DCMAKE_BUILD_VERSION=V2.1.1 .. 
    make -j4

    checkBuildResult buildMyprj

    logDebug "buildMyprj end"
}

function MAIN() 
{
    logDebug "build.sh MAIN begin"

    preDeal
    buildMyprj

    logDebug "build.sh MAIN end"
}

MAIN
