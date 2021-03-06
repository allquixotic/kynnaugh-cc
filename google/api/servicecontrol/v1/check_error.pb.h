// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: google/api/servicecontrol/v1/check_error.proto

#ifndef PROTOBUF_google_2fapi_2fservicecontrol_2fv1_2fcheck_5ferror_2eproto__INCLUDED
#define PROTOBUF_google_2fapi_2fservicecontrol_2fv1_2fcheck_5ferror_2eproto__INCLUDED

#include <string>

#include <google/protobuf/stubs/common.h>

#if GOOGLE_PROTOBUF_VERSION < 3001000
#error This file was generated by a newer version of protoc which is
#error incompatible with your Protocol Buffer headers.  Please update
#error your headers.
#endif
#if 3001000 < GOOGLE_PROTOBUF_MIN_PROTOC_VERSION
#error This file was generated by an older version of protoc which is
#error incompatible with your Protocol Buffer headers.  Please
#error regenerate this file with a newer version of protoc.
#endif

#include <google/protobuf/arena.h>
#include <google/protobuf/arenastring.h>
#include <google/protobuf/generated_message_util.h>
#include <google/protobuf/metadata.h>
#include <google/protobuf/message.h>
#include <google/protobuf/repeated_field.h>
#include <google/protobuf/extension_set.h>
#include <google/protobuf/generated_enum_reflection.h>
#include <google/protobuf/unknown_field_set.h>
#include "google/api/annotations.pb.h"
// @@protoc_insertion_point(includes)

namespace google {
namespace api {
namespace servicecontrol {
namespace v1 {

// Internal implementation detail -- do not call these.
void protobuf_AddDesc_google_2fapi_2fservicecontrol_2fv1_2fcheck_5ferror_2eproto();
void protobuf_InitDefaults_google_2fapi_2fservicecontrol_2fv1_2fcheck_5ferror_2eproto();
void protobuf_AssignDesc_google_2fapi_2fservicecontrol_2fv1_2fcheck_5ferror_2eproto();
void protobuf_ShutdownFile_google_2fapi_2fservicecontrol_2fv1_2fcheck_5ferror_2eproto();

class CheckError;

enum CheckError_Code {
  CheckError_Code_ERROR_CODE_UNSPECIFIED = 0,
  CheckError_Code_NOT_FOUND = 5,
  CheckError_Code_PERMISSION_DENIED = 7,
  CheckError_Code_RESOURCE_EXHAUSTED = 8,
  CheckError_Code_SERVICE_NOT_ACTIVATED = 104,
  CheckError_Code_BILLING_DISABLED = 107,
  CheckError_Code_PROJECT_DELETED = 108,
  CheckError_Code_PROJECT_INVALID = 114,
  CheckError_Code_IP_ADDRESS_BLOCKED = 109,
  CheckError_Code_REFERER_BLOCKED = 110,
  CheckError_Code_CLIENT_APP_BLOCKED = 111,
  CheckError_Code_API_KEY_INVALID = 105,
  CheckError_Code_API_KEY_EXPIRED = 112,
  CheckError_Code_API_KEY_NOT_FOUND = 113,
  CheckError_Code_NAMESPACE_LOOKUP_UNAVAILABLE = 300,
  CheckError_Code_SERVICE_STATUS_UNAVAILABLE = 301,
  CheckError_Code_BILLING_STATUS_UNAVAILABLE = 302,
  CheckError_Code_CheckError_Code_INT_MIN_SENTINEL_DO_NOT_USE_ = ::google::protobuf::kint32min,
  CheckError_Code_CheckError_Code_INT_MAX_SENTINEL_DO_NOT_USE_ = ::google::protobuf::kint32max
};
bool CheckError_Code_IsValid(int value);
const CheckError_Code CheckError_Code_Code_MIN = CheckError_Code_ERROR_CODE_UNSPECIFIED;
const CheckError_Code CheckError_Code_Code_MAX = CheckError_Code_BILLING_STATUS_UNAVAILABLE;
const int CheckError_Code_Code_ARRAYSIZE = CheckError_Code_Code_MAX + 1;

const ::google::protobuf::EnumDescriptor* CheckError_Code_descriptor();
inline const ::std::string& CheckError_Code_Name(CheckError_Code value) {
  return ::google::protobuf::internal::NameOfEnum(
    CheckError_Code_descriptor(), value);
}
inline bool CheckError_Code_Parse(
    const ::std::string& name, CheckError_Code* value) {
  return ::google::protobuf::internal::ParseNamedEnum<CheckError_Code>(
    CheckError_Code_descriptor(), name, value);
}
// ===================================================================

class CheckError : public ::google::protobuf::Message /* @@protoc_insertion_point(class_definition:google.api.servicecontrol.v1.CheckError) */ {
 public:
  CheckError();
  virtual ~CheckError();

