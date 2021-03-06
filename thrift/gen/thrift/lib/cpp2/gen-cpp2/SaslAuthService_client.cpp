/**
 * Autogenerated by Thrift
 *
 * DO NOT EDIT UNLESS YOU ARE SURE THAT YOU KNOW WHAT YOU ARE DOING
 *  @generated
 */
#include "thrift/lib/cpp2/gen-cpp2/SaslAuthService.h"

#include "thrift/lib/cpp2/gen-cpp2/SaslAuthService.tcc"

#include <thrift/lib/cpp2/protocol/BinaryProtocol.h>
#include <thrift/lib/cpp2/protocol/CompactProtocol.h>
namespace apache { namespace thrift { namespace sasl {

const char* SaslAuthServiceAsyncClient::getServiceName() {
  return "SaslAuthService";
}

void SaslAuthServiceAsyncClient::authFirstRequest(std::unique_ptr<apache::thrift::RequestCallback> callback, const  ::apache::thrift::sasl::SaslStart& saslStart) {
  ::apache::thrift::RpcOptions rpcOptions;
  authFirstRequest(rpcOptions, std::move(callback), saslStart);
}

void SaslAuthServiceAsyncClient::authFirstRequest(apache::thrift::RpcOptions& rpcOptions, std::unique_ptr<apache::thrift::RequestCallback> callback, const  ::apache::thrift::sasl::SaslStart& saslStart) {
  switch(getChannel()->getProtocolId()) {
    case apache::thrift::protocol::T_BINARY_PROTOCOL:
    {
      apache::thrift::BinaryProtocolWriter writer;
      authFirstRequestT(&writer, rpcOptions, std::move(callback), saslStart);
      break;
    }
    case apache::thrift::protocol::T_COMPACT_PROTOCOL:
    {
      apache::thrift::CompactProtocolWriter writer;
      authFirstRequestT(&writer, rpcOptions, std::move(callback), saslStart);
      break;
    }
    default:
    {
      throw apache::thrift::TApplicationException("Could not find Protocol");
    }
  }
}

void SaslAuthServiceAsyncClient::sync_authFirstRequest( ::apache::thrift::sasl::SaslReply& _return, const  ::apache::thrift::sasl::SaslStart& saslStart) {
  ::apache::thrift::RpcOptions rpcOptions;
  sync_authFirstRequest(rpcOptions, _return, saslStart);
}

void SaslAuthServiceAsyncClient::sync_authFirstRequest(apache::thrift::RpcOptions& rpcOptions,  ::apache::thrift::sasl::SaslReply& _return, const  ::apache::thrift::sasl::SaslStart& saslStart) {
  apache::thrift::ClientReceiveState _returnState;
  auto callback8 = folly::make_unique<apache::thrift::ClientSyncCallback>(&_returnState, getChannel()->getEventBase(), false);
  authFirstRequest(rpcOptions, std::move(callback8), saslStart);
  getChannel()->getEventBase()->loopForever();
  SCOPE_EXIT {
    if (_returnState.header() && !_returnState.header()->getHeaders().empty()) {
      rpcOptions.setReadHeaders(_returnState.header()->releaseHeaders());
    }
  };
  if (!_returnState.buf()) {
    assert(_returnState.exception());
    std::rethrow_exception(_returnState.exception());
  }
  recv_authFirstRequest(_return, _returnState);
}

folly::Future< ::apache::thrift::sasl::SaslReply> SaslAuthServiceAsyncClient::future_authFirstRequest(const  ::apache::thrift::sasl::SaslStart& saslStart) {
  ::apache::thrift::RpcOptions rpcOptions;
  return future_authFirstRequest(rpcOptions, saslStart);
}

folly::Future< ::apache::thrift::sasl::SaslReply> SaslAuthServiceAsyncClient::future_authFirstRequest(apache::thrift::RpcOptions& rpcOptions, const  ::apache::thrift::sasl::SaslStart& saslStart) {
  folly::Promise< ::apache::thrift::sasl::SaslReply> promise9;
  auto future10 = promise9.getFuture();
  auto callback11 = folly::make_unique<apache::thrift::FutureCallback< ::apache::thrift::sasl::SaslReply>>(std::move(promise9), recv_wrapped_authFirstRequest, channel_);
  authFirstRequest(rpcOptions, std::move(callback11), saslStart);
  return future10;
}

folly::Future<std::pair< ::apache::thrift::sasl::SaslReply, std::unique_ptr<apache::thrift::transport::THeader>>> SaslAuthServiceAsyncClient::header_future_authFirstRequest(apache::thrift::RpcOptions& rpcOptions, const  ::apache::thrift::sasl::SaslStart& saslStart) {
  folly::Promise<std::pair< ::apache::thrift::sasl::SaslReply, std::unique_ptr<apache::thrift::transport::THeader>>> promise12;
  auto future13 = promise12.getFuture();
  auto callback14 = folly::make_unique<apache::thrift::HeaderFutureCallback< ::apache::thrift::sasl::SaslReply>>(std::move(promise12), recv_wrapped_authFirstRequest, channel_);
  authFirstRequest(rpcOptions, std::move(callback14), saslStart);
  return future13;
}

void SaslAuthServiceAsyncClient::authFirstRequest(std::function<void (::apache::thrift::ClientReceiveState&&)> callback, const  ::apache::thrift::sasl::SaslStart& saslStart) {
  authFirstRequest(folly::make_unique<apache::thrift::FunctionReplyCallback>(std::move(callback)),saslStart);
}

folly::exception_wrapper SaslAuthServiceAsyncClient::recv_wrapped_authFirstRequest( ::apache::thrift::sasl::SaslReply& _return, ::apache::thrift::ClientReceiveState& state) {
  auto ew = state.exceptionWrapper();
  if (ew) {
    return ew;
  }
  if (!state.buf()) {
    return folly::make_exception_wrapper<apache::thrift::TApplicationException>("recv_ called without result");
  }
  switch(state.protocolId()) {
    case apache::thrift::protocol::T_BINARY_PROTOCOL:
    {
      apache::thrift::BinaryProtocolReader reader;
      return recv_wrapped_authFirstRequestT(&reader, _return, state);
    }
    case apache::thrift::protocol::T_COMPACT_PROTOCOL:
    {
      apache::thrift::CompactProtocolReader reader;
      return recv_wrapped_authFirstRequestT(&reader, _return, state);
    }
    default:
    {
    }
  }
  return folly::make_exception_wrapper<apache::thrift::TApplicationException>("Could not find Protocol");
}

void SaslAuthServiceAsyncClient::recv_authFirstRequest( ::apache::thrift::sasl::SaslReply& _return, ::apache::thrift::ClientReceiveState& state) {
  auto ew = recv_wrapped_authFirstRequest(_return, state);
  if (ew) {
    ew.throwException();
  }
}

void SaslAuthServiceAsyncClient::recv_instance_authFirstRequest( ::apache::thrift::sasl::SaslReply& _return, ::apache::thrift::ClientReceiveState& state) {
  return recv_authFirstRequest(_return, state);
}

folly::exception_wrapper SaslAuthServiceAsyncClient::recv_instance_wrapped_authFirstRequest( ::apache::thrift::sasl::SaslReply& _return, ::apache::thrift::ClientReceiveState& state) {
  return recv_wrapped_authFirstRequest(_return, state);
}

void SaslAuthServiceAsyncClient::authNextRequest(std::unique_ptr<apache::thrift::RequestCallback> callback, const  ::apache::thrift::sasl::SaslRequest& saslRequest) {
  ::apache::thrift::RpcOptions rpcOptions;
  authNextRequest(rpcOptions, std::move(callback), saslRequest);
}

void SaslAuthServiceAsyncClient::authNextRequest(apache::thrift::RpcOptions& rpcOptions, std::unique_ptr<apache::thrift::RequestCallback> callback, const  ::apache::thrift::sasl::SaslRequest& saslRequest) {
  switch(getChannel()->getProtocolId()) {
    case apache::thrift::protocol::T_BINARY_PROTOCOL:
    {
      apache::thrift::BinaryProtocolWriter writer;
      authNextRequestT(&writer, rpcOptions, std::move(callback), saslRequest);
      break;
    }
    case apache::thrift::protocol::T_COMPACT_PROTOCOL:
    {
      apache::thrift::CompactProtocolWriter writer;
      authNextRequestT(&writer, rpcOptions, std::move(callback), saslRequest);
      break;
    }
    default:
    {
      throw apache::thrift::TApplicationException("Could not find Protocol");
    }
  }
}

void SaslAuthServiceAsyncClient::sync_authNextRequest( ::apache::thrift::sasl::SaslReply& _return, const  ::apache::thrift::sasl::SaslRequest& saslRequest) {
  ::apache::thrift::RpcOptions rpcOptions;
  sync_authNextRequest(rpcOptions, _return, saslRequest);
}

void SaslAuthServiceAsyncClient::sync_authNextRequest(apache::thrift::RpcOptions& rpcOptions,  ::apache::thrift::sasl::SaslReply& _return, const  ::apache::thrift::sasl::SaslRequest& saslRequest) {
  apache::thrift::ClientReceiveState _returnState;
  auto callback15 = folly::make_unique<apache::thrift::ClientSyncCallback>(&_returnState, getChannel()->getEventBase(), false);
  authNextRequest(rpcOptions, std::move(callback15), saslRequest);
  getChannel()->getEventBase()->loopForever();
  SCOPE_EXIT {
    if (_returnState.header() && !_returnState.header()->getHeaders().empty()) {
      rpcOptions.setReadHeaders(_returnState.header()->releaseHeaders());
    }
  };
  if (!_returnState.buf()) {
    assert(_returnState.exception());
    std::rethrow_exception(_returnState.exception());
  }
  recv_authNextRequest(_return, _returnState);
}

folly::Future< ::apache::thrift::sasl::SaslReply> SaslAuthServiceAsyncClient::future_authNextRequest(const  ::apache::thrift::sasl::SaslRequest& saslRequest) {
  ::apache::thrift::RpcOptions rpcOptions;
  return future_authNextRequest(rpcOptions, saslRequest);
}

folly::Future< ::apache::thrift::sasl::SaslReply> SaslAuthServiceAsyncClient::future_authNextRequest(apache::thrift::RpcOptions& rpcOptions, const  ::apache::thrift::sasl::SaslRequest& saslRequest) {
  folly::Promise< ::apache::thrift::sasl::SaslReply> promise16;
  auto future17 = promise16.getFuture();
  auto callback18 = folly::make_unique<apache::thrift::FutureCallback< ::apache::thrift::sasl::SaslReply>>(std::move(promise16), recv_wrapped_authNextRequest, channel_);
  authNextRequest(rpcOptions, std::move(callback18), saslRequest);
  return future17;
}

folly::Future<std::pair< ::apache::thrift::sasl::SaslReply, std::unique_ptr<apache::thrift::transport::THeader>>> SaslAuthServiceAsyncClient::header_future_authNextRequest(apache::thrift::RpcOptions& rpcOptions, const  ::apache::thrift::sasl::SaslRequest& saslRequest) {
  folly::Promise<std::pair< ::apache::thrift::sasl::SaslReply, std::unique_ptr<apache::thrift::transport::THeader>>> promise19;
  auto future20 = promise19.getFuture();
  auto callback21 = folly::make_unique<apache::thrift::HeaderFutureCallback< ::apache::thrift::sasl::SaslReply>>(std::move(promise19), recv_wrapped_authNextRequest, channel_);
  authNextRequest(rpcOptions, std::move(callback21), saslRequest);
  return future20;
}

void SaslAuthServiceAsyncClient::authNextRequest(std::function<void (::apache::thrift::ClientReceiveState&&)> callback, const  ::apache::thrift::sasl::SaslRequest& saslRequest) {
  authNextRequest(folly::make_unique<apache::thrift::FunctionReplyCallback>(std::move(callback)),saslRequest);
}

folly::exception_wrapper SaslAuthServiceAsyncClient::recv_wrapped_authNextRequest( ::apache::thrift::sasl::SaslReply& _return, ::apache::thrift::ClientReceiveState& state) {
  auto ew = state.exceptionWrapper();
  if (ew) {
    return ew;
  }
  if (!state.buf()) {
    return folly::make_exception_wrapper<apache::thrift::TApplicationException>("recv_ called without result");
  }
  switch(state.protocolId()) {
    case apache::thrift::protocol::T_BINARY_PROTOCOL:
    {
      apache::thrift::BinaryProtocolReader reader;
      return recv_wrapped_authNextRequestT(&reader, _return, state);
    }
    case apache::thrift::protocol::T_COMPACT_PROTOCOL:
    {
      apache::thrift::CompactProtocolReader reader;
      return recv_wrapped_authNextRequestT(&reader, _return, state);
    }
    default:
    {
    }
  }
  return folly::make_exception_wrapper<apache::thrift::TApplicationException>("Could not find Protocol");
}

void SaslAuthServiceAsyncClient::recv_authNextRequest( ::apache::thrift::sasl::SaslReply& _return, ::apache::thrift::ClientReceiveState& state) {
  auto ew = recv_wrapped_authNextRequest(_return, state);
  if (ew) {
    ew.throwException();
  }
}

void SaslAuthServiceAsyncClient::recv_instance_authNextRequest( ::apache::thrift::sasl::SaslReply& _return, ::apache::thrift::ClientReceiveState& state) {
  return recv_authNextRequest(_return, state);
}

folly::exception_wrapper SaslAuthServiceAsyncClient::recv_instance_wrapped_authNextRequest( ::apache::thrift::sasl::SaslReply& _return, ::apache::thrift::ClientReceiveState& state) {
  return recv_wrapped_authNextRequest(_return, state);
}

}}} // apache::thrift::sasl
namespace apache { namespace thrift {

}} // apache::thrift