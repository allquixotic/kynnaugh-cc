// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: google/type/postal_address.proto

#ifndef PROTOBUF_google_2ftype_2fpostal_5faddress_2eproto__INCLUDED
#define PROTOBUF_google_2ftype_2fpostal_5faddress_2eproto__INCLUDED

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
#include <google/protobuf/unknown_field_set.h>
// @@protoc_insertion_point(includes)

namespace google {
namespace type {

// Internal implementation detail -- do not call these.
void protobuf_AddDesc_google_2ftype_2fpostal_5faddress_2eproto();
void protobuf_InitDefaults_google_2ftype_2fpostal_5faddress_2eproto();
void protobuf_AssignDesc_google_2ftype_2fpostal_5faddress_2eproto();
void protobuf_ShutdownFile_google_2ftype_2fpostal_5faddress_2eproto();

class PostalAddress;

// ===================================================================

class PostalAddress : public ::google::protobuf::Message /* @@protoc_insertion_point(class_definition:google.type.PostalAddress) */ {
 public:
  PostalAddress();
  virtual ~PostalAddress();

  PostalAddress(const PostalAddress& from);

  inline PostalAddress& operator=(const PostalAddress& from) {
    CopyFrom(from);
    return *this;
  }

  static const ::google::protobuf::Descriptor* descriptor();
  static const PostalAddress& default_instance();

  static const PostalAddress* internal_default_instance();

  void Swap(PostalAddress* other);

  // implements Message ----------------------------------------------

  inline PostalAddress* New() const { return New(NULL); }

  PostalAddress* New(::google::protobuf::Arena* arena) const;
  void CopyFrom(const ::google::protobuf::Message& from);
  void MergeFrom(const ::google::protobuf::Message& from);
  void CopyFrom(const PostalAddress& from);
  void MergeFrom(const PostalAddress& from);
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
  void InternalSwap(PostalAddress* other);
  void UnsafeMergeFrom(const PostalAddress& from);
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

  // accessors -------------------------------------------------------

  // optional int32 revision = 1;
  void clear_revision();
  static const int kRevisionFieldNumber = 1;
  ::google::protobuf::int32 revision() const;
  void set_revision(::google::protobuf::int32 value);

  // optional string region_code = 2;
  void clear_region_code();
  static const int kRegionCodeFieldNumber = 2;
  const ::std::string& region_code() const;
  void set_region_code(const ::std::string& value);
  void set_region_code(const char* value);
  void set_region_code(const char* value, size_t size);
  ::std::string* mutable_region_code();
  ::std::string* release_region_code();
  void set_allocated_region_code(::std::string* region_code);

  // optional string language_code = 3;
  void clear_language_code();
  static const int kLanguageCodeFieldNumber = 3;
  const ::std::string& language_code() const;
  void set_language_code(const ::std::string& value);
  void set_language_code(const char* value);
  void set_language_code(const char* value, size_t size);
  ::std::string* mutable_language_code();
  ::std::string* release_language_code();
  void set_allocated_language_code(::std::string* language_code);

  // optional string postal_code = 4;
  void clear_postal_code();
  static const int kPostalCodeFieldNumber = 4;
  const ::std::string& postal_code() const;
  void set_postal_code(const ::std::string& value);
  void set_postal_code(const char* value);
  void set_postal_code(const char* value, size_t size);
  ::std::string* mutable_postal_code();
  ::std::string* release_postal_code();
  void set_allocated_postal_code(::std::string* postal_code);

  // optional string sorting_code = 5;
  void clear_sorting_code();
  static const int kSortingCodeFieldNumber = 5;
  const ::std::string& sorting_code() const;
  void set_sorting_code(const ::std::string& value);
  void set_sorting_code(const char* value);
  void set_sorting_code(const char* value, size_t size);
  ::std::string* mutable_sorting_code();
  ::std::string* release_sorting_code();
  void set_allocated_sorting_code(::std::string* sorting_code);

