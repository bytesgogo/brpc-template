// A client sending requests to server every 1 second.

#include <gflags/gflags.h>
#include <butil/logging.h>
#include <butil/time.h>
#include <brpc/channel.h>
#include "interface.pb.h"

DEFINE_string(attachment, "", "Carry this along with requests");
DEFINE_string(protocol, "baidu_std", "Protocol type. Defined in src/brpc/options.proto");
DEFINE_string(connection_type, "", "Connection type. Available values: single, pooled, short");
DEFINE_string(server, "0.0.0.0:8000", "IP Address of server");
DEFINE_string(load_balancer, "", "The algorithm for load balancing");
DEFINE_int32(timeout_ms, 1000, "RPC timeout in milliseconds");
DEFINE_int32(max_retry, 3, "Max retries(not including the first RPC)");
DEFINE_int32(interval_ms, 1000, "Milliseconds between consecutive requests");


void send_create_index(int &log_id, hilbert::SDKService_Stub &stub) {
    hilbert::IndexRequest request;
    hilbert::IndexResponse response;
    brpc::Controller cntl;

    request.set_id(std::to_string(log_id));

    cntl.set_log_id(log_id ++);  // set by user
    // Set attachment which is wired to network directly instead of
    // being serialized into protobuf messages.
    cntl.request_attachment().append(FLAGS_attachment);

    // Because `done'(last parameter) is NULL, this function waits until
    // the response comes back or error occurs(including timedout).
    stub.create_index(&cntl, &request, &response, NULL);
    if (!cntl.Failed()) {
        LOG(INFO) << "Received response from " << cntl.remote_side()
            << " to " << cntl.local_side()
            << ": " << response.id() << " (attached="
            << cntl.response_attachment() << ")"
            << " latency=" << cntl.latency_us() << "us";
    } else {
        LOG(WARNING) << cntl.ErrorText();
    }
}

void send_delete_index(int &log_id, hilbert::SDKService_Stub &stub) {
    hilbert::IndexRequest request;
    hilbert::IndexResponse response;
    brpc::Controller cntl;

    request.set_id(std::to_string(log_id));

    cntl.set_log_id(log_id ++);  // set by user
    // Set attachment which is wired to network directly instead of
    // being serialized into protobuf messages.
    cntl.request_attachment().append(FLAGS_attachment);

    // Because `done'(last parameter) is NULL, this function waits until
    // the response comes back or error occurs(including timedout).
    stub.delete_index(&cntl, &request, &response, NULL);
    if (!cntl.Failed()) {
        LOG(INFO) << "Received response from " << cntl.remote_side()
            << " to " << cntl.local_side()
            << ": " << response.id() << " (attached="
            << cntl.response_attachment() << ")"
            << " latency=" << cntl.latency_us() << "us";
    } else {
        LOG(WARNING) << cntl.ErrorText();
    }
}

void send_add_vector(int &log_id, hilbert::SDKService_Stub &stub) {
    hilbert::IndexAddRequest request;
    hilbert::IndexAddResponse response;
    brpc::Controller cntl;

    request.set_id(std::to_string(log_id));

    cntl.set_log_id(log_id ++);  // set by user
    // Set attachment which is wired to network directly instead of
    // being serialized into protobuf messages.
    cntl.request_attachment().append(FLAGS_attachment);

    // Because `done'(last parameter) is NULL, this function waits until
    // the response comes back or error occurs(including timedout).
    stub.add(&cntl, &request, &response, NULL);
    if (!cntl.Failed()) {
        LOG(INFO) << "Received response from " << cntl.remote_side()
            << " to " << cntl.local_side()
            << ": " << response.id() << " (attached="
            << cntl.response_attachment() << ")"
            << " latency=" << cntl.latency_us() << "us";
    } else {
        LOG(WARNING) << cntl.ErrorText();
    }
}

void send_search(int &log_id, hilbert::SDKService_Stub &stub) {
    hilbert::IndexSearchRequest request;
    hilbert::IndexSearchResponse response;
    brpc::Controller cntl;

    request.set_id(std::to_string(log_id));

    cntl.set_log_id(log_id ++);  // set by user
    // Set attachment which is wired to network directly instead of
    // being serialized into protobuf messages.
    cntl.request_attachment().append(FLAGS_attachment);

    // Because `done'(last parameter) is NULL, this function waits until
    // the response comes back or error occurs(including timedout).
    stub.search(&cntl, &request, &response, NULL);
    if (!cntl.Failed()) {
        LOG(INFO) << "Received response from " << cntl.remote_side()
            << " to " << cntl.local_side()
            << ": " << response.results_size() << " (attached="
            << cntl.response_attachment() << ")"
            << " latency=" << cntl.latency_us() << "us";
    } else {
        LOG(WARNING) << cntl.ErrorText();
    }
}

void send_search_qps(int &log_id, hilbert::SDKService_Stub &stub) {
    hilbert::QPSRequest request;
    hilbert::QPSResponse response;
    brpc::Controller cntl;

    request.set_range(1);

    cntl.set_log_id(log_id ++);  // set by user
    // Set attachment which is wired to network directly instead of
    // being serialized into protobuf messages.
    cntl.request_attachment().append(FLAGS_attachment);

    // Because `done'(last parameter) is NULL, this function waits until
    // the response comes back or error occurs(including timedout).
    stub.search_qps(&cntl, &request, &response, NULL);
    if (!cntl.Failed()) {
        LOG(INFO) << "Received response from " << cntl.remote_side()
            << " to " << cntl.local_side()
            << ": " << response.qps() << " (attached="
            << cntl.response_attachment() << ")"
            << " latency=" << cntl.latency_us() << "us";
    } else {
        LOG(WARNING) << cntl.ErrorText();
    }
}

int main(int argc, char* argv[]) {
    // Parse gflags. We recommend you to use gflags as well.
    // GFLAGS_NS::ParseCommandLineFlags(&argc, &argv, true);

    // A Channel represents a communication line to a Server. Notice that
    // Channel is thread-safe and can be shared by all threads in your program.
    brpc::Channel channel;

    // Initialize the channel, NULL means using default options.
    brpc::ChannelOptions options;
    options.protocol = FLAGS_protocol;
    options.connection_type = FLAGS_connection_type;
    options.timeout_ms = FLAGS_timeout_ms/*milliseconds*/;
    options.max_retry = FLAGS_max_retry;
    if (channel.Init(FLAGS_server.c_str(), FLAGS_load_balancer.c_str(), &options) != 0) {
        LOG(ERROR) << "Fail to initialize channel";
        return -1;
    }

    // Normally, you should not call a Channel directly, but instead construct
    // a stub Service wrapping it. stub can be shared by all threads as well.
    hilbert::SDKService_Stub stub(&channel);

    // Send a request and wait for the response every 1 second.
    int log_id = 0;
    while (!brpc::IsAskedToQuit()) {
        // We will receive response synchronously, safe to put variables
        // on stack.
        send_create_index(log_id, stub);
        send_delete_index(log_id, stub);
        send_add_vector(log_id, stub);
        send_search(log_id, stub);
        send_search_qps(log_id, stub);
        usleep(FLAGS_interval_ms * 10L);
    }

    LOG(INFO) << "EchoClient is going to quit";
    return 0;
}