// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: google/type/dayofweek.proto

#define INTERNAL_SUPPRESS_PROTOBUF_FIELD_DEPRECATION
#include "google/type/dayofweek.pb.h"

#include <algorithm>

#include <google/protobuf/stubs/common.h>
#include <google/protobuf/stubs/port.h>
#include <google/protobuf/stubs/once.h>
#include <google/protobuf/io/coded_stream.h>
#include <google/protobuf/wire_format_lite_inl.h>
#include <google/protobuf/descriptor.h>
#include <google/protobuf/generated_message_reflection.h>
#include <google/protobuf/reflection_ops.h>
#include <google/protobuf/wire_format.h>
// @@protoc_insertion_point(includes)

namespace google {
namespace type {

namespace {

const ::google::protobuf::EnumDescriptor* DayOfWeek_descriptor_ = NULL;

}  // namespace


void protobuf_AssignDesc_google_2ftype_2fdayofweek_2eproto() GOOGLE_ATTRIBUTE_COLD;
void protobuf_AssignDesc_google_2ftype_2fdayofweek_2eproto() {
  protobuf_AddDesc_google_2ftype_2fdayofweek_2eproto();
  const ::google::protobuf::FileDescriptor* file =
    ::google::protobuf::DescriptorPool::generated_pool()->FindFileByName(
      "google/type/dayofweek.proto");
  GOOGLE_CHECK(file != NULL);
  DayOfWeek_descriptor_ = file->enum_type(0);
}

namespace {

GOOGLE_PROTOBUF_DECLARE_ONCE(protobuf_AssignDescriptors_once_);
void protobuf_AssignDescriptorsOnce() {
  ::google::protobuf::GoogleOnceInit(&protobuf_AssignDescriptors_once_,
                 &protobuf_AssignDesc_google_2ftype_2fdayofweek_2eproto);
}

void protobuf_RegisterTypes(const ::std::string&) GOOGLE_ATTRIBUTE_COLD;
void protobuf_RegisterTypes(const ::std::string&) {
  protobuf_AssignDescriptorsOnce();
}

}  // namespace

void protobuf_ShutdownFile_google_2ftype_2fdayofweek_2eproto() {
}

void protobuf_InitDefaults_google_2ftype_2fdayofweek_2eproto_impl() {
  GOOGLE_PROTOBUF_VERIFY_VERSION;

}

GOOGLE_PROTOBUF_DECLARE_ONCE(protobuf_InitDefaults_google_2ftype_2fdayofweek_2eproto_once_);
void protobuf_InitDefaults_google_2ftype_2fdayofweek_2eproto() {
  ::google::protobuf::GoogleOnceInit(&protobuf_InitDefaults_google_2ftype_2fdayofweek_2eproto_once_,
                 &protobuf_InitDefaults_google_2ftype_2fdayofweek_2eproto_impl);
}
void protobuf_AddDesc_google_2ftype_2fdayofweek_2eproto_impl() {
  GOOGLE_PROTOBUF_VERIFY_VERSION;

  protobuf_InitDefaults_google_2ftype_2fdayofweek_2eproto();
  ::google::protobuf::DescriptorPool::InternalAddGeneratedFile(
    "\n\033google/type/dayofweek.proto\022\013google.ty"
    "pe*\204\001\n\tDayOfWeek\022\033\n\027DAY_OF_WEEK_UNSPECIF"
    "IED\020\000\022\n\n\006MONDAY\020\001\022\013\n\007TUESDAY\020\002\022\r\n\tWEDNES"
    "DAY\020\003\022\014\n\010THURSDAY\020\004\022\n\n\006FRIDAY\020\005\022\014\n\010SATUR"
    "DAY\020\006\022\n\n\006SUNDAY\020\007Bi\n\017com.google.typeB\016Da"
    "yOfWeekProtoP\001Z>google.golang.org/genpro"
    "to/googleapis/type/dayofweek;dayofweek\242\002"
    "\003GTPb\006proto3", 292);
  ::google::protobuf::MessageFactory::InternalRegisterGeneratedFile(
    "google/type/dayofweek.proto", &protobuf_RegisterTypes);
  ::google::protobuf::internal::OnShutdown(&protobuf_ShutdownFile_google_2ftype_2fdayofweek_2eproto);
}

GOOGLE_PROTOBUF_DECLARE_ONCE(protobuf_AddDesc_google_2ftype_2fdayofweek_2eproto_once_);
void protobuf_AddDesc_google_2ftype_2fdayofweek_2eproto() {
  ::google::protobuf::GoogleOnceInit(&protobuf_AddDesc_google_2ftype_2fdayofweek_2eproto_once_,
                 &protobuf_AddDesc_google_2ftype_2fdayofweek_2eproto_impl);
}
// Force AddDescriptors() to be called at static initialization time.
struct StaticDescriptorInitializer_google_2ftype_2fdayofweek_2eproto {
  StaticDescriptorInitializer_google_2ftype_2fdayofweek_2eproto() {
    protobuf_AddDesc_google_2ftype_2fdayofweek_2eproto();
  }
} static_descriptor_initializer_google_2ftype_2fdayofweek_2eproto_;
const ::google::protobuf::EnumDescriptor* DayOfWeek_descriptor() {
  protobuf_AssignDescriptorsOnce();
  return DayOfWeek_descriptor_;
}
bool DayOfWeek_IsValid(int value) {
  switch (value) {
    case 0:
    case 1:
    case 2:
    case 3:
    case 4:
    case 5:
    case 6:
    case 7:
      return true;
    default:
      return false;
  }
}


// @@protoc_insertion_point(namespace_scope)

}  // namespace type
}  // namespace google

// @@protoc_insertion_point(global_scope)