  // optional string administrative_area = 6;
  void clear_administrative_area();
  static const int kAdministrativeAreaFieldNumber = 6;
  const ::std::string& administrative_area() const;
  void set_administrative_area(const ::std::string& value);
  void set_administrative_area(const char* value);
  void set_administrative_area(const char* value, size_t size);
  ::std::string* mutable_administrative_area();
  ::std::string* release_administrative_area();
  void set_allocated_administrative_area(::std::string* administrative_area);

  // optional string locality = 7;
  void clear_locality();
  static const int kLocalityFieldNumber = 7;
  const ::std::string& locality() const;
  void set_locality(const ::std::string& value);
  void set_locality(const char* value);
  void set_locality(const char* value, size_t size);
  ::std::string* mutable_locality();
  ::std::string* release_locality();
  void set_allocated_locality(::std::string* locality);

  // optional string sublocality = 8;
  void clear_sublocality();
  static const int kSublocalityFieldNumber = 8;
  const ::std::string& sublocality() const;
  void set_sublocality(const ::std::string& value);
  void set_sublocality(const char* value);
  void set_sublocality(const char* value, size_t size);
  ::std::string* mutable_sublocality();
  ::std::string* release_sublocality();
  void set_allocated_sublocality(::std::string* sublocality);

  // repeated string address_lines = 9;
  int address_lines_size() const;
  void clear_address_lines();
  static const int kAddressLinesFieldNumber = 9;
  const ::std::string& address_lines(int index) const;
  ::std::string* mutable_address_lines(int index);
  void set_address_lines(int index, const ::std::string& value);
  void set_address_lines(int index, const char* value);
  void set_address_lines(int index, const char* value, size_t size);
  ::std::string* add_address_lines();
  void add_address_lines(const ::std::string& value);
  void add_address_lines(const char* value);
  void add_address_lines(const char* value, size_t size);
  const ::google::protobuf::RepeatedPtrField< ::std::string>& address_lines() const;
  ::google::protobuf::RepeatedPtrField< ::std::string>* mutable_address_lines();

  // repeated string recipients = 10;
  int recipients_size() const;
  void clear_recipients();
  static const int kRecipientsFieldNumber = 10;
  const ::std::string& recipients(int index) const;
  ::std::string* mutable_recipients(int index);
  void set_recipients(int index, const ::std::string& value);
  void set_recipients(int index, const char* value);
  void set_recipients(int index, const char* value, size_t size);
  ::std::string* add_recipients();
  void add_recipients(const ::std::string& value);
  void add_recipients(const char* value);
  void add_recipients(const char* value, size_t size);
  const ::google::protobuf::RepeatedPtrField< ::std::string>& recipients() const;
  ::google::protobuf::RepeatedPtrField< ::std::string>* mutable_recipients();

  // optional string organization = 11;
  void clear_organization();
  static const int kOrganizationFieldNumber = 11;
  const ::std::string& organization() const;
  void set_organization(const ::std::string& value);
  void set_organization(const char* value);
  void set_organization(const char* value, size_t size);
  ::std::string* mutable_organization();
  ::std::string* release_organization();
  void set_allocated_organization(::std::string* organization);

  // @@protoc_insertion_point(class_scope:google.type.PostalAddress)
 private:

  ::google::protobuf::internal::InternalMetadataWithArena _internal_metadata_;
  ::google::protobuf::RepeatedPtrField< ::std::string> address_lines_;
  ::google::protobuf::RepeatedPtrField< ::std::string> recipients_;
  ::google::protobuf::internal::ArenaStringPtr region_code_;
  ::google::protobuf::internal::ArenaStringPtr language_code_;
  ::google::protobuf::internal::ArenaStringPtr postal_code_;
  ::google::protobuf::internal::ArenaStringPtr sorting_code_;
  ::google::protobuf::internal::ArenaStringPtr administrative_area_;
  ::google::protobuf::internal::ArenaStringPtr locality_;
  ::google::protobuf::internal::ArenaStringPtr sublocality_;
  ::google::protobuf::internal::ArenaStringPtr organization_;
  ::google::protobuf::int32 revision_;
  mutable int _cached_size_;
  friend void  protobuf_InitDefaults_google_2ftype_2fpostal_5faddress_2eproto_impl();
  friend void  protobuf_AddDesc_google_2ftype_2fpostal_5faddress_2eproto_impl();
  friend void protobuf_AssignDesc_google_2ftype_2fpostal_5faddress_2eproto();
  friend void protobuf_ShutdownFile_google_2ftype_2fpostal_5faddress_2eproto();

