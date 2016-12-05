// Generated by the gRPC protobuf plugin.
// If you make any local change, they will be lost.
// source: google/logging/v2/logging.proto

#include "google/logging/v2/logging.pb.h"
#include "google/logging/v2/logging.grpc.pb.h"

#include <grpc++/impl/codegen/async_stream.h>
#include <grpc++/impl/codegen/async_unary_call.h>
#include <grpc++/impl/codegen/channel_interface.h>
#include <grpc++/impl/codegen/client_unary_call.h>
#include <grpc++/impl/codegen/method_handler_impl.h>
#include <grpc++/impl/codegen/rpc_service_method.h>
#include <grpc++/impl/codegen/service_type.h>
#include <grpc++/impl/codegen/sync_stream.h>
namespace google {
namespace logging {
namespace v2 {

static const char* LoggingServiceV2_method_names[] = {
  "/google.logging.v2.LoggingServiceV2/DeleteLog",
  "/google.logging.v2.LoggingServiceV2/WriteLogEntries",
  "/google.logging.v2.LoggingServiceV2/ListLogEntries",
  "/google.logging.v2.LoggingServiceV2/ListMonitoredResourceDescriptors",
};

std::unique_ptr< LoggingServiceV2::Stub> LoggingServiceV2::NewStub(const std::shared_ptr< ::grpc::ChannelInterface>& channel, const ::grpc::StubOptions& options) {
  std::unique_ptr< LoggingServiceV2::Stub> stub(new LoggingServiceV2::Stub(channel));
  return stub;
}

LoggingServiceV2::Stub::Stub(const std::shared_ptr< ::grpc::ChannelInterface>& channel)
  : channel_(channel), rpcmethod_DeleteLog_(LoggingServiceV2_method_names[0], ::grpc::RpcMethod::NORMAL_RPC, channel)
  , rpcmethod_WriteLogEntries_(LoggingServiceV2_method_names[1], ::grpc::RpcMethod::NORMAL_RPC, channel)
  , rpcmethod_ListLogEntries_(LoggingServiceV2_method_names[2], ::grpc::RpcMethod::NORMAL_RPC, channel)
  , rpcmethod_ListMonitoredResourceDescriptors_(LoggingServiceV2_method_names[3], ::grpc::RpcMethod::NORMAL_RPC, channel)
  {}

::grpc::Status LoggingServiceV2::Stub::DeleteLog(::grpc::ClientContext* context, const ::google::logging::v2::DeleteLogRequest& request, ::google::protobuf::Empty* response) {
  return ::grpc::BlockingUnaryCall(channel_.get(), rpcmethod_DeleteLog_, context, request, response);
}

::grpc::ClientAsyncResponseReader< ::google::protobuf::Empty>* LoggingServiceV2::Stub::AsyncDeleteLogRaw(::grpc::ClientContext* context, const ::google::logging::v2::DeleteLogRequest& request, ::grpc::CompletionQueue* cq) {
  return new ::grpc::ClientAsyncResponseReader< ::google::protobuf::Empty>(channel_.get(), cq, rpcmethod_DeleteLog_, context, request);
}

::grpc::Status LoggingServiceV2::Stub::WriteLogEntries(::grpc::ClientContext* context, const ::google::logging::v2::WriteLogEntriesRequest& request, ::google::logging::v2::WriteLogEntriesResponse* response) {
  return ::grpc::BlockingUnaryCall(channel_.get(), rpcmethod_WriteLogEntries_, context, request, response);
}

::grpc::ClientAsyncResponseReader< ::google::logging::v2::WriteLogEntriesResponse>* LoggingServiceV2::Stub::AsyncWriteLogEntriesRaw(::grpc::ClientContext* context, const ::google::logging::v2::WriteLogEntriesRequest& request, ::grpc::CompletionQueue* cq) {
  return new ::grpc::ClientAsyncResponseReader< ::google::logging::v2::WriteLogEntriesResponse>(channel_.get(), cq, rpcmethod_WriteLogEntries_, context, request);
}

::grpc::Status LoggingServiceV2::Stub::ListLogEntries(::grpc::ClientContext* context, const ::google::logging::v2::ListLogEntriesRequest& request, ::google::logging::v2::ListLogEntriesResponse* response) {
  return ::grpc::BlockingUnaryCall(channel_.get(), rpcmethod_ListLogEntries_, context, request, response);
}

::grpc::ClientAsyncResponseReader< ::google::logging::v2::ListLogEntriesResponse>* LoggingServiceV2::Stub::AsyncListLogEntriesRaw(::grpc::ClientContext* context, const ::google::logging::v2::ListLogEntriesRequest& request, ::grpc::CompletionQueue* cq) {
  return new ::grpc::ClientAsyncResponseReader< ::google::logging::v2::ListLogEntriesResponse>(channel_.get(), cq, rpcmethod_ListLogEntries_, context, request);
}

::grpc::Status LoggingServiceV2::Stub::ListMonitoredResourceDescriptors(::grpc::ClientContext* context, const ::google::logging::v2::ListMonitoredResourceDescriptorsRequest& request, ::google::logging::v2::ListMonitoredResourceDescriptorsResponse* response) {
  return ::grpc::BlockingUnaryCall(channel_.get(), rpcmethod_ListMonitoredResourceDescriptors_, context, request, response);
}

::grpc::ClientAsyncResponseReader< ::google::logging::v2::ListMonitoredResourceDescriptorsResponse>* LoggingServiceV2::Stub::AsyncListMonitoredResourceDescriptorsRaw(::grpc::ClientContext* context, const ::google::logging::v2::ListMonitoredResourceDescriptorsRequest& request, ::grpc::CompletionQueue* cq) {
  return new ::grpc::ClientAsyncResponseReader< ::google::logging::v2::ListMonitoredResourceDescriptorsResponse>(channel_.get(), cq, rpcmethod_ListMonitoredResourceDescriptors_, context, request);
}

LoggingServiceV2::Service::Service() {
  (void)LoggingServiceV2_method_names;
  AddMethod(new ::grpc::RpcServiceMethod(
      LoggingServiceV2_method_names[0],
      ::grpc::RpcMethod::NORMAL_RPC,
      new ::grpc::RpcMethodHandler< LoggingServiceV2::Service, ::google::logging::v2::DeleteLogRequest, ::google::protobuf::Empty>(
          std::mem_fn(&LoggingServiceV2::Service::DeleteLog), this)));
  AddMethod(new ::grpc::RpcServiceMethod(
      LoggingServiceV2_method_names[1],
      ::grpc::RpcMethod::NORMAL_RPC,
      new ::grpc::RpcMethodHandler< LoggingServiceV2::Service, ::google::logging::v2::WriteLogEntriesRequest, ::google::logging::v2::WriteLogEntriesResponse>(
          std::mem_fn(&LoggingServiceV2::Service::WriteLogEntries), this)));
  AddMethod(new ::grpc::RpcServiceMethod(
      LoggingServiceV2_method_names[2],
      ::grpc::RpcMethod::NORMAL_RPC,
      new ::grpc::RpcMethodHandler< LoggingServiceV2::Service, ::google::logging::v2::ListLogEntriesRequest, ::google::logging::v2::ListLogEntriesResponse>(
          std::mem_fn(&LoggingServiceV2::Service::ListLogEntries), this)));
  AddMethod(new ::grpc::RpcServiceMethod(
      LoggingServiceV2_method_names[3],
      ::grpc::RpcMethod::NORMAL_RPC,
      new ::grpc::RpcMethodHandler< LoggingServiceV2::Service, ::google::logging::v2::ListMonitoredResourceDescriptorsRequest, ::google::logging::v2::ListMonitoredResourceDescriptorsResponse>(
          std::mem_fn(&LoggingServiceV2::Service::ListMonitoredResourceDescriptors), this)));
}

LoggingServiceV2::Service::~Service() {
}

::grpc::Status LoggingServiceV2::Service::DeleteLog(::grpc::ServerContext* context, const ::google::logging::v2::DeleteLogRequest* request, ::google::protobuf::Empty* response) {
  (void) context;
  (void) request;
  (void) response;
  return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
}

::grpc::Status LoggingServiceV2::Service::WriteLogEntries(::grpc::ServerContext* context, const ::google::logging::v2::WriteLogEntriesRequest* request, ::google::logging::v2::WriteLogEntriesResponse* response) {
  (void) context;
  (void) request;
  (void) response;
  return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
}

::grpc::Status LoggingServiceV2::Service::ListLogEntries(::grpc::ServerContext* context, const ::google::logging::v2::ListLogEntriesRequest* request, ::google::logging::v2::ListLogEntriesResponse* response) {
  (void) context;
  (void) request;
  (void) response;
  return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
}

::grpc::Status LoggingServiceV2::Service::ListMonitoredResourceDescriptors(::grpc::ServerContext* context, const ::google::logging::v2::ListMonitoredResourceDescriptorsRequest* request, ::google::logging::v2::ListMonitoredResourceDescriptorsResponse* response) {
  (void) context;
  (void) request;
  (void) response;
  return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
}


}  // namespace google
}  // namespace logging
}  // namespace v2

