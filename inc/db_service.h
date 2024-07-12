// db_service.h
// 功能概述: 
// 作者: linjinzhu
// 创建日期: 2024.07.12 15:12
// 版本: v1.0.0
// 版权信息: Copyright (c) 2024 Elemem Tech. All rights reserved.

#ifndef _HILBERT_db_service_H
#define _HILBERT_db_service_H

#include "interface.pb.h"

namespace hilbert {
class SDKServiceImpl : public SDKService {
public:
    SDKServiceImpl() {}
    virtual ~SDKServiceImpl() {}
    virtual void create_index(google::protobuf::RpcController* cntl_base,
                      const IndexRequest* request,
                      IndexResponse* response,
                      google::protobuf::Closure* done);
    virtual void delete_index(google::protobuf::RpcController* cntl_base,
                      const IndexRequest* request,
                      IndexResponse* response,
                      google::protobuf::Closure* done);
    virtual void add(google::protobuf::RpcController* cntl_base,
                      const IndexAddRequest* request,
                      IndexAddResponse* response,
                      google::protobuf::Closure* done);
    virtual void search(google::protobuf::RpcController* cntl_base,
                      const IndexSearchRequest* request,
                      IndexSearchResponse* response,
                      google::protobuf::Closure* done);
    virtual void search_qps(google::protobuf::RpcController* cntl_base,
                      const QPSRequest* request,
                      QPSResponse* response,
                      google::protobuf::Closure* done);
};

}
#endif // _HILBERT_db_service_H