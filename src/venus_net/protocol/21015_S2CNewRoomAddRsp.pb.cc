// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: 21015_S2CNewRoomAddRsp.proto

#define INTERNAL_SUPPRESS_PROTOBUF_FIELD_DEPRECATION
#include "21015_S2CNewRoomAddRsp.pb.h"

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

const ::google::protobuf::Descriptor* S2CNewRoomAddRsp_descriptor_ = NULL;
const ::google::protobuf::internal::GeneratedMessageReflection*
  S2CNewRoomAddRsp_reflection_ = NULL;

}  // namespace


void protobuf_AssignDesc_21015_5fS2CNewRoomAddRsp_2eproto() {
  protobuf_AddDesc_21015_5fS2CNewRoomAddRsp_2eproto();
  const ::google::protobuf::FileDescriptor* file =
    ::google::protobuf::DescriptorPool::generated_pool()->FindFileByName(
      "21015_S2CNewRoomAddRsp.proto");
  GOOGLE_CHECK(file != NULL);
  S2CNewRoomAddRsp_descriptor_ = file->message_type(0);
  static const int S2CNewRoomAddRsp_offsets_[2] = {
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(S2CNewRoomAddRsp, id_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(S2CNewRoomAddRsp, room_name_),
  };
  S2CNewRoomAddRsp_reflection_ =
    new ::google::protobuf::internal::GeneratedMessageReflection(
      S2CNewRoomAddRsp_descriptor_,
      S2CNewRoomAddRsp::default_instance_,
      S2CNewRoomAddRsp_offsets_,
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(S2CNewRoomAddRsp, _has_bits_[0]),
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(S2CNewRoomAddRsp, _unknown_fields_),
      -1,
      ::google::protobuf::DescriptorPool::generated_pool(),
      ::google::protobuf::MessageFactory::generated_factory(),
      sizeof(S2CNewRoomAddRsp));
}

namespace {

GOOGLE_PROTOBUF_DECLARE_ONCE(protobuf_AssignDescriptors_once_);
inline void protobuf_AssignDescriptorsOnce() {
  ::google::protobuf::GoogleOnceInit(&protobuf_AssignDescriptors_once_,
                 &protobuf_AssignDesc_21015_5fS2CNewRoomAddRsp_2eproto);
}

void protobuf_RegisterTypes(const ::std::string&) {
  protobuf_AssignDescriptorsOnce();
  ::google::protobuf::MessageFactory::InternalRegisterGeneratedMessage(
    S2CNewRoomAddRsp_descriptor_, &S2CNewRoomAddRsp::default_instance());
}

}  // namespace

void protobuf_ShutdownFile_21015_5fS2CNewRoomAddRsp_2eproto() {
  delete S2CNewRoomAddRsp::default_instance_;
  delete S2CNewRoomAddRsp_reflection_;
}

void protobuf_AddDesc_21015_5fS2CNewRoomAddRsp_2eproto() {
  static bool already_here = false;
  if (already_here) return;
  already_here = true;
  GOOGLE_PROTOBUF_VERIFY_VERSION;

  ::google::protobuf::DescriptorPool::InternalAddGeneratedFile(
    "\n\03421015_S2CNewRoomAddRsp.proto\022\010Protocol"
    "\"1\n\020S2CNewRoomAddRsp\022\n\n\002id\030\001 \002(\r\022\021\n\troom"
    "_name\030\002 \002(\t", 91);
  ::google::protobuf::MessageFactory::InternalRegisterGeneratedFile(
    "21015_S2CNewRoomAddRsp.proto", &protobuf_RegisterTypes);
  S2CNewRoomAddRsp::default_instance_ = new S2CNewRoomAddRsp();
  S2CNewRoomAddRsp::default_instance_->InitAsDefaultInstance();
  ::google::protobuf::internal::OnShutdown(&protobuf_ShutdownFile_21015_5fS2CNewRoomAddRsp_2eproto);
}

// Force AddDescriptors() to be called at static initialization time.
struct StaticDescriptorInitializer_21015_5fS2CNewRoomAddRsp_2eproto {
  StaticDescriptorInitializer_21015_5fS2CNewRoomAddRsp_2eproto() {
    protobuf_AddDesc_21015_5fS2CNewRoomAddRsp_2eproto();
  }
} static_descriptor_initializer_21015_5fS2CNewRoomAddRsp_2eproto_;

// ===================================================================

#ifndef _MSC_VER
const int S2CNewRoomAddRsp::kIdFieldNumber;
const int S2CNewRoomAddRsp::kRoomNameFieldNumber;
#endif  // !_MSC_VER

S2CNewRoomAddRsp::S2CNewRoomAddRsp()
  : ::google::protobuf::Message() {
  SharedCtor();
}

void S2CNewRoomAddRsp::InitAsDefaultInstance() {
}

S2CNewRoomAddRsp::S2CNewRoomAddRsp(const S2CNewRoomAddRsp& from)
  : ::google::protobuf::Message() {
  SharedCtor();
  MergeFrom(from);
}

void S2CNewRoomAddRsp::SharedCtor() {
  _cached_size_ = 0;
  id_ = 0u;
  room_name_ = const_cast< ::std::string*>(&::google::protobuf::internal::kEmptyString);
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
}

S2CNewRoomAddRsp::~S2CNewRoomAddRsp() {
  SharedDtor();
}

void S2CNewRoomAddRsp::SharedDtor() {
  if (room_name_ != &::google::protobuf::internal::kEmptyString) {
    delete room_name_;
  }
  if (this != default_instance_) {
  }
}

void S2CNewRoomAddRsp::SetCachedSize(int size) const {
  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
}
const ::google::protobuf::Descriptor* S2CNewRoomAddRsp::descriptor() {
  protobuf_AssignDescriptorsOnce();
  return S2CNewRoomAddRsp_descriptor_;
}

const S2CNewRoomAddRsp& S2CNewRoomAddRsp::default_instance() {
  if (default_instance_ == NULL) protobuf_AddDesc_21015_5fS2CNewRoomAddRsp_2eproto();
  return *default_instance_;
}

S2CNewRoomAddRsp* S2CNewRoomAddRsp::default_instance_ = NULL;

S2CNewRoomAddRsp* S2CNewRoomAddRsp::New() const {
  return new S2CNewRoomAddRsp;
}

void S2CNewRoomAddRsp::Clear() {
  if (_has_bits_[0 / 32] & (0xffu << (0 % 32))) {
    id_ = 0u;
    if (has_room_name()) {
      if (room_name_ != &::google::protobuf::internal::kEmptyString) {
        room_name_->clear();
      }
    }
  }
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
  mutable_unknown_fields()->Clear();
}

bool S2CNewRoomAddRsp::MergePartialFromCodedStream(
    ::google::protobuf::io::CodedInputStream* input) {
#define DO_(EXPRESSION) if (!(EXPRESSION)) return false
  ::google::protobuf::uint32 tag;
  while ((tag = input->ReadTag()) != 0) {
    switch (::google::protobuf::internal::WireFormatLite::GetTagFieldNumber(tag)) {
      // required uint32 id = 1;
      case 1: {
        if (::google::protobuf::internal::WireFormatLite::GetTagWireType(tag) ==
            ::google::protobuf::internal::WireFormatLite::WIRETYPE_VARINT) {
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   ::google::protobuf::uint32, ::google::protobuf::internal::WireFormatLite::TYPE_UINT32>(
                 input, &id_)));
          set_has_id();
        } else {
          goto handle_uninterpreted;
        }
        if (input->ExpectTag(18)) goto parse_room_name;
        break;
      }

      // required string room_name = 2;
      case 2: {
        if (::google::protobuf::internal::WireFormatLite::GetTagWireType(tag) ==
            ::google::protobuf::internal::WireFormatLite::WIRETYPE_LENGTH_DELIMITED) {
         parse_room_name:
          DO_(::google::protobuf::internal::WireFormatLite::ReadString(
                input, this->mutable_room_name()));
          ::google::protobuf::internal::WireFormat::VerifyUTF8String(
            this->room_name().data(), this->room_name().length(),
            ::google::protobuf::internal::WireFormat::PARSE);
        } else {
          goto handle_uninterpreted;
        }
        if (input->ExpectAtEnd()) return true;
        break;
      }

      default: {
      handle_uninterpreted:
        if (::google::protobuf::internal::WireFormatLite::GetTagWireType(tag) ==
            ::google::protobuf::internal::WireFormatLite::WIRETYPE_END_GROUP) {
          return true;
        }
        DO_(::google::protobuf::internal::WireFormat::SkipField(
              input, tag, mutable_unknown_fields()));
        break;
      }
    }
  }
  return true;
