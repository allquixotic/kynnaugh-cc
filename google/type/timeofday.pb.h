// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: google/type/timeofday.proto

#ifndef PROTOBUF_google_2ftype_2ftimeofday_2eproto__INCLUDED
#define PROTOBUF_google_2ftype_2ftimeofday_2eproto__INCLUDED

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
void protobuf_AddDesc_google_2ftype_2ftimeofday_2eproto();
void protobuf_InitDefaults_google_2ftype_2ftimeofday_2eproto();
void protobuf_AssignDesc_google_2ftype_2ftimeofday_2eproto();
void protobuf_ShutdownFile_google_2ftype_2ftimeofday_2eproto();

class TimeOfDay;

// ===================================================================

class TimeOfDay : public ::google::protobuf::Message /* @@protoc_insertion_point(class_definition:google.type.TimeOfDay) */ {
 public:
  TimeOfDay();
  virtual ~TimeOfDay();

  TimeOfDay(const TimeOfDay& from);

  inline TimeOfDay& operator=(const TimeOfDay& from) {
    CopyFrom(from);
    return *this;
  }

  static const ::google::protobuf::Descriptor* descriptor();
  static const TimeOfDay& default_instance();

  static const TimeOfDay* internal_default_instance();

  void Swap(TimeOfDay* other);

  // implements Message ----------------------------------------------

  inline TimeOfDay* New() const { return New(NULL); }

  TimeOfDay* New(::google::protobuf::Arena* arena) const;
  void CopyFrom(const ::google::protobuf::Message& from);
  void MergeFrom(const ::google::protobuf::Message& from);
  void CopyFrom(const TimeOfDay& from);
  void MergeFrom(const TimeOfDay& from);
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
  void InternalSwap(TimeOfDay* other);
  void UnsafeMergeFrom(const TimeOfDay& from);
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

  // optional int32 hours = 1;
  void clear_hours();
  static const int kHoursFieldNumber = 1;
  ::google::protobuf::int32 hours() const;
  void set_hours(::google::protobuf::int32 value);

  // optional int32 minutes = 2;
  void clear_minutes();
  static const int kMinutesFieldNumber = 2;
  ::google::protobuf::int32 minutes() const;
  void set_minutes(::google::protobuf::int32 value);

  // optional int32 seconds = 3;
  void clear_seconds();
  static const int kSecondsFieldNumber = 3;
  ::google::protobuf::int32 seconds() const;
  void set_seconds(::google::protobuf::int32 value);

  // optional int32 nanos = 4;
  void clear_nanos();
  static const int kNanosFieldNumber = 4;
  ::google::protobuf::int32 nanos() const;
  void set_nanos(::google::protobuf::int32 value);

  // @@protoc_insertion_point(class_scope:google.type.TimeOfDay)
 private:

  ::google::protobuf::internal::InternalMetadataWithArena _internal_metadata_;
  ::google::protobuf::int32 hours_;
  ::google::protobuf::int32 minutes_;
  ::google::protobuf::int32 seconds_;
  ::google::protobuf::int32 nanos_;
  mutable int _cached_size_;
  friend void  protobuf_InitDefaults_google_2ftype_2ftimeofday_2eproto_impl();
  friend void  protobuf_AddDesc_google_2ftype_2ftimeofday_2eproto_impl();
  friend void protobuf_AssignDesc_google_2ftype_2ftimeofday_2eproto();
  friend void protobuf_ShutdownFile_google_2ftype_2ftimeofday_2eproto();

  void InitAsDefaultInstance();
};
extern ::google::protobuf::internal::ExplicitlyConstructed<TimeOfDay> TimeOfDay_default_instance_;

// ===================================================================


// ===================================================================

#if !PROTOBUF_INLINE_NOT_IN_HEADERS
// TimeOfDay

// optional int32 hours = 1;
inline void TimeOfDay::clear_hours() {
  hours_ = 0;
}
inline ::google::protobuf::int32 TimeOfDay::hours() const {
  // @@protoc_insertion_point(field_get:google.type.TimeOfDay.hours)
  return hours_;
}
inline void TimeOfDay::set_hours(::google::protobuf::int32 value) {
  
  hours_ = value;
  // @@protoc_insertion_point(field_set:google.type.TimeOfDay.hours)
}

// optional int32 minutes = 2;
inline void TimeOfDay::clear_minutes() {
  minutes_ = 0;
}
inline ::google::protobuf::int32 TimeOfDay::minutes() const {
  // @@protoc_insertion_point(field_get:google.type.TimeOfDay.minutes)
  return minutes_;
}
inline void TimeOfDay::set_minutes(::google::protobuf::int32 value) {
  
  minutes_ = value;
  // @@protoc_insertion_point(field_set:google.type.TimeOfDay.minutes)
}

// optional int32 seconds = 3;
inline void TimeOfDay::clear_seconds() {
  seconds_ = 0;
}
inline ::google::protobuf::int32 TimeOfDay::seconds() const {
  // @@protoc_insertion_point(field_get:google.type.TimeOfDay.seconds)
  return seconds_;
}
inline void TimeOfDay::set_seconds(::google::protobuf::int32 value) {
  
  seconds_ = value;
  // @@protoc_insertion_point(field_set:google.type.TimeOfDay.seconds)
}

// optional int32 nanos = 4;
inline void TimeOfDay::clear_nanos() {
  nanos_ = 0;
}
inline ::google::protobuf::int32 TimeOfDay::nanos() const {
  // @@protoc_insertion_point(field_get:google.type.TimeOfDay.nanos)
  return nanos_;
}
inline void TimeOfDay::set_nanos(::google::protobuf::int32 value) {
  
  nanos_ = value;
  // @@protoc_insertion_point(field_set:google.type.TimeOfDay.nanos)
}

inline const TimeOfDay* TimeOfDay::internal_default_instance() {
  return &TimeOfDay_default_instance_.get();
}
#endif  // !PROTOBUF_INLINE_NOT_IN_HEADERS

// @@protoc_insertion_point(namespace_scope)

}  // namespace type
}  // namespace google

// @@protoc_insertion_point(global_scope)

#endif  // PROTOBUF_google_2ftype_2ftimeofday_2eproto__INCLUDED
