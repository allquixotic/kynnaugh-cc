// Generated by the gRPC protobuf plugin.
// If you make any local change, they will be lost.
// source: google/genomics/v1alpha2/pipelines.proto
// Original file comments:
// Copyright 2016 Google Inc.
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.
//
#ifndef GRPC_google_2fgenomics_2fv1alpha2_2fpipelines_2eproto__INCLUDED
#define GRPC_google_2fgenomics_2fv1alpha2_2fpipelines_2eproto__INCLUDED

#include "google/genomics/v1alpha2/pipelines.pb.h"

#include <grpc++/impl/codegen/async_stream.h>
#include <grpc++/impl/codegen/async_unary_call.h>
#include <grpc++/impl/codegen/proto_utils.h>
#include <grpc++/impl/codegen/rpc_method.h>
#include <grpc++/impl/codegen/service_type.h>
#include <grpc++/impl/codegen/status.h>
#include <grpc++/impl/codegen/stub_options.h>
#include <grpc++/impl/codegen/sync_stream.h>

namespace grpc {
class CompletionQueue;
class Channel;
class RpcService;
class ServerCompletionQueue;
class ServerContext;
}  // namespace grpc

namespace google {
namespace genomics {
namespace v1alpha2 {

// A service for running genomics pipelines.
class PipelinesV1Alpha2 GRPC_FINAL {
 public:
  class StubInterface {
   public:
    virtual ~StubInterface() {}
    // Creates a pipeline that can be run later. Create takes a Pipeline that
    // has all fields other than `pipelineId` populated, and then returns
    // the same pipeline with `pipelineId` populated. This id can be used
    // to run the pipeline.
    //
    // Caller must have WRITE permission to the project.
    virtual ::grpc::Status CreatePipeline(::grpc::ClientContext* context, const ::google::genomics::v1alpha2::CreatePipelineRequest& request, ::google::genomics::v1alpha2::Pipeline* response) = 0;
    std::unique_ptr< ::grpc::ClientAsyncResponseReaderInterface< ::google::genomics::v1alpha2::Pipeline>> AsyncCreatePipeline(::grpc::ClientContext* context, const ::google::genomics::v1alpha2::CreatePipelineRequest& request, ::grpc::CompletionQueue* cq) {
      return std::unique_ptr< ::grpc::ClientAsyncResponseReaderInterface< ::google::genomics::v1alpha2::Pipeline>>(AsyncCreatePipelineRaw(context, request, cq));
    }
    // Runs a pipeline. If `pipelineId` is specified in the request, then
    // run a saved pipeline. If `ephemeralPipeline` is specified, then run
    // that pipeline once without saving a copy.
    //
    // The caller must have READ permission to the project where the pipeline
    // is stored and WRITE permission to the project where the pipeline will be
    // run, as VMs will be created and storage will be used.
    virtual ::grpc::Status RunPipeline(::grpc::ClientContext* context, const ::google::genomics::v1alpha2::RunPipelineRequest& request, ::google::longrunning::Operation* response) = 0;
    std::unique_ptr< ::grpc::ClientAsyncResponseReaderInterface< ::google::longrunning::Operation>> AsyncRunPipeline(::grpc::ClientContext* context, const ::google::genomics::v1alpha2::RunPipelineRequest& request, ::grpc::CompletionQueue* cq) {
      return std::unique_ptr< ::grpc::ClientAsyncResponseReaderInterface< ::google::longrunning::Operation>>(AsyncRunPipelineRaw(context, request, cq));
    }
    // Retrieves a pipeline based on ID.
    //
    // Caller must have READ permission to the project.
    virtual ::grpc::Status GetPipeline(::grpc::ClientContext* context, const ::google::genomics::v1alpha2::GetPipelineRequest& request, ::google::genomics::v1alpha2::Pipeline* response) = 0;
    std::unique_ptr< ::grpc::ClientAsyncResponseReaderInterface< ::google::genomics::v1alpha2::Pipeline>> AsyncGetPipeline(::grpc::ClientContext* context, const ::google::genomics::v1alpha2::GetPipelineRequest& request, ::grpc::CompletionQueue* cq) {
      return std::unique_ptr< ::grpc::ClientAsyncResponseReaderInterface< ::google::genomics::v1alpha2::Pipeline>>(AsyncGetPipelineRaw(context, request, cq));
    }
    // Lists pipelines.
    //
    // Caller must have READ permission to the project.
    virtual ::grpc::Status ListPipelines(::grpc::ClientContext* context, const ::google::genomics::v1alpha2::ListPipelinesRequest& request, ::google::genomics::v1alpha2::ListPipelinesResponse* response) = 0;
    std::unique_ptr< ::grpc::ClientAsyncResponseReaderInterface< ::google::genomics::v1alpha2::ListPipelinesResponse>> AsyncListPipelines(::grpc::ClientContext* context, const ::google::genomics::v1alpha2::ListPipelinesRequest& request, ::grpc::CompletionQueue* cq) {
      return std::unique_ptr< ::grpc::ClientAsyncResponseReaderInterface< ::google::genomics::v1alpha2::ListPipelinesResponse>>(AsyncListPipelinesRaw(context, request, cq));
    }
    // Deletes a pipeline based on ID.
    //
    // Caller must have WRITE permission to the project.
    virtual ::grpc::Status DeletePipeline(::grpc::ClientContext* context, const ::google::genomics::v1alpha2::DeletePipelineRequest& request, ::google::protobuf::Empty* response) = 0;
    std::unique_ptr< ::grpc::ClientAsyncResponseReaderInterface< ::google::protobuf::Empty>> AsyncDeletePipeline(::grpc::ClientContext* context, const ::google::genomics::v1alpha2::DeletePipelineRequest& request, ::grpc::CompletionQueue* cq) {
      return std::unique_ptr< ::grpc::ClientAsyncResponseReaderInterface< ::google::protobuf::Empty>>(AsyncDeletePipelineRaw(context, request, cq));
    }
    // Gets controller configuration information. Should only be called
    // by VMs created by the Pipelines Service and not by end users.
    virtual ::grpc::Status GetControllerConfig(::grpc::ClientContext* context, const ::google::genomics::v1alpha2::GetControllerConfigRequest& request, ::google::genomics::v1alpha2::ControllerConfig* response) = 0;
    std::unique_ptr< ::grpc::ClientAsyncResponseReaderInterface< ::google::genomics::v1alpha2::ControllerConfig>> AsyncGetControllerConfig(::grpc::ClientContext* context, const ::google::genomics::v1alpha2::GetControllerConfigRequest& request, ::grpc::CompletionQueue* cq) {
      return std::unique_ptr< ::grpc::ClientAsyncResponseReaderInterface< ::google::genomics::v1alpha2::ControllerConfig>>(AsyncGetControllerConfigRaw(context, request, cq));
    }
    // Sets status of a given operation. All timestamps are sent on each
    // call, and the whole series of events is replaced, in case
    // intermediate calls are lost. Should only be called by VMs created
    // by the Pipelines Service and not by end users.
    virtual ::grpc::Status SetOperationStatus(::grpc::ClientContext* context, const ::google::genomics::v1alpha2::SetOperationStatusRequest& request, ::google::protobuf::Empty* response) = 0;
    std::unique_ptr< ::grpc::ClientAsyncResponseReaderInterface< ::google::protobuf::Empty>> AsyncSetOperationStatus(::grpc::ClientContext* context, const ::google::genomics::v1alpha2::SetOperationStatusRequest& request, ::grpc::CompletionQueue* cq) {
      return std::unique_ptr< ::grpc::ClientAsyncResponseReaderInterface< ::google::protobuf::Empty>>(AsyncSetOperationStatusRaw(context, request, cq));
    }
  private:
    virtual ::grpc::ClientAsyncResponseReaderInterface< ::google::genomics::v1alpha2::Pipeline>* AsyncCreatePipelineRaw(::grpc::ClientContext* context, const ::google::genomics::v1alpha2::CreatePipelineRequest& request, ::grpc::CompletionQueue* cq) = 0;
    virtual ::grpc::ClientAsyncResponseReaderInterface< ::google::longrunning::Operation>* AsyncRunPipelineRaw(::grpc::ClientContext* context, const ::google::genomics::v1alpha2::RunPipelineRequest& request, ::grpc::CompletionQueue* cq) = 0;
    virtual ::grpc::ClientAsyncResponseReaderInterface< ::google::genomics::v1alpha2::Pipeline>* AsyncGetPipelineRaw(::grpc::ClientContext* context, const ::google::genomics::v1alpha2::GetPipelineRequest& request, ::grpc::CompletionQueue* cq) = 0;
    virtual ::grpc::ClientAsyncResponseReaderInterface< ::google::genomics::v1alpha2::ListPipelinesResponse>* AsyncListPipelinesRaw(::grpc::ClientContext* context, const ::google::genomics::v1alpha2::ListPipelinesRequest& request, ::grpc::CompletionQueue* cq) = 0;
    virtual ::grpc::ClientAsyncResponseReaderInterface< ::google::protobuf::Empty>* AsyncDeletePipelineRaw(::grpc::ClientContext* context, const ::google::genomics::v1alpha2::DeletePipelineRequest& request, ::grpc::CompletionQueue* cq) = 0;
    virtual ::grpc::ClientAsyncResponseReaderInterface< ::google::genomics::v1alpha2::ControllerConfig>* AsyncGetControllerConfigRaw(::grpc::ClientContext* context, const ::google::genomics::v1alpha2::GetControllerConfigRequest& request, ::grpc::CompletionQueue* cq) = 0;
    virtual ::grpc::ClientAsyncResponseReaderInterface< ::google::protobuf::Empty>* AsyncSetOperationStatusRaw(::grpc::ClientContext* context, const ::google::genomics::v1alpha2::SetOperationStatusRequest& request, ::grpc::CompletionQueue* cq) = 0;
  };
  class Stub GRPC_FINAL : public StubInterface {
   public:
    Stub(const std::shared_ptr< ::grpc::ChannelInterface>& channel);
    ::grpc::Status CreatePipeline(::grpc::ClientContext* context, const ::google::genomics::v1alpha2::CreatePipelineRequest& request, ::google::genomics::v1alpha2::Pipeline* response) GRPC_OVERRIDE;
    std::unique_ptr< ::grpc::ClientAsyncResponseReader< ::google::genomics::v1alpha2::Pipeline>> AsyncCreatePipeline(::grpc::ClientContext* context, const ::google::genomics::v1alpha2::CreatePipelineRequest& request, ::grpc::CompletionQueue* cq) {
      return std::unique_ptr< ::grpc::ClientAsyncResponseReader< ::google::genomics::v1alpha2::Pipeline>>(AsyncCreatePipelineRaw(context, request, cq));
    }
    ::grpc::Status RunPipeline(::grpc::ClientContext* context, const ::google::genomics::v1alpha2::RunPipelineRequest& request, ::google::longrunning::Operation* response) GRPC_OVERRIDE;
    std::unique_ptr< ::grpc::ClientAsyncResponseReader< ::google::longrunning::Operation>> AsyncRunPipeline(::grpc::ClientContext* context, const ::google::genomics::v1alpha2::RunPipelineRequest& request, ::grpc::CompletionQueue* cq) {
      return std::unique_ptr< ::grpc::ClientAsyncResponseReader< ::google::longrunning::Operation>>(AsyncRunPipelineRaw(context, request, cq));
    }
    ::grpc::Status GetPipeline(::grpc::ClientContext* context, const ::google::genomics::v1alpha2::GetPipelineRequest& request, ::google::genomics::v1alpha2::Pipeline* response) GRPC_OVERRIDE;
    std::unique_ptr< ::grpc::ClientAsyncResponseReader< ::google::genomics::v1alpha2::Pipeline>> AsyncGetPipeline(::grpc::ClientContext* context, const ::google::genomics::v1alpha2::GetPipelineRequest& request, ::grpc::CompletionQueue* cq) {
      return std::unique_ptr< ::grpc::ClientAsyncResponseReader< ::google::genomics::v1alpha2::Pipeline>>(AsyncGetPipelineRaw(context, request, cq));
    }
    ::grpc::Status ListPipelines(::grpc::ClientContext* context, const ::google::genomics::v1alpha2::ListPipelinesRequest& request, ::google::genomics::v1alpha2::ListPipelinesResponse* response) GRPC_OVERRIDE;
    std::unique_ptr< ::grpc::ClientAsyncResponseReader< ::google::genomics::v1alpha2::ListPipelinesResponse>> AsyncListPipelines(::grpc::ClientContext* context, const ::google::genomics::v1alpha2::ListPipelinesRequest& request, ::grpc::CompletionQueue* cq) {
      return std::unique_ptr< ::grpc::ClientAsyncResponseReader< ::google::genomics::v1alpha2::ListPipelinesResponse>>(AsyncListPipelinesRaw(context, request, cq));
    }
    ::grpc::Status DeletePipeline(::grpc::ClientContext* context, const ::google::genomics::v1alpha2::DeletePipelineRequest& request, ::google::protobuf::Empty* response) GRPC_OVERRIDE;
    std::unique_ptr< ::grpc::ClientAsyncResponseReader< ::google::protobuf::Empty>> AsyncDeletePipeline(::grpc::ClientContext* context, const ::google::genomics::v1alpha2::DeletePipelineRequest& request, ::grpc::CompletionQueue* cq) {
      return std::unique_ptr< ::grpc::ClientAsyncResponseReader< ::google::protobuf::Empty>>(AsyncDeletePipelineRaw(context, request, cq));
    }
    ::grpc::Status GetControllerConfig(::grpc::ClientContext* context, const ::google::genomics::v1alpha2::GetControllerConfigRequest& request, ::google::genomics::v1alpha2::ControllerConfig* response) GRPC_OVERRIDE;
    std::unique_ptr< ::grpc::ClientAsyncResponseReader< ::google::genomics::v1alpha2::ControllerConfig>> AsyncGetControllerConfig(::grpc::ClientContext* context, const ::google::genomics::v1alpha2::GetControllerConfigRequest& request, ::grpc::CompletionQueue* cq) {
      return std::unique_ptr< ::grpc::ClientAsyncResponseReader< ::google::genomics::v1alpha2::ControllerConfig>>(AsyncGetControllerConfigRaw(context, request, cq));
    }
    ::grpc::Status SetOperationStatus(::grpc::ClientContext* context, const ::google::genomics::v1alpha2::SetOperationStatusRequest& request, ::google::protobuf::Empty* response) GRPC_OVERRIDE;
    std::unique_ptr< ::grpc::ClientAsyncResponseReader< ::google::protobuf::Empty>> AsyncSetOperationStatus(::grpc::ClientContext* context, const ::google::genomics::v1alpha2::SetOperationStatusRequest& request, ::grpc::CompletionQueue* cq) {
      return std::unique_ptr< ::grpc::ClientAsyncResponseReader< ::google::protobuf::Empty>>(AsyncSetOperationStatusRaw(context, request, cq));
    }