#undef DO_
}

void S2CNewRoomAddRsp::SerializeWithCachedSizes(
    ::google::protobuf::io::CodedOutputStream* output) const {
  // required uint32 id = 1;
  if (has_id()) {
    ::google::protobuf::internal::WireFormatLite::WriteUInt32(1, this->id(), output);
  }

  // required string room_name = 2;
  if (has_room_name()) {
    ::google::protobuf::internal::WireFormat::VerifyUTF8String(
      this->room_name().data(), this->room_name().length(),
      ::google::protobuf::internal::WireFormat::SERIALIZE);
    ::google::protobuf::internal::WireFormatLite::WriteString(
      2, this->room_name(), output);
  }

  if (!unknown_fields().empty()) {
    ::google::protobuf::internal::WireFormat::SerializeUnknownFields(
        unknown_fields(), output);
  }
}

::google::protobuf::uint8* S2CNewRoomAddRsp::SerializeWithCachedSizesToArray(
    ::google::protobuf::uint8* target) const {
  // required uint32 id = 1;
  if (has_id()) {
    target = ::google::protobuf::internal::WireFormatLite::WriteUInt32ToArray(1, this->id(), target);
  }

  // required string room_name = 2;
  if (has_room_name()) {
    ::google::protobuf::internal::WireFormat::VerifyUTF8String(
      this->room_name().data(), this->room_name().length(),
      ::google::protobuf::internal::WireFormat::SERIALIZE);
    target =
      ::google::protobuf::internal::WireFormatLite::WriteStringToArray(
        2, this->room_name(), target);
  }

  if (!unknown_fields().empty()) {
    target = ::google::protobuf::internal::WireFormat::SerializeUnknownFieldsToArray(
        unknown_fields(), target);
  }
  return target;
}

