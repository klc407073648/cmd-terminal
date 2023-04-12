/**
 *
 *  LoginFilter.h
 *
 */

#pragma once

#include <services/impl/UserServiceImpl.h>
#include <drogon/HttpFilter.h>

using namespace drogon;
using namespace cmdterminal;

class LoginFilter : public HttpFilter<LoginFilter>
{
  public:
    LoginFilter():srvPtr_(new UserServiceImpl()) {}

    virtual void doFilter(const HttpRequestPtr &req,
                          FilterCallback &&fcb,
                          FilterChainCallback &&fccb) override;
  private:
    UserServicePtr srvPtr_;
};