   private:
    std::shared_ptr< ::grpc::ChannelInterface> channel_;
    ::grpc::ClientAsyncResponseReader< ::google::genomics::v1alpha2::Pipeline>* AsyncCreatePipelineRaw(::grpc::ClientContext* context, const ::google::genomics::v1alpha2::CreatePipelineRequest& request, ::grpc::CompletionQueue* cq) GRPC_OVERRIDE;
    ::grpc::ClientAsyncResponseReader< ::google::longrunning::Operation>* AsyncRunPipelineRaw(::grpc::ClientContext* context, const ::google::genomics::v1alpha2::RunPipelineRequest& request, ::grpc::CompletionQueue* cq) GRPC_OVERRIDE;
    ::grpc::ClientAsyncResponseReader< ::google::genomics::v1alpha2::Pipeline>* AsyncGetPipelineRaw(::grpc::ClientContext* context, const ::google::genomics::v1alpha2::GetPipelineRequest& request, ::grpc::CompletionQueue* cq) GRPC_OVERRIDE;
    ::grpc::ClientAsyncResponseReader< ::google::genomics::v1alpha2::ListPipelinesResponse>* AsyncListPipelinesRaw(::grpc::ClientContext* context, const ::google::genomics::v1alpha2::ListPipelinesRequest& request, ::grpc::CompletionQueue* cq) GRPC_OVERRIDE;
    ::grpc::ClientAsyncResponseReader< ::google::protobuf::Empty>* AsyncDeletePipelineRaw(::grpc::ClientContext* context, const ::google::genomics::v1alpha2::DeletePipelineRequest& request, ::grpc::CompletionQueue* cq) GRPC_OVERRIDE;
    ::grpc::ClientAsyncResponseReader< ::google::genomics::v1alpha2::ControllerConfig>* AsyncGetControllerConfigRaw(::grpc::ClientContext* context, const ::google::genomics::v1alpha2::GetControllerConfigRequest& request, ::grpc::CompletionQueue* cq) GRPC_OVERRIDE;
    ::grpc::ClientAsyncResponseReader< ::google::protobuf::Empty>* AsyncSetOperationStatusRaw(::grpc::ClientContext* context, const ::google::genomics::v1alpha2::SetOperationStatusRequest& request, ::grpc::CompletionQueue* cq) GRPC_OVERRIDE;
    const ::grpc::RpcMethod rpcmethod_CreatePipeline_;
    const ::grpc::RpcMethod rpcmethod_RunPipeline_;
    const ::grpc::RpcMethod rpcmethod_GetPipeline_;
    const ::grpc::RpcMethod rpcmethod_ListPipelines_;
    const ::grpc::RpcMethod rpcmethod_DeletePipeline_;
    const ::grpc::RpcMethod rpcmethod_GetControllerConfig_;
    const ::grpc::RpcMethod rpcmethod_SetOperationStatus_;
  };
  static std::unique_ptr<Stub> NewStub(const std::shared_ptr< ::grpc::ChannelInterface>& channel, const ::grpc::StubOptions& options = ::grpc::StubOptions());

  class Service : public ::grpc::Service {
   public:
    Service();
    virtual ~Service();
    // Creates a pipeline that can be run later. Create takes a Pipeline that
    // has all fields other than `pipelineId` populated, and then returns
    // the same pipeline with `pipelineId` populated. This id can be used
    // to run the pipeline.
    //
    // Caller must have WRITE permission to the project.
    virtual ::grpc::Status CreatePipeline(::grpc::ServerContext* context, const ::google::genomics::v1alpha2::CreatePipelineRequest* request, ::google::genomics::v1alpha2::Pipeline* response);
    // Runs a pipeline. If `pipelineId` is specified in the request, then
    // run a saved pipeline. If `ephemeralPipeline` is specified, then run
    // that pipeline once without saving a copy.
    //
    // The caller must have READ permission to the project where the pipeline
    // is stored and WRITE permission to the project where the pipeline will be
    // run, as VMs will be created and storage will be used.
    virtual ::grpc::Status RunPipeline(::grpc::ServerContext* context, const ::google::genomics::v1alpha2::RunPipelineRequest* request, ::google::longrunning::Operation* response);
    // Retrieves a pipeline based on ID.
    //
    // Caller must have READ permission to the project.
    virtual ::grpc::Status GetPipeline(::grpc::ServerContext* context, const ::google::genomics::v1alpha2::GetPipelineRequest* request, ::google::genomics::v1alpha2::Pipeline* response);
    // Lists pipelines.
    //
    // Caller must have READ permission to the project.
    virtual ::grpc::Status ListPipelines(::grpc::ServerContext* context, const ::google::genomics::v1alpha2::ListPipelinesRequest* request, ::google::genomics::v1alpha2::ListPipelinesResponse* response);
    // Deletes a pipeline based on ID.
    //
    // Caller must have WRITE permission to the project.
    virtual ::grpc::Status DeletePipeline(::grpc::ServerContext* context, const ::google::genomics::v1alpha2::DeletePipelineRequest* request, ::google::protobuf::Empty* response);
    // Gets controller configuration information. Should only be called
    // by VMs created by the Pipelines Service and not by end users.
    virtual ::grpc::Status GetControllerConfig(::grpc::ServerContext* context, const ::google::genomics::v1alpha2::GetControllerConfigRequest* request, ::google::genomics::v1alpha2::ControllerConfig* response);
    // Sets status of a given operation. All timestamps are sent on each
    // call, and the whole series of events is replaced, in case
    // intermediate calls are lost. Should only be called by VMs created
    // by the Pipelines Service and not by end users.
    virtual ::grpc::Status SetOperationStatus(::grpc::ServerContext* context, const ::google::genomics::v1alpha2::SetOperationStatusRequest* request, ::google::protobuf::Empty* response);
  };
  template <class BaseClass>
  class WithAsyncMethod_CreatePipeline : public BaseClass {
   private:
    void BaseClassMustBeDerivedFromService(const Service *service) {}
   public:
    WithAsyncMethod_CreatePipeline() {
      ::grpc::Service::MarkMethodAsync(0);
    }
    ~WithAsyncMethod_CreatePipeline() GRPC_OVERRIDE {
      BaseClassMustBeDerivedFromService(this);
    }
    // disable synchronous version of this method
    ::grpc::Status CreatePipeline(::grpc::ServerContext* context, const ::google::genomics::v1alpha2::CreatePipelineRequest* request, ::google::genomics::v1alpha2::Pipeline* response) GRPC_FINAL GRPC_OVERRIDE {
      abort();
      return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
    }
    void RequestCreatePipeline(::grpc::ServerContext* context, ::google::genomics::v1alpha2::CreatePipelineRequest* request, ::grpc::ServerAsyncResponseWriter< ::google::genomics::v1alpha2::Pipeline>* response, ::grpc::CompletionQueue* new_call_cq, ::grpc::ServerCompletionQueue* notification_cq, void *tag) {
      ::grpc::Service::RequestAsyncUnary(0, context, request, response, new_call_cq, notification_cq, tag);
    }
  };
  template <class BaseClass>
  class WithAsyncMethod_RunPipeline : public BaseClass {
   private:
    void BaseClassMustBeDerivedFromService(const Service *service) {}
   public:
    WithAsyncMethod_RunPipeline() {
      ::grpc::Service::MarkMethodAsync(1);
    }
    ~WithAsyncMethod_RunPipeline() GRPC_OVERRIDE {
      BaseClassMustBeDerivedFromService(this);
    }
    // disable synchronous version of this method
    ::grpc::Status RunPipeline(::grpc::ServerContext* context, const ::google::genomics::v1alpha2::RunPipelineRequest* request, ::google::longrunning::Operation* response) GRPC_FINAL GRPC_OVERRIDE {
      abort();
      return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
    }
    void RequestRunPipeline(::grpc::ServerContext* context, ::google::genomics::v1alpha2::RunPipelineRequest* request, ::grpc::ServerAsyncResponseWriter< ::google::longrunning::Operation>* response, ::grpc::CompletionQueue* new_call_cq, ::grpc::ServerCompletionQueue* notification_cq, void *tag) {
      ::grpc::Service::RequestAsyncUnary(1, context, request, response, new_call_cq, notification_cq, tag);
    }
  };
  template <class BaseClass>
  class WithAsyncMethod_GetPipeline : public BaseClass {
   private:
    void BaseClassMustBeDerivedFromService(const Service *service) {}
   public:
    WithAsyncMethod_GetPipeline() {
      ::grpc::Service::MarkMethodAsync(2);
    }
    ~WithAsyncMethod_GetPipeline() GRPC_OVERRIDE {
      BaseClassMustBeDerivedFromService(this);
    }
    // disable synchronous version of this method
    ::grpc::Status GetPipeline(::grpc::ServerContext* context, const ::google::genomics::v1alpha2::GetPipelineRequest* request, ::google::genomics::v1alpha2::Pipeline* response) GRPC_FINAL GRPC_OVERRIDE {
      abort();
      return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
    }
    void RequestGetPipeline(::grpc::ServerContext* context, ::google::genomics::v1alpha2::GetPipelineRequest* request, ::grpc::ServerAsyncResponseWriter< ::google::genomics::v1alpha2::Pipeline>* response, ::grpc::CompletionQueue* new_call_cq, ::grpc::ServerCompletionQueue* notification_cq, void *tag) {
      ::grpc::Service::RequestAsyncUnary(2, context, request, response, new_call_cq, notification_cq, tag);
    }
  };
  template <class BaseClass>
  class WithAsyncMethod_ListPipelines : public BaseClass {
   private:
    void BaseClassMustBeDerivedFromService(const Service *service) {}
   public:
    WithAsyncMethod_ListPipelines() {
      ::grpc::Service::MarkMethodAsync(3);
    }
    ~WithAsyncMethod_ListPipelines() GRPC_OVERRIDE {
      BaseClassMustBeDerivedFromService(this);
    }
    // disable synchronous version of this method
    ::grpc::Status ListPipelines(::grpc::ServerContext* context, const ::google::genomics::v1alpha2::ListPipelinesRequest* request, ::google::genomics::v1alpha2::ListPipelinesResponse* response) GRPC_FINAL GRPC_OVERRIDE {
      abort();
      return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
    }
    void RequestListPipelines(::grpc::ServerContext* context, ::google::genomics::v1alpha2::ListPipelinesRequest* request, ::grpc::ServerAsyncResponseWriter< ::google::genomics::v1alpha2::ListPipelinesResponse>* response, ::grpc::CompletionQueue* new_call_cq, ::grpc::ServerCompletionQueue* notification_cq, void *tag) {
      ::grpc::Service::RequestAsyncUnary(3, context, request, response, new_call_cq, notification_cq, tag);
    }
  };
  template <class BaseClass>
  class WithAsyncMethod_DeletePipeline : public BaseClass {
   private:
    void BaseClassMustBeDerivedFromService(const Service *service) {}
   public:
    WithAsyncMethod_DeletePipeline() {
      ::grpc::Service::MarkMethodAsync(4);
    }
    ~WithAsyncMethod_DeletePipeline() GRPC_OVERRIDE {
      BaseClassMustBeDerivedFromService(this);
    }
    // disable synchronous version of this method
    ::grpc::Status DeletePipeline(::grpc::ServerContext* context, const ::google::genomics::v1alpha2::DeletePipelineRequest* request, ::google::protobuf::Empty* response) GRPC_FINAL GRPC_OVERRIDE {
      abort();
      return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
    }
    void RequestDeletePipeline(::grpc::ServerContext* context, ::google::genomics::v1alpha2::DeletePipelineRequest* request, ::grpc::ServerAsyncResponseWriter< ::google::protobuf::Empty>* response, ::grpc::CompletionQueue* new_call_cq, ::grpc::ServerCompletionQueue* notification_cq, void *tag) {
      ::grpc::Service::RequestAsyncUnary(4, context, request, response, new_call_cq, notification_cq, tag);
    }
  };
  template <class BaseClass>
  class WithAsyncMethod_GetControllerConfig : public BaseClass {
   private:
    void BaseClassMustBeDerivedFromService(const Service *service) {}
   public:
    WithAsyncMethod_GetControllerConfig() {
      ::grpc::Service::MarkMethodAsync(5);
    }
    ~WithAsyncMethod_GetControllerConfig() GRPC_OVERRIDE {
      BaseClassMustBeDerivedFromService(this);
    }
    // disable synchronous version of this method
    ::grpc::Status GetControllerConfig(::grpc::ServerContext* context, const ::google::genomics::v1alpha2::GetControllerConfigRequest* request, ::google::genomics::v1alpha2::ControllerConfig* response) GRPC_FINAL GRPC_OVERRIDE {
      abort();
      return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
    }
    void RequestGetControllerConfig(::grpc::ServerContext* context, ::google::genomics::v1alpha2::GetControllerConfigRequest* request, ::grpc::ServerAsyncResponseWriter< ::google::genomics::v1alpha2::ControllerConfig>* response, ::grpc::CompletionQueue* new_call_cq, ::grpc::ServerCompletionQueue* notification_cq, void *tag) {
      ::grpc::Service::RequestAsyncUnary(5, context, request, response, new_call_cq, notification_cq, tag);
    }
  };
  template <class BaseClass>
  class WithAsyncMethod_SetOperationStatus : public BaseClass {
   private:
    void BaseClassMustBeDerivedFromService(const Service *service) {}
   public:
    WithAsyncMethod_SetOperationStatus() {
      ::grpc::Service::MarkMethodAsync(6);
    }
    ~WithAsyncMethod_SetOperationStatus() GRPC_OVERRIDE {
      BaseClassMustBeDerivedFromService(this);
    }
    // disable synchronous version of this method
    ::grpc::Status SetOperationStatus(::grpc::ServerContext* context, const ::google::genomics::v1alpha2::SetOperationStatusRequest* request, ::google::protobuf::Empty* response) GRPC_FINAL GRPC_OVERRIDE {
      abort();
      return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
    }
    void RequestSetOperationStatus(::grpc::ServerContext* context, ::google::genomics::v1alpha2::SetOperationStatusRequest* request, ::grpc::ServerAsyncResponseWriter< ::google::protobuf::Empty>* response, ::grpc::CompletionQueue* new_call_cq, ::grpc::ServerCompletionQueue* notification_cq, void *tag) {
      ::grpc::Service::RequestAsyncUnary(6, context, request, response, new_call_cq, notification_cq, tag);
    }
  };
  typedef WithAsyncMethod_CreatePipeline<WithAsyncMethod_RunPipeline<WithAsyncMethod_GetPipeline<WithAsyncMethod_ListPipelines<WithAsyncMethod_DeletePipeline<WithAsyncMethod_GetControllerConfig<WithAsyncMethod_SetOperationStatus<Service > > > > > > > AsyncService;
  template <class BaseClass>
  class WithGenericMethod_CreatePipeline : public BaseClass {
   private:
    void BaseClassMustBeDerivedFromService(const Service *service) {}
   public:
    WithGenericMethod_CreatePipeline() {
      ::grpc::Service::MarkMethodGeneric(0);
    }
    ~WithGenericMethod_CreatePipeline() GRPC_OVERRIDE {
      BaseClassMustBeDerivedFromService(this);
    }
    // disable synchronous version of this method
    ::grpc::Status CreatePipeline(::grpc::ServerContext* context, const ::google::genomics::v1alpha2::CreatePipelineRequest* request, ::google::genomics::v1alpha2::Pipeline* response) GRPC_FINAL GRPC_OVERRIDE {
      abort();
      return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
    }
  };
  template <class BaseClass>
  class WithGenericMethod_RunPipeline : public BaseClass {
   private:
    void BaseClassMustBeDerivedFromService(const Service *service) {}
   public:
    WithGenericMethod_RunPipeline() {
      ::grpc::Service::MarkMethodGeneric(1);
    }
    ~WithGenericMethod_RunPipeline() GRPC_OVERRIDE {
      BaseClassMustBeDerivedFromService(this);
    }
    // disable synchronous version of this method
    ::grpc::Status RunPipeline(::grpc::ServerContext* context, const ::google::genomics::v1alpha2::RunPipelineRequest* request, ::google::longrunning::Operation* response) GRPC_FINAL GRPC_OVERRIDE {
      abort();
      return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
    }
  };
  template <class BaseClass>
  class WithGenericMethod_GetPipeline : public BaseClass {
   private:
    void BaseClassMustBeDerivedFromService(const Service *service) {}
   public:
    WithGenericMethod_GetPipeline() {
      ::grpc::Service::MarkMethodGeneric(2);
    }
    ~WithGenericMethod_GetPipeline() GRPC_OVERRIDE {
      BaseClassMustBeDerivedFromService(this);
    }
    // disable synchronous version of this method
    ::grpc::Status GetPipeline(::grpc::ServerContext* context, const ::google::genomics::v1alpha2::GetPipelineRequest* request, ::google::genomics::v1alpha2::Pipeline* response) GRPC_FINAL GRPC_OVERRIDE {
      abort();
      return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
    }
  };
  template <class BaseClass>
  class WithGenericMethod_ListPipelines : public BaseClass {
   private:
    void BaseClassMustBeDerivedFromService(const Service *service) {}
   public:
    WithGenericMethod_ListPipelines() {
      ::grpc::Service::MarkMethodGeneric(3);
    }
    ~WithGenericMethod_ListPipelines() GRPC_OVERRIDE {
      BaseClassMustBeDerivedFromService(this);
    }
    // disable synchronous version of this method
    ::grpc::Status ListPipelines(::grpc::ServerContext* context, const ::google::genomics::v1alpha2::ListPipelinesRequest* request, ::google::genomics::v1alpha2::ListPipelinesResponse* response) GRPC_FINAL GRPC_OVERRIDE {
      abort();
      return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
    }
  };
  template <class BaseClass>
  class WithGenericMethod_DeletePipeline : public BaseClass {
   private:
    void BaseClassMustBeDerivedFromService(const Service *service) {}
   public:
    WithGenericMethod_DeletePipeline() {
      ::grpc::Service::MarkMethodGeneric(4);
    }
    ~WithGenericMethod_DeletePipeline() GRPC_OVERRIDE {
      BaseClassMustBeDerivedFromService(this);
    }
    // disable synchronous version of this method
    ::grpc::Status DeletePipeline(::grpc::ServerContext* context, const ::google::genomics::v1alpha2::DeletePipelineRequest* request, ::google::protobuf::Empty* response) GRPC_FINAL GRPC_OVERRIDE {
      abort();
      return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
    }
  };
  template <class BaseClass>
  class WithGenericMethod_GetControllerConfig : public BaseClass {
   private:
    void BaseClassMustBeDerivedFromService(const Service *service) {}
   public:
    WithGenericMethod_GetControllerConfig() {
      ::grpc::Service::MarkMethodGeneric(5);
    }
    ~WithGenericMethod_GetControllerConfig() GRPC_OVERRIDE {
      BaseClassMustBeDerivedFromService(this);
    }
    // disable synchronous version of this method
    ::grpc::Status GetControllerConfig(::grpc::ServerContext* context, const ::google::genomics::v1alpha2::GetControllerConfigRequest* request, ::google::genomics::v1alpha2::ControllerConfig* response) GRPC_FINAL GRPC_OVERRIDE {
      abort();
      return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
    }
  };
  template <class BaseClass>
  class WithGenericMethod_SetOperationStatus : public BaseClass {
   private:
    void BaseClassMustBeDerivedFromService(const Service *service) {}
   public:
    WithGenericMethod_SetOperationStatus() {
      ::grpc::Service::MarkMethodGeneric(6);
    }
    ~WithGenericMethod_SetOperationStatus() GRPC_OVERRIDE {
      BaseClassMustBeDerivedFromService(this);
    }
    // disable synchronous version of this method
    ::grpc::Status SetOperationStatus(::grpc::ServerContext* context, const ::google::genomics::v1alpha2::SetOperationStatusRequest* request, ::google::protobuf::Empty* response) GRPC_FINAL GRPC_OVERRIDE {
      abort();
      return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
    }
  };
};

}  // namespace v1alpha2
}  // namespace genomics
}  // namespace google


#endif  // GRPC_google_2fgenomics_2fv1alpha2_2fpipelines_2eproto__INCLUDED