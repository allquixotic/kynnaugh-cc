// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: google/api/documentation.proto

#ifndef PROTOBUF_google_2fapi_2fdocumentation_2eproto__INCLUDED
#define PROTOBUF_google_2fapi_2fdocumentation_2eproto__INCLUDED

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
namespace api {

// Internal implementation detail -- do not call these.
void protobuf_AddDesc_google_2fapi_2fdocumentation_2eproto();
void protobuf_InitDefaults_google_2fapi_2fdocumentation_2eproto();
void protobuf_AssignDesc_google_2fapi_2fdocumentation_2eproto();
void protobuf_ShutdownFile_google_2fapi_2fdocumentation_2eproto();

class Documentation;
class DocumentationRule;
class Page;

// ===================================================================

class Documentation : public ::google::protobuf::Message /* @@protoc_insertion_point(class_definition:google.api.Documentation) */ {
 public:
  Documentation();
  virtual ~Documentation();

  Documentation(const Documentation& from);

  inline Documentation& operator=(const Documentation& from) {
    CopyFrom(from);
    return *this;
  }

  static const ::google::protobuf::Descriptor* descriptor();
  static const Documentation& default_instance();

  static const Documentation* internal_default_instance();

  void Swap(Documentation* other);

  // implements Message ----------------------------------------------

  inline Documentation* New() const { return New(NULL); }

  Documentation* New(::google::protobuf::Arena* arena) const;
  void CopyFrom(const ::google::protobuf::Message& from);
  void MergeFrom(const ::google::protobuf::Message& from);
  void CopyFrom(const Documentation& from);
  void MergeFrom(const Documentation& from);
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
  void InternalSwap(Documentation* other);
  void UnsafeMergeFrom(const Documentation& from);
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

  // optional string summary = 1;
  void clear_summary();
  static const int kSummaryFieldNumber = 1;
  const ::std::string& summary() const;
  void set_summary(const ::std::string& value);
  void set_summary(const char* value);
  void set_summary(const char* value, size_t size);
  ::std::string* mutable_summary();
  ::std::string* release_summary();
  void set_allocated_summary(::std::string* summary);

  // repeated .google.api.Page pages = 5;
  int pages_size() const;
  void clear_pages();
  static const int kPagesFieldNumber = 5;
  const ::google::api::Page& pages(int index) const;
  ::google::api::Page* mutable_pages(int index);
  ::google::api::Page* add_pages();
  ::google::protobuf::RepeatedPtrField< ::google::api::Page >*
      mutable_pages();
  const ::google::protobuf::RepeatedPtrField< ::google::api::Page >&
      pages() const;

  // repeated .google.api.DocumentationRule rules = 3;
  int rules_size() const;
  void clear_rules();
  static const int kRulesFieldNumber = 3;
  const ::google::api::DocumentationRule& rules(int index) const;
  ::google::api::DocumentationRule* mutable_rules(int index);
  ::google::api::DocumentationRule* add_rules();
  ::google::protobuf::RepeatedPtrField< ::google::api::DocumentationRule >*
      mutable_rules();
  const ::google::protobuf::RepeatedPtrField< ::google::api::DocumentationRule >&
      rules() const;

  // optional string documentation_root_url = 4;
  void clear_documentation_root_url();
  static const int kDocumentationRootUrlFieldNumber = 4;
  const ::std::string& documentation_root_url() const;
  void set_documentation_root_url(const ::std::string& value);
  void set_documentation_root_url(const char* value);
  void set_documentation_root_url(const char* value, size_t size);
  ::std::string* mutable_documentation_root_url();
  ::std::string* release_documentation_root_url();
  void set_allocated_documentation_root_url(::std::string* documentation_root_url);

  // optional string overview = 2;
  void clear_overview();
  static const int kOverviewFieldNumber = 2;
  const ::std::string& overview() const;
  void set_overview(const ::std::string& value);
  void set_overview(const char* value);
  void set_overview(const char* value, size_t size);
  ::std::string* mutable_overview();
  ::std::string* release_overview();
  void set_allocated_overview(::std::string* overview);

  // @@protoc_insertion_point(class_scope:google.api.Documentation)
 private:

  ::google::protobuf::internal::InternalMetadataWithArena _internal_metadata_;
  ::google::protobuf::RepeatedPtrField< ::google::api::Page > pages_;
  ::google::protobuf::RepeatedPtrField< ::google::api::DocumentationRule > rules_;
  ::google::protobuf::internal::ArenaStringPtr summary_;
  ::google::protobuf::internal::ArenaStringPtr documentation_root_url_;
  ::google::protobuf::internal::ArenaStringPtr overview_;
  mutable int _cached_size_;
  friend void  protobuf_InitDefaults_google_2fapi_2fdocumentation_2eproto_impl();
  friend void  protobuf_AddDesc_google_2fapi_2fdocumentation_2eproto_impl();
  friend void protobuf_AssignDesc_google_2fapi_2fdocumentation_2eproto();
  friend void protobuf_ShutdownFile_google_2fapi_2fdocumentation_2eproto();

  void InitAsDefaultInstance();
};
extern ::google::protobuf::internal::ExplicitlyConstructed<Documentation> Documentation_default_instance_;

// -------------------------------------------------------------------

class DocumentationRule : public ::google::protobuf::Message /* @@protoc_insertion_point(class_definition:google.api.DocumentationRule) */ {
 public:
  DocumentationRule();
  virtual ~DocumentationRule();

  DocumentationRule(const DocumentationRule& from);

  inline DocumentationRule& operator=(const DocumentationRule& from) {
    CopyFrom(from);
    return *this;
  }

  static const ::google::protobuf::Descriptor* descriptor();
  static const DocumentationRule& default_instance();

  static const DocumentationRule* internal_default_instance();

  void Swap(DocumentationRule* other);

  // implements Message ----------------------------------------------

  inline DocumentationRule* New() const { return New(NULL); }

  DocumentationRule* New(::google::protobuf::Arena* arena) const;
  void CopyFrom(const ::google::protobuf::Message& from);
  void MergeFrom(const ::google::protobuf::Message& from);
  void CopyFrom(const DocumentationRule& from);
  void MergeFrom(const DocumentationRule& from);
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
  void InternalSwap(DocumentationRule* other);
  void UnsafeMergeFrom(const DocumentationRule& from);
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

  // optional string selector = 1;
  void clear_selector();
  static const int kSelectorFieldNumber = 1;
  const ::std::string& selector() const;
  void set_selector(const ::std::string& value);
  void set_selector(const char* value);
  void set_selector(const char* value, size_t size);
  ::std::string* mutable_selector();
  ::std::string* release_selector();
  void set_allocated_selector(::std::string* selector);

  // optional string description = 2;
  void clear_description();
  static const int kDescriptionFieldNumber = 2;
  const ::std::string& description() const;
  void set_description(const ::std::string& value);
  void set_description(const char* value);
  void set_description(const char* value, size_t size);
  ::std::string* mutable_description();
  ::std::string* release_description();
  void set_allocated_description(::std::string* description);

  // optional string deprecation_description = 3;
  void clear_deprecation_description();
  static const int kDeprecationDescriptionFieldNumber = 3;
  const ::std::string& deprecation_description() const;
  void set_deprecation_description(const ::std::string& value);
  void set_deprecation_description(const char* value);
  void set_deprecation_description(const char* value, size_t size);
  ::std::string* mutable_deprecation_description();
  ::std::string* release_deprecation_description();
  void set_allocated_deprecation_description(::std::string* deprecation_description);

  // @@protoc_insertion_point(class_scope:google.api.DocumentationRule)
 private:

  ::google::protobuf::internal::InternalMetadataWithArena _internal_metadata_;
  ::google::protobuf::internal::ArenaStringPtr selector_;
  ::google::protobuf::internal::ArenaStringPtr description_;
  ::google::protobuf::internal::ArenaStringPtr deprecation_description_;
  mutable int _cached_size_;
  friend void  protobuf_InitDefaults_google_2fapi_2fdocumentation_2eproto_impl();
  friend void  protobuf_AddDesc_google_2fapi_2fdocumentation_2eproto_impl();
  friend void protobuf_AssignDesc_google_2fapi_2fdocumentation_2eproto();
  friend void protobuf_ShutdownFile_google_2fapi_2fdocumentation_2eproto();

