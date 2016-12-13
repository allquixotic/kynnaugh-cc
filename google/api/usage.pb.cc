// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: google/api/usage.proto

#define INTERNAL_SUPPRESS_PROTOBUF_FIELD_DEPRECATION
#include "google/api/usage.pb.h"

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
namespace api {

namespace {

const ::google::protobuf::Descriptor* Usage_descriptor_ = NULL;
const ::google::protobuf::internal::GeneratedMessageReflection*
  Usage_reflection_ = NULL;
const ::google::protobuf::Descriptor* UsageRule_descriptor_ = NULL;
const ::google::protobuf::internal::GeneratedMessageReflection*
  UsageRule_reflection_ = NULL;

}  // namespace


void protobuf_AssignDesc_google_2fapi_2fusage_2eproto() GOOGLE_ATTRIBUTE_COLD;
void protobuf_AssignDesc_google_2fapi_2fusage_2eproto() {
  protobuf_AddDesc_google_2fapi_2fusage_2eproto();
  const ::google::protobuf::FileDescriptor* file =
    ::google::protobuf::DescriptorPool::generated_pool()->FindFileByName(
      "google/api/usage.proto");
  GOOGLE_CHECK(file != NULL);
  Usage_descriptor_ = file->message_type(0);
  static const int Usage_offsets_[2] = {
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(Usage, requirements_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(Usage, rules_),
  };
  Usage_reflection_ =
    ::google::protobuf::internal::GeneratedMessageReflection::NewGeneratedMessageReflection(
      Usage_descriptor_,
      Usage::default_instance_,
      Usage_offsets_,
      -1,
      -1,
      -1,
      sizeof(Usage),
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(Usage, _internal_metadata_),
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(Usage, _is_default_instance_));
  UsageRule_descriptor_ = file->message_type(1);
  static const int UsageRule_offsets_[2] = {
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(UsageRule, selector_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(UsageRule, allow_unregistered_calls_),
  };
  UsageRule_reflection_ =
    ::google::protobuf::internal::GeneratedMessageReflection::NewGeneratedMessageReflection(
      UsageRule_descriptor_,
      UsageRule::default_instance_,
      UsageRule_offsets_,
      -1,
      -1,
      -1,
      sizeof(UsageRule),
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(UsageRule, _internal_metadata_),
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(UsageRule, _is_default_instance_));
}

namespace {

GOOGLE_PROTOBUF_DECLARE_ONCE(protobuf_AssignDescriptors_once_);
inline void protobuf_AssignDescriptorsOnce() {
  ::google::protobuf::GoogleOnceInit(&protobuf_AssignDescriptors_once_,
                 &protobuf_AssignDesc_google_2fapi_2fusage_2eproto);
}

void protobuf_RegisterTypes(const ::std::string&) GOOGLE_ATTRIBUTE_COLD;
void protobuf_RegisterTypes(const ::std::string&) {
  protobuf_AssignDescriptorsOnce();
  ::google::protobuf::MessageFactory::InternalRegisterGeneratedMessage(
      Usage_descriptor_, &Usage::default_instance());
  ::google::protobuf::MessageFactory::InternalRegisterGeneratedMessage(
      UsageRule_descriptor_, &UsageRule::default_instance());
}

}  // namespace

void protobuf_ShutdownFile_google_2fapi_2fusage_2eproto() {
  delete Usage::default_instance_;
  delete Usage_reflection_;
  delete UsageRule::default_instance_;
  delete UsageRule_reflection_;
}

void protobuf_AddDesc_google_2fapi_2fusage_2eproto() GOOGLE_ATTRIBUTE_COLD;
void protobuf_AddDesc_google_2fapi_2fusage_2eproto() {
  static bool already_here = false;
  if (already_here) return;
  already_here = true;
  GOOGLE_PROTOBUF_VERIFY_VERSION;

  ::google::api::protobuf_AddDesc_google_2fapi_2fannotations_2eproto();
  ::google::protobuf::DescriptorPool::InternalAddGeneratedFile(
    "\n\026google/api/usage.proto\022\ngoogle.api\032\034go"
    "ogle/api/annotations.proto\"C\n\005Usage\022\024\n\014r"
    "equirements\030\001 \003(\t\022$\n\005rules\030\006 \003(\0132\025.googl"
    "e.api.UsageRule\"\?\n\tUsageRule\022\020\n\010selector"
    "\030\001 \001(\t\022 \n\030allow_unregistered_calls\030\002 \001(\010"
    "B%\n\016com.google.apiB\nUsageProtoP\001\242\002\004GAPIb"
    "\006proto3", 247);
  ::google::protobuf::MessageFactory::InternalRegisterGeneratedFile(
    "google/api/usage.proto", &protobuf_RegisterTypes);
  Usage::default_instance_ = new Usage();
  UsageRule::default_instance_ = new UsageRule();
  Usage::default_instance_->InitAsDefaultInstance();
  UsageRule::default_instance_->InitAsDefaultInstance();
  ::google::protobuf::internal::OnShutdown(&protobuf_ShutdownFile_google_2fapi_2fusage_2eproto);
}

// Force AddDescriptors() to be called at static initialization time.
struct StaticDescriptorInitializer_google_2fapi_2fusage_2eproto {
  StaticDescriptorInitializer_google_2fapi_2fusage_2eproto() {
    protobuf_AddDesc_google_2fapi_2fusage_2eproto();
  }
} static_descriptor_initializer_google_2fapi_2fusage_2eproto_;

// ===================================================================

#if !defined(_MSC_VER) || _MSC_VER >= 1900
const int Usage::kRequirementsFieldNumber;
const int Usage::kRulesFieldNumber;
#endif  // !defined(_MSC_VER) || _MSC_VER >= 1900

Usage::Usage()
  : ::google::protobuf::Message(), _internal_metadata_(NULL) {
  SharedCtor();
  // @@protoc_insertion_point(constructor:google.api.Usage)
}

void Usage::InitAsDefaultInstance() {
  _is_default_instance_ = true;
}

Usage::Usage(const Usage& from)
  : ::google::protobuf::Message(),
    _internal_metadata_(NULL) {
  SharedCtor();
  MergeFrom(from);
  // @@protoc_insertion_point(copy_constructor:google.api.Usage)
}

void Usage::SharedCtor() {
    _is_default_instance_ = false;
  ::google::protobuf::internal::GetEmptyString();
  _cached_size_ = 0;
}

Usage::~Usage() {
  // @@protoc_insertion_point(destructor:google.api.Usage)
  SharedDtor();
}

void Usage::SharedDtor() {
  if (this != default_instance_) {
  }
}

void Usage::SetCachedSize(int size) const {
  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
}
const ::google::protobuf::Descriptor* Usage::descriptor() {
  protobuf_AssignDescriptorsOnce();
  return Usage_descriptor_;
}

const Usage& Usage::default_instance() {
  if (default_instance_ == NULL) protobuf_AddDesc_google_2fapi_2fusage_2eproto();
  return *default_instance_;
}

Usage* Usage::default_instance_ = NULL;

Usage* Usage::New(::google::protobuf::Arena* arena) const {
  Usage* n = new Usage;
  if (arena != NULL) {
    arena->Own(n);
  }
  return n;
}

void Usage::Clear() {
// @@protoc_insertion_point(message_clear_start:google.api.Usage)
  requirements_.Clear();
  rules_.Clear();
}

bool Usage::MergePartialFromCodedStream(
    ::google::protobuf::io::CodedInputStream* input) {
#define DO_(EXPRESSION) if (!GOOGLE_PREDICT_TRUE(EXPRESSION)) goto failure
  ::google::protobuf::uint32 tag;
  // @@protoc_insertion_point(parse_start:google.api.Usage)
  for (;;) {
    ::std::pair< ::google::protobuf::uint32, bool> p = input->ReadTagWithCutoff(127);
    tag = p.first;
    if (!p.second) goto handle_unusual;
    switch (::google::protobuf::internal::WireFormatLite::GetTagFieldNumber(tag)) {
      // repeated string requirements = 1;
      case 1: {
        if (tag == 10) {
         parse_requirements:
          DO_(::google::protobuf::internal::WireFormatLite::ReadString(
                input, this->add_requirements()));
          DO_(::google::protobuf::internal::WireFormatLite::VerifyUtf8String(
            this->requirements(this->requirements_size() - 1).data(),
            this->requirements(this->requirements_size() - 1).length(),
            ::google::protobuf::internal::WireFormatLite::PARSE,
            "google.api.Usage.requirements"));
        } else {
          goto handle_unusual;
        }
        if (input->ExpectTag(10)) goto parse_requirements;
        if (input->ExpectTag(50)) goto parse_rules;
        break;
      }

      // repeated .google.api.UsageRule rules = 6;
      case 6: {
        if (tag == 50) {
         parse_rules:
          DO_(input->IncrementRecursionDepth());
         parse_loop_rules:
          DO_(::google::protobuf::internal::WireFormatLite::ReadMessageNoVirtualNoRecursionDepth(
                input, add_rules()));
        } else {
          goto handle_unusual;
        }
        if (input->ExpectTag(50)) goto parse_loop_rules;
        input->UnsafeDecrementRecursionDepth();
        if (input->ExpectAtEnd()) goto success;
        break;
      }

      default: {
      handle_unusual:
        if (tag == 0 ||
            ::google::protobuf::internal::WireFormatLite::GetTagWireType(tag) ==
            ::google::protobuf::internal::WireFormatLite::WIRETYPE_END_GROUP) {
          goto success;
        }
        DO_(::google::protobuf::internal::WireFormatLite::SkipField(input, tag));
        break;
      }
    }
  }
success:
  // @@protoc_insertion_point(parse_success:google.api.Usage)
  return true;
failure:
  // @@protoc_insertion_point(parse_failure:google.api.Usage)
  return false;
#undef DO_
}

void Usage::SerializeWithCachedSizes(
    ::google::protobuf::io::CodedOutputStream* output) const {
  // @@protoc_insertion_point(serialize_start:google.api.Usage)
  // repeated string requirements = 1;
  for (int i = 0; i < this->requirements_size(); i++) {
    ::google::protobuf::internal::WireFormatLite::VerifyUtf8String(
      this->requirements(i).data(), this->requirements(i).length(),
      ::google::protobuf::internal::WireFormatLite::SERIALIZE,
      "google.api.Usage.requirements");
    ::google::protobuf::internal::WireFormatLite::WriteString(
      1, this->requirements(i), output);
  }

  // repeated .google.api.UsageRule rules = 6;
  for (unsigned int i = 0, n = this->rules_size(); i < n; i++) {
    ::google::protobuf::internal::WireFormatLite::WriteMessageMaybeToArray(
      6, this->rules(i), output);
  }

  // @@protoc_insertion_point(serialize_end:google.api.Usage)
}

::google::protobuf::uint8* Usage::InternalSerializeWithCachedSizesToArray(
    bool deterministic, ::google::protobuf::uint8* target) const {
  // @@protoc_insertion_point(serialize_to_array_start:google.api.Usage)
  // repeated string requirements = 1;
  for (int i = 0; i < this->requirements_size(); i++) {
    ::google::protobuf::internal::WireFormatLite::VerifyUtf8String(
      this->requirements(i).data(), this->requirements(i).length(),
      ::google::protobuf::internal::WireFormatLite::SERIALIZE,
      "google.api.Usage.requirements");
    target = ::google::protobuf::internal::WireFormatLite::
      WriteStringToArray(1, this->requirements(i), target);
  }

  // repeated .google.api.UsageRule rules = 6;
  for (unsigned int i = 0, n = this->rules_size(); i < n; i++) {
    target = ::google::protobuf::internal::WireFormatLite::
      InternalWriteMessageNoVirtualToArray(
        6, this->rules(i), false, target);
  }

  // @@protoc_insertion_point(serialize_to_array_end:google.api.Usage)
  return target;
}

int Usage::ByteSize() const {
// @@protoc_insertion_point(message_byte_size_start:google.api.Usage)
  int total_size = 0;

  // repeated string requirements = 1;
  total_size += 1 * this->requirements_size();
  for (int i = 0; i < this->requirements_size(); i++) {
    total_size += ::google::protobuf::internal::WireFormatLite::StringSize(
      this->requirements(i));
  }

  // repeated .google.api.UsageRule rules = 6;
  total_size += 1 * this->rules_size();
  for (int i = 0; i < this->rules_size(); i++) {
    total_size +=
      ::google::protobuf::internal::WireFormatLite::MessageSizeNoVirtual(
        this->rules(i));
  }

  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = total_size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
  return total_size;
}

void Usage::MergeFrom(const ::google::protobuf::Message& from) {
// @@protoc_insertion_point(generalized_merge_from_start:google.api.Usage)
  if (GOOGLE_PREDICT_FALSE(&from == this)) {
    ::google::protobuf::internal::MergeFromFail(__FILE__, __LINE__);
  }
  const Usage* source = 
      ::google::protobuf::internal::DynamicCastToGenerated<const Usage>(
          &from);
  if (source == NULL) {
  // @@protoc_insertion_point(generalized_merge_from_cast_fail:google.api.Usage)
    ::google::protobuf::internal::ReflectionOps::Merge(from, this);
  } else {
  // @@protoc_insertion_point(generalized_merge_from_cast_success:google.api.Usage)
    MergeFrom(*source);
  }
}

void Usage::MergeFrom(const Usage& from) {
// @@protoc_insertion_point(class_specific_merge_from_start:google.api.Usage)
  if (GOOGLE_PREDICT_FALSE(&from == this)) {
    ::google::protobuf::internal::MergeFromFail(__FILE__, __LINE__);
  }
  requirements_.MergeFrom(from.requirements_);
  rules_.MergeFrom(from.rules_);
}

void Usage::CopyFrom(const ::google::protobuf::Message& from) {
// @@protoc_insertion_point(generalized_copy_from_start:google.api.Usage)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

void Usage::CopyFrom(const Usage& from) {
// @@protoc_insertion_point(class_specific_copy_from_start:google.api.Usage)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool Usage::IsInitialized() const {

  return true;
}

void Usage::Swap(Usage* other) {
  if (other == this) return;
  InternalSwap(other);
}
void Usage::InternalSwap(Usage* other) {
  requirements_.UnsafeArenaSwap(&other->requirements_);
  rules_.UnsafeArenaSwap(&other->rules_);
  _internal_metadata_.Swap(&other->_internal_metadata_);
  std::swap(_cached_size_, other->_cached_size_);
}

::google::protobuf::Metadata Usage::GetMetadata() const {
  protobuf_AssignDescriptorsOnce();
  ::google::protobuf::Metadata metadata;
  metadata.descriptor = Usage_descriptor_;
  metadata.reflection = Usage_reflection_;
  return metadata;
}

#if PROTOBUF_INLINE_NOT_IN_HEADERS
// Usage

// repeated string requirements = 1;
int Usage::requirements_size() const {
  return requirements_.size();
}
void Usage::clear_requirements() {
  requirements_.Clear();
}
 const ::std::string& Usage::requirements(int index) const {
  // @@protoc_insertion_point(field_get:google.api.Usage.requirements)
  return requirements_.Get(index);
}
 ::std::string* Usage::mutable_requirements(int index) {
  // @@protoc_insertion_point(field_mutable:google.api.Usage.requirements)
  return requirements_.Mutable(index);
}
 void Usage::set_requirements(int index, const ::std::string& value) {
  // @@protoc_insertion_point(field_set:google.api.Usage.requirements)
  requirements_.Mutable(index)->assign(value);
}
 void Usage::set_requirements(int index, const char* value) {
  requirements_.Mutable(index)->assign(value);
  // @@protoc_insertion_point(field_set_char:google.api.Usage.requirements)
}
 void Usage::set_requirements(int index, const char* value, size_t size) {
  requirements_.Mutable(index)->assign(
    reinterpret_cast<const char*>(value), size);
  // @@protoc_insertion_point(field_set_pointer:google.api.Usage.requirements)
}
 ::std::string* Usage::add_requirements() {
  // @@protoc_insertion_point(field_add_mutable:google.api.Usage.requirements)
  return requirements_.Add();
}
 void Usage::add_requirements(const ::std::string& value) {
  requirements_.Add()->assign(value);
  // @@protoc_insertion_point(field_add:google.api.Usage.requirements)
}
 void Usage::add_requirements(const char* value) {
  requirements_.Add()->assign(value);
  // @@protoc_insertion_point(field_add_char:google.api.Usage.requirements)
}
 void Usage::add_requirements(const char* value, size_t size) {
  requirements_.Add()->assign(reinterpret_cast<const char*>(value), size);
  // @@protoc_insertion_point(field_add_pointer:google.api.Usage.requirements)
}
 const ::google::protobuf::RepeatedPtrField< ::std::string>&
Usage::requirements() const {
  // @@protoc_insertion_point(field_list:google.api.Usage.requirements)
  return requirements_;
}
 ::google::protobuf::RepeatedPtrField< ::std::string>*
Usage::mutable_requirements() {
  // @@protoc_insertion_point(field_mutable_list:google.api.Usage.requirements)
  return &requirements_;
}

// repeated .google.api.UsageRule rules = 6;
int Usage::rules_size() const {
  return rules_.size();
}
void Usage::clear_rules() {
  rules_.Clear();
}
const ::google::api::UsageRule& Usage::rules(int index) const {
  // @@protoc_insertion_point(field_get:google.api.Usage.rules)
  return rules_.Get(index);
}
::google::api::UsageRule* Usage::mutable_rules(int index) {
  // @@protoc_insertion_point(field_mutable:google.api.Usage.rules)
  return rules_.Mutable(index);
}
::google::api::UsageRule* Usage::add_rules() {
  // @@protoc_insertion_point(field_add:google.api.Usage.rules)
  return rules_.Add();
}
::google::protobuf::RepeatedPtrField< ::google::api::UsageRule >*
Usage::mutable_rules() {
  // @@protoc_insertion_point(field_mutable_list:google.api.Usage.rules)
  return &rules_;
}
const ::google::protobuf::RepeatedPtrField< ::google::api::UsageRule >&
Usage::rules() const {
  // @@protoc_insertion_point(field_list:google.api.Usage.rules)
  return rules_;
}

#endif  // PROTOBUF_INLINE_NOT_IN_HEADERS

// ===================================================================

#if !defined(_MSC_VER) || _MSC_VER >= 1900
const int UsageRule::kSelectorFieldNumber;
const int UsageRule::kAllowUnregisteredCallsFieldNumber;
#endif  // !defined(_MSC_VER) || _MSC_VER >= 1900

UsageRule::UsageRule()
  : ::google::protobuf::Message(), _internal_metadata_(NULL) {
  SharedCtor();
  // @@protoc_insertion_point(constructor:google.api.UsageRule)
}

void UsageRule::InitAsDefaultInstance() {
  _is_default_instance_ = true;
}

UsageRule::UsageRule(const UsageRule& from)
  : ::google::protobuf::Message(),
    _internal_metadata_(NULL) {
  SharedCtor();
  MergeFrom(from);
  // @@protoc_insertion_point(copy_constructor:google.api.UsageRule)
}

void UsageRule::SharedCtor() {
    _is_default_instance_ = false;
  ::google::protobuf::internal::GetEmptyString();
  _cached_size_ = 0;
  selector_.UnsafeSetDefault(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
  allow_unregistered_calls_ = false;
}

UsageRule::~UsageRule() {
  // @@protoc_insertion_point(destructor:google.api.UsageRule)
  SharedDtor();
}

void UsageRule::SharedDtor() {
  selector_.DestroyNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
  if (this != default_instance_) {
  }
}

void UsageRule::SetCachedSize(int size) const {
  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
}
const ::google::protobuf::Descriptor* UsageRule::descriptor() {
  protobuf_AssignDescriptorsOnce();
  return UsageRule_descriptor_;
}

const UsageRule& UsageRule::default_instance() {
  if (default_instance_ == NULL) protobuf_AddDesc_google_2fapi_2fusage_2eproto();
  return *default_instance_;
}

UsageRule* UsageRule::default_instance_ = NULL;

UsageRule* UsageRule::New(::google::protobuf::Arena* arena) const {
  UsageRule* n = new UsageRule;
  if (arena != NULL) {
    arena->Own(n);
  }
  return n;
}

void UsageRule::Clear() {
// @@protoc_insertion_point(message_clear_start:google.api.UsageRule)
  selector_.ClearToEmptyNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
  allow_unregistered_calls_ = false;
}

bool UsageRule::MergePartialFromCodedStream(
    ::google::protobuf::io::CodedInputStream* input) {
#define DO_(EXPRESSION) if (!GOOGLE_PREDICT_TRUE(EXPRESSION)) goto failure
  ::google::protobuf::uint32 tag;
  // @@protoc_insertion_point(parse_start:google.api.UsageRule)
  for (;;) {
    ::std::pair< ::google::protobuf::uint32, bool> p = input->ReadTagWithCutoff(127);
    tag = p.first;
    if (!p.second) goto handle_unusual;
    switch (::google::protobuf::internal::WireFormatLite::GetTagFieldNumber(tag)) {
      // optional string selector = 1;
      case 1: {
        if (tag == 10) {
          DO_(::google::protobuf::internal::WireFormatLite::ReadString(
                input, this->mutable_selector()));
          DO_(::google::protobuf::internal::WireFormatLite::VerifyUtf8String(
            this->selector().data(), this->selector().length(),
            ::google::protobuf::internal::WireFormatLite::PARSE,
            "google.api.UsageRule.selector"));
        } else {
          goto handle_unusual;
        }
        if (input->ExpectTag(16)) goto parse_allow_unregistered_calls;
        break;
      }

      // optional bool allow_unregistered_calls = 2;
      case 2: {
        if (tag == 16) {
         parse_allow_unregistered_calls:
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   bool, ::google::protobuf::internal::WireFormatLite::TYPE_BOOL>(
                 input, &allow_unregistered_calls_)));

        } else {
          goto handle_unusual;
        }
        if (input->ExpectAtEnd()) goto success;
        break;
      }

      default: {
      handle_unusual:
        if (tag == 0 ||
            ::google::protobuf::internal::WireFormatLite::GetTagWireType(tag) ==
            ::google::protobuf::internal::WireFormatLite::WIRETYPE_END_GROUP) {
          goto success;
        }
        DO_(::google::protobuf::internal::WireFormatLite::SkipField(input, tag));
        break;
      }
    }
  }
success:
  // @@protoc_insertion_point(parse_success:google.api.UsageRule)
  return true;
failure:
  // @@protoc_insertion_point(parse_failure:google.api.UsageRule)
  return false;
#undef DO_
}

void UsageRule::SerializeWithCachedSizes(
    ::google::protobuf::io::CodedOutputStream* output) const {
  // @@protoc_insertion_point(serialize_start:google.api.UsageRule)
  // optional string selector = 1;
  if (this->selector().size() > 0) {
    ::google::protobuf::internal::WireFormatLite::VerifyUtf8String(
      this->selector().data(), this->selector().length(),
      ::google::protobuf::internal::WireFormatLite::SERIALIZE,
      "google.api.UsageRule.selector");
    ::google::protobuf::internal::WireFormatLite::WriteStringMaybeAliased(
      1, this->selector(), output);
  }

  // optional bool allow_unregistered_calls = 2;
  if (this->allow_unregistered_calls() != 0) {
    ::google::protobuf::internal::WireFormatLite::WriteBool(2, this->allow_unregistered_calls(), output);
  }

  // @@protoc_insertion_point(serialize_end:google.api.UsageRule)
}

::google::protobuf::uint8* UsageRule::InternalSerializeWithCachedSizesToArray(
    bool deterministic, ::google::protobuf::uint8* target) const {
  // @@protoc_insertion_point(serialize_to_array_start:google.api.UsageRule)
  // optional string selector = 1;
  if (this->selector().size() > 0) {
    ::google::protobuf::internal::WireFormatLite::VerifyUtf8String(
      this->selector().data(), this->selector().length(),
      ::google::protobuf::internal::WireFormatLite::SERIALIZE,
      "google.api.UsageRule.selector");
    target =
      ::google::protobuf::internal::WireFormatLite::WriteStringToArray(
        1, this->selector(), target);
  }

  // optional bool allow_unregistered_calls = 2;
  if (this->allow_unregistered_calls() != 0) {
    target = ::google::protobuf::internal::WireFormatLite::WriteBoolToArray(2, this->allow_unregistered_calls(), target);
  }

  // @@protoc_insertion_point(serialize_to_array_end:google.api.UsageRule)
  return target;
}

int UsageRule::ByteSize() const {
// @@protoc_insertion_point(message_byte_size_start:google.api.UsageRule)
  int total_size = 0;

  // optional string selector = 1;
  if (this->selector().size() > 0) {
    total_size += 1 +
      ::google::protobuf::internal::WireFormatLite::StringSize(
        this->selector());
  }

  // optional bool allow_unregistered_calls = 2;
  if (this->allow_unregistered_calls() != 0) {
    total_size += 1 + 1;
  }

  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = total_size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
  return total_size;
}

void UsageRule::MergeFrom(const ::google::protobuf::Message& from) {
// @@protoc_insertion_point(generalized_merge_from_start:google.api.UsageRule)
  if (GOOGLE_PREDICT_FALSE(&from == this)) {
    ::google::protobuf::internal::MergeFromFail(__FILE__, __LINE__);
  }
  const UsageRule* source = 
      ::google::protobuf::internal::DynamicCastToGenerated<const UsageRule>(
          &from);
  if (source == NULL) {
  // @@protoc_insertion_point(generalized_merge_from_cast_fail:google.api.UsageRule)
    ::google::protobuf::internal::ReflectionOps::Merge(from, this);
  } else {
  // @@protoc_insertion_point(generalized_merge_from_cast_success:google.api.UsageRule)
    MergeFrom(*source);
  }
}

void UsageRule::MergeFrom(const UsageRule& from) {
// @@protoc_insertion_point(class_specific_merge_from_start:google.api.UsageRule)
  if (GOOGLE_PREDICT_FALSE(&from == this)) {
    ::google::protobuf::internal::MergeFromFail(__FILE__, __LINE__);
  }
  if (from.selector().size() > 0) {

    selector_.AssignWithDefault(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), from.selector_);
  }
  if (from.allow_unregistered_calls() != 0) {
    set_allow_unregistered_calls(from.allow_unregistered_calls());
  }
}

void UsageRule::CopyFrom(const ::google::protobuf::Message& from) {
// @@protoc_insertion_point(generalized_copy_from_start:google.api.UsageRule)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

void UsageRule::CopyFrom(const UsageRule& from) {
// @@protoc_insertion_point(class_specific_copy_from_start:google.api.UsageRule)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool UsageRule::IsInitialized() const {

  return true;
}

void UsageRule::Swap(UsageRule* other) {
  if (other == this) return;
  InternalSwap(other);
}
void UsageRule::InternalSwap(UsageRule* other) {
  selector_.Swap(&other->selector_);
  std::swap(allow_unregistered_calls_, other->allow_unregistered_calls_);
  _internal_metadata_.Swap(&other->_internal_metadata_);
  std::swap(_cached_size_, other->_cached_size_);
}

::google::protobuf::Metadata UsageRule::GetMetadata() const {
  protobuf_AssignDescriptorsOnce();
  ::google::protobuf::Metadata metadata;
  metadata.descriptor = UsageRule_descriptor_;
  metadata.reflection = UsageRule_reflection_;
  return metadata;
}

#if PROTOBUF_INLINE_NOT_IN_HEADERS
// UsageRule

// optional string selector = 1;
void UsageRule::clear_selector() {
  selector_.ClearToEmptyNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
 const ::std::string& UsageRule::selector() const {
  // @@protoc_insertion_point(field_get:google.api.UsageRule.selector)
  return selector_.GetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
 void UsageRule::set_selector(const ::std::string& value) {
  
  selector_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), value);
  // @@protoc_insertion_point(field_set:google.api.UsageRule.selector)
}
 void UsageRule::set_selector(const char* value) {
  
  selector_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), ::std::string(value));
  // @@protoc_insertion_point(field_set_char:google.api.UsageRule.selector)
}
 void UsageRule::set_selector(const char* value, size_t size) {
  
  selector_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(),
      ::std::string(reinterpret_cast<const char*>(value), size));
  // @@protoc_insertion_point(field_set_pointer:google.api.UsageRule.selector)
}
 ::std::string* UsageRule::mutable_selector() {
  
  // @@protoc_insertion_point(field_mutable:google.api.UsageRule.selector)
  return selector_.MutableNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
 ::std::string* UsageRule::release_selector() {
  // @@protoc_insertion_point(field_release:google.api.UsageRule.selector)
  
  return selector_.ReleaseNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
 void UsageRule::set_allocated_selector(::std::string* selector) {
  if (selector != NULL) {
    
  } else {
    
  }
  selector_.SetAllocatedNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), selector);
  // @@protoc_insertion_point(field_set_allocated:google.api.UsageRule.selector)
}

// optional bool allow_unregistered_calls = 2;
void UsageRule::clear_allow_unregistered_calls() {
  allow_unregistered_calls_ = false;
}
 bool UsageRule::allow_unregistered_calls() const {
  // @@protoc_insertion_point(field_get:google.api.UsageRule.allow_unregistered_calls)
  return allow_unregistered_calls_;
}
 void UsageRule::set_allow_unregistered_calls(bool value) {
  
  allow_unregistered_calls_ = value;
  // @@protoc_insertion_point(field_set:google.api.UsageRule.allow_unregistered_calls)
}

#endif  // PROTOBUF_INLINE_NOT_IN_HEADERS

// @@protoc_insertion_point(namespace_scope)

}  // namespace api
}  // namespace google

// @@protoc_insertion_point(global_scope)