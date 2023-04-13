#!/bin/bash

#进程名列表、工作路径、间隔时间
export cur_path=`pwd`
process_list='cmdterminal'
workPath=${cur_path}/../deploy
intervalTime='5'

##日志路径、日志名称
LOG_DIR=${cur_path}/../logs/swd
LOG_FILE=$LOG_DIR/swd.log

cd $workPath

#日志打印函数
function write_log()
{
  if [ ! -d ${LOG_DIR} ];then
	 mkdir -p ${LOG_DIR} 
  fi
  
  if [ ! -d ${LOG_FILE} ];then
	 touch  ${LOG_FILE} 
  fi
  
  fileCount=`ls ${LOG_DIR}/*.log |wc -l`
  
  if [ ${fileCount} -gt 10 ];then
     find ${LOG_DIR} -type f |xargs ls -tr | head -5 | xargs rm
  fi
  
  echo -n `date "+%Y-%m-%d %T"` >>${LOG_FILE}
  echo " $1" >>${LOG_FILE}
  
  return 0
}

function MAIN()
{
    while true ; do
        for process_name in $process_list  
        do 
            write_log "current deal ${process_name} begin."

            process_num=`ps aux | grep ${process_name} | grep -v grep |wc -l`

            if [ "${process_num}" -lt "1" ];then
                write_log "${process_name} was killed,wait for pull."
                ./${process_name} &
            elif [ "${process_num}" -gt "1" ];then
                write_log "more than 1 ${process_name},killall ${process_name}"
                pidlist=`ps -ef | grep ${process_name}  | grep -v grep | awk '{print $2}'`
                for pid in $pidlist
                do
                    kill -9 ${pid} >/dev/null
                    write_log "kill -9 ${pid}."
                done 
                write_log "${process_name} killall finish."
            fi

            count=0

            while [ ${count} -lt ${intervalTime} ]
            do
                count=`expr ${count} + 1`
                write_log "current deal ${process_name} sleep ${count}."
                sleep 1
            done

            write_log "current deal ${process_name} end."
        done
    done
}

MAIN