  void InitAsDefaultInstance();
};
extern ::google::protobuf::internal::ExplicitlyConstructed<PostalAddress> PostalAddress_default_instance_;

// ===================================================================


// ===================================================================

#if !PROTOBUF_INLINE_NOT_IN_HEADERS
// PostalAddress

// optional int32 revision = 1;
inline void PostalAddress::clear_revision() {
  revision_ = 0;
}
inline ::google::protobuf::int32 PostalAddress::revision() const {
  // @@protoc_insertion_point(field_get:google.type.PostalAddress.revision)
  return revision_;
}
inline void PostalAddress::set_revision(::google::protobuf::int32 value) {
  
  revision_ = value;
  // @@protoc_insertion_point(field_set:google.type.PostalAddress.revision)
}

// optional string region_code = 2;
inline void PostalAddress::clear_region_code() {
  region_code_.ClearToEmptyNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline const ::std::string& PostalAddress::region_code() const {
  // @@protoc_insertion_point(field_get:google.type.PostalAddress.region_code)
  return region_code_.GetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline void PostalAddress::set_region_code(const ::std::string& value) {
  
  region_code_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), value);
  // @@protoc_insertion_point(field_set:google.type.PostalAddress.region_code)
}
inline void PostalAddress::set_region_code(const char* value) {
  
  region_code_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), ::std::string(value));
  // @@protoc_insertion_point(field_set_char:google.type.PostalAddress.region_code)
}
inline void PostalAddress::set_region_code(const char* value, size_t size) {
  
  region_code_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(),
      ::std::string(reinterpret_cast<const char*>(value), size));
  // @@protoc_insertion_point(field_set_pointer:google.type.PostalAddress.region_code)
}
inline ::std::string* PostalAddress::mutable_region_code() {
  
  // @@protoc_insertion_point(field_mutable:google.type.PostalAddress.region_code)
  return region_code_.MutableNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline ::std::string* PostalAddress::release_region_code() {
  // @@protoc_insertion_point(field_release:google.type.PostalAddress.region_code)
  
  return region_code_.ReleaseNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline void PostalAddress::set_allocated_region_code(::std::string* region_code) {
  if (region_code != NULL) {
    
  } else {
    
  }
  region_code_.SetAllocatedNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), region_code);
  // @@protoc_insertion_point(field_set_allocated:google.type.PostalAddress.region_code)
}

// optional string language_code = 3;
inline void PostalAddress::clear_language_code() {
  language_code_.ClearToEmptyNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline const ::std::string& PostalAddress::language_code() const {
  // @@protoc_insertion_point(field_get:google.type.PostalAddress.language_code)
  return language_code_.GetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline void PostalAddress::set_language_code(const ::std::string& value) {
  
  language_code_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), value);
  // @@protoc_insertion_point(field_set:google.type.PostalAddress.language_code)
}
inline void PostalAddress::set_language_code(const char* value) {
  
  language_code_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), ::std::string(value));
  // @@protoc_insertion_point(field_set_char:google.type.PostalAddress.language_code)
}
inline void PostalAddress::set_language_code(const char* value, size_t size) {
  
  language_code_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(),
      ::std::string(reinterpret_cast<const char*>(value), size));
  // @@protoc_insertion_point(field_set_pointer:google.type.PostalAddress.language_code)
}
inline ::std::string* PostalAddress::mutable_language_code() {
  
  // @@protoc_insertion_point(field_mutable:google.type.PostalAddress.language_code)
  return language_code_.MutableNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline ::std::string* PostalAddress::release_language_code() {
  // @@protoc_insertion_point(field_release:google.type.PostalAddress.language_code)
  
  return language_code_.ReleaseNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline void PostalAddress::set_allocated_language_code(::std::string* language_code) {
  if (language_code != NULL) {
    
  } else {
    
  }
  language_code_.SetAllocatedNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), language_code);
  // @@protoc_insertion_point(field_set_allocated:google.type.PostalAddress.language_code)
}

