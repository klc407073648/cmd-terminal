#!/bin/bash
source ./common.sh

function runMyprj() 
{
    logDebug "runMyprj begin"

    cd $work_path/deploy

    ./cmdterminal &

    logDebug "runMyprj end"
}

function runSwd() {

    logDebug "runSwd begin"

    cd $work_path/docker

    ./swd.sh &

    logDebug "runSwd end"
}

function MAIN() 
{
    logDebug "run.sh MAIN begin"

    runMyprj
    runSwd

    logDebug "run.sh MAIN end"
}

MAIN
