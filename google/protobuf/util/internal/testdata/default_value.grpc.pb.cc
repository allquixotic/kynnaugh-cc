// Generated by the gRPC protobuf plugin.
// If you make any local change, they will be lost.
// source: google/protobuf/util/internal/testdata/default_value.proto

#include "google/protobuf/util/internal/testdata/default_value.pb.h"
#include "google/protobuf/util/internal/testdata/default_value.grpc.pb.h"

#include <grpc++/impl/codegen/async_stream.h>
#include <grpc++/impl/codegen/async_unary_call.h>
#include <grpc++/impl/codegen/channel_interface.h>
#include <grpc++/impl/codegen/client_unary_call.h>
#include <grpc++/impl/codegen/method_handler_impl.h>
#include <grpc++/impl/codegen/rpc_service_method.h>
#include <grpc++/impl/codegen/service_type.h>
#include <grpc++/impl/codegen/sync_stream.h>
namespace google {
namespace protobuf {
namespace testing {

static const char* DefaultValueTestService_method_names[] = {
  "/google.protobuf.testing.DefaultValueTestService/Call",
};

std::unique_ptr< DefaultValueTestService::Stub> DefaultValueTestService::NewStub(const std::shared_ptr< ::grpc::ChannelInterface>& channel, const ::grpc::StubOptions& options) {
  std::unique_ptr< DefaultValueTestService::Stub> stub(new DefaultValueTestService::Stub(channel));
  return stub;
}

DefaultValueTestService::Stub::Stub(const std::shared_ptr< ::grpc::ChannelInterface>& channel)
  : channel_(channel), rpcmethod_Call_(DefaultValueTestService_method_names[0], ::grpc::RpcMethod::NORMAL_RPC, channel)
  {}

::grpc::Status DefaultValueTestService::Stub::Call(::grpc::ClientContext* context, const ::google::protobuf::testing::RequestMessage& request, ::google::protobuf::testing::DefaultValueTestCases* response) {
  return ::grpc::BlockingUnaryCall(channel_.get(), rpcmethod_Call_, context, request, response);
}

::grpc::ClientAsyncResponseReader< ::google::protobuf::testing::DefaultValueTestCases>* DefaultValueTestService::Stub::AsyncCallRaw(::grpc::ClientContext* context, const ::google::protobuf::testing::RequestMessage& request, ::grpc::CompletionQueue* cq) {
  return new ::grpc::ClientAsyncResponseReader< ::google::protobuf::testing::DefaultValueTestCases>(channel_.get(), cq, rpcmethod_Call_, context, request);
}

DefaultValueTestService::Service::Service() {
  (void)DefaultValueTestService_method_names;
  AddMethod(new ::grpc::RpcServiceMethod(
      DefaultValueTestService_method_names[0],
      ::grpc::RpcMethod::NORMAL_RPC,
      new ::grpc::RpcMethodHandler< DefaultValueTestService::Service, ::google::protobuf::testing::RequestMessage, ::google::protobuf::testing::DefaultValueTestCases>(
          std::mem_fn(&DefaultValueTestService::Service::Call), this)));
}

DefaultValueTestService::Service::~Service() {
}

::grpc::Status DefaultValueTestService::Service::Call(::grpc::ServerContext* context, const ::google::protobuf::testing::RequestMessage* request, ::google::protobuf::testing::DefaultValueTestCases* response) {
  (void) context;
  (void) request;
  (void) response;
  return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
}


}  // namespace google
}  // namespace protobuf
}  // namespace testing