  void InitAsDefaultInstance();
};
extern ::google::protobuf::internal::ExplicitlyConstructed<DocumentationRule> DocumentationRule_default_instance_;

// -------------------------------------------------------------------

class Page : public ::google::protobuf::Message /* @@protoc_insertion_point(class_definition:google.api.Page) */ {
 public:
  Page();
  virtual ~Page();

  Page(const Page& from);

  inline Page& operator=(const Page& from) {
    CopyFrom(from);
    return *this;
  }

  static const ::google::protobuf::Descriptor* descriptor();
  static const Page& default_instance();

  static const Page* internal_default_instance();

  void Swap(Page* other);

  // implements Message ----------------------------------------------

  inline Page* New() const { return New(NULL); }

  Page* New(::google::protobuf::Arena* arena) const;
  void CopyFrom(const ::google::protobuf::Message& from);
  void MergeFrom(const ::google::protobuf::Message& from);
  void CopyFrom(const Page& from);
  void MergeFrom(const Page& from);
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
  void InternalSwap(Page* other);
  void UnsafeMergeFrom(const Page& from);
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

  // optional string name = 1;
  void clear_name();
  static const int kNameFieldNumber = 1;
  const ::std::string& name() const;
  void set_name(const ::std::string& value);
  void set_name(const char* value);
  void set_name(const char* value, size_t size);
  ::std::string* mutable_name();
  ::std::string* release_name();
  void set_allocated_name(::std::string* name);

  // optional string content = 2;
  void clear_content();
  static const int kContentFieldNumber = 2;
  const ::std::string& content() const;
  void set_content(const ::std::string& value);
  void set_content(const char* value);
  void set_content(const char* value, size_t size);
  ::std::string* mutable_content();
  ::std::string* release_content();
  void set_allocated_content(::std::string* content);

  // repeated .google.api.Page subpages = 3;
  int subpages_size() const;
  void clear_subpages();
  static const int kSubpagesFieldNumber = 3;
  const ::google::api::Page& subpages(int index) const;
  ::google::api::Page* mutable_subpages(int index);
  ::google::api::Page* add_subpages();
  ::google::protobuf::RepeatedPtrField< ::google::api::Page >*
      mutable_subpages();
  const ::google::protobuf::RepeatedPtrField< ::google::api::Page >&
      subpages() const;

  // @@protoc_insertion_point(class_scope:google.api.Page)
 private:

  ::google::protobuf::internal::InternalMetadataWithArena _internal_metadata_;
  ::google::protobuf::RepeatedPtrField< ::google::api::Page > subpages_;
  ::google::protobuf::internal::ArenaStringPtr name_;
  ::google::protobuf::internal::ArenaStringPtr content_;
  mutable int _cached_size_;
  friend void  protobuf_InitDefaults_google_2fapi_2fdocumentation_2eproto_impl();
  friend void  protobuf_AddDesc_google_2fapi_2fdocumentation_2eproto_impl();
  friend void protobuf_AssignDesc_google_2fapi_2fdocumentation_2eproto();
  friend void protobuf_ShutdownFile_google_2fapi_2fdocumentation_2eproto();

  void InitAsDefaultInstance();
};
extern ::google::protobuf::internal::ExplicitlyConstructed<Page> Page_default_instance_;

// ===================================================================


// ===================================================================

#if !PROTOBUF_INLINE_NOT_IN_HEADERS
// Documentation

// optional string summary = 1;
inline void Documentation::clear_summary() {
  summary_.ClearToEmptyNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline const ::std::string& Documentation::summary() const {
  // @@protoc_insertion_point(field_get:google.api.Documentation.summary)
  return summary_.GetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline void Documentation::set_summary(const ::std::string& value) {
  
  summary_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), value);
  // @@protoc_insertion_point(field_set:google.api.Documentation.summary)
}
inline void Documentation::set_summary(const char* value) {
  
  summary_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), ::std::string(value));
  // @@protoc_insertion_point(field_set_char:google.api.Documentation.summary)
}
inline void Documentation::set_summary(const char* value, size_t size) {
  
  summary_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(),
      ::std::string(reinterpret_cast<const char*>(value), size));
  // @@protoc_insertion_point(field_set_pointer:google.api.Documentation.summary)
}
inline ::std::string* Documentation::mutable_summary() {
  
  // @@protoc_insertion_point(field_mutable:google.api.Documentation.summary)
  return summary_.MutableNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline ::std::string* Documentation::release_summary() {
  // @@protoc_insertion_point(field_release:google.api.Documentation.summary)
  
  return summary_.ReleaseNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline void Documentation::set_allocated_summary(::std::string* summary) {
  if (summary != NULL) {
    
  } else {
    
  }
  summary_.SetAllocatedNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), summary);
  // @@protoc_insertion_point(field_set_allocated:google.api.Documentation.summary)
}

// repeated .google.api.Page pages = 5;
inline int Documentation::pages_size() const {
  return pages_.size();
}
inline void Documentation::clear_pages() {
  pages_.Clear();
}
inline const ::google::api::Page& Documentation::pages(int index) const {
  // @@protoc_insertion_point(field_get:google.api.Documentation.pages)
  return pages_.Get(index);
}
inline ::google::api::Page* Documentation::mutable_pages(int index) {
  // @@protoc_insertion_point(field_mutable:google.api.Documentation.pages)
  return pages_.Mutable(index);
}
inline ::google::api::Page* Documentation::add_pages() {
  // @@protoc_insertion_point(field_add:google.api.Documentation.pages)
  return pages_.Add();
}
inline ::google::protobuf::RepeatedPtrField< ::google::api::Page >*
Documentation::mutable_pages() {
  // @@protoc_insertion_point(field_mutable_list:google.api.Documentation.pages)
  return &pages_;
}
inline const ::google::protobuf::RepeatedPtrField< ::google::api::Page >&
Documentation::pages() const {
  // @@protoc_insertion_point(field_list:google.api.Documentation.pages)
  return pages_;
}

// repeated .google.api.DocumentationRule rules = 3;
inline int Documentation::rules_size() const {
  return rules_.size();
}
inline void Documentation::clear_rules() {
  rules_.Clear();
}
inline const ::google::api::DocumentationRule& Documentation::rules(int index) const {
  // @@protoc_insertion_point(field_get:google.api.Documentation.rules)
  return rules_.Get(index);
}
inline ::google::api::DocumentationRule* Documentation::mutable_rules(int index) {
  // @@protoc_insertion_point(field_mutable:google.api.Documentation.rules)
  return rules_.Mutable(index);
}
inline ::google::api::DocumentationRule* Documentation::add_rules() {
  // @@protoc_insertion_point(field_add:google.api.Documentation.rules)
  return rules_.Add();
}
inline ::google::protobuf::RepeatedPtrField< ::google::api::DocumentationRule >*
Documentation::mutable_rules() {
  // @@protoc_insertion_point(field_mutable_list:google.api.Documentation.rules)
  return &rules_;
}
inline const ::google::protobuf::RepeatedPtrField< ::google::api::DocumentationRule >&
Documentation::rules() const {
  // @@protoc_insertion_point(field_list:google.api.Documentation.rules)
  return rules_;
}

// optional string documentation_root_url = 4;
inline void Documentation::clear_documentation_root_url() {
  documentation_root_url_.ClearToEmptyNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline const ::std::string& Documentation::documentation_root_url() const {
  // @@protoc_insertion_point(field_get:google.api.Documentation.documentation_root_url)
  return documentation_root_url_.GetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline void Documentation::set_documentation_root_url(const ::std::string& value) {
  
  documentation_root_url_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), value);
  // @@protoc_insertion_point(field_set:google.api.Documentation.documentation_root_url)
}
inline void Documentation::set_documentation_root_url(const char* value) {
  
  documentation_root_url_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), ::std::string(value));
  // @@protoc_insertion_point(field_set_char:google.api.Documentation.documentation_root_url)
}
inline void Documentation::set_documentation_root_url(const char* value, size_t size) {
  
  documentation_root_url_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(),
      ::std::string(reinterpret_cast<const char*>(value), size));
  // @@protoc_insertion_point(field_set_pointer:google.api.Documentation.documentation_root_url)
}
inline ::std::string* Documentation::mutable_documentation_root_url() {
  
  // @@protoc_insertion_point(field_mutable:google.api.Documentation.documentation_root_url)
  return documentation_root_url_.MutableNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline ::std::string* Documentation::release_documentation_root_url() {
  // @@protoc_insertion_point(field_release:google.api.Documentation.documentation_root_url)
  
  return documentation_root_url_.ReleaseNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline void Documentation::set_allocated_documentation_root_url(::std::string* documentation_root_url) {
  if (documentation_root_url != NULL) {
    
  } else {
    
  }
  documentation_root_url_.SetAllocatedNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), documentation_root_url);
  // @@protoc_insertion_point(field_set_allocated:google.api.Documentation.documentation_root_url)
}

// optional string overview = 2;
inline void Documentation::clear_overview() {
  overview_.ClearToEmptyNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline const ::std::string& Documentation::overview() const {
  // @@protoc_insertion_point(field_get:google.api.Documentation.overview)
  return overview_.GetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline void Documentation::set_overview(const ::std::string& value) {
  
  overview_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), value);
  // @@protoc_insertion_point(field_set:google.api.Documentation.overview)
}
inline void Documentation::set_overview(const char* value) {
  
  overview_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), ::std::string(value));
  // @@protoc_insertion_point(field_set_char:google.api.Documentation.overview)
}
inline void Documentation::set_overview(const char* value, size_t size) {
  
  overview_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(),
      ::std::string(reinterpret_cast<const char*>(value), size));
  // @@protoc_insertion_point(field_set_pointer:google.api.Documentation.overview)
}
inline ::std::string* Documentation::mutable_overview() {
  
  // @@protoc_insertion_point(field_mutable:google.api.Documentation.overview)
  return overview_.MutableNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline ::std::string* Documentation::release_overview() {
  // @@protoc_insertion_point(field_release:google.api.Documentation.overview)
  
  return overview_.ReleaseNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline void Documentation::set_allocated_overview(::std::string* overview) {
  if (overview != NULL) {
    
  } else {
    
  }
  overview_.SetAllocatedNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), overview);
  // @@protoc_insertion_point(field_set_allocated:google.api.Documentation.overview)
}

inline const Documentation* Documentation::internal_default_instance() {
  return &Documentation_default_instance_.get();
}
// -------------------------------------------------------------------

// DocumentationRule

// optional string selector = 1;
inline void DocumentationRule::clear_selector() {
  selector_.ClearToEmptyNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline const ::std::string& DocumentationRule::selector() const {
  // @@protoc_insertion_point(field_get:google.api.DocumentationRule.selector)
  return selector_.GetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline void DocumentationRule::set_selector(const ::std::string& value) {
  
  selector_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), value);
  // @@protoc_insertion_point(field_set:google.api.DocumentationRule.selector)
}
inline void DocumentationRule::set_selector(const char* value) {
  
  selector_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), ::std::string(value));
  // @@protoc_insertion_point(field_set_char:google.api.DocumentationRule.selector)
}
inline void DocumentationRule::set_selector(const char* value, size_t size) {
  
  selector_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(),
      ::std::string(reinterpret_cast<const char*>(value), size));
  // @@protoc_insertion_point(field_set_pointer:google.api.DocumentationRule.selector)
}
inline ::std::string* DocumentationRule::mutable_selector() {
  
  // @@protoc_insertion_point(field_mutable:google.api.DocumentationRule.selector)
  return selector_.MutableNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline ::std::string* DocumentationRule::release_selector() {
  // @@protoc_insertion_point(field_release:google.api.DocumentationRule.selector)
  
  return selector_.ReleaseNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline void DocumentationRule::set_allocated_selector(::std::string* selector) {
  if (selector != NULL) {
    
  } else {
    
  }
  selector_.SetAllocatedNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), selector);
  // @@protoc_insertion_point(field_set_allocated:google.api.DocumentationRule.selector)
}

// optional string description = 2;
inline void DocumentationRule::clear_description() {
  description_.ClearToEmptyNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline const ::std::string& DocumentationRule::description() const {
  // @@protoc_insertion_point(field_get:google.api.DocumentationRule.description)
  return description_.GetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline void DocumentationRule::set_description(const ::std::string& value) {
  
  description_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), value);
  // @@protoc_insertion_point(field_set:google.api.DocumentationRule.description)
}
inline void DocumentationRule::set_description(const char* value) {
  
  description_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), ::std::string(value));
  // @@protoc_insertion_point(field_set_char:google.api.DocumentationRule.description)
}
inline void DocumentationRule::set_description(const char* value, size_t size) {
  
  description_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(),
      ::std::string(reinterpret_cast<const char*>(value), size));
  // @@protoc_insertion_point(field_set_pointer:google.api.DocumentationRule.description)
}
inline ::std::string* DocumentationRule::mutable_description() {
  
  // @@protoc_insertion_point(field_mutable:google.api.DocumentationRule.description)
  return description_.MutableNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline ::std::string* DocumentationRule::release_description() {
  // @@protoc_insertion_point(field_release:google.api.DocumentationRule.description)
  
  return description_.ReleaseNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline void DocumentationRule::set_allocated_description(::std::string* description) {
  if (description != NULL) {
    
  } else {
    
  }
  description_.SetAllocatedNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), description);
  // @@protoc_insertion_point(field_set_allocated:google.api.DocumentationRule.description)
}

// optional string deprecation_description = 3;
inline void DocumentationRule::clear_deprecation_description() {
  deprecation_description_.ClearToEmptyNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline const ::std::string& DocumentationRule::deprecation_description() const {
  // @@protoc_insertion_point(field_get:google.api.DocumentationRule.deprecation_description)
  return deprecation_description_.GetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline void DocumentationRule::set_deprecation_description(const ::std::string& value) {
  
  deprecation_description_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), value);
  // @@protoc_insertion_point(field_set:google.api.DocumentationRule.deprecation_description)
}
inline void DocumentationRule::set_deprecation_description(const char* value) {
  
  deprecation_description_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), ::std::string(value));
  // @@protoc_insertion_point(field_set_char:google.api.DocumentationRule.deprecation_description)
}
inline void DocumentationRule::set_deprecation_description(const char* value, size_t size) {
  
  deprecation_description_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(),
      ::std::string(reinterpret_cast<const char*>(value), size));
  // @@protoc_insertion_point(field_set_pointer:google.api.DocumentationRule.deprecation_description)
}
inline ::std::string* DocumentationRule::mutable_deprecation_description() {
  
  // @@protoc_insertion_point(field_mutable:google.api.DocumentationRule.deprecation_description)
  return deprecation_description_.MutableNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline ::std::string* DocumentationRule::release_deprecation_description() {
  // @@protoc_insertion_point(field_release:google.api.DocumentationRule.deprecation_description)
  
  return deprecation_description_.ReleaseNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline void DocumentationRule::set_allocated_deprecation_description(::std::string* deprecation_description) {
  if (deprecation_description != NULL) {
    
  } else {
    
  }
  deprecation_description_.SetAllocatedNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), deprecation_description);
  // @@protoc_insertion_point(field_set_allocated:google.api.DocumentationRule.deprecation_description)
}

inline const DocumentationRule* DocumentationRule::internal_default_instance() {
  return &DocumentationRule_default_instance_.get();
}
// -------------------------------------------------------------------

// Page