  CheckError(const CheckError& from);

  inline CheckError& operator=(const CheckError& from) {
    CopyFrom(from);
    return *this;
  }

  inline ::google::protobuf::Arena* GetArena() const { return GetArenaNoVirtual(); }
  inline void* GetMaybeArenaPointer() const {
    return MaybeArenaPtr();
  }
  static const ::google::protobuf::Descriptor* descriptor();
  static const CheckError& default_instance();

  static const CheckError* internal_default_instance();

  void UnsafeArenaSwap(CheckError* other);
  void Swap(CheckError* other);

  // implements Message ----------------------------------------------

  inline CheckError* New() const { return New(NULL); }

  CheckError* New(::google::protobuf::Arena* arena) const;
  void CopyFrom(const ::google::protobuf::Message& from);
  void MergeFrom(const ::google::protobuf::Message& from);
  void CopyFrom(const CheckError& from);
  void MergeFrom(const CheckError& from);
  void Clear();
  bool IsInitialized() const;

  size_t ByteSizeLong() const;
  bool MergePartialFromCodedStream(
      ::google::protobuf::io::CodedInputStream* input);
  void SerializeWithCachedSizes(
      ::google::protobuf::io::CodedOutputStream* output) const;
  ::google::protobuf::uint8* InternalSerializeWithCachedSizesToArray(
      bool deterministic, ::google::protobuf::uint8* output) const;
  ::google::protobuf::uint8* SerializeWithCachedSizesToArray(::google::protobuf::uint8* output) const {
    return InternalSerializeWithCachedSizesToArray(false, output);
  }
  int GetCachedSize() const { return _cached_size_; }
  private:
  void SharedCtor();
  void SharedDtor();
  void SetCachedSize(int size) const;
  void InternalSwap(CheckError* other);
  void UnsafeMergeFrom(const CheckError& from);
  protected:
  explicit CheckError(::google::protobuf::Arena* arena);
  private:
  static void ArenaDtor(void* object);
  inline void RegisterArenaDtor(::google::protobuf::Arena* arena);
  private:
  inline ::google::protobuf::Arena* GetArenaNoVirtual() const {
    return _internal_metadata_.arena();
  }
  inline void* MaybeArenaPtr() const {
    return _internal_metadata_.raw_arena_ptr();
  }
  public:

  ::google::protobuf::Metadata GetMetadata() const;

  // nested types ----------------------------------------------------