// optional string postal_code = 4;
inline void PostalAddress::clear_postal_code() {
  postal_code_.ClearToEmptyNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline const ::std::string& PostalAddress::postal_code() const {
  // @@protoc_insertion_point(field_get:google.type.PostalAddress.postal_code)
  return postal_code_.GetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline void PostalAddress::set_postal_code(const ::std::string& value) {
  
  postal_code_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), value);
  // @@protoc_insertion_point(field_set:google.type.PostalAddress.postal_code)
}
inline void PostalAddress::set_postal_code(const char* value) {
  
  postal_code_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), ::std::string(value));
  // @@protoc_insertion_point(field_set_char:google.type.PostalAddress.postal_code)
}
inline void PostalAddress::set_postal_code(const char* value, size_t size) {
  
  postal_code_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(),
      ::std::string(reinterpret_cast<const char*>(value), size));
  // @@protoc_insertion_point(field_set_pointer:google.type.PostalAddress.postal_code)
}
inline ::std::string* PostalAddress::mutable_postal_code() {
  
  // @@protoc_insertion_point(field_mutable:google.type.PostalAddress.postal_code)
  return postal_code_.MutableNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline ::std::string* PostalAddress::release_postal_code() {
  // @@protoc_insertion_point(field_release:google.type.PostalAddress.postal_code)
  
  return postal_code_.ReleaseNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline void PostalAddress::set_allocated_postal_code(::std::string* postal_code) {
  if (postal_code != NULL) {
    
  } else {
    
  }
  postal_code_.SetAllocatedNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), postal_code);
  // @@protoc_insertion_point(field_set_allocated:google.type.PostalAddress.postal_code)
}

// optional string sorting_code = 5;
inline void PostalAddress::clear_sorting_code() {
  sorting_code_.ClearToEmptyNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline const ::std::string& PostalAddress::sorting_code() const {
  // @@protoc_insertion_point(field_get:google.type.PostalAddress.sorting_code)
  return sorting_code_.GetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline void PostalAddress::set_sorting_code(const ::std::string& value) {
  
  sorting_code_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), value);
  // @@protoc_insertion_point(field_set:google.type.PostalAddress.sorting_code)
}
inline void PostalAddress::set_sorting_code(const char* value) {
  
  sorting_code_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), ::std::string(value));
  // @@protoc_insertion_point(field_set_char:google.type.PostalAddress.sorting_code)
}
inline void PostalAddress::set_sorting_code(const char* value, size_t size) {
  
  sorting_code_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(),
      ::std::string(reinterpret_cast<const char*>(value), size));
  // @@protoc_insertion_point(field_set_pointer:google.type.PostalAddress.sorting_code)
}
inline ::std::string* PostalAddress::mutable_sorting_code() {
  
  // @@protoc_insertion_point(field_mutable:google.type.PostalAddress.sorting_code)
  return sorting_code_.MutableNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline ::std::string* PostalAddress::release_sorting_code() {
  // @@protoc_insertion_point(field_release:google.type.PostalAddress.sorting_code)
  
  return sorting_code_.ReleaseNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline void PostalAddress::set_allocated_sorting_code(::std::string* sorting_code) {
  if (sorting_code != NULL) {
    
  } else {
    
  }
  sorting_code_.SetAllocatedNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), sorting_code);
  // @@protoc_insertion_point(field_set_allocated:google.type.PostalAddress.sorting_code)
}

