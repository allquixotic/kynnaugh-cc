// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: google/type/latlng.proto

#ifndef PROTOBUF_google_2ftype_2flatlng_2eproto__INCLUDED
#define PROTOBUF_google_2ftype_2flatlng_2eproto__INCLUDED

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
void protobuf_AddDesc_google_2ftype_2flatlng_2eproto();
void protobuf_InitDefaults_google_2ftype_2flatlng_2eproto();
void protobuf_AssignDesc_google_2ftype_2flatlng_2eproto();
void protobuf_ShutdownFile_google_2ftype_2flatlng_2eproto();

class LatLng;

// ===================================================================

class LatLng : public ::google::protobuf::Message /* @@protoc_insertion_point(class_definition:google.type.LatLng) */ {
 public:
  LatLng();
  virtual ~LatLng();

  LatLng(const LatLng& from);

  inline LatLng& operator=(const LatLng& from) {
    CopyFrom(from);
    return *this;
  }

  static const ::google::protobuf::Descriptor* descriptor();
  static const LatLng& default_instance();

  static const LatLng* internal_default_instance();

  void Swap(LatLng* other);

  // implements Message ----------------------------------------------

  inline LatLng* New() const { return New(NULL); }

  LatLng* New(::google::protobuf::Arena* arena) const;
  void CopyFrom(const ::google::protobuf::Message& from);
  void MergeFrom(const ::google::protobuf::Message& from);
  void CopyFrom(const LatLng& from);
  void MergeFrom(const LatLng& from);
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
  void InternalSwap(LatLng* other);
  void UnsafeMergeFrom(const LatLng& from);
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

  // optional double latitude = 1;
  void clear_latitude();
  static const int kLatitudeFieldNumber = 1;
  double latitude() const;
  void set_latitude(double value);

  // optional double longitude = 2;
  void clear_longitude();
  static const int kLongitudeFieldNumber = 2;
  double longitude() const;
  void set_longitude(double value);

  // @@protoc_insertion_point(class_scope:google.type.LatLng)
 private:

  ::google::protobuf::internal::InternalMetadataWithArena _internal_metadata_;
  double latitude_;
  double longitude_;
  mutable int _cached_size_;
  friend void  protobuf_InitDefaults_google_2ftype_2flatlng_2eproto_impl();
  friend void  protobuf_AddDesc_google_2ftype_2flatlng_2eproto_impl();
  friend void protobuf_AssignDesc_google_2ftype_2flatlng_2eproto();
  friend void protobuf_ShutdownFile_google_2ftype_2flatlng_2eproto();

  void InitAsDefaultInstance();
};
extern ::google::protobuf::internal::ExplicitlyConstructed<LatLng> LatLng_default_instance_;

// ===================================================================


// ===================================================================

#if !PROTOBUF_INLINE_NOT_IN_HEADERS
// LatLng

// optional double latitude = 1;
inline void LatLng::clear_latitude() {
  latitude_ = 0;
}
inline double LatLng::latitude() const {
  // @@protoc_insertion_point(field_get:google.type.LatLng.latitude)
  return latitude_;
}
inline void LatLng::set_latitude(double value) {
  
  latitude_ = value;
  // @@protoc_insertion_point(field_set:google.type.LatLng.latitude)
}

// optional double longitude = 2;
inline void LatLng::clear_longitude() {
  longitude_ = 0;
}
inline double LatLng::longitude() const {
  // @@protoc_insertion_point(field_get:google.type.LatLng.longitude)
  return longitude_;
}
inline void LatLng::set_longitude(double value) {
  
  longitude_ = value;
  // @@protoc_insertion_point(field_set:google.type.LatLng.longitude)
}

inline const LatLng* LatLng::internal_default_instance() {
  return &LatLng_default_instance_.get();
}
#endif  // !PROTOBUF_INLINE_NOT_IN_HEADERS

// @@protoc_insertion_point(namespace_scope)

}  // namespace type
}  // namespace google

// @@protoc_insertion_point(global_scope)

#endif  // PROTOBUF_google_2ftype_2flatlng_2eproto__INCLUDED
