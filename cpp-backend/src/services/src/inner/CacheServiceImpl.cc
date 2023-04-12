#include <services/inner/impl/CacheServiceImpl.h>
#include <json/json.h>
#include <exception/BusinessException.h>

using namespace cmdterminal;
using namespace drogon;

CacheServiceImpl::CacheServiceImpl() //: cacheType_(type)
{
    LOG_INFO << "CacheServiceImpl constructor!";
    //LOG_INFO << "CacheServiceImpl cacheType_:"<<cacheType_;
    initData();
}

CacheServiceImpl::~CacheServiceImpl()
{
    LOG_INFO << "CacheServiceImpl destructor!";
}

void CacheServiceImpl::initData()
{
    try
    {
        auto interfaces = interfaceMapper_.findAll();

        for (auto &interface : interfaces)
        {
            std::string name = interface.getValueOfName();
            int isDelete = interface.getValueOfIsdelete();

            //接口未被删除
            if( isDelete == 0){
                name2Interface_.insert(make_pair(name,interface));
                LOG_DEBUG << "name:" << name << ",value:" << interface.toJson().toStyledString();
            }
        }
    }
    catch (const DrogonDbException &e)
    {
        throw BusinessException(ErrorCode::PARAMS_ERROR(), "获取接口表信息失败");
    }
}

bool CacheServiceImpl::getInterfaceInfoByName(const std::string &name, Interface &interface)
{
    if (name2Interface_.count(name) > 0)
    {
        interface = name2Interface_[name];
        return true;
    }
    return false;
}
