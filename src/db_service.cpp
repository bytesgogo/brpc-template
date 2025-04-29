// db_service.cpp
// 功能概述: 
// 作者: bytesgogo
// 创建日期: 2024.07.12 15:54
// 版本: v1.0.0
// 版权信息: bytesgogo

// A server to receive EchoRequest and send back EchoResponse.

#include <gflags/gflags.h>
#include <butil/logging.h>
#include <brpc/server.h>
#include <json2pb/pb_to_json.h>
#include "interface.pb.h"
#include "db_service.h"

// Your implementation of example::EchoService
// Notice that implementing brpc::Describable grants the ability to put
// additional information in /status.
namespace hilbert {
void SDKServiceImpl::create_index(google::protobuf::RpcController* cntl_base,
                    const IndexRequest* request,
                    IndexResponse* response,
                    google::protobuf::Closure* done) {
    // This object helps you to call done->Run() in RAII style. If you need
    // to process the request asynchronously, pass done_guard.release().
    brpc::ClosureGuard done_guard(done);

    brpc::Controller* cntl = static_cast<brpc::Controller*>(cntl_base);

    // The purpose of following logs is to help you to understand
    // how clients interact with servers more intuitively. You should
    // remove these logs in performance-sensitive servers.
    LOG(INFO) << "Received request[log_id=" << cntl->log_id()
                << "] from " << cntl->remote_side()
                << " to " << cntl->local_side()
                << ": " << request->from()
                << " (attached=" << cntl->request_attachment() << ")";

    LOG(INFO) << "create_index" << " logid: " << cntl->log_id();
    // Fill response.
    response->set_id(request->id());

    // You can compress the response by setting Controller, but be aware
    // that compression may be costly, evaluate before turning on.
    // cntl->set_response_compress_type(brpc::COMPRESS_TYPE_GZIP);

    // TODO:实现业务逻辑
}

void SDKServiceImpl::delete_index(google::protobuf::RpcController* cntl_base,
                      const IndexRequest* request,
                      IndexResponse* response,
                      google::protobuf::Closure* done) 
{
    brpc::ClosureGuard done_guard(done);

    brpc::Controller* cntl = static_cast<brpc::Controller*>(cntl_base);

    // TODO:实现业务逻辑
    LOG(INFO) << "delete_index" << " logid: " << cntl->log_id();
    response->set_id(request->id());
}

void SDKServiceImpl::add(google::protobuf::RpcController* cntl_base,
                      const IndexAddRequest* request,
                      IndexAddResponse* response,
                      google::protobuf::Closure* done) {
    brpc::ClosureGuard done_guard(done);

    brpc::Controller* cntl = static_cast<brpc::Controller*>(cntl_base);

    // TODO:实现业务逻辑
    LOG(INFO) << "add" << " logid: " << cntl->log_id();
}
void SDKServiceImpl::search(google::protobuf::RpcController* cntl_base,
                      const IndexSearchRequest* request,
                      IndexSearchResponse* response,
                      google::protobuf::Closure* done) {
    brpc::ClosureGuard done_guard(done);

    brpc::Controller* cntl = static_cast<brpc::Controller*>(cntl_base);

    // TODO:实现业务逻辑
    LOG(INFO) << "search" << " logid: " << cntl->log_id();
}
void SDKServiceImpl::search_qps(google::protobuf::RpcController* cntl_base,
                      const QPSRequest* request,
                      QPSResponse* response,
                      google::protobuf::Closure* done) {
    brpc::ClosureGuard done_guard(done);

    brpc::Controller* cntl = static_cast<brpc::Controller*>(cntl_base);

    // TODO:实现业务逻辑
    response->set_qps(10);
    LOG(INFO) << "search_qps" << " logid: " << cntl->log_id();
}
}
