#include <services/impl/LogServiceImpl.h>
#include <common/ErrorCode.h>
#include <exception/BusinessException.h>

using namespace cmdterminal;
using namespace drogon;
using namespace drogon::internal;

LogServiceImpl::LogServiceImpl()
{
    LOG_INFO << "LogServiceImpl constructor!";
}

LogServiceImpl::~LogServiceImpl()
{
    LOG_INFO << "LogServiceImpl destructor!";
}

bool LogServiceImpl::writeUserLog(long userid, const std::string &content)
{
    std::string funName = __FUNCTION__;
    bool res = false;
    try
    {
        Log log;
        log.setUserid(userid);
        log.setContent(content);
        logMapper.insert(log);

        /*
        auto ret = logMapper.findBy(Criteria(Log::Cols::_userid, CompareOperator::EQ, userid) &&
                                    Criteria(Log::Cols::_content, CompareOperator::EQ, content));
        if (ret.size() >= 1)//可能有重复内容的记录
        {
            throw BusinessException(ErrorCode::PARAMS_ERROR(), "插入数据失败");
        }
        */

        LOG_ERROR << "[writeUserLog] userid:" << userid << ", content:" << content << " success";

        res = true;
    }
    catch (const DrogonDbException &e)
    {
        throw BusinessException(ErrorCode::PARAMS_ERROR(), funName + "执行失败");
    }

    return res;
}