// optional string administrative_area = 6;
inline void PostalAddress::clear_administrative_area() {
  administrative_area_.ClearToEmptyNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline const ::std::string& PostalAddress::administrative_area() const {
  // @@protoc_insertion_point(field_get:google.type.PostalAddress.administrative_area)
  return administrative_area_.GetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline void PostalAddress::set_administrative_area(const ::std::string& value) {
  
  administrative_area_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), value);
  // @@protoc_insertion_point(field_set:google.type.PostalAddress.administrative_area)
}
inline void PostalAddress::set_administrative_area(const char* value) {
  
  administrative_area_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), ::std::string(value));
  // @@protoc_insertion_point(field_set_char:google.type.PostalAddress.administrative_area)
}
inline void PostalAddress::set_administrative_area(const char* value, size_t size) {
  
  administrative_area_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(),
      ::std::string(reinterpret_cast<const char*>(value), size));
  // @@protoc_insertion_point(field_set_pointer:google.type.PostalAddress.administrative_area)
}
inline ::std::string* PostalAddress::mutable_administrative_area() {
  
  // @@protoc_insertion_point(field_mutable:google.type.PostalAddress.administrative_area)
  return administrative_area_.MutableNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline ::std::string* PostalAddress::release_administrative_area() {
  // @@protoc_insertion_point(field_release:google.type.PostalAddress.administrative_area)
  
  return administrative_area_.ReleaseNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline void PostalAddress::set_allocated_administrative_area(::std::string* administrative_area) {
  if (administrative_area != NULL) {
    
  } else {
    
  }
  administrative_area_.SetAllocatedNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), administrative_area);
  // @@protoc_insertion_point(field_set_allocated:google.type.PostalAddress.administrative_area)
}

// optional string locality = 7;
inline void PostalAddress::clear_locality() {
  locality_.ClearToEmptyNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline const ::std::string& PostalAddress::locality() const {
  // @@protoc_insertion_point(field_get:google.type.PostalAddress.locality)
  return locality_.GetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline void PostalAddress::set_locality(const ::std::string& value) {
  
  locality_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), value);
  // @@protoc_insertion_point(field_set:google.type.PostalAddress.locality)
}
inline void PostalAddress::set_locality(const char* value) {
  
  locality_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), ::std::string(value));
  // @@protoc_insertion_point(field_set_char:google.type.PostalAddress.locality)
}
inline void PostalAddress::set_locality(const char* value, size_t size) {
  
  locality_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(),
      ::std::string(reinterpret_cast<const char*>(value), size));
  // @@protoc_insertion_point(field_set_pointer:google.type.PostalAddress.locality)
}
inline ::std::string* PostalAddress::mutable_locality() {
  
  // @@protoc_insertion_point(field_mutable:google.type.PostalAddress.locality)
  return locality_.MutableNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline ::std::string* PostalAddress::release_locality() {
  // @@protoc_insertion_point(field_release:google.type.PostalAddress.locality)
  
  return locality_.ReleaseNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline void PostalAddress::set_allocated_locality(::std::string* locality) {
  if (locality != NULL) {
    
  } else {
    
  }
  locality_.SetAllocatedNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), locality);
  // @@protoc_insertion_point(field_set_allocated:google.type.PostalAddress.locality)
}

// optional string sublocality = 8;
inline void PostalAddress::clear_sublocality() {
  sublocality_.ClearToEmptyNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline const ::std::string& PostalAddress::sublocality() const {
  // @@protoc_insertion_point(field_get:google.type.PostalAddress.sublocality)
  return sublocality_.GetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline void PostalAddress::set_sublocality(const ::std::string& value) {
  
  sublocality_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), value);
  // @@protoc_insertion_point(field_set:google.type.PostalAddress.sublocality)
}
inline void PostalAddress::set_sublocality(const char* value) {
  
  sublocality_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), ::std::string(value));
  // @@protoc_insertion_point(field_set_char:google.type.PostalAddress.sublocality)
}
inline void PostalAddress::set_sublocality(const char* value, size_t size) {
  
  sublocality_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(),
      ::std::string(reinterpret_cast<const char*>(value), size));
  // @@protoc_insertion_point(field_set_pointer:google.type.PostalAddress.sublocality)
}
inline ::std::string* PostalAddress::mutable_sublocality() {
  
  // @@protoc_insertion_point(field_mutable:google.type.PostalAddress.sublocality)
  return sublocality_.MutableNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline ::std::string* PostalAddress::release_sublocality() {
  // @@protoc_insertion_point(field_release:google.type.PostalAddress.sublocality)
  
  return sublocality_.ReleaseNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline void PostalAddress::set_allocated_sublocality(::std::string* sublocality) {
  if (sublocality != NULL) {
    
  } else {
    
  }
  sublocality_.SetAllocatedNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), sublocality);
  // @@protoc_insertion_point(field_set_allocated:google.type.PostalAddress.sublocality)
}

