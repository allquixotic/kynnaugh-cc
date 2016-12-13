// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: google/genomics/v1/range.proto

#ifndef PROTOBUF_google_2fgenomics_2fv1_2frange_2eproto__INCLUDED
#define PROTOBUF_google_2fgenomics_2fv1_2frange_2eproto__INCLUDED

#include <string>

#include <google/protobuf/stubs/common.h>

#if GOOGLE_PROTOBUF_VERSION < 3000000
#error This file was generated by a newer version of protoc which is
#error incompatible with your Protocol Buffer headers.  Please update
#error your headers.
#endif
#if 3000000 < GOOGLE_PROTOBUF_MIN_PROTOC_VERSION
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
#include "google/api/annotations.pb.h"
// @@protoc_insertion_point(includes)

namespace google {
namespace genomics {
namespace v1 {

// Internal implementation detail -- do not call these.
void protobuf_AddDesc_google_2fgenomics_2fv1_2frange_2eproto();
void protobuf_AssignDesc_google_2fgenomics_2fv1_2frange_2eproto();
void protobuf_ShutdownFile_google_2fgenomics_2fv1_2frange_2eproto();

class Range;

// ===================================================================

class Range : public ::google::protobuf::Message /* @@protoc_insertion_point(class_definition:google.genomics.v1.Range) */ {
 public:
  Range();
  virtual ~Range();

  Range(const Range& from);

  inline Range& operator=(const Range& from) {
    CopyFrom(from);
    return *this;
  }

  inline ::google::protobuf::Arena* GetArena() const { return GetArenaNoVirtual(); }
  inline void* GetMaybeArenaPointer() const {
    return MaybeArenaPtr();
  }
  static const ::google::protobuf::Descriptor* descriptor();
  static const Range& default_instance();

  void UnsafeArenaSwap(Range* other);
  void Swap(Range* other);

  // implements Message ----------------------------------------------

  inline Range* New() const { return New(NULL); }

  Range* New(::google::protobuf::Arena* arena) const;
  void CopyFrom(const ::google::protobuf::Message& from);
  void MergeFrom(const ::google::protobuf::Message& from);
  void CopyFrom(const Range& from);
  void MergeFrom(const Range& from);
  void Clear();
  bool IsInitialized() const;

  int ByteSize() const;
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
  void InternalSwap(Range* other);
  protected:
  explicit Range(::google::protobuf::Arena* arena);
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

  // accessors -------------------------------------------------------

  // optional string reference_name = 1;
  void clear_reference_name();
  static const int kReferenceNameFieldNumber = 1;
  const ::std::string& reference_name() const;
  void set_reference_name(const ::std::string& value);
  void set_reference_name(const char* value);
  void set_reference_name(const char* value, size_t size);
  ::std::string* mutable_reference_name();
  ::std::string* release_reference_name();
  void set_allocated_reference_name(::std::string* reference_name);
  ::std::string* unsafe_arena_release_reference_name();
  void unsafe_arena_set_allocated_reference_name(
      ::std::string* reference_name);

  // optional int64 start = 2;
  void clear_start();
  static const int kStartFieldNumber = 2;
  ::google::protobuf::int64 start() const;
  void set_start(::google::protobuf::int64 value);

  // optional int64 end = 3;
  void clear_end();
  static const int kEndFieldNumber = 3;
  ::google::protobuf::int64 end() const;
  void set_end(::google::protobuf::int64 value);

  // @@protoc_insertion_point(class_scope:google.genomics.v1.Range)
 private:

  ::google::protobuf::internal::InternalMetadataWithArena _internal_metadata_;
  friend class ::google::protobuf::Arena;
  typedef void InternalArenaConstructable_;
  typedef void DestructorSkippable_;
  bool _is_default_instance_;
  ::google::protobuf::internal::ArenaStringPtr reference_name_;
  ::google::protobuf::int64 start_;
  ::google::protobuf::int64 end_;
  mutable int _cached_size_;
  friend void  protobuf_AddDesc_google_2fgenomics_2fv1_2frange_2eproto();
  friend void protobuf_AssignDesc_google_2fgenomics_2fv1_2frange_2eproto();
  friend void protobuf_ShutdownFile_google_2fgenomics_2fv1_2frange_2eproto();

