// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: 21014_S2CRoomKickedRsp.proto

#define INTERNAL_SUPPRESS_PROTOBUF_FIELD_DEPRECATION
#include "21014_S2CRoomKickedRsp.pb.h"

#include <algorithm>

#include <google/protobuf/stubs/common.h>
#include <google/protobuf/stubs/once.h>
#include <google/protobuf/io/coded_stream.h>
#include <google/protobuf/wire_format_lite_inl.h>
#include <google/protobuf/descriptor.h>
#include <google/protobuf/generated_message_reflection.h>
#include <google/protobuf/reflection_ops.h>
#include <google/protobuf/wire_format.h>
// @@protoc_insertion_point(includes)

namespace Protocol {

namespace {

const ::google::protobuf::Descriptor* S2CRoomKickedRsp_descriptor_ = NULL;
const ::google::protobuf::internal::GeneratedMessageReflection*
  S2CRoomKickedRsp_reflection_ = NULL;

}  // namespace


void protobuf_AssignDesc_21014_5fS2CRoomKickedRsp_2eproto() {
  protobuf_AddDesc_21014_5fS2CRoomKickedRsp_2eproto();
  const ::google::protobuf::FileDescriptor* file =
    ::google::protobuf::DescriptorPool::generated_pool()->FindFileByName(
      "21014_S2CRoomKickedRsp.proto");
  GOOGLE_CHECK(file != NULL);
  S2CRoomKickedRsp_descriptor_ = file->message_type(0);
  static const int S2CRoomKickedRsp_offsets_[1] = {
  };
  S2CRoomKickedRsp_reflection_ =
    new ::google::protobuf::internal::GeneratedMessageReflection(
      S2CRoomKickedRsp_descriptor_,
      S2CRoomKickedRsp::default_instance_,
      S2CRoomKickedRsp_offsets_,
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(S2CRoomKickedRsp, _has_bits_[0]),
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(S2CRoomKickedRsp, _unknown_fields_),
      -1,
      ::google::protobuf::DescriptorPool::generated_pool(),
      ::google::protobuf::MessageFactory::generated_factory(),
      sizeof(S2CRoomKickedRsp));
}

namespace {

GOOGLE_PROTOBUF_DECLARE_ONCE(protobuf_AssignDescriptors_once_);
inline void protobuf_AssignDescriptorsOnce() {
  ::google::protobuf::GoogleOnceInit(&protobuf_AssignDescriptors_once_,
                 &protobuf_AssignDesc_21014_5fS2CRoomKickedRsp_2eproto);
}

void protobuf_RegisterTypes(const ::std::string&) {
  protobuf_AssignDescriptorsOnce();
  ::google::protobuf::MessageFactory::InternalRegisterGeneratedMessage(
    S2CRoomKickedRsp_descriptor_, &S2CRoomKickedRsp::default_instance());
}

}  // namespace

void protobuf_ShutdownFile_21014_5fS2CRoomKickedRsp_2eproto() {
  delete S2CRoomKickedRsp::default_instance_;
  delete S2CRoomKickedRsp_reflection_;
}

void protobuf_AddDesc_21014_5fS2CRoomKickedRsp_2eproto() {
  static bool already_here = false;
  if (already_here) return;
  already_here = true;
  GOOGLE_PROTOBUF_VERIFY_VERSION;

  ::google::protobuf::DescriptorPool::InternalAddGeneratedFile(
    "\n\03421014_S2CRoomKickedRsp.proto\022\010Protocol"
    "\"\022\n\020S2CRoomKickedRsp", 60);
  ::google::protobuf::MessageFactory::InternalRegisterGeneratedFile(
    "21014_S2CRoomKickedRsp.proto", &protobuf_RegisterTypes);
  S2CRoomKickedRsp::default_instance_ = new S2CRoomKickedRsp();
  S2CRoomKickedRsp::default_instance_->InitAsDefaultInstance();
  ::google::protobuf::internal::OnShutdown(&protobuf_ShutdownFile_21014_5fS2CRoomKickedRsp_2eproto);
}

// Force AddDescriptors() to be called at static initialization time.
struct StaticDescriptorInitializer_21014_5fS2CRoomKickedRsp_2eproto {
  StaticDescriptorInitializer_21014_5fS2CRoomKickedRsp_2eproto() {
    protobuf_AddDesc_21014_5fS2CRoomKickedRsp_2eproto();
  }
} static_descriptor_initializer_21014_5fS2CRoomKickedRsp_2eproto_;

// ===================================================================

#ifndef _MSC_VER
#endif  // !_MSC_VER

S2CRoomKickedRsp::S2CRoomKickedRsp()
  : ::google::protobuf::Message() {
  SharedCtor();
}

void S2CRoomKickedRsp::InitAsDefaultInstance() {
}

S2CRoomKickedRsp::S2CRoomKickedRsp(const S2CRoomKickedRsp& from)
  : ::google::protobuf::Message() {
  SharedCtor();
  MergeFrom(from);
}

void S2CRoomKickedRsp::SharedCtor() {
  _cached_size_ = 0;
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
}

S2CRoomKickedRsp::~S2CRoomKickedRsp() {
  SharedDtor();
}

void S2CRoomKickedRsp::SharedDtor() {
  if (this != default_instance_) {
  }
}

void S2CRoomKickedRsp::SetCachedSize(int size) const {
  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
}
const ::google::protobuf::Descriptor* S2CRoomKickedRsp::descriptor() {
  protobuf_AssignDescriptorsOnce();
  return S2CRoomKickedRsp_descriptor_;
}

const S2CRoomKickedRsp& S2CRoomKickedRsp::default_instance() {
  if (default_instance_ == NULL) protobuf_AddDesc_21014_5fS2CRoomKickedRsp_2eproto();
  return *default_instance_;
}

S2CRoomKickedRsp* S2CRoomKickedRsp::default_instance_ = NULL;

S2CRoomKickedRsp* S2CRoomKickedRsp::New() const {
  return new S2CRoomKickedRsp;
}

void S2CRoomKickedRsp::Clear() {
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
  mutable_unknown_fields()->Clear();
}

bool S2CRoomKickedRsp::MergePartialFromCodedStream(
    ::google::protobuf::io::CodedInputStream* input) {
#define DO_(EXPRESSION) if (!(EXPRESSION)) return false
  ::google::protobuf::uint32 tag;
  while ((tag = input->ReadTag()) != 0) {
    if (::google::protobuf::internal::WireFormatLite::GetTagWireType(tag) ==
        ::google::protobuf::internal::WireFormatLite::WIRETYPE_END_GROUP) {
      return true;
    }
    DO_(::google::protobuf::internal::WireFormat::SkipField(
          input, tag, mutable_unknown_fields()));
  }
  return true;
#undef DO_
}

void S2CRoomKickedRsp::SerializeWithCachedSizes(
    ::google::protobuf::io::CodedOutputStream* output) const {
  if (!unknown_fields().empty()) {
    ::google::protobuf::internal::WireFormat::SerializeUnknownFields(
        unknown_fields(), output);
  }
}

::google::protobuf::uint8* S2CRoomKickedRsp::SerializeWithCachedSizesToArray(
    ::google::protobuf::uint8* target) const {
  if (!unknown_fields().empty()) {
    target = ::google::protobuf::internal::WireFormat::SerializeUnknownFieldsToArray(
        unknown_fields(), target);
  }
  return target;
}

int S2CRoomKickedRsp::ByteSize() const {
  int total_size = 0;

  if (!unknown_fields().empty()) {
    total_size +=
      ::google::protobuf::internal::WireFormat::ComputeUnknownFieldsSize(
        unknown_fields());
  }
  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = total_size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
  return total_size;
}

void S2CRoomKickedRsp::MergeFrom(const ::google::protobuf::Message& from) {
  GOOGLE_CHECK_NE(&from, this);
  const S2CRoomKickedRsp* source =
    ::google::protobuf::internal::dynamic_cast_if_available<const S2CRoomKickedRsp*>(
      &from);
  if (source == NULL) {
    ::google::protobuf::internal::ReflectionOps::Merge(from, this);
  } else {
    MergeFrom(*source);
  }
}

void S2CRoomKickedRsp::MergeFrom(const S2CRoomKickedRsp& from) {
  GOOGLE_CHECK_NE(&from, this);
  mutable_unknown_fields()->MergeFrom(from.unknown_fields());
}

void S2CRoomKickedRsp::CopyFrom(const ::google::protobuf::Message& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

void S2CRoomKickedRsp::CopyFrom(const S2CRoomKickedRsp& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool S2CRoomKickedRsp::IsInitialized() const {

  return true;
}

void S2CRoomKickedRsp::Swap(S2CRoomKickedRsp* other) {
  if (other != this) {
    _unknown_fields_.Swap(&other->_unknown_fields_);
    std::swap(_cached_size_, other->_cached_size_);
  }
}

::google::protobuf::Metadata S2CRoomKickedRsp::GetMetadata() const {
  protobuf_AssignDescriptorsOnce();
  ::google::protobuf::Metadata metadata;
  metadata.descriptor = S2CRoomKickedRsp_descriptor_;
  metadata.reflection = S2CRoomKickedRsp_reflection_;
  return metadata;
}


// @@protoc_insertion_point(namespace_scope)

}  // namespace Protocol

// @@protoc_insertion_point(global_scope)
