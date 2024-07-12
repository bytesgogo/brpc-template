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

    brpc::Controller* cntl =
        static_cast<brpc::Controller*>(cntl_base);

    // optional: set a callback function which is called after response is sent
    // and before cntl/req/res is destructed.
    // cntl->set_after_rpc_resp_fn(std::bind(&EchoServiceImpl::CallAfterRpc,
    //     std::placeholders::_1, std::placeholders::_2, std::placeholders::_3));

    // The purpose of following logs is to help you to understand
    // how clients interact with servers more intuitively. You should
    // remove these logs in performance-sensitive servers.
    LOG(INFO) << "Received request[log_id=" << cntl->log_id()
                << "] from " << cntl->remote_side()
                << " to " << cntl->local_side()
                << ": " << request->from()
                << " (attached=" << cntl->request_attachment() << ")";

    // Fill response.
    response->set_id(request->id());

    // You can compress the response by setting Controller, but be aware
    // that compression may be costly, evaluate before turning on.
    // cntl->set_response_compress_type(brpc::COMPRESS_TYPE_GZIP);

    cntl->response_attachment().append(cntl->request_attachment());
}

void SDKServiceImpl::delete_index(google::protobuf::RpcController* cntl_base,
                      const IndexRequest* request,
                      IndexResponse* response,
                      google::protobuf::Closure* done) 
                      {

                      }
void SDKServiceImpl::add(google::protobuf::RpcController* cntl_base,
                      const IndexAddRequest* request,
                      IndexAddResponse* response,
                      google::protobuf::Closure* done) {

                      }
void SDKServiceImpl::search(google::protobuf::RpcController* cntl_base,
                      const IndexSearchRequest* request,
                      IndexSearchResponse* response,
                      google::protobuf::Closure* done) {

                      }
void SDKServiceImpl::search_qps(google::protobuf::RpcController* cntl_base,
                      const QPSRequest* request,
                      QPSResponse* response,
                      google::protobuf::Closure* done) {

                      }
}
