// Generated by the gRPC C++ plugin.
// If you make any local change, they will be lost.
// source: master.proto

#include "master.pb.h"
#include "master.grpc.pb.h"

#include <functional>
#include <grpcpp/impl/codegen/async_stream.h>
#include <grpcpp/impl/codegen/async_unary_call.h>
#include <grpcpp/impl/codegen/channel_interface.h>
#include <grpcpp/impl/codegen/client_unary_call.h>
#include <grpcpp/impl/codegen/client_callback.h>
#include <grpcpp/impl/codegen/method_handler_impl.h>
#include <grpcpp/impl/codegen/rpc_service_method.h>
#include <grpcpp/impl/codegen/server_callback.h>
#include <grpcpp/impl/codegen/service_type.h>
#include <grpcpp/impl/codegen/sync_stream.h>
namespace master {

static const char* Greeter_method_names[] = {
  "/master.Greeter/ReportAddress",
  "/master.Greeter/GetAddress",
};

std::unique_ptr< Greeter::Stub> Greeter::NewStub(const std::shared_ptr< ::grpc::ChannelInterface>& channel, const ::grpc::StubOptions& options) {
  (void)options;
  std::unique_ptr< Greeter::Stub> stub(new Greeter::Stub(channel));
  return stub;
}

Greeter::Stub::Stub(const std::shared_ptr< ::grpc::ChannelInterface>& channel)
  : channel_(channel), rpcmethod_ReportAddress_(Greeter_method_names[0], ::grpc::internal::RpcMethod::NORMAL_RPC, channel)
  , rpcmethod_GetAddress_(Greeter_method_names[1], ::grpc::internal::RpcMethod::NORMAL_RPC, channel)
  {}

::grpc::Status Greeter::Stub::ReportAddress(::grpc::ClientContext* context, const ::master::Request& request, ::master::Reply* response) {
  return ::grpc::internal::BlockingUnaryCall(channel_.get(), rpcmethod_ReportAddress_, context, request, response);
}

void Greeter::Stub::experimental_async::ReportAddress(::grpc::ClientContext* context, const ::master::Request* request, ::master::Reply* response, std::function<void(::grpc::Status)> f) {
  ::grpc_impl::internal::CallbackUnaryCall(stub_->channel_.get(), stub_->rpcmethod_ReportAddress_, context, request, response, std::move(f));
}

void Greeter::Stub::experimental_async::ReportAddress(::grpc::ClientContext* context, const ::grpc::ByteBuffer* request, ::master::Reply* response, std::function<void(::grpc::Status)> f) {
  ::grpc_impl::internal::CallbackUnaryCall(stub_->channel_.get(), stub_->rpcmethod_ReportAddress_, context, request, response, std::move(f));
}

void Greeter::Stub::experimental_async::ReportAddress(::grpc::ClientContext* context, const ::master::Request* request, ::master::Reply* response, ::grpc::experimental::ClientUnaryReactor* reactor) {
  ::grpc_impl::internal::ClientCallbackUnaryFactory::Create(stub_->channel_.get(), stub_->rpcmethod_ReportAddress_, context, request, response, reactor);
}

void Greeter::Stub::experimental_async::ReportAddress(::grpc::ClientContext* context, const ::grpc::ByteBuffer* request, ::master::Reply* response, ::grpc::experimental::ClientUnaryReactor* reactor) {
  ::grpc_impl::internal::ClientCallbackUnaryFactory::Create(stub_->channel_.get(), stub_->rpcmethod_ReportAddress_, context, request, response, reactor);
}

::grpc::ClientAsyncResponseReader< ::master::Reply>* Greeter::Stub::AsyncReportAddressRaw(::grpc::ClientContext* context, const ::master::Request& request, ::grpc::CompletionQueue* cq) {
  return ::grpc_impl::internal::ClientAsyncResponseReaderFactory< ::master::Reply>::Create(channel_.get(), cq, rpcmethod_ReportAddress_, context, request, true);
}

::grpc::ClientAsyncResponseReader< ::master::Reply>* Greeter::Stub::PrepareAsyncReportAddressRaw(::grpc::ClientContext* context, const ::master::Request& request, ::grpc::CompletionQueue* cq) {
  return ::grpc_impl::internal::ClientAsyncResponseReaderFactory< ::master::Reply>::Create(channel_.get(), cq, rpcmethod_ReportAddress_, context, request, false);
}

::grpc::Status Greeter::Stub::GetAddress(::grpc::ClientContext* context, const ::master::EmptyRequest& request, ::master::Request* response) {
  return ::grpc::internal::BlockingUnaryCall(channel_.get(), rpcmethod_GetAddress_, context, request, response);
}

void Greeter::Stub::experimental_async::GetAddress(::grpc::ClientContext* context, const ::master::EmptyRequest* request, ::master::Request* response, std::function<void(::grpc::Status)> f) {
  ::grpc_impl::internal::CallbackUnaryCall(stub_->channel_.get(), stub_->rpcmethod_GetAddress_, context, request, response, std::move(f));
}

void Greeter::Stub::experimental_async::GetAddress(::grpc::ClientContext* context, const ::grpc::ByteBuffer* request, ::master::Request* response, std::function<void(::grpc::Status)> f) {
  ::grpc_impl::internal::CallbackUnaryCall(stub_->channel_.get(), stub_->rpcmethod_GetAddress_, context, request, response, std::move(f));
}

void Greeter::Stub::experimental_async::GetAddress(::grpc::ClientContext* context, const ::master::EmptyRequest* request, ::master::Request* response, ::grpc::experimental::ClientUnaryReactor* reactor) {
  ::grpc_impl::internal::ClientCallbackUnaryFactory::Create(stub_->channel_.get(), stub_->rpcmethod_GetAddress_, context, request, response, reactor);
}

void Greeter::Stub::experimental_async::GetAddress(::grpc::ClientContext* context, const ::grpc::ByteBuffer* request, ::master::Request* response, ::grpc::experimental::ClientUnaryReactor* reactor) {
  ::grpc_impl::internal::ClientCallbackUnaryFactory::Create(stub_->channel_.get(), stub_->rpcmethod_GetAddress_, context, request, response, reactor);
}

::grpc::ClientAsyncResponseReader< ::master::Request>* Greeter::Stub::AsyncGetAddressRaw(::grpc::ClientContext* context, const ::master::EmptyRequest& request, ::grpc::CompletionQueue* cq) {
  return ::grpc_impl::internal::ClientAsyncResponseReaderFactory< ::master::Request>::Create(channel_.get(), cq, rpcmethod_GetAddress_, context, request, true);
}

::grpc::ClientAsyncResponseReader< ::master::Request>* Greeter::Stub::PrepareAsyncGetAddressRaw(::grpc::ClientContext* context, const ::master::EmptyRequest& request, ::grpc::CompletionQueue* cq) {
  return ::grpc_impl::internal::ClientAsyncResponseReaderFactory< ::master::Request>::Create(channel_.get(), cq, rpcmethod_GetAddress_, context, request, false);
}

Greeter::Service::Service() {
  AddMethod(new ::grpc::internal::RpcServiceMethod(
      Greeter_method_names[0],
      ::grpc::internal::RpcMethod::NORMAL_RPC,
      new ::grpc::internal::RpcMethodHandler< Greeter::Service, ::master::Request, ::master::Reply>(
          std::mem_fn(&Greeter::Service::ReportAddress), this)));
  AddMethod(new ::grpc::internal::RpcServiceMethod(
      Greeter_method_names[1],
      ::grpc::internal::RpcMethod::NORMAL_RPC,
      new ::grpc::internal::RpcMethodHandler< Greeter::Service, ::master::EmptyRequest, ::master::Request>(
          std::mem_fn(&Greeter::Service::GetAddress), this)));
}

Greeter::Service::~Service() {
}

::grpc::Status Greeter::Service::ReportAddress(::grpc::ServerContext* context, const ::master::Request* request, ::master::Reply* response) {
  (void) context;
  (void) request;
  (void) response;
  return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
}

::grpc::Status Greeter::Service::GetAddress(::grpc::ServerContext* context, const ::master::EmptyRequest* request, ::master::Request* response) {
  (void) context;
  (void) request;
  (void) response;
  return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
}


}  // namespace master