  void InitAsDefaultInstance();
  static Range* default_instance_;
};
// ===================================================================


// ===================================================================

#if !PROTOBUF_INLINE_NOT_IN_HEADERS
// Range

// optional string reference_name = 1;
inline void Range::clear_reference_name() {
  reference_name_.ClearToEmpty(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), GetArenaNoVirtual());
}
inline const ::std::string& Range::reference_name() const {
  // @@protoc_insertion_point(field_get:google.genomics.v1.Range.reference_name)
  return reference_name_.Get(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline void Range::set_reference_name(const ::std::string& value) {
  
  reference_name_.Set(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), value, GetArenaNoVirtual());
  // @@protoc_insertion_point(field_set:google.genomics.v1.Range.reference_name)
}
inline void Range::set_reference_name(const char* value) {
  
  reference_name_.Set(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), ::std::string(value),
              GetArenaNoVirtual());
  // @@protoc_insertion_point(field_set_char:google.genomics.v1.Range.reference_name)
}
inline void Range::set_reference_name(const char* value,
    size_t size) {
  
  reference_name_.Set(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), ::std::string(
      reinterpret_cast<const char*>(value), size), GetArenaNoVirtual());
  // @@protoc_insertion_point(field_set_pointer:google.genomics.v1.Range.reference_name)
}
inline ::std::string* Range::mutable_reference_name() {
  
  // @@protoc_insertion_point(field_mutable:google.genomics.v1.Range.reference_name)
  return reference_name_.Mutable(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), GetArenaNoVirtual());
}
inline ::std::string* Range::release_reference_name() {
  // @@protoc_insertion_point(field_release:google.genomics.v1.Range.reference_name)
  
  return reference_name_.Release(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), GetArenaNoVirtual());
}
inline ::std::string* Range::unsafe_arena_release_reference_name() {
  // @@protoc_insertion_point(field_unsafe_arena_release:google.genomics.v1.Range.reference_name)
  GOOGLE_DCHECK(GetArenaNoVirtual() != NULL);
  
  return reference_name_.UnsafeArenaRelease(&::google::protobuf::internal::GetEmptyStringAlreadyInited(),
      GetArenaNoVirtual());
}
inline void Range::set_allocated_reference_name(::std::string* reference_name) {
  if (reference_name != NULL) {
    
  } else {
    
  }
  reference_name_.SetAllocated(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), reference_name,
      GetArenaNoVirtual());
  // @@protoc_insertion_point(field_set_allocated:google.genomics.v1.Range.reference_name)
}
inline void Range::unsafe_arena_set_allocated_reference_name(
    ::std::string* reference_name) {
  GOOGLE_DCHECK(GetArenaNoVirtual() != NULL);
  if (reference_name != NULL) {
    
  } else {
    
  }
  reference_name_.UnsafeArenaSetAllocated(&::google::protobuf::internal::GetEmptyStringAlreadyInited(),
      reference_name, GetArenaNoVirtual());
  // @@protoc_insertion_point(field_unsafe_arena_set_allocated:google.genomics.v1.Range.reference_name)
}

// optional int64 start = 2;
inline void Range::clear_start() {
  start_ = GOOGLE_LONGLONG(0);
}
inline ::google::protobuf::int64 Range::start() const {
  // @@protoc_insertion_point(field_get:google.genomics.v1.Range.start)
  return start_;
}
inline void Range::set_start(::google::protobuf::int64 value) {
  
  start_ = value;
  // @@protoc_insertion_point(field_set:google.genomics.v1.Range.start)
}

// optional int64 end = 3;
inline void Range::clear_end() {
  end_ = GOOGLE_LONGLONG(0);
}
inline ::google::protobuf::int64 Range::end() const {
  // @@protoc_insertion_point(field_get:google.genomics.v1.Range.end)
  return end_;
}
inline void Range::set_end(::google::protobuf::int64 value) {
  
  end_ = value;
  // @@protoc_insertion_point(field_set:google.genomics.v1.Range.end)
}

#endif  // !PROTOBUF_INLINE_NOT_IN_HEADERS

// @@protoc_insertion_point(namespace_scope)

}  // namespace v1
}  // namespace genomics
}  // namespace google

// @@protoc_insertion_point(global_scope)

#endif  // PROTOBUF_google_2fgenomics_2fv1_2frange_2eproto__INCLUDED