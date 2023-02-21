/**
 *
 *  LoginFilter.cc
 *
 */

#include "LoginFilter.h"
#include <common/HttpResponseUtils.h>

using namespace drogon;

void LoginFilter::doFilter(const HttpRequestPtr &req,
                         FilterCallback &&fcb,
                         FilterChainCallback &&fccb)
{
    //Edit your logic here
    try{
        //Check failed
        if (!srvPtr_->isAdmin(req))
        {
            throw BusinessException(ErrorCode::PARAMS_ERROR(), "LoginFilter::非管理员用户，无查询权限");
        }

        //Passed
        fccb();
        return;
    }
    catch (BusinessException &e)
    {
        callErrorResponse(std::move(fcb), e);
    }
}