int S2CNewRoomAddRsp::ByteSize() const {
  int total_size = 0;

  if (_has_bits_[0 / 32] & (0xffu << (0 % 32))) {
    // required uint32 id = 1;
    if (has_id()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::UInt32Size(
          this->id());
    }

    // required string room_name = 2;
    if (has_room_name()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::StringSize(
          this->room_name());
    }

  }
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

void S2CNewRoomAddRsp::MergeFrom(const ::google::protobuf::Message& from) {
  GOOGLE_CHECK_NE(&from, this);
  const S2CNewRoomAddRsp* source =
    ::google::protobuf::internal::dynamic_cast_if_available<const S2CNewRoomAddRsp*>(
      &from);
  if (source == NULL) {
    ::google::protobuf::internal::ReflectionOps::Merge(from, this);
  } else {
    MergeFrom(*source);
  }
}

void S2CNewRoomAddRsp::MergeFrom(const S2CNewRoomAddRsp& from) {
  GOOGLE_CHECK_NE(&from, this);
  if (from._has_bits_[0 / 32] & (0xffu << (0 % 32))) {
    if (from.has_id()) {
      set_id(from.id());
    }
    if (from.has_room_name()) {
      set_room_name(from.room_name());
    }
  }
  mutable_unknown_fields()->MergeFrom(from.unknown_fields());
}

void S2CNewRoomAddRsp::CopyFrom(const ::google::protobuf::Message& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

void S2CNewRoomAddRsp::CopyFrom(const S2CNewRoomAddRsp& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool S2CNewRoomAddRsp::IsInitialized() const {
  if ((_has_bits_[0] & 0x00000003) != 0x00000003) return false;

  return true;
}

void S2CNewRoomAddRsp::Swap(S2CNewRoomAddRsp* other) {
  if (other != this) {
    std::swap(id_, other->id_);
    std::swap(room_name_, other->room_name_);
    std::swap(_has_bits_[0], other->_has_bits_[0]);
    _unknown_fields_.Swap(&other->_unknown_fields_);
    std::swap(_cached_size_, other->_cached_size_);
  }
}

::google::protobuf::Metadata S2CNewRoomAddRsp::GetMetadata() const {
  protobuf_AssignDescriptorsOnce();
  ::google::protobuf::Metadata metadata;
  metadata.descriptor = S2CNewRoomAddRsp_descriptor_;
  metadata.reflection = S2CNewRoomAddRsp_reflection_;
  return metadata;
}


// @@protoc_insertion_point(namespace_scope)

}  // namespace Protocol

// @@protoc_insertion_point(global_scope)