  typedef CheckError_Code Code;
  static const Code ERROR_CODE_UNSPECIFIED =
    CheckError_Code_ERROR_CODE_UNSPECIFIED;
  static const Code NOT_FOUND =
    CheckError_Code_NOT_FOUND;
  static const Code PERMISSION_DENIED =
    CheckError_Code_PERMISSION_DENIED;
  static const Code RESOURCE_EXHAUSTED =
    CheckError_Code_RESOURCE_EXHAUSTED;
  static const Code SERVICE_NOT_ACTIVATED =
    CheckError_Code_SERVICE_NOT_ACTIVATED;
  static const Code BILLING_DISABLED =
    CheckError_Code_BILLING_DISABLED;
  static const Code PROJECT_DELETED =
    CheckError_Code_PROJECT_DELETED;
  static const Code PROJECT_INVALID =
    CheckError_Code_PROJECT_INVALID;
  static const Code IP_ADDRESS_BLOCKED =
    CheckError_Code_IP_ADDRESS_BLOCKED;
  static const Code REFERER_BLOCKED =
    CheckError_Code_REFERER_BLOCKED;
  static const Code CLIENT_APP_BLOCKED =
    CheckError_Code_CLIENT_APP_BLOCKED;
  static const Code API_KEY_INVALID =
    CheckError_Code_API_KEY_INVALID;
  static const Code API_KEY_EXPIRED =
    CheckError_Code_API_KEY_EXPIRED;
  static const Code API_KEY_NOT_FOUND =
    CheckError_Code_API_KEY_NOT_FOUND;
  static const Code NAMESPACE_LOOKUP_UNAVAILABLE =
    CheckError_Code_NAMESPACE_LOOKUP_UNAVAILABLE;
  static const Code SERVICE_STATUS_UNAVAILABLE =
    CheckError_Code_SERVICE_STATUS_UNAVAILABLE;
  static const Code BILLING_STATUS_UNAVAILABLE =
    CheckError_Code_BILLING_STATUS_UNAVAILABLE;
  static inline bool Code_IsValid(int value) {
    return CheckError_Code_IsValid(value);
  }
  static const Code Code_MIN =
    CheckError_Code_Code_MIN;
  static const Code Code_MAX =
    CheckError_Code_Code_MAX;
  static const int Code_ARRAYSIZE =
    CheckError_Code_Code_ARRAYSIZE;
  static inline const ::google::protobuf::EnumDescriptor*
  Code_descriptor() {
    return CheckError_Code_descriptor();
  }
  static inline const ::std::string& Code_Name(Code value) {
    return CheckError_Code_Name(value);
  }
  static inline bool Code_Parse(const ::std::string& name,
      Code* value) {
    return CheckError_Code_Parse(name, value);
  }

  // accessors -------------------------------------------------------

  // optional .google.api.servicecontrol.v1.CheckError.Code code = 1;
  void clear_code();
  static const int kCodeFieldNumber = 1;
  ::google::api::servicecontrol::v1::CheckError_Code code() const;
  void set_code(::google::api::servicecontrol::v1::CheckError_Code value);

  // optional string detail = 2;
  void clear_detail();
  static const int kDetailFieldNumber = 2;
  const ::std::string& detail() const;
  void set_detail(const ::std::string& value);
  void set_detail(const char* value);
  void set_detail(const char* value, size_t size);
  ::std::string* mutable_detail();
  ::std::string* release_detail();
  void set_allocated_detail(::std::string* detail);
  ::std::string* unsafe_arena_release_detail();
  void unsafe_arena_set_allocated_detail(
      ::std::string* detail);

  // @@protoc_insertion_point(class_scope:google.api.servicecontrol.v1.CheckError)
 private:

  ::google::protobuf::internal::InternalMetadataWithArena _internal_metadata_;
  friend class ::google::protobuf::Arena;
  typedef void InternalArenaConstructable_;
  typedef void DestructorSkippable_;
  ::google::protobuf::internal::ArenaStringPtr detail_;
  int code_;
  mutable int _cached_size_;
  friend void  protobuf_InitDefaults_google_2fapi_2fservicecontrol_2fv1_2fcheck_5ferror_2eproto_impl();
  friend void  protobuf_AddDesc_google_2fapi_2fservicecontrol_2fv1_2fcheck_5ferror_2eproto_impl();
  friend void protobuf_AssignDesc_google_2fapi_2fservicecontrol_2fv1_2fcheck_5ferror_2eproto();
  friend void protobuf_ShutdownFile_google_2fapi_2fservicecontrol_2fv1_2fcheck_5ferror_2eproto();

