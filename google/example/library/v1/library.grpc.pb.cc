// Generated by the gRPC protobuf plugin.
// If you make any local change, they will be lost.
// source: google/example/library/v1/library.proto

#include "google/example/library/v1/library.pb.h"
#include "google/example/library/v1/library.grpc.pb.h"

#include <grpc++/impl/codegen/async_stream.h>
#include <grpc++/impl/codegen/async_unary_call.h>
#include <grpc++/impl/codegen/channel_interface.h>
#include <grpc++/impl/codegen/client_unary_call.h>
#include <grpc++/impl/codegen/method_handler_impl.h>
#include <grpc++/impl/codegen/rpc_service_method.h>
#include <grpc++/impl/codegen/service_type.h>
#include <grpc++/impl/codegen/sync_stream.h>
namespace google {
namespace example {
namespace library {
namespace v1 {

static const char* LibraryService_method_names[] = {
  "/google.example.library.v1.LibraryService/CreateShelf",
  "/google.example.library.v1.LibraryService/GetShelf",
  "/google.example.library.v1.LibraryService/ListShelves",
  "/google.example.library.v1.LibraryService/DeleteShelf",
  "/google.example.library.v1.LibraryService/MergeShelves",
  "/google.example.library.v1.LibraryService/CreateBook",
  "/google.example.library.v1.LibraryService/GetBook",
  "/google.example.library.v1.LibraryService/ListBooks",
  "/google.example.library.v1.LibraryService/DeleteBook",
  "/google.example.library.v1.LibraryService/UpdateBook",
  "/google.example.library.v1.LibraryService/MoveBook",
};

std::unique_ptr< LibraryService::Stub> LibraryService::NewStub(const std::shared_ptr< ::grpc::ChannelInterface>& channel, const ::grpc::StubOptions& options) {
  std::unique_ptr< LibraryService::Stub> stub(new LibraryService::Stub(channel));
  return stub;
}

LibraryService::Stub::Stub(const std::shared_ptr< ::grpc::ChannelInterface>& channel)
  : channel_(channel), rpcmethod_CreateShelf_(LibraryService_method_names[0], ::grpc::RpcMethod::NORMAL_RPC, channel)
  , rpcmethod_GetShelf_(LibraryService_method_names[1], ::grpc::RpcMethod::NORMAL_RPC, channel)
  , rpcmethod_ListShelves_(LibraryService_method_names[2], ::grpc::RpcMethod::NORMAL_RPC, channel)
  , rpcmethod_DeleteShelf_(LibraryService_method_names[3], ::grpc::RpcMethod::NORMAL_RPC, channel)
  , rpcmethod_MergeShelves_(LibraryService_method_names[4], ::grpc::RpcMethod::NORMAL_RPC, channel)
  , rpcmethod_CreateBook_(LibraryService_method_names[5], ::grpc::RpcMethod::NORMAL_RPC, channel)
  , rpcmethod_GetBook_(LibraryService_method_names[6], ::grpc::RpcMethod::NORMAL_RPC, channel)
  , rpcmethod_ListBooks_(LibraryService_method_names[7], ::grpc::RpcMethod::NORMAL_RPC, channel)
  , rpcmethod_DeleteBook_(LibraryService_method_names[8], ::grpc::RpcMethod::NORMAL_RPC, channel)
  , rpcmethod_UpdateBook_(LibraryService_method_names[9], ::grpc::RpcMethod::NORMAL_RPC, channel)
  , rpcmethod_MoveBook_(LibraryService_method_names[10], ::grpc::RpcMethod::NORMAL_RPC, channel)
  {}

::grpc::Status LibraryService::Stub::CreateShelf(::grpc::ClientContext* context, const ::google::example::library::v1::CreateShelfRequest& request, ::google::example::library::v1::Shelf* response) {
  return ::grpc::BlockingUnaryCall(channel_.get(), rpcmethod_CreateShelf_, context, request, response);
}

::grpc::ClientAsyncResponseReader< ::google::example::library::v1::Shelf>* LibraryService::Stub::AsyncCreateShelfRaw(::grpc::ClientContext* context, const ::google::example::library::v1::CreateShelfRequest& request, ::grpc::CompletionQueue* cq) {
  return new ::grpc::ClientAsyncResponseReader< ::google::example::library::v1::Shelf>(channel_.get(), cq, rpcmethod_CreateShelf_, context, request);
}

::grpc::Status LibraryService::Stub::GetShelf(::grpc::ClientContext* context, const ::google::example::library::v1::GetShelfRequest& request, ::google::example::library::v1::Shelf* response) {
  return ::grpc::BlockingUnaryCall(channel_.get(), rpcmethod_GetShelf_, context, request, response);
}

::grpc::ClientAsyncResponseReader< ::google::example::library::v1::Shelf>* LibraryService::Stub::AsyncGetShelfRaw(::grpc::ClientContext* context, const ::google::example::library::v1::GetShelfRequest& request, ::grpc::CompletionQueue* cq) {
  return new ::grpc::ClientAsyncResponseReader< ::google::example::library::v1::Shelf>(channel_.get(), cq, rpcmethod_GetShelf_, context, request);
}

::grpc::Status LibraryService::Stub::ListShelves(::grpc::ClientContext* context, const ::google::example::library::v1::ListShelvesRequest& request, ::google::example::library::v1::ListShelvesResponse* response) {
  return ::grpc::BlockingUnaryCall(channel_.get(), rpcmethod_ListShelves_, context, request, response);
}

::grpc::ClientAsyncResponseReader< ::google::example::library::v1::ListShelvesResponse>* LibraryService::Stub::AsyncListShelvesRaw(::grpc::ClientContext* context, const ::google::example::library::v1::ListShelvesRequest& request, ::grpc::CompletionQueue* cq) {
  return new ::grpc::ClientAsyncResponseReader< ::google::example::library::v1::ListShelvesResponse>(channel_.get(), cq, rpcmethod_ListShelves_, context, request);
}

::grpc::Status LibraryService::Stub::DeleteShelf(::grpc::ClientContext* context, const ::google::example::library::v1::DeleteShelfRequest& request, ::google::protobuf::Empty* response) {
  return ::grpc::BlockingUnaryCall(channel_.get(), rpcmethod_DeleteShelf_, context, request, response);
}

::grpc::ClientAsyncResponseReader< ::google::protobuf::Empty>* LibraryService::Stub::AsyncDeleteShelfRaw(::grpc::ClientContext* context, const ::google::example::library::v1::DeleteShelfRequest& request, ::grpc::CompletionQueue* cq) {
  return new ::grpc::ClientAsyncResponseReader< ::google::protobuf::Empty>(channel_.get(), cq, rpcmethod_DeleteShelf_, context, request);
}

::grpc::Status LibraryService::Stub::MergeShelves(::grpc::ClientContext* context, const ::google::example::library::v1::MergeShelvesRequest& request, ::google::example::library::v1::Shelf* response) {
  return ::grpc::BlockingUnaryCall(channel_.get(), rpcmethod_MergeShelves_, context, request, response);
}

::grpc::ClientAsyncResponseReader< ::google::example::library::v1::Shelf>* LibraryService::Stub::AsyncMergeShelvesRaw(::grpc::ClientContext* context, const ::google::example::library::v1::MergeShelvesRequest& request, ::grpc::CompletionQueue* cq) {
  return new ::grpc::ClientAsyncResponseReader< ::google::example::library::v1::Shelf>(channel_.get(), cq, rpcmethod_MergeShelves_, context, request);
}

::grpc::Status LibraryService::Stub::CreateBook(::grpc::ClientContext* context, const ::google::example::library::v1::CreateBookRequest& request, ::google::example::library::v1::Book* response) {
  return ::grpc::BlockingUnaryCall(channel_.get(), rpcmethod_CreateBook_, context, request, response);
}

::grpc::ClientAsyncResponseReader< ::google::example::library::v1::Book>* LibraryService::Stub::AsyncCreateBookRaw(::grpc::ClientContext* context, const ::google::example::library::v1::CreateBookRequest& request, ::grpc::CompletionQueue* cq) {
  return new ::grpc::ClientAsyncResponseReader< ::google::example::library::v1::Book>(channel_.get(), cq, rpcmethod_CreateBook_, context, request);
}

::grpc::Status LibraryService::Stub::GetBook(::grpc::ClientContext* context, const ::google::example::library::v1::GetBookRequest& request, ::google::example::library::v1::Book* response) {
  return ::grpc::BlockingUnaryCall(channel_.get(), rpcmethod_GetBook_, context, request, response);
}

::grpc::ClientAsyncResponseReader< ::google::example::library::v1::Book>* LibraryService::Stub::AsyncGetBookRaw(::grpc::ClientContext* context, const ::google::example::library::v1::GetBookRequest& request, ::grpc::CompletionQueue* cq) {
  return new ::grpc::ClientAsyncResponseReader< ::google::example::library::v1::Book>(channel_.get(), cq, rpcmethod_GetBook_, context, request);
}

::grpc::Status LibraryService::Stub::ListBooks(::grpc::ClientContext* context, const ::google::example::library::v1::ListBooksRequest& request, ::google::example::library::v1::ListBooksResponse* response) {
  return ::grpc::BlockingUnaryCall(channel_.get(), rpcmethod_ListBooks_, context, request, response);
}

::grpc::ClientAsyncResponseReader< ::google::example::library::v1::ListBooksResponse>* LibraryService::Stub::AsyncListBooksRaw(::grpc::ClientContext* context, const ::google::example::library::v1::ListBooksRequest& request, ::grpc::CompletionQueue* cq) {
  return new ::grpc::ClientAsyncResponseReader< ::google::example::library::v1::ListBooksResponse>(channel_.get(), cq, rpcmethod_ListBooks_, context, request);
}

::grpc::Status LibraryService::Stub::DeleteBook(::grpc::ClientContext* context, const ::google::example::library::v1::DeleteBookRequest& request, ::google::protobuf::Empty* response) {
  return ::grpc::BlockingUnaryCall(channel_.get(), rpcmethod_DeleteBook_, context, request, response);
}

::grpc::ClientAsyncResponseReader< ::google::protobuf::Empty>* LibraryService::Stub::AsyncDeleteBookRaw(::grpc::ClientContext* context, const ::google::example::library::v1::DeleteBookRequest& request, ::grpc::CompletionQueue* cq) {
  return new ::grpc::ClientAsyncResponseReader< ::google::protobuf::Empty>(channel_.get(), cq, rpcmethod_DeleteBook_, context, request);
}

::grpc::Status LibraryService::Stub::UpdateBook(::grpc::ClientContext* context, const ::google::example::library::v1::UpdateBookRequest& request, ::google::example::library::v1::Book* response) {
  return ::grpc::BlockingUnaryCall(channel_.get(), rpcmethod_UpdateBook_, context, request, response);
}

::grpc::ClientAsyncResponseReader< ::google::example::library::v1::Book>* LibraryService::Stub::AsyncUpdateBookRaw(::grpc::ClientContext* context, const ::google::example::library::v1::UpdateBookRequest& request, ::grpc::CompletionQueue* cq) {
  return new ::grpc::ClientAsyncResponseReader< ::google::example::library::v1::Book>(channel_.get(), cq, rpcmethod_UpdateBook_, context, request);
}

::grpc::Status LibraryService::Stub::MoveBook(::grpc::ClientContext* context, const ::google::example::library::v1::MoveBookRequest& request, ::google::example::library::v1::Book* response) {
  return ::grpc::BlockingUnaryCall(channel_.get(), rpcmethod_MoveBook_, context, request, response);
}

::grpc::ClientAsyncResponseReader< ::google::example::library::v1::Book>* LibraryService::Stub::AsyncMoveBookRaw(::grpc::ClientContext* context, const ::google::example::library::v1::MoveBookRequest& request, ::grpc::CompletionQueue* cq) {
  return new ::grpc::ClientAsyncResponseReader< ::google::example::library::v1::Book>(channel_.get(), cq, rpcmethod_MoveBook_, context, request);
}

LibraryService::Service::Service() {
  (void)LibraryService_method_names;
  AddMethod(new ::grpc::RpcServiceMethod(
      LibraryService_method_names[0],
      ::grpc::RpcMethod::NORMAL_RPC,
      new ::grpc::RpcMethodHandler< LibraryService::Service, ::google::example::library::v1::CreateShelfRequest, ::google::example::library::v1::Shelf>(
          std::mem_fn(&LibraryService::Service::CreateShelf), this)));
  AddMethod(new ::grpc::RpcServiceMethod(
      LibraryService_method_names[1],
      ::grpc::RpcMethod::NORMAL_RPC,
      new ::grpc::RpcMethodHandler< LibraryService::Service, ::google::example::library::v1::GetShelfRequest, ::google::example::library::v1::Shelf>(
          std::mem_fn(&LibraryService::Service::GetShelf), this)));
  AddMethod(new ::grpc::RpcServiceMethod(
      LibraryService_method_names[2],
      ::grpc::RpcMethod::NORMAL_RPC,
      new ::grpc::RpcMethodHandler< LibraryService::Service, ::google::example::library::v1::ListShelvesRequest, ::google::example::library::v1::ListShelvesResponse>(
          std::mem_fn(&LibraryService::Service::ListShelves), this)));
  AddMethod(new ::grpc::RpcServiceMethod(
      LibraryService_method_names[3],
      ::grpc::RpcMethod::NORMAL_RPC,
      new ::grpc::RpcMethodHandler< LibraryService::Service, ::google::example::library::v1::DeleteShelfRequest, ::google::protobuf::Empty>(
          std::mem_fn(&LibraryService::Service::DeleteShelf), this)));
  AddMethod(new ::grpc::RpcServiceMethod(
      LibraryService_method_names[4],
      ::grpc::RpcMethod::NORMAL_RPC,
      new ::grpc::RpcMethodHandler< LibraryService::Service, ::google::example::library::v1::MergeShelvesRequest, ::google::example::library::v1::Shelf>(
          std::mem_fn(&LibraryService::Service::MergeShelves), this)));
  AddMethod(new ::grpc::RpcServiceMethod(
      LibraryService_method_names[5],
      ::grpc::RpcMethod::NORMAL_RPC,
      new ::grpc::RpcMethodHandler< LibraryService::Service, ::google::example::library::v1::CreateBookRequest, ::google::example::library::v1::Book>(
          std::mem_fn(&LibraryService::Service::CreateBook), this)));
  AddMethod(new ::grpc::RpcServiceMethod(
      LibraryService_method_names[6],
      ::grpc::RpcMethod::NORMAL_RPC,
      new ::grpc::RpcMethodHandler< LibraryService::Service, ::google::example::library::v1::GetBookRequest, ::google::example::library::v1::Book>(
          std::mem_fn(&LibraryService::Service::GetBook), this)));
  AddMethod(new ::grpc::RpcServiceMethod(
      LibraryService_method_names[7],
      ::grpc::RpcMethod::NORMAL_RPC,
      new ::grpc::RpcMethodHandler< LibraryService::Service, ::google::example::library::v1::ListBooksRequest, ::google::example::library::v1::ListBooksResponse>(
          std::mem_fn(&LibraryService::Service::ListBooks), this)));
  AddMethod(new ::grpc::RpcServiceMethod(
      LibraryService_method_names[8],
      ::grpc::RpcMethod::NORMAL_RPC,
      new ::grpc::RpcMethodHandler< LibraryService::Service, ::google::example::library::v1::DeleteBookRequest, ::google::protobuf::Empty>(
          std::mem_fn(&LibraryService::Service::DeleteBook), this)));
  AddMethod(new ::grpc::RpcServiceMethod(
      LibraryService_method_names[9],
      ::grpc::RpcMethod::NORMAL_RPC,
      new ::grpc::RpcMethodHandler< LibraryService::Service, ::google::example::library::v1::UpdateBookRequest, ::google::example::library::v1::Book>(
          std::mem_fn(&LibraryService::Service::UpdateBook), this)));
  AddMethod(new ::grpc::RpcServiceMethod(
      LibraryService_method_names[10],
      ::grpc::RpcMethod::NORMAL_RPC,
      new ::grpc::RpcMethodHandler< LibraryService::Service, ::google::example::library::v1::MoveBookRequest, ::google::example::library::v1::Book>(
          std::mem_fn(&LibraryService::Service::MoveBook), this)));
}

LibraryService::Service::~Service() {
}

::grpc::Status LibraryService::Service::CreateShelf(::grpc::ServerContext* context, const ::google::example::library::v1::CreateShelfRequest* request, ::google::example::library::v1::Shelf* response) {
  (void) context;
  (void) request;
  (void) response;
  return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
}

::grpc::Status LibraryService::Service::GetShelf(::grpc::ServerContext* context, const ::google::example::library::v1::GetShelfRequest* request, ::google::example::library::v1::Shelf* response) {
  (void) context;
  (void) request;
  (void) response;
  return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
}

::grpc::Status LibraryService::Service::ListShelves(::grpc::ServerContext* context, const ::google::example::library::v1::ListShelvesRequest* request, ::google::example::library::v1::ListShelvesResponse* response) {
  (void) context;
  (void) request;
  (void) response;
  return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
}

::grpc::Status LibraryService::Service::DeleteShelf(::grpc::ServerContext* context, const ::google::example::library::v1::DeleteShelfRequest* request, ::google::protobuf::Empty* response) {
  (void) context;
  (void) request;
  (void) response;
  return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
}

::grpc::Status LibraryService::Service::MergeShelves(::grpc::ServerContext* context, const ::google::example::library::v1::MergeShelvesRequest* request, ::google::example::library::v1::Shelf* response) {
  (void) context;
  (void) request;
  (void) response;
  return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
}

::grpc::Status LibraryService::Service::CreateBook(::grpc::ServerContext* context, const ::google::example::library::v1::CreateBookRequest* request, ::google::example::library::v1::Book* response) {
  (void) context;
  (void) request;
  (void) response;
  return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
}

::grpc::Status LibraryService::Service::GetBook(::grpc::ServerContext* context, const ::google::example::library::v1::GetBookRequest* request, ::google::example::library::v1::Book* response) {
  (void) context;
  (void) request;
  (void) response;
  return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
}

::grpc::Status LibraryService::Service::ListBooks(::grpc::ServerContext* context, const ::google::example::library::v1::ListBooksRequest* request, ::google::example::library::v1::ListBooksResponse* response) {
  (void) context;
  (void) request;
  (void) response;
  return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
}

::grpc::Status LibraryService::Service::DeleteBook(::grpc::ServerContext* context, const ::google::example::library::v1::DeleteBookRequest* request, ::google::protobuf::Empty* response) {
  (void) context;
  (void) request;
  (void) response;
  return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
}

::grpc::Status LibraryService::Service::UpdateBook(::grpc::ServerContext* context, const ::google::example::library::v1::UpdateBookRequest* request, ::google::example::library::v1::Book* response) {
  (void) context;
  (void) request;
  (void) response;
  return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
}

::grpc::Status LibraryService::Service::MoveBook(::grpc::ServerContext* context, const ::google::example::library::v1::MoveBookRequest* request, ::google::example::library::v1::Book* response) {
  (void) context;
  (void) request;
  (void) response;
  return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
}


}  // namespace google
}  // namespace example
}  // namespace library
}  // namespace v1