// optional string name = 1;
inline void Page::clear_name() {
  name_.ClearToEmptyNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline const ::std::string& Page::name() const {
  // @@protoc_insertion_point(field_get:google.api.Page.name)
  return name_.GetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline void Page::set_name(const ::std::string& value) {
  
  name_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), value);
  // @@protoc_insertion_point(field_set:google.api.Page.name)
}
inline void Page::set_name(const char* value) {
  
  name_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), ::std::string(value));
  // @@protoc_insertion_point(field_set_char:google.api.Page.name)
}
inline void Page::set_name(const char* value, size_t size) {
  
  name_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(),
      ::std::string(reinterpret_cast<const char*>(value), size));
  // @@protoc_insertion_point(field_set_pointer:google.api.Page.name)
}
inline ::std::string* Page::mutable_name() {
  
  // @@protoc_insertion_point(field_mutable:google.api.Page.name)
  return name_.MutableNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline ::std::string* Page::release_name() {
  // @@protoc_insertion_point(field_release:google.api.Page.name)
  
  return name_.ReleaseNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline void Page::set_allocated_name(::std::string* name) {
  if (name != NULL) {
    
  } else {
    
  }
  name_.SetAllocatedNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), name);
  // @@protoc_insertion_point(field_set_allocated:google.api.Page.name)
}

// optional string content = 2;
inline void Page::clear_content() {
  content_.ClearToEmptyNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline const ::std::string& Page::content() const {
  // @@protoc_insertion_point(field_get:google.api.Page.content)
  return content_.GetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline void Page::set_content(const ::std::string& value) {
  
  content_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), value);
  // @@protoc_insertion_point(field_set:google.api.Page.content)
}
inline void Page::set_content(const char* value) {
  
  content_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), ::std::string(value));
  // @@protoc_insertion_point(field_set_char:google.api.Page.content)
}
inline void Page::set_content(const char* value, size_t size) {
  
  content_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(),
      ::std::string(reinterpret_cast<const char*>(value), size));
  // @@protoc_insertion_point(field_set_pointer:google.api.Page.content)
}
inline ::std::string* Page::mutable_content() {
  
  // @@protoc_insertion_point(field_mutable:google.api.Page.content)
  return content_.MutableNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline ::std::string* Page::release_content() {
  // @@protoc_insertion_point(field_release:google.api.Page.content)
  
  return content_.ReleaseNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline void Page::set_allocated_content(::std::string* content) {
  if (content != NULL) {
    
  } else {
    
  }
  content_.SetAllocatedNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), content);
  // @@protoc_insertion_point(field_set_allocated:google.api.Page.content)
}

// repeated .google.api.Page subpages = 3;
inline int Page::subpages_size() const {
  return subpages_.size();
}
inline void Page::clear_subpages() {
  subpages_.Clear();
}
inline const ::google::api::Page& Page::subpages(int index) const {
  // @@protoc_insertion_point(field_get:google.api.Page.subpages)
  return subpages_.Get(index);
}
inline ::google::api::Page* Page::mutable_subpages(int index) {
  // @@protoc_insertion_point(field_mutable:google.api.Page.subpages)
  return subpages_.Mutable(index);
}
inline ::google::api::Page* Page::add_subpages() {
  // @@protoc_insertion_point(field_add:google.api.Page.subpages)
  return subpages_.Add();
}
inline ::google::protobuf::RepeatedPtrField< ::google::api::Page >*
Page::mutable_subpages() {
  // @@protoc_insertion_point(field_mutable_list:google.api.Page.subpages)
  return &subpages_;
}
inline const ::google::protobuf::RepeatedPtrField< ::google::api::Page >&
Page::subpages() const {
  // @@protoc_insertion_point(field_list:google.api.Page.subpages)
  return subpages_;
}

inline const Page* Page::internal_default_instance() {
  return &Page_default_instance_.get();
}
#endif  // !PROTOBUF_INLINE_NOT_IN_HEADERS
// -------------------------------------------------------------------

// -------------------------------------------------------------------


// @@protoc_insertion_point(namespace_scope)

}  // namespace api
}  // namespace google

// @@protoc_insertion_point(global_scope)

#endif  // PROTOBUF_google_2fapi_2fdocumentation_2eproto__INCLUDED