// repeated string address_lines = 9;
inline int PostalAddress::address_lines_size() const {
  return address_lines_.size();
}
inline void PostalAddress::clear_address_lines() {
  address_lines_.Clear();
}
inline const ::std::string& PostalAddress::address_lines(int index) const {
  // @@protoc_insertion_point(field_get:google.type.PostalAddress.address_lines)
  return address_lines_.Get(index);
}
inline ::std::string* PostalAddress::mutable_address_lines(int index) {
  // @@protoc_insertion_point(field_mutable:google.type.PostalAddress.address_lines)
  return address_lines_.Mutable(index);
}
inline void PostalAddress::set_address_lines(int index, const ::std::string& value) {
  // @@protoc_insertion_point(field_set:google.type.PostalAddress.address_lines)
  address_lines_.Mutable(index)->assign(value);
}
inline void PostalAddress::set_address_lines(int index, const char* value) {
  address_lines_.Mutable(index)->assign(value);
  // @@protoc_insertion_point(field_set_char:google.type.PostalAddress.address_lines)
}
inline void PostalAddress::set_address_lines(int index, const char* value, size_t size) {
  address_lines_.Mutable(index)->assign(
    reinterpret_cast<const char*>(value), size);
  // @@protoc_insertion_point(field_set_pointer:google.type.PostalAddress.address_lines)
}
inline ::std::string* PostalAddress::add_address_lines() {
  // @@protoc_insertion_point(field_add_mutable:google.type.PostalAddress.address_lines)
  return address_lines_.Add();
}
inline void PostalAddress::add_address_lines(const ::std::string& value) {
  address_lines_.Add()->assign(value);
  // @@protoc_insertion_point(field_add:google.type.PostalAddress.address_lines)
}
inline void PostalAddress::add_address_lines(const char* value) {
  address_lines_.Add()->assign(value);
  // @@protoc_insertion_point(field_add_char:google.type.PostalAddress.address_lines)
}
inline void PostalAddress::add_address_lines(const char* value, size_t size) {
  address_lines_.Add()->assign(reinterpret_cast<const char*>(value), size);
  // @@protoc_insertion_point(field_add_pointer:google.type.PostalAddress.address_lines)
}
inline const ::google::protobuf::RepeatedPtrField< ::std::string>&
PostalAddress::address_lines() const {
  // @@protoc_insertion_point(field_list:google.type.PostalAddress.address_lines)
  return address_lines_;
}
inline ::google::protobuf::RepeatedPtrField< ::std::string>*
PostalAddress::mutable_address_lines() {
  // @@protoc_insertion_point(field_mutable_list:google.type.PostalAddress.address_lines)
  return &address_lines_;
}