  void InitAsDefaultInstance();
};
extern ::google::protobuf::internal::ExplicitlyConstructed<CheckError> CheckError_default_instance_;

// ===================================================================


// ===================================================================

#if !PROTOBUF_INLINE_NOT_IN_HEADERS
// CheckError

// optional .google.api.servicecontrol.v1.CheckError.Code code = 1;
inline void CheckError::clear_code() {
  code_ = 0;
}
inline ::google::api::servicecontrol::v1::CheckError_Code CheckError::code() const {
  // @@protoc_insertion_point(field_get:google.api.servicecontrol.v1.CheckError.code)
  return static_cast< ::google::api::servicecontrol::v1::CheckError_Code >(code_);
}
inline void CheckError::set_code(::google::api::servicecontrol::v1::CheckError_Code value) {
  
  code_ = value;
  // @@protoc_insertion_point(field_set:google.api.servicecontrol.v1.CheckError.code)
}

// optional string detail = 2;
inline void CheckError::clear_detail() {
  detail_.ClearToEmpty(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), GetArenaNoVirtual());
}
inline const ::std::string& CheckError::detail() const {
  // @@protoc_insertion_point(field_get:google.api.servicecontrol.v1.CheckError.detail)
  return detail_.Get(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline void CheckError::set_detail(const ::std::string& value) {
  
  detail_.Set(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), value, GetArenaNoVirtual());
  // @@protoc_insertion_point(field_set:google.api.servicecontrol.v1.CheckError.detail)
}
inline void CheckError::set_detail(const char* value) {
  
  detail_.Set(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), ::std::string(value),
              GetArenaNoVirtual());
  // @@protoc_insertion_point(field_set_char:google.api.servicecontrol.v1.CheckError.detail)
}
inline void CheckError::set_detail(const char* value,
    size_t size) {
  
  detail_.Set(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), ::std::string(
      reinterpret_cast<const char*>(value), size), GetArenaNoVirtual());
  // @@protoc_insertion_point(field_set_pointer:google.api.servicecontrol.v1.CheckError.detail)
}
inline ::std::string* CheckError::mutable_detail() {
  
  // @@protoc_insertion_point(field_mutable:google.api.servicecontrol.v1.CheckError.detail)
  return detail_.Mutable(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), GetArenaNoVirtual());
}
inline ::std::string* CheckError::release_detail() {
  // @@protoc_insertion_point(field_release:google.api.servicecontrol.v1.CheckError.detail)
  
  return detail_.Release(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), GetArenaNoVirtual());
}
inline ::std::string* CheckError::unsafe_arena_release_detail() {
  // @@protoc_insertion_point(field_unsafe_arena_release:google.api.servicecontrol.v1.CheckError.detail)
  GOOGLE_DCHECK(GetArenaNoVirtual() != NULL);
  
  return detail_.UnsafeArenaRelease(&::google::protobuf::internal::GetEmptyStringAlreadyInited(),
      GetArenaNoVirtual());
}
inline void CheckError::set_allocated_detail(::std::string* detail) {
  if (detail != NULL) {
    
  } else {
    
  }
  detail_.SetAllocated(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), detail,
      GetArenaNoVirtual());
  // @@protoc_insertion_point(field_set_allocated:google.api.servicecontrol.v1.CheckError.detail)
}
inline void CheckError::unsafe_arena_set_allocated_detail(
    ::std::string* detail) {
  GOOGLE_DCHECK(GetArenaNoVirtual() != NULL);
  if (detail != NULL) {
    
  } else {
    
  }
  detail_.UnsafeArenaSetAllocated(&::google::protobuf::internal::GetEmptyStringAlreadyInited(),
      detail, GetArenaNoVirtual());
  // @@protoc_insertion_point(field_unsafe_arena_set_allocated:google.api.servicecontrol.v1.CheckError.detail)
}

inline const CheckError* CheckError::internal_default_instance() {
  return &CheckError_default_instance_.get();
}
#endif  // !PROTOBUF_INLINE_NOT_IN_HEADERS

// @@protoc_insertion_point(namespace_scope)

}  // namespace v1
}  // namespace servicecontrol
}  // namespace api
}  // namespace google

#ifndef SWIG
namespace google {
namespace protobuf {

template <> struct is_proto_enum< ::google::api::servicecontrol::v1::CheckError_Code> : ::google::protobuf::internal::true_type {};
template <>
inline const EnumDescriptor* GetEnumDescriptor< ::google::api::servicecontrol::v1::CheckError_Code>() {
  return ::google::api::servicecontrol::v1::CheckError_Code_descriptor();
}

}  // namespace protobuf
}  // namespace google
#endif  // SWIG

// @@protoc_insertion_point(global_scope)

#endif  // PROTOBUF_google_2fapi_2fservicecontrol_2fv1_2fcheck_5ferror_2eproto__INCLUDED