// repeated string recipients = 10;
inline int PostalAddress::recipients_size() const {
  return recipients_.size();
}
inline void PostalAddress::clear_recipients() {
  recipients_.Clear();
}
inline const ::std::string& PostalAddress::recipients(int index) const {
  // @@protoc_insertion_point(field_get:google.type.PostalAddress.recipients)
  return recipients_.Get(index);
}
inline ::std::string* PostalAddress::mutable_recipients(int index) {
  // @@protoc_insertion_point(field_mutable:google.type.PostalAddress.recipients)
  return recipients_.Mutable(index);
}
inline void PostalAddress::set_recipients(int index, const ::std::string& value) {
  // @@protoc_insertion_point(field_set:google.type.PostalAddress.recipients)
  recipients_.Mutable(index)->assign(value);
}
inline void PostalAddress::set_recipients(int index, const char* value) {
  recipients_.Mutable(index)->assign(value);
  // @@protoc_insertion_point(field_set_char:google.type.PostalAddress.recipients)
}
inline void PostalAddress::set_recipients(int index, const char* value, size_t size) {
  recipients_.Mutable(index)->assign(
    reinterpret_cast<const char*>(value), size);
  // @@protoc_insertion_point(field_set_pointer:google.type.PostalAddress.recipients)
}
inline ::std::string* PostalAddress::add_recipients() {
  // @@protoc_insertion_point(field_add_mutable:google.type.PostalAddress.recipients)
  return recipients_.Add();
}
inline void PostalAddress::add_recipients(const ::std::string& value) {
  recipients_.Add()->assign(value);
  // @@protoc_insertion_point(field_add:google.type.PostalAddress.recipients)
}
inline void PostalAddress::add_recipients(const char* value) {
  recipients_.Add()->assign(value);
  // @@protoc_insertion_point(field_add_char:google.type.PostalAddress.recipients)
}
inline void PostalAddress::add_recipients(const char* value, size_t size) {
  recipients_.Add()->assign(reinterpret_cast<const char*>(value), size);
  // @@protoc_insertion_point(field_add_pointer:google.type.PostalAddress.recipients)
}
inline const ::google::protobuf::RepeatedPtrField< ::std::string>&
PostalAddress::recipients() const {
  // @@protoc_insertion_point(field_list:google.type.PostalAddress.recipients)
  return recipients_;
}
inline ::google::protobuf::RepeatedPtrField< ::std::string>*
PostalAddress::mutable_recipients() {
  // @@protoc_insertion_point(field_mutable_list:google.type.PostalAddress.recipients)
  return &recipients_;
}

// optional string organization = 11;
inline void PostalAddress::clear_organization() {
  organization_.ClearToEmptyNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline const ::std::string& PostalAddress::organization() const {
  // @@protoc_insertion_point(field_get:google.type.PostalAddress.organization)
  return organization_.GetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline void PostalAddress::set_organization(const ::std::string& value) {
  
  organization_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), value);
  // @@protoc_insertion_point(field_set:google.type.PostalAddress.organization)
}
inline void PostalAddress::set_organization(const char* value) {
  
  organization_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), ::std::string(value));
  // @@protoc_insertion_point(field_set_char:google.type.PostalAddress.organization)
}
inline void PostalAddress::set_organization(const char* value, size_t size) {
  
  organization_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(),
      ::std::string(reinterpret_cast<const char*>(value), size));
  // @@protoc_insertion_point(field_set_pointer:google.type.PostalAddress.organization)
}
inline ::std::string* PostalAddress::mutable_organization() {
  
  // @@protoc_insertion_point(field_mutable:google.type.PostalAddress.organization)
  return organization_.MutableNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline ::std::string* PostalAddress::release_organization() {
  // @@protoc_insertion_point(field_release:google.type.PostalAddress.organization)
  
  return organization_.ReleaseNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline void PostalAddress::set_allocated_organization(::std::string* organization) {
  if (organization != NULL) {
    
  } else {
    
  }
  organization_.SetAllocatedNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), organization);
  // @@protoc_insertion_point(field_set_allocated:google.type.PostalAddress.organization)
}

inline const PostalAddress* PostalAddress::internal_default_instance() {
  return &PostalAddress_default_instance_.get();
}
#endif  // !PROTOBUF_INLINE_NOT_IN_HEADERS

// @@protoc_insertion_point(namespace_scope)

}  // namespace type
}  // namespace google

// @@protoc_insertion_point(global_scope)

#endif  // PROTOBUF_google_2ftype_2fpostal_5faddress_2eproto__INCLUDED